#include "stdafx.h"
#include "AtlHttpClient2.h"

///////////////////////////////////////////////////////////////////////////////
CAtlHttpClient2::CAtlHttpClient2()
{
}

///////////////////////////////////////////////////////////////////////////////
CAtlHttpClient2::~CAtlHttpClient2()
{
}

///////////////////////////////////////////////////////////////////////////////
bool CAtlHttpClient2::Navigate2(LPCTSTR szURL, ATL_NAVIGATE_DATA *pNavData)
throw(...)
{
    if (!szURL || *szURL == _T('\0'))
        return false;

    CUrl url;
    TCHAR szTmp[ATL_URL_MAX_URL_LENGTH];
    if (!AtlEscapeUrl(szURL, szTmp, 0, ATL_URL_MAX_URL_LENGTH - 1,
        ATL_URL_BROWSER_MODE))
        return false;

    if (!url.CrackUrl(szTmp))
        return false;

    return Navigate2(&url, pNavData);
}

///////////////////////////////////////////////////////////////////////////////
bool CAtlHttpClient2::Navigate2(const CUrl* pUrl, ATL_NAVIGATE_DATA *pNavData)
throw(...)
{
    bool bRet = false;
    if (!pUrl)
        return false;

    ResetRequest();

    CAtlNavigateData default_nav_data;
    if (!pNavData)
        m_pNavData = &default_nav_data;
    else
        m_pNavData = pNavData;

    ATLASSUME(m_pNavData);

    _ATLTRY
    {
        m_strMethod = m_pNavData->szMethod;
    }
        _ATLCATCHALL()
    {
        return false;
    }

    SetSocketTimeout(m_pNavData->dwTimeout);

    // set m_urlCurrent
    if (!SetDefaultUrl(pUrl, m_pNavData->nPort))
        return false;
    DWORD dwSent = 0;
    CString strRequest;
    CString strExtraInfo;

    if (!BuildRequest2(&strRequest,
        m_pNavData->szMethod,
        m_pNavData->szExtraHeaders))
    {
        return false;
    }

    if (!ConnectSocket())
        return false;

    LPCTSTR szTRequest = strRequest;
    CT2CA strARequest(szTRequest);
    DWORD dwRequestLen = (DWORD)strlen(strARequest);
    DWORD dwAvailable = dwRequestLen + m_pNavData->dwDataLen;

    if (m_pNavData->dwFlags & ATL_HTTP_FLAG_SEND_CALLBACK)
    {
        dwSent = WriteWithCallback(strARequest, dwRequestLen);
    }
    else if (!m_pNavData->pData)
        dwSent = WriteWithNoData(strARequest, dwRequestLen);
    else if (m_pNavData->pData && (m_pNavData->dwFlags & ATL_HTTP_FLAG_SEND_BLOCKS))
    {
        dwSent = WriteWithChunks(strARequest, dwRequestLen);
    }
    else if (m_pNavData->pData)
    {
        dwSent = WriteWithData(strARequest, dwRequestLen);
    }

    // make sure everything was sent
    if (dwSent == dwAvailable)
    {
        // Read the response
        if (RR_OK == ReadHttpResponse2())
        {
            // if navigation isn't complete, try to complete
            // it based on the status code and flags
            if ((m_pNavData->dwFlags & ATL_HTTP_FLAG_PROCESS_RESULT) &&
                !ProcessStatus(m_pNavData->dwFlags))
            {
                bRet = false;
            }
            else
                bRet = true;
        }
        else
            bRet = false;
    }

    if (!bRet)
        Close(); // some kind of failure happened, close the socket.

    m_pNavData = NULL;

    return bRet;
}

///////////////////////////////////////////////////////////////////////////////
bool CAtlHttpClient2::BuildRequest2(/*out*/CString *pstrRequest,
    LPCTSTR szMethod, LPCTSTR szExtraHeaders) throw()
{
    if (!m_pNavData)
        return false;
    _ATLTRY
    {
        // build up the request
        CString strRequest = szMethod;
        strRequest += _T(" ");
        if (GetProxy())
        {
            TCHAR buffURL[ATL_URL_MAX_URL_LENGTH];
            DWORD dwSize = ATL_URL_MAX_URL_LENGTH;
            m_urlCurrent.CreateUrl(buffURL, &dwSize);
            strRequest += buffURL;

            strRequest += ATL_HTTP_HEADER_PROXY;
            CString strHost;
            if (m_urlCurrent.GetPortNumber() != ATL_URL_DEFAULT_HTTP_PORT)
                strHost.Format(_T("Host: %s:%d\r\n"),
                m_urlCurrent.GetHostName(), m_urlCurrent.GetPortNumber());
            else
                strHost.Format(_T("Host: %s\r\n"), m_urlCurrent.GetHostName());
            strRequest += strHost;

            if (m_pNavData->dwDataLen > 0)
            {
                CString strCL;
                strCL.Format(_T("Content-Length: %d\r\n"), m_pNavData->dwDataLen);
                strRequest += strCL;
            }

            if (m_pNavData->szDataType)
            {
                strRequest += _T("Content-Type: ");
                strRequest += m_pNavData->szDataType;
                strRequest += _T("\r\n");
            }

            if (m_pNavData->szExtraHeaders)
                strRequest += szExtraHeaders;
            strRequest += ATL_HTTP_USERAGENT;
        }
        else
        {
            strRequest += m_urlCurrent.GetUrlPath();
            strRequest += m_urlCurrent.GetExtraInfo();
            strRequest += ATL_HTTP_HEADER;

            if (m_pNavData->dwDataLen > 0)
            {
                CString strCL;
                strCL.Format(_T("Content-Length: %d\r\n"), m_pNavData->dwDataLen);
                strRequest += strCL;
            }

            if (m_pNavData->szDataType &&
                *m_pNavData->szDataType)
            {
                strRequest += _T("Content-Type: ");
                strRequest += m_pNavData->szDataType;
                strRequest += _T("\r\n");
            }

            if (szExtraHeaders)
                strRequest += szExtraHeaders;


            CString strHost;
            strHost.Format(_T("Host: %s:%d\r\n"), m_urlCurrent.GetHostName(),
                m_urlCurrent.GetPortNumber());
            strRequest += strHost;
            strRequest += ATL_HTTP_USERAGENT;
        }

        strRequest += _T("\r\n");
        *pstrRequest = strRequest;

        return true;
    }
        _ATLCATCHALL()
    {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////////
CAtlHttpClient2::HTTP_RESPONSE_READ_STATUS CAtlHttpClient2::ReadHttpResponse2()
{
    // Read until we at least have the response headers
    HTTP_RESPONSE_READ_STATUS result = RR_OK;
    readstate state = rs_init;
    unsigned char *pBodyBegin = NULL;
    unsigned char *pHeaderBegin = NULL;
    m_current.Empty();
    m_pCurrent = NULL;
    m_LastResponseParseError = RR_OK;

    while (state != rs_complete)
    {
        switch (state)
        {
        case rs_init:
            m_HeaderMap.RemoveAll();
            m_nStatus = ATL_INVALID_STATUS;
            m_dwHeaderLen = 0;
            m_dwBodyLen = 0;
            state = rs_readheader;
            // fall through

        case rs_readheader:

            // read from the socket until we have a complete set of headers.
            pBodyBegin = FindHeaderEnd(&pHeaderBegin);
            if (!pBodyBegin)
            {
                if (!ReadSocket())
                {
                    // Either reading from the socket failed, or there
                    // was not data to read. Set the nav status to error
                    // and change the state to complete.
                    state = rs_complete;
                    result = RR_READSOCKET_FAILED;
                    break;
                }
                else
                    break; // loop back and FindHeaderEnd again.
            }
            // we have a complete set of headers
            m_dwHeaderLen = (DWORD)(pBodyBegin - pHeaderBegin);
            m_dwHeaderStart = (DWORD)(pHeaderBegin - (BYTE*)(LPCSTR)m_current);
            // fall through
            state = rs_scanheader;

        case rs_scanheader:
            // set m_nStatus and check for valid status
            ParseStatusLine(pHeaderBegin);
            // failed to set m_nStatus;
            if (m_nStatus == ATL_INVALID_STATUS)
            {
                state = rs_complete;
                result = RR_STATUS_INVALID;
                break;
            }

            else if (m_nStatus == 100) // continue
            {
                state = rs_init;
                break;
            }

            // crack all the headers and put them into a header map. We've already
            // done the check to make sure we have a complete set of headers in 
            // rs_readheader above
            if (ATL_HEADER_PARSE_COMPLETE != CrackResponseHeader((LPCSTR)pHeaderBegin,
                (LPCSTR*)&pBodyBegin))
            {
                // something bad happened while parsing the headers!
                state = rs_complete;
                result = RR_PARSEHEADERS_FAILED;
                break;
            }
            state = rs_readbody;
            // fall through

        case rs_readbody:
            // headers are parsed and cracked, we're ready to read the rest
            // of the response. 
            if (IsMsgBodyChunked())
            {
                if (!ReadChunkedBody())
                {
                    result = RR_READCHUNKEDBODY_FAILED;
                    state = rs_complete;
                    break;
                }
            }
            else if (m_nStatus != 204 /* no content */)
            {
                if (!ReadBody(GetContentLength(), m_current.GetLength() - (m_dwHeaderStart + m_dwHeaderLen)))
                    result = RR_READBODY_FAILED;
            }
            state = rs_complete;
            //fall through

        case rs_complete:
            // clean up the connection if the server requested a close;
            DisconnectIfRequired();
            break;
        }
    }
    m_LastResponseParseError = result;
    return result;
}

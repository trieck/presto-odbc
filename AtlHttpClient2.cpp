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
        if (RR_OK == ReadHttpResponse())
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
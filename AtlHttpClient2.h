#pragma once

#include <atlhttp.h>

///////////////////////////////////////////////////////////////////////////////
class CAtlHttpClient2 : public CAtlHttpClient
{
public:
    CAtlHttpClient2();
    ~CAtlHttpClient2();

    bool Navigate2(LPCTSTR szURL, ATL_NAVIGATE_DATA *pNavData = NULL)
        throw(...);

    bool Navigate2(const CUrl* pUrl, ATL_NAVIGATE_DATA *pNavData = NULL)
        throw(...);
protected:
    bool BuildRequest2(/*out*/CString *pstrRequest,
        LPCTSTR szDataType = NULL,
        LPCTSTR szExtraHeaders = NULL) throw();
};


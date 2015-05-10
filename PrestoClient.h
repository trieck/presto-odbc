#pragma once

#include <atlhttp.h>
#include "Session.h"
#include "QueryResults.h"

///////////////////////////////////////////////////////////////////////////////
class PrestoClient
{
public:
    PrestoClient();
    ~PrestoClient();
    bool query(const Session& session, const wstring & str);
private:
    static wstring makeHeaders(const Session& session);
    CAtlHttpClient m_client;
    QueryResults m_results;
};


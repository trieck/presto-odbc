#pragma once

#include "Session.h"
#include "QueryResults.h"
#include "AtlHttpClient2.h"

///////////////////////////////////////////////////////////////////////////////
class PrestoClient
{
public:
    PrestoClient();
    ~PrestoClient();
    bool query(const Session& session, const wstring & str);
private:
    static wstring makeHeaders(const Session& session);
    CAtlHttpClient2 m_client;
    QueryResults m_results;
};


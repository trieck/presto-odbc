#pragma once

#include <atlhttp.h>
#include "Session.h"

///////////////////////////////////////////////////////////////////////////////
class PrestoClient
{
public:
    PrestoClient();
    ~PrestoClient();
    wstring query(const Session& session, const wstring & str);
private:
    static wstring makeHeaders(const Session& session);
    CAtlHttpClient m_client;
};


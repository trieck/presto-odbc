#pragma once

#include "Session.h"
#include "StatementClient.h"

///////////////////////////////////////////////////////////////////////////////
class PrestoClient
{
public:
    PrestoClient();
    ~PrestoClient();
    StatementClientPtr query(const Session& session, const wstring& str);
};


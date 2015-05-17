#pragma once

#include "Session.h"
#include "Statement.h"

///////////////////////////////////////////////////////////////////////////////
class PrestoClient
{
public:
    PrestoClient();
    ~PrestoClient();
    StatementPtr query(const Session& session, const wstring& str);
};


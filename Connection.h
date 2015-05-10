#pragma once

#include "Environment.h"
#include "Session.h"
#include "PrestoClient.h"

///////////////////////////////////////////////////////////////////////////////
class Connection
{
public:
    Connection(LPENVIRONMENT);
    ~Connection();

    static stringmap parseConnectionString(const wstring &input);

    bool connect();
    Session& getSession();

private:
    LPENVIRONMENT m_pEnv;
    Session session;
    PrestoClient client;
};

typedef Connection *LPCONNECTION;
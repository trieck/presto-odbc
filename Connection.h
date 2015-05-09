#pragma once

#include "Environment.h"

///////////////////////////////////////////////////////////////////////////////
class Connection
{
public:
    Connection(LPENVIRONMENT);
    ~Connection();

    static stringmap parseConnectionString(const wstring &input);

private:
    LPENVIRONMENT m_pEnv;
};

typedef Connection *LPCONNECTION;
#pragma once

#include "Environment.h"

///////////////////////////////////////////////////////////////////////////////
class Connection
{
public:
    Connection(LPENVIRONMENT);
    ~Connection();
private:
    LPENVIRONMENT m_pEnv;
};

typedef Connection *LPCONNECTION;
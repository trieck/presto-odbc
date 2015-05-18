#pragma once
#include "Connection.h"

///////////////////////////////////////////////////////////////////////////////
class Statement
{
public:
    Statement(LPCONNECTION);
    ~Statement();
private:
    LPCONNECTION m_pConn;
};

typedef Statement *LPSTATEMENT;
#pragma once

///////////////////////////////////////////////////////////////////////////////
class Session
{
public:
    Session();
    Session(const Session & rhs);
    ~Session();

    Session& operator = (const Session & rhs);
public:
    wstring endpoint, user, schema, catalog;
    uint64_t timeout;
};


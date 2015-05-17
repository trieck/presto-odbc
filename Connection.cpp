#include "stdafx.h"
#include <atlrx.h>
#include "Connection.h"
#include "util.h"

///////////////////////////////////////////////////////////////////////////////
Connection::Connection(LPENVIRONMENT pEnv) : m_pEnv(pEnv)
{
}

///////////////////////////////////////////////////////////////////////////////
Connection::~Connection()
{
}

///////////////////////////////////////////////////////////////////////////////
stringmap Connection::parseConnectionString(const wstring &input)
{
    stringmap output;

    CAtlRegExp<> re;
    REParseError status = re.Parse(
        L"{[^;]+}=(\\{{[^\\}]*}\\})|({[^;\\{]*})");

    if (REPARSE_ERROR_OK != status)
        return output;

    CAtlREMatchContext<> mc;

    const CAtlREMatchContext<>::RECHAR* szStart = 0;
    const CAtlREMatchContext<>::RECHAR* szEnd = 0;
    const CAtlREMatchContext<>::RECHAR* pzIn = input.c_str();

    wstring key, value;
    while (re.Match(pzIn, &mc)) {
        if (mc.m_uNumGroups != 3)
            break;

        mc.GetMatch(0, &szStart, &szEnd);
        key = wstring(szStart, szEnd - szStart);

        mc.GetMatch(1, &szStart, &szEnd);
        value = wstring(szStart, szEnd - szStart);

        if (szStart == NULL) {
            mc.GetMatch(2, &szStart, &szEnd);
            value = wstring(szStart, szEnd - szStart);
        }

        output[upper(key)] = value;

        pzIn = szEnd;
    }

    return output;
}

///////////////////////////////////////////////////////////////////////////////
bool Connection::connect()
{
    StatementPtr stmt = client.query(session, L"select 1");
    return stmt->succeeded();
}

///////////////////////////////////////////////////////////////////////////////
Session& Connection::getSession()
{
    return session;
}

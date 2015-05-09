#include "stdafx.h"
#include "util.h"
#include <sql.h>

///////////////////////////////////////////////////////////////////////////////
wstring makeString(SQLWCHAR* szStr, SQLSMALLINT length)
{
    if (length == SQL_NTS) {
        length = (SQLSMALLINT)wcslen(szStr);
    }

    return wstring(szStr, length);
}

/////////////////////////////////////////////////////////////////////////////
wstring upper(const wstring & input)
{
    wstring output;

    size_t N = input.length();
    output.resize(N);

    unsigned i;
    for (i = 0; i < N; i++)
        output[i] = toupper(input[i]);

    return output;
}

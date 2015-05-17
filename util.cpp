#include "stdafx.h"
#include "util.h"
#include <sql.h>

///////////////////////////////////////////////////////////////////////////////
wstring ODBCString(SQLWCHAR* szStr, SQLSMALLINT length)
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

/////////////////////////////////////////////////////////////////////////////
wstringvec split(const wstring &input, wchar_t delim) 
{
    wstringvec output;

    wstringstream ss(input);

    wstring item;
    while (std::getline(ss, item, delim)) {
        output.push_back(item);
    }

    return output;
}

/////////////////////////////////////////////////////////////////////////////
wstring UTF8ToWide(LPCSTR pUtf8String)
{
    return (LPCWSTR)CA2W(pUtf8String, CP_UTF8);
}

/////////////////////////////////////////////////////////////////////////////
CStringA WideToUTF8(LPCWSTR pWideString)
{
    return (LPCSTR)CW2A(pWideString, CP_UTF8);
}

/////////////////////////////////////////////////////////////////////////////
wstring modulename()
{
    wchar_t path[_MAX_PATH + _MAX_FNAME + 1] = { 0 };
    GetModuleFileName(modulehandle(), path, _MAX_PATH + _MAX_FNAME);
    return path;
}

/////////////////////////////////////////////////////////////////////////////
HINSTANCE modulehandle()
{
    MEMORY_BASIC_INFORMATION mbi;
    VirtualQuery(modulehandle, &mbi, sizeof(mbi));
    return (HINSTANCE)mbi.AllocationBase;
}
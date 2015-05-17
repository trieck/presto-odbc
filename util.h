#pragma once

///////////////////////////////////////////////////////////////////////////////
wstring modulename();
HINSTANCE modulehandle();
wstringvec split(const wstring &input, wchar_t delim);
wstring upper(const wstring &input);
wstring ODBCString(SQLWCHAR* szStr, SQLSMALLINT length);
wstring UTF8ToWide(LPCSTR pUtf8String);
CStringA WideToUTF8(LPCWSTR pWideString);
///////////////////////////////////////////////////////////////////////////////
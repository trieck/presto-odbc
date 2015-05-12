#pragma once

///////////////////////////////////////////////////////////////////////////////
wstring ODBCString(SQLWCHAR* szStr, SQLSMALLINT length);
wstring upper(const wstring &input);
wstringvec split(const wstring &input, wchar_t delim);
wstring UTF8toWide(LPCSTR pUtf8String);
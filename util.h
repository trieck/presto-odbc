#pragma once

///////////////////////////////////////////////////////////////////////////////
wstring makeString(SQLWCHAR* szStr, SQLSMALLINT length);
wstring upper(const wstring &input);
wstringvec split(const wstring &input, wchar_t delim);
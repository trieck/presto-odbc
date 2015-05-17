// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

#include <atlbase.h>
#include <atlstr.h>
#include <sqltypes.h>
#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <sstream>
#include <vector>

typedef std::basic_string<wchar_t> wstring;
typedef std::basic_stringstream<wchar_t> wstringstream;
typedef std::map<wstring, wstring> stringmap;
typedef std::vector<wstring> wstringvec;

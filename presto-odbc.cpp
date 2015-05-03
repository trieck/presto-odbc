// presto-odbc.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "presto-odbc.h"


// This is an example of an exported variable
PRESTOODBC_API int nprestoodbc=0;

// This is an example of an exported function.
PRESTOODBC_API int fnprestoodbc(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see presto-odbc.h for the class definition
Cprestoodbc::Cprestoodbc()
{
	return;
}

#include "stdafx.h"
#include "presto-odbc.h"
#include <sql.h>

extern "C" {

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLAllocHandle(SQLSMALLINT HandleType,
        SQLHANDLE InputHandle, _Out_ SQLHANDLE *OutputHandle)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLBindCol(SQLHSTMT StatementHandle,
        SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
        _Inout_updates_opt_(_Inexpressible_(BufferLength)) SQLPOINTER TargetValue,
        SQLLEN BufferLength, _Inout_opt_ SQLLEN *StrLen_or_Ind)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLBindParameter(
        SQLHSTMT           hstmt,
        SQLUSMALLINT       ipar,
        SQLSMALLINT        fParamType,
        SQLSMALLINT        fCType,
        SQLSMALLINT        fSqlType,
        SQLULEN            cbColDef,
        SQLSMALLINT        ibScale,
        SQLPOINTER         rgbValue,
        SQLLEN             cbValueMax,
        SQLLEN             *pcbValue)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLBrowseConnect(
        SQLHDBC            hdbc,
        _In_reads_(cchConnStrIn)
        SQLCHAR           *szConnStrIn,
        SQLSMALLINT        cchConnStrIn,
        _Out_writes_opt_(cchConnStrOutMax)
        SQLCHAR           *szConnStrOut,
        SQLSMALLINT        cchConnStrOutMax,
        _Out_opt_
        SQLSMALLINT       *pcchConnStrOut)
    {
        return SQL_SUCCESS;
    }
}
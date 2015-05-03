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
    PRESTOODBC_API SQLRETURN SQL_API SQLBrowseConnectW(
        SQLHDBC            hdbc,
        _In_reads_(cchConnStrIn)
        SQLWCHAR           *szConnStrIn,
        SQLSMALLINT        cchConnStrIn,
        _Out_writes_opt_(cchConnStrOutMax)
        SQLWCHAR           *szConnStrOut,
        SQLSMALLINT        cchConnStrOutMax,
        _Out_opt_
        SQLSMALLINT       *pcchConnStrOut)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN  SQL_API SQLBulkOperations(
        SQLHSTMT            StatementHandle,
        SQLSMALLINT         Operation)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN  SQL_API SQLCancel(SQLHSTMT StatementHandle)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN  SQL_API SQLCloseCursor(SQLHSTMT StatementHandle)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN  SQL_API SQLColAttributeW(SQLHSTMT StatementHandle,
        SQLUSMALLINT ColumnNumber, SQLUSMALLINT FieldIdentifier,
        _Out_writes_bytes_opt_(BufferLength) SQLPOINTER CharacterAttribute,
        SQLSMALLINT BufferLength, _Out_opt_ SQLSMALLINT *StringLength,
        _Out_opt_ SQLLEN *NumericAttribute)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLColumnPrivilegesW(
        SQLHSTMT           hstmt,
        _In_reads_opt_(cchCatalogName)
        SQLWCHAR           *szCatalogName,
        SQLSMALLINT        cchCatalogName,
        _In_reads_opt_(cchSchemaName)
        SQLWCHAR           *szSchemaName,
        SQLSMALLINT        cchSchemaName,
        _In_reads_opt_(cchTableName)
        SQLWCHAR           *szTableName,
        SQLSMALLINT        cchTableName,
        _In_reads_opt_(cchColumnName)
        SQLWCHAR           *szColumnName,
        SQLSMALLINT        cchColumnName)
    {
        return SQL_SUCCESS;
    }
}
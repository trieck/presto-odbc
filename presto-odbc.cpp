#include "stdafx.h"
#include "presto-odbc.h"
#include "Connection.h"
#include <sql.h>

extern "C" {

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLAllocHandle(SQLSMALLINT HandleType,
        SQLHANDLE InputHandle, _Out_ SQLHANDLE *OutputHandle)
    {
        ATLVERIFY(OutputHandle != NULL);

        switch (HandleType) {
        case SQL_HANDLE_ENV:
            *OutputHandle = static_cast<SQLHANDLE>(new Environment);
            break;
        case SQL_HANDLE_DBC:
            *OutputHandle = static_cast<SQLHANDLE>(
                new Connection(static_cast<LPENVIRONMENT>(InputHandle))
                );
            break;
        default:
            return SQL_ERROR;
        }
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
    PRESTOODBC_API SQLRETURN SQL_API SQLBulkOperations(
        SQLHSTMT            StatementHandle,
        SQLSMALLINT         Operation)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLCancel(SQLHSTMT StatementHandle)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLCloseCursor(SQLHSTMT StatementHandle)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLColAttributeW(SQLHSTMT StatementHandle,
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

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLDisconnect(SQLHDBC ConnectionHandle)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLEndTran(SQLSMALLINT HandleType,
        SQLHANDLE Handle, SQLSMALLINT CompletionType)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLExecDirectW(SQLHSTMT StatementHandle,
        _In_reads_opt_(TextLength) SQLWCHAR* StatementText,
        SQLINTEGER TextLength)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLExecute(SQLHSTMT StatementHandle)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLFetch(SQLHSTMT StatementHandle)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLFetchScroll(SQLHSTMT StatementHandle,
        SQLSMALLINT FetchOrientation, SQLLEN FetchOffset)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLFreeHandle(SQLSMALLINT HandleType,
        SQLHANDLE Handle)
    {
        ATLVERIFY(Handle != NULL);

        switch (HandleType) {
        case SQL_HANDLE_ENV:
            delete static_cast<LPENVIRONMENT>(Handle);
            break;
        case SQL_HANDLE_DBC:
            delete static_cast<LPCONNECTION>(Handle);
            break;
        default:
            return SQL_ERROR;
        }

        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLFreeStmt(SQLHSTMT StatementHandle,
        SQLUSMALLINT Option)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLGetConnectAttr(SQLHDBC ConnectionHandle,
        SQLINTEGER Attribute, _Out_writes_opt_(_Inexpressible_(BufferLength))
        SQLPOINTER Value, SQLINTEGER BufferLength,
        _Out_opt_ SQLINTEGER *StringLengthPtr)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLGetCursorNameW(
        SQLHSTMT StatementHandle,
        _Out_writes_opt_(BufferLength) SQLWCHAR *CursorName,
        SQLSMALLINT BufferLength,
        _Out_opt_
        SQLSMALLINT *NameLengthPtr)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLGetData(SQLHSTMT StatementHandle,
        SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
        _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER TargetValue,
        SQLLEN BufferLength, _Out_opt_ SQLLEN *StrLen_or_IndPtr)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLGetDescFieldW(SQLHDESC DescriptorHandle,
        SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,
        _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER Value,
        SQLINTEGER BufferLength, _Out_opt_ SQLINTEGER *StringLength)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLGetDescRecW(SQLHDESC DescriptorHandle,
        SQLSMALLINT RecNumber, _Out_writes_opt_(BufferLength) SQLCHAR *Name,
        SQLSMALLINT BufferLength, _Out_opt_ SQLSMALLINT *StringLengthPtr,
        _Out_opt_ SQLSMALLINT *TypePtr, _Out_opt_ SQLSMALLINT *SubTypePtr,
        _Out_opt_ SQLLEN     *LengthPtr, _Out_opt_ SQLSMALLINT *PrecisionPtr,
        _Out_opt_ SQLSMALLINT *ScalePtr, _Out_opt_ SQLSMALLINT *NullablePtr)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLGetDiagFieldW(SQLSMALLINT HandleType,
        SQLHANDLE Handle, SQLSMALLINT RecNumber, SQLSMALLINT DiagIdentifier,
        _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER DiagInfo,
        SQLSMALLINT BufferLength, _Out_opt_ SQLSMALLINT *StringLength)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLGetDiagRecW(SQLSMALLINT HandleType,
        SQLHANDLE Handle, SQLSMALLINT RecNumber,
        _Out_writes_opt_(6) SQLCHAR *Sqlstate, SQLINTEGER *NativeError,
        _Out_writes_opt_(BufferLength) SQLCHAR* MessageText,
        SQLSMALLINT BufferLength, _Out_opt_ SQLSMALLINT *TextLength)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLSetEnvAttr(SQLHENV EnvironmentHandle,
        SQLINTEGER Attribute, _In_reads_bytes_opt_(StringLength) SQLPOINTER Value,
        SQLINTEGER StringLength)
    {
        return SQL_SUCCESS;
    }
}
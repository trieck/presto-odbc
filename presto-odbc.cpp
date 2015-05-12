#include "stdafx.h"
#include "presto-odbc.h"
#include "Connection.h"
#include "util.h"
#include "Session.h"
#include <sqlext.h>

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
    PRESTOODBC_API SQLRETURN SQL_API SQLColumnsW(SQLHSTMT StatementHandle,
        _In_reads_opt_(NameLength1) SQLWCHAR *CatalogName, SQLSMALLINT NameLength1,
        _In_reads_opt_(NameLength2) SQLWCHAR *SchemaName, SQLSMALLINT NameLength2,
        _In_reads_opt_(NameLength3) SQLWCHAR *TableName, SQLSMALLINT NameLength3,
        _In_reads_opt_(NameLength4) SQLWCHAR *ColumnName, SQLSMALLINT NameLength4)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLConnectW(SQLHDBC ConnectionHandle,
        _In_reads_(NameLength1) SQLWCHAR *ServerName, SQLSMALLINT NameLength1,
        _In_reads_(NameLength2) SQLWCHAR *UserName, SQLSMALLINT NameLength2,
        _In_reads_(NameLength3) SQLWCHAR *Authentication, SQLSMALLINT NameLength3)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLCopyDesc(SQLHDESC SourceDescHandle,
        SQLHDESC TargetDescHandle)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLDescribeColW(SQLHSTMT StatementHandle,
        SQLUSMALLINT ColumnNumber, _Out_writes_opt_(BufferLength) SQLWCHAR *ColumnName,
        SQLSMALLINT BufferLength, _Out_opt_ SQLSMALLINT *NameLength,
        _Out_opt_ SQLSMALLINT *DataType, _Out_opt_ SQLULEN *ColumnSize,
        _Out_opt_ SQLSMALLINT *DecimalDigits, _Out_opt_ SQLSMALLINT *Nullable)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLDescribeParam(
        SQLHSTMT           hstmt,
        SQLUSMALLINT       ipar,
        _Out_opt_
        SQLSMALLINT       *pfSqlType,
        _Out_opt_
        SQLULEN           *pcbParamDef,
        _Out_opt_
        SQLSMALLINT       *pibScale,
        _Out_opt_
        SQLSMALLINT       *pfNullable)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLDisconnect(SQLHDBC ConnectionHandle)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLDriverConnectW(
        SQLHDBC            hdbc,
        SQLHWND            hwnd,
        _In_reads_(cchConnStrIn)
        SQLWCHAR           *szConnStrIn,
        SQLSMALLINT        cchConnStrIn,
        _Out_writes_opt_(cchConnStrOutMax)
        SQLWCHAR           *szConnStrOut,
        SQLSMALLINT        cchConnStrOutMax,
        _Out_opt_
        SQLSMALLINT       *pcchConnStrOut,
        SQLUSMALLINT       fDriverCompletion)
    {
        auto conn = static_cast<LPCONNECTION>(hdbc);
        auto strConn = ODBCString(szConnStrIn, cchConnStrIn);
        auto map = Connection::parseConnectionString(strConn);

        auto& session = conn->getSession();
        session.endpoint = map[L"ENDPOINT"];
        if (session.endpoint.empty()) {
            return SQL_ERROR;   // no endpoint
        }

        session.catalog = map[L"PRESTOCATALOG"];
        if (session.catalog.empty()) {
            return SQL_ERROR;   // no catalog
        }

        session.schema = map[L"PRESTOSCHEMA"];
        if (session.schema.empty()) {
            return SQL_ERROR;   // no schema
        }

        session.user = map[L"USERNAME"];

        if (!conn->connect()) {
            return SQL_ERROR;   // can't connect
        }

        if (szConnStrOut != NULL) {
            auto inlen = cchConnStrIn == SQL_NTS ?
                wcslen(szConnStrIn) : cchConnStrIn;
            auto len = min(cchConnStrOutMax, inlen);
            wcsncpy(szConnStrOut, szConnStrIn, len);
            szConnStrOut[len] = L'\0';
            *pcchConnStrOut = (SQLSMALLINT)len;
        }

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
    PRESTOODBC_API SQLRETURN SQL_API SQLForeignKeysW(
        SQLHSTMT           hstmt,
        _In_reads_opt_(cchPkCatalogName)
        SQLWCHAR           *szPkCatalogName,
        SQLSMALLINT        cchPkCatalogName,
        _In_reads_opt_(cchPkSchemaName)
        SQLWCHAR           *szPkSchemaName,
        SQLSMALLINT        cchPkSchemaName,
        _In_reads_opt_(cchPkTableName)
        SQLWCHAR           *szPkTableName,
        SQLSMALLINT        cchPkTableName,
        _In_reads_opt_(cchFkCatalogName)
        SQLWCHAR           *szFkCatalogName,
        SQLSMALLINT        cchFkCatalogName,
        _In_reads_opt_(cchFkSchemaName)
        SQLWCHAR           *szFkSchemaName,
        SQLSMALLINT        cchFkSchemaName,
        _In_reads_opt_(cchFkTableName)
        SQLWCHAR           *szFkTableName,
        SQLSMALLINT        cchFkTableName)
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
    PRESTOODBC_API SQLRETURN SQL_API SQLGetConnectAttrW(SQLHDBC ConnectionHandle,
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
        SQLSMALLINT RecNumber, _Out_writes_opt_(BufferLength) SQLWCHAR *Name,
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
        _Out_writes_opt_(6) SQLWCHAR *Sqlstate, SQLINTEGER *NativeError,
        _Out_writes_opt_(BufferLength) SQLWCHAR* MessageText,
        SQLSMALLINT BufferLength, _Out_opt_ SQLSMALLINT *TextLength)
    {
        return SQL_NO_DATA;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLGetEnvAttr(SQLHENV EnvironmentHandle,
        SQLINTEGER Attribute,
        _Out_writes_(_Inexpressible_(BufferLength)) SQLPOINTER Value,
        SQLINTEGER BufferLength, _Out_opt_ SQLINTEGER *StringLength)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLGetInfoW(SQLHDBC hdbc,
        SQLUSMALLINT fInfoType,
        _Out_writes_bytes_opt_(cbInfoValueMax) SQLPOINTER rgbInfoValue,
        SQLSMALLINT cbInfoValueMax,
        _Out_opt_ SQLSMALLINT* pcbInfoValue)
    {
        auto conn = static_cast<LPCONNECTION>(hdbc);

        switch (fInfoType) {
        case SQL_MAX_DRIVER_CONNECTIONS:
        case SQL_MAX_CONCURRENT_ACTIVITIES:
            *(SQLUSMALLINT*)rgbInfoValue = 1;
            break;
        case SQL_DATA_SOURCE_NAME:
            break;
        default:
            break;
        }
        return SQL_ERROR;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLGetStmtAttrW(SQLHSTMT StatementHandle,
        SQLINTEGER Attribute,
        _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER Value,
        SQLINTEGER BufferLength, _Out_opt_ SQLINTEGER *StringLength)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLGetTypeInfoW(SQLHSTMT StatementHandle,
        SQLSMALLINT DataType)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLMoreResults(SQLHSTMT hstmt)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLNativeSqlW(
        SQLHDBC            hdbc,
        _In_reads_(cchSqlStrIn) SQLWCHAR* szSqlStrIn,
        SQLINTEGER  cchSqlStrIn,
        _Out_writes_opt_(cchSqlStrMax) SQLWCHAR* szSqlStr,
        SQLINTEGER         cchSqlStrMax,
        SQLINTEGER        *pcbSqlStr
        )
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLNumParams(SQLHSTMT hstmt,
        _Out_opt_ SQLSMALLINT *pcpar)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN  SQL_API SQLNumResultCols(SQLHSTMT StatementHandle,
        _Out_ SQLSMALLINT *ColumnCount)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    SQLRETURN  SQL_API SQLParamData(SQLHSTMT StatementHandle,
        _Out_opt_ SQLPOINTER *Value)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLPrepareW(SQLHSTMT StatementHandle,
        _In_reads_(TextLength) SQLWCHAR* StatementText,
        SQLINTEGER TextLength)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLPrimaryKeysW(
        SQLHSTMT           hstmt,
        _In_reads_opt_(cchCatalogName)
        SQLWCHAR           *szCatalogName,
        SQLSMALLINT        cchCatalogName,
        _In_reads_opt_(cchSchemaName)
        SQLWCHAR           *szSchemaName,
        SQLSMALLINT        cchSchemaName,
        _In_reads_opt_(cchTableName)
        SQLWCHAR           *szTableName,
        SQLSMALLINT        cchTableName)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLProcedureColumnsW(
        SQLHSTMT           hstmt,
        _In_reads_opt_(cchCatalogName)
        SQLWCHAR           *szCatalogName,
        SQLSMALLINT        cchCatalogName,
        _In_reads_opt_(cchSchemaName)
        SQLWCHAR           *szSchemaName,
        SQLSMALLINT        cchSchemaName,
        _In_reads_opt_(cchProcName)
        SQLWCHAR           *szProcName,
        SQLSMALLINT        cchProcName,
        _In_reads_opt_(cchColumnName)
        SQLWCHAR           *szColumnName,
        SQLSMALLINT        cchColumnName)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLProceduresW(
        SQLHSTMT           hstmt,
        _In_reads_opt_(cchCatalogName)
        SQLWCHAR           *szCatalogName,
        SQLSMALLINT        cchCatalogName,
        _In_reads_opt_(cchSchemaName)
        SQLWCHAR           *szSchemaName,
        SQLSMALLINT        cchSchemaName,
        _In_reads_opt_(cchProcName)
        SQLWCHAR           *szProcName,
        SQLSMALLINT        cchProcName)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLPutData(SQLHSTMT StatementHandle,
        _In_reads_(_Inexpressible_(StrLen_or_Ind)) SQLPOINTER Data,
        SQLLEN StrLen_or_Ind)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN  SQL_API SQLRowCount(_In_ SQLHSTMT StatementHandle,
        _Out_ SQLLEN* RowCount)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLSetConnectAttrW(SQLHDBC ConnectionHandle,
        SQLINTEGER Attribute, _In_reads_bytes_opt_(StringLength) SQLPOINTER Value,
        SQLINTEGER StringLength)
    {
        auto conn = static_cast<LPCONNECTION>(ConnectionHandle);
        auto& session = conn->getSession();

        switch (Attribute) {
        case SQL_ATTR_LOGIN_TIMEOUT:
            session.timeout = reinterpret_cast<SQLLEN>(Value);
            break;
        default:
            break;
        }

        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLSetCursorNameW(SQLHSTMT StatementHandle,
        _In_reads_(NameLength) SQLWCHAR* CursorName, SQLSMALLINT NameLength)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLSetDescFieldW(SQLHDESC DescriptorHandle,
        SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,
        _In_reads_(_Inexpressible_(BufferLength)) SQLPOINTER Value,
        SQLINTEGER BufferLength)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLSetDescRec(SQLHDESC DescriptorHandle,
        SQLSMALLINT RecNumber, SQLSMALLINT Type,
        SQLSMALLINT SubType, SQLLEN Length,
        SQLSMALLINT Precision, SQLSMALLINT Scale,
        _Inout_updates_bytes_opt_(Length) SQLPOINTER Data,
        _Inout_opt_ SQLLEN *StringLength,
        _Inout_opt_ SQLLEN *Indicator)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLSetPos(
        SQLHSTMT           hstmt,
        SQLSETPOSIROW      irow,
        SQLUSMALLINT       fOption,
        SQLUSMALLINT       fLock)
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

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLSetStmtAttrW(SQLHSTMT StatementHandle,
        SQLINTEGER Attribute,
        _In_reads_(_Inexpressible_(StringLength)) SQLPOINTER Value,
        SQLINTEGER StringLength)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLSpecialColumnsW(SQLHSTMT StatementHandle,
        SQLUSMALLINT IdentifierType,
        _In_reads_opt_(NameLength1) SQLWCHAR *CatalogName, SQLSMALLINT NameLength1,
        _In_reads_opt_(NameLength2) SQLWCHAR *SchemaName, SQLSMALLINT NameLength2,
        _In_reads_opt_(NameLength3) SQLWCHAR *TableName, SQLSMALLINT NameLength3,
        SQLUSMALLINT Scope, SQLUSMALLINT Nullable)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLStatisticsW(SQLHSTMT StatementHandle,
        _In_reads_opt_(NameLength1) SQLWCHAR *CatalogName, SQLSMALLINT NameLength1,
        _In_reads_opt_(NameLength2) SQLWCHAR *SchemaName, SQLSMALLINT NameLength2,
        _In_reads_opt_(NameLength3) SQLWCHAR *TableName, SQLSMALLINT NameLength3,
        SQLUSMALLINT Unique, SQLUSMALLINT Reserved)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLTablePrivilegesW(
        SQLHSTMT           hstmt,
        _In_reads_opt_(cchCatalogName)
        SQLWCHAR           *szCatalogName,
        SQLSMALLINT        cchCatalogName,
        _In_reads_opt_(cchSchemaName)
        SQLWCHAR           *szSchemaName,
        SQLSMALLINT        cchSchemaName,
        _In_reads_opt_(cchTableName)
        SQLWCHAR           *szTableName,
        SQLSMALLINT        cchTableName)
    {
        return SQL_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    PRESTOODBC_API SQLRETURN SQL_API SQLTablesW(SQLHSTMT StatementHandle,
        _In_reads_opt_(NameLength1) SQLWCHAR *CatalogName, SQLSMALLINT NameLength1,
        _In_reads_opt_(NameLength2) SQLWCHAR *SchemaName, SQLSMALLINT NameLength2,
        _In_reads_opt_(NameLength3) SQLWCHAR *TableName, SQLSMALLINT NameLength3,
        _In_reads_opt_(NameLength4) SQLWCHAR *TableType, SQLSMALLINT NameLength4)
    {
        return SQL_SUCCESS;
    }
}
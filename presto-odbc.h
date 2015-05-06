// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PRESTOODBC_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PRESTOODBC_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef PRESTOODBC_EXPORTS
#define PRESTOODBC_API __declspec(dllexport)
#else
#define PRESTOODBC_API __declspec(dllimport)
#endif

extern "C" {
    PRESTOODBC_API SQLRETURN SQL_API SQLAllocHandle(SQLSMALLINT HandleType,
        SQLHANDLE InputHandle, _Out_ SQLHANDLE *OutputHandle);

    PRESTOODBC_API SQLRETURN SQL_API SQLBindCol(SQLHSTMT StatementHandle,
        SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
        _Inout_updates_opt_(_Inexpressible_(BufferLength)) SQLPOINTER TargetValue,
        SQLLEN BufferLength, _Inout_opt_ SQLLEN *StrLen_or_Ind);

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
        SQLLEN             *pcbValue);

    PRESTOODBC_API SQLRETURN SQL_API SQLBrowseConnectW(
        SQLHDBC            hdbc,
        _In_reads_(cchConnStrIn)
        SQLWCHAR           *szConnStrIn,
        SQLSMALLINT        cchConnStrIn,
        _Out_writes_opt_(cchConnStrOutMax)
        SQLWCHAR           *szConnStrOut,
        SQLSMALLINT        cchConnStrOutMax,
        _Out_opt_
        SQLSMALLINT       *pcchConnStrOut);

    PRESTOODBC_API SQLRETURN  SQL_API SQLBulkOperations(
        SQLHSTMT            StatementHandle,
        SQLSMALLINT         Operation);

    PRESTOODBC_API SQLRETURN  SQL_API SQLCancel(SQLHSTMT StatementHandle);

    PRESTOODBC_API SQLRETURN  SQL_API SQLCloseCursor(SQLHSTMT StatementHandle);

    PRESTOODBC_API SQLRETURN  SQL_API SQLColAttributeW(SQLHSTMT StatementHandle,
        SQLUSMALLINT ColumnNumber, SQLUSMALLINT FieldIdentifier,
        _Out_writes_bytes_opt_(BufferLength) SQLPOINTER CharacterAttribute, SQLSMALLINT BufferLength,
        _Out_opt_ SQLSMALLINT *StringLength, _Out_opt_ SQLLEN *NumericAttribute);

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
        SQLSMALLINT        cchColumnName);

    PRESTOODBC_API SQLRETURN SQL_API SQLDisconnect(SQLHDBC ConnectionHandle);

    PRESTOODBC_API SQLRETURN SQL_API SQLEndTran(SQLSMALLINT HandleType, SQLHANDLE Handle,
        SQLSMALLINT CompletionType);

    PRESTOODBC_API SQLRETURN SQL_API SQLExecDirectW(SQLHSTMT StatementHandle,
        _In_reads_opt_(TextLength) SQLWCHAR* StatementText,
        SQLINTEGER TextLength);

    PRESTOODBC_API SQLRETURN SQL_API SQLExecute(SQLHSTMT StatementHandle);

    PRESTOODBC_API SQLRETURN SQL_API SQLFetch(SQLHSTMT StatementHandle);

    PRESTOODBC_API SQLRETURN SQL_API SQLFetchScroll(SQLHSTMT StatementHandle,
        SQLSMALLINT FetchOrientation, SQLLEN FetchOffset);

    PRESTOODBC_API SQLRETURN SQL_API SQLFreeHandle(SQLSMALLINT HandleType, SQLHANDLE Handle);

    PRESTOODBC_API SQLRETURN SQL_API SQLFreeStmt(SQLHSTMT StatementHandle, SQLUSMALLINT Option);

    PRESTOODBC_API SQLRETURN SQL_API SQLGetConnectAttr(SQLHDBC ConnectionHandle,
        SQLINTEGER Attribute, _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER Value,
        SQLINTEGER BufferLength, _Out_opt_ SQLINTEGER *StringLengthPtr);

    PRESTOODBC_API SQLRETURN SQL_API SQLGetCursorNameW(
        SQLHSTMT StatementHandle,
        _Out_writes_opt_(BufferLength) SQLWCHAR *CursorName,
        SQLSMALLINT BufferLength,
        _Out_opt_
        SQLSMALLINT *NameLengthPtr);

    PRESTOODBC_API SQLRETURN SQL_API SQLGetData(SQLHSTMT StatementHandle,
        SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
        _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER TargetValue, SQLLEN BufferLength,
        _Out_opt_ SQLLEN *StrLen_or_IndPtr);

    PRESTOODBC_API SQLRETURN SQL_API SQLGetDescFieldW(SQLHDESC DescriptorHandle,
        SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,
        _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER Value, SQLINTEGER BufferLength,
        _Out_opt_ SQLINTEGER *StringLength);

    PRESTOODBC_API SQLRETURN SQL_API SQLGetDescRecW(SQLHDESC DescriptorHandle,
        SQLSMALLINT RecNumber, _Out_writes_opt_(BufferLength) SQLWCHAR *Name,
        SQLSMALLINT BufferLength, _Out_opt_ SQLSMALLINT *StringLengthPtr,
        _Out_opt_ SQLSMALLINT *TypePtr, _Out_opt_ SQLSMALLINT *SubTypePtr,
        _Out_opt_ SQLLEN     *LengthPtr, _Out_opt_ SQLSMALLINT *PrecisionPtr,
        _Out_opt_ SQLSMALLINT *ScalePtr, _Out_opt_ SQLSMALLINT *NullablePtr);

    PRESTOODBC_API SQLRETURN SQL_API SQLGetDiagFieldW(SQLSMALLINT HandleType, SQLHANDLE Handle,
        SQLSMALLINT RecNumber, SQLSMALLINT DiagIdentifier,
        _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER DiagInfo, SQLSMALLINT BufferLength,
        _Out_opt_ SQLSMALLINT *StringLength);

    PRESTOODBC_API SQLRETURN SQL_API SQLGetDiagRecW(SQLSMALLINT HandleType, SQLHANDLE Handle,
        SQLSMALLINT RecNumber, _Out_writes_opt_(6) SQLWCHAR *Sqlstate, SQLINTEGER *NativeError,
        _Out_writes_opt_(BufferLength) SQLWCHAR* MessageText, SQLSMALLINT BufferLength,
        _Out_opt_ SQLSMALLINT *TextLength);

    PRESTOODBC_API SQLRETURN SQL_API SQLGetEnvAttr(SQLHENV EnvironmentHandle,
        SQLINTEGER Attribute, _Out_writes_(_Inexpressible_(BufferLength)) SQLPOINTER Value,
        SQLINTEGER BufferLength, _Out_opt_ SQLINTEGER *StringLength);

    PRESTOODBC_API SQLRETURN SQL_API SQLGetStmtAttrW(SQLHSTMT StatementHandle,
        SQLINTEGER Attribute, _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER Value,
        SQLINTEGER BufferLength, _Out_opt_ SQLINTEGER *StringLength);

    PRESTOODBC_API SQLRETURN SQL_API SQLGetTypeInfoW(SQLHSTMT StatementHandle,
        SQLSMALLINT DataType);

    PRESTOODBC_API SQLRETURN SQL_API SQLMoreResults(SQLHSTMT hstmt);

    PRESTOODBC_API SQLRETURN SQL_API SQLNativeSqlW(
        SQLHDBC            hdbc,
        _In_reads_(cchSqlStrIn) SQLWCHAR* szSqlStrIn,
        SQLINTEGER  cchSqlStrIn,
        _Out_writes_opt_(cchSqlStrMax) SQLWCHAR* szSqlStr,
        SQLINTEGER         cchSqlStrMax,
        SQLINTEGER        *pcbSqlStr
        );

    PRESTOODBC_API SQLRETURN SQL_API SQLNumParams(
        SQLHSTMT           hstmt,
        _Out_opt_
        SQLSMALLINT       *pcpar);

    PRESTOODBC_API SQLRETURN  SQL_API SQLNumResultCols(SQLHSTMT StatementHandle,
        _Out_ SQLSMALLINT *ColumnCount);

    PRESTOODBC_API SQLRETURN SQL_API SQLParamData(SQLHSTMT StatementHandle,
        _Out_opt_ SQLPOINTER *Value);

    PRESTOODBC_API SQLRETURN SQL_API SQLPrepareW(SQLHSTMT StatementHandle,
        _In_reads_(TextLength) SQLWCHAR* StatementText,
        SQLINTEGER TextLength);

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
        SQLSMALLINT        cchTableName);

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
        SQLSMALLINT        cchColumnName);

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
        SQLSMALLINT        cchProcName);

    PRESTOODBC_API SQLRETURN SQL_API SQLPutData(SQLHSTMT StatementHandle,
        _In_reads_(_Inexpressible_(StrLen_or_Ind)) SQLPOINTER Data, SQLLEN StrLen_or_Ind);
    
    PRESTOODBC_API SQLRETURN  SQL_API SQLRowCount(_In_ SQLHSTMT StatementHandle,
        _Out_ SQLLEN* RowCount);

    PRESTOODBC_API SQLRETURN SQL_API SQLSetConnectAttrW(SQLHDBC ConnectionHandle,
        SQLINTEGER Attribute, _In_reads_bytes_opt_(StringLength) SQLPOINTER Value,
        SQLINTEGER StringLength);
    
    PRESTOODBC_API SQLRETURN SQL_API SQLSetCursorNameW(SQLHSTMT StatementHandle,
        _In_reads_(NameLength) SQLCHAR* CursorName, SQLSMALLINT NameLength);

    PRESTOODBC_API SQLRETURN SQL_API SQLSetDescRec(SQLHDESC DescriptorHandle,
        SQLSMALLINT RecNumber, SQLSMALLINT Type,
        SQLSMALLINT SubType, SQLLEN Length,
        SQLSMALLINT Precision, SQLSMALLINT Scale,
        _Inout_updates_bytes_opt_(Length) SQLPOINTER Data, _Inout_opt_ SQLLEN *StringLength,
        _Inout_opt_ SQLLEN *Indicator);

    PRESTOODBC_API SQLRETURN SQL_API SQLSetPos(
        SQLHSTMT           hstmt,
        SQLSETPOSIROW      irow,
        SQLUSMALLINT       fOption,
        SQLUSMALLINT       fLock);

    PRESTOODBC_API SQLRETURN SQL_API SQLSetEnvAttr(SQLHENV EnvironmentHandle,
        SQLINTEGER Attribute, _In_reads_bytes_opt_(StringLength) SQLPOINTER Value,
        SQLINTEGER StringLength);

    PRESTOODBC_API SQLRETURN SQL_API SQLSetStmtAttrW(SQLHSTMT StatementHandle,
        SQLINTEGER Attribute, _In_reads_(_Inexpressible_(StringLength)) SQLPOINTER Value,
        SQLINTEGER StringLength);

    PRESTOODBC_API SQLRETURN SQL_API SQLSpecialColumnsW(SQLHSTMT StatementHandle,
        SQLUSMALLINT IdentifierType,
        _In_reads_opt_(NameLength1) SQLWCHAR *CatalogName, SQLSMALLINT NameLength1,
        _In_reads_opt_(NameLength2) SQLWCHAR *SchemaName, SQLSMALLINT NameLength2,
        _In_reads_opt_(NameLength3) SQLWCHAR *TableName, SQLSMALLINT NameLength3,
        SQLUSMALLINT Scope, SQLUSMALLINT Nullable);

    PRESTOODBC_API SQLRETURN SQL_API SQLStatisticsW(SQLHSTMT StatementHandle,
        _In_reads_opt_(NameLength1) SQLWCHAR *CatalogName, SQLSMALLINT NameLength1,
        _In_reads_opt_(NameLength2) SQLWCHAR *SchemaName, SQLSMALLINT NameLength2,
        _In_reads_opt_(NameLength3) SQLWCHAR *TableName, SQLSMALLINT NameLength3,
        SQLUSMALLINT Unique, SQLUSMALLINT Reserved);

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
        SQLSMALLINT        cchTableName);

    PRESTOODBC_API SQLRETURN SQL_API SQLTablesW(SQLHSTMT StatementHandle,
        _In_reads_opt_(NameLength1) SQLWCHAR *CatalogName, SQLSMALLINT NameLength1,
        _In_reads_opt_(NameLength2) SQLWCHAR *SchemaName, SQLSMALLINT NameLength2,
        _In_reads_opt_(NameLength3) SQLWCHAR *TableName, SQLSMALLINT NameLength3,
        _In_reads_opt_(NameLength4) SQLWCHAR *TableType, SQLSMALLINT NameLength4);
}
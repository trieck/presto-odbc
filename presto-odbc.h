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
        SQLSMALLINT RecNumber, _Out_writes_opt_(BufferLength) SQLCHAR *Name,
        SQLSMALLINT BufferLength, _Out_opt_ SQLSMALLINT *StringLengthPtr,
        _Out_opt_ SQLSMALLINT *TypePtr, _Out_opt_ SQLSMALLINT *SubTypePtr,
        _Out_opt_ SQLLEN     *LengthPtr, _Out_opt_ SQLSMALLINT *PrecisionPtr,
        _Out_opt_ SQLSMALLINT *ScalePtr, _Out_opt_ SQLSMALLINT *NullablePtr);

    PRESTOODBC_API SQLRETURN SQL_API SQLGetDiagFieldW(SQLSMALLINT HandleType, SQLHANDLE Handle,
        SQLSMALLINT RecNumber, SQLSMALLINT DiagIdentifier,
        _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER DiagInfo, SQLSMALLINT BufferLength,
        _Out_opt_ SQLSMALLINT *StringLength);

    PRESTOODBC_API SQLRETURN SQL_API SQLGetDiagRecW(SQLSMALLINT HandleType, SQLHANDLE Handle,
        SQLSMALLINT RecNumber, _Out_writes_opt_(6) SQLCHAR *Sqlstate, SQLINTEGER *NativeError,
        _Out_writes_opt_(BufferLength) SQLCHAR* MessageText, SQLSMALLINT BufferLength,
        _Out_opt_ SQLSMALLINT *TextLength);

    PRESTOODBC_API SQLRETURN SQL_API SQLSetEnvAttr(SQLHENV EnvironmentHandle,
        SQLINTEGER Attribute, _In_reads_bytes_opt_(StringLength) SQLPOINTER Value,
        SQLINTEGER StringLength);
}
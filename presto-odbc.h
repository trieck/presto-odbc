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

    PRESTOODBC_API SQLRETURN SQL_API SQLBrowseConnect(
        SQLHDBC            hdbc,
        _In_reads_(cchConnStrIn)
        SQLCHAR           *szConnStrIn,
        SQLSMALLINT        cchConnStrIn,
        _Out_writes_opt_(cchConnStrOutMax)
        SQLCHAR           *szConnStrOut,
        SQLSMALLINT        cchConnStrOutMax,
        _Out_opt_
        SQLSMALLINT       *pcchConnStrOut);
}
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

// This class is exported from the presto-odbc.dll
class PRESTOODBC_API Cprestoodbc {
public:
	Cprestoodbc(void);
	// TODO: add your methods here.
};

extern PRESTOODBC_API int nprestoodbc;

PRESTOODBC_API int fnprestoodbc(void);

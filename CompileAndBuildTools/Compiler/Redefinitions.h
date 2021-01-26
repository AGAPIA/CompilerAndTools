// Redefinitions for compiling on UNIX
#ifndef REDEFINITIONS_H
#define REDEFINITIONS_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	#include <Windows.h>
	#include <direct.h>
#else
	#include <sys/stat.h>
	#include <unistd.h>
	#include "time.h"
#endif


// Windows.h typedef to coerce the code into compiling on non-windows platforms
#ifndef DWORD
#define WINAPI
typedef unsigned long DWORD;
typedef short WCHAR;
typedef void * HANDLE;
// typedef int32_t LONG;
// typedef int64_t LONGLONG;
// typedef union _LARGE_INTEGER {
//   struct {
//     DWORD LowPart;
//     LONG  HighPart;
//   };
//   struct {
//     DWORD LowPart;
//     LONG  HighPart;
//   } u;
//   LONGLONG QuadPart;
// } LARGE_INTEGER, *PLARGE_INTEGER;
#define MAX_PATH    PATH_MAX
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int BOOL;
#endif

#ifdef REDEF
#define _strdup strdup
#define fprintf_s fprintf
#define sprintf_s snprintf
// #define sprintf_s(buf, ...) snprintf((buf), sizeof(buf), __VA_ARGS__)
#define fopen_s(pFile,filename,mode) ((*(pFile))=fopen((filename),  (mode)))==NULL
#endif

#endif /* REDEFINITIONS_H */
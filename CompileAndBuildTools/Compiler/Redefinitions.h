// Redefinitions for compiling on UNIX
#ifndef REDEFINITIONS_H
#define REDEFINITIONS_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	#include <direct.h>
#else
	#include <sys/stat.h>
	#include <unistd.h>
	#include "time.h"
#endif

#ifdef REDEF
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

#include <assert.h>
static inline void portable_strcpy_s(char *dst, size_t dstlen, const char *src) {
	int charactersWritten = snprintf(dst, dstlen, "%s", src);
	// test for truncation (if the return value is >= dstlen, the output was truncated)
	assert(charactersWritten < dstlen);
}
#define strcpy_s portable_strcpy_s
// POSSIBLY UNSAFE
// #define strcpy_s(dst, dstlen, src) strncpy((dst), (src), (dstlen))
#define _fileno fileno
#define _strdup strdup
#define fprintf_s fprintf
#define sprintf_s snprintf
#include <errno.h>
// #define sprintf_s(buf, ...) snprintf((buf), sizeof(buf), __VA_ARGS__)
static inline int fopen_s(FILE **f, const char *name, const char *mode) {
    int ret = 0;
    assert(f);
    *f = fopen(name, mode);
    /* Can't be sure about 1-to-1 mapping of errno and MS' errno_t */
    if (!*f)
        ret = errno;
    return ret;
}
#endif

#endif /* REDEFINITIONS_H */
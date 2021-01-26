// Redefinitions for compiling on UNIX
#ifndef REDEFINITIONS_H
#define REDEFINITIONS_H

#ifdef REDEF
#define _strdup strdup
#define fprintf_s fprintf
#define sprintf_s snprintf
// #define sprintf_s(buf, ...) snprintf((buf), sizeof(buf), __VA_ARGS__)
#define fopen_s(pFile,filename,mode) ((*(pFile))=fopen((filename),  (mode)))==NULL
#endif

#endif /* REDEFINITIONS_H */
// Redefinitions for compiling on UNIX
#ifndef REDEFINITIONS_H
#define REDEFINITIONS_H

#ifdef REDEF
#define fprintf_s fprintf
#define sprintf_s(buf, size, ...) snprintf((buf), (size), __VA_ARGS__)
#define sprintf_s(buf, ...) snprintf((buf), sizeof(buf), __VA_ARGS__)
#define fopen_s(pFile,filename,mode) ((*(pFile))=fopen((filename),  (mode)))==NULL
#endif

#endif /* REDEFINITIONS_H */
#ifndef _SLWC_STDIO_H
#define _SLWC_STDIO_H

#include <stddef.h>

struct _IO_FILE;
typedef struct _IO_FILE FILE;

struct fpos;
typedef struct fpos fpos_t;

extern struct _IO_FILE * stdin;
extern struct _IO_FILE * stdout;
extern struct _IO_FILE * stderr;

#define EOF (-1)

#define SEEK_SET (0)
#define SEEK_CUR (1)
#define SEEK_END (2)

FILE * fopen(const char * path, const char * mode);

FILE * fdopen(int fd, const char * mode);

FILE * freopen(const char * path, const char * mode, FILE * fp);

int fclose(FILE * fp);

int fflush(FILE * fp);

int fseek(FILE * fp, long offset, int whence);

long ftell(FILE * fp);

void rewind(FILE * fp);

int fputc(int c, FILE * fp);

int fputs(const char * s, FILE * fp);

int putc(int c, FILE * fp);

int putchar(int c);

int puts(const char * s);

#endif // _SLWC_STDIO_H
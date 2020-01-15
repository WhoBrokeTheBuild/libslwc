#ifndef _SLWC_STDIO_H
#define _SLWC_STDIO_H

#include <stddef.h>

struct FILE;
typedef struct FILE FILE;

extern FILE * stdin;
extern FILE * stdout;
extern FILE * stderr;

int puts(const char * str);

#endif // _SLWC_STDIO_H
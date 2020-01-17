#include "file.h"

struct FILE _stdin = {
    .fd = 0,
};

struct FILE * stdin = &_stdin;

struct FILE _stdout = {
    .fd = 1,
};

struct FILE * stdout = &_stdout;

struct FILE _stderr = {
    .fd = 2,
};

struct FILE * stderr = &_stderr;


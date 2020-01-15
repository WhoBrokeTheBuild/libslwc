#include "file.h"

struct FILE _stdin = {
    .fd = 0,
};

struct FILE * stdin = &_stdin;

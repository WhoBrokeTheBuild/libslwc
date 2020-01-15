#include "file.h"

struct FILE _stdout = {
    .fd = 1,
};

struct FILE * stdout = &_stdout;

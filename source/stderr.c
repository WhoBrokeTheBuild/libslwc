#include "file.h"

struct FILE _stderr = {
    .fd = 2,
};

struct FILE * stderr = &_stderr;

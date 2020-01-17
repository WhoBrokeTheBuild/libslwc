#include <stdint.h>
#include "file.h"

int fclose(struct FILE * fp)
{
    __asm__(
        "mov $3, %%rax;"
        "mov %0, %%rdi;"
        "syscall;"
        : 
        : "r" ((uint64_t)fp->fd)
        : "rax", "rdi"
    );

    return 0;
}
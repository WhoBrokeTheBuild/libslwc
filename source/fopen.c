#include <stdio.h>
#include <stdint.h>
#include "file.h"

FILE tmp;

FILE * fopen(const char * filename, const char * mode)
{
    int flags = 0;
    int64_t fd;

    __asm__(
        "mov $2, %%rax;"
        "mov %0, %%rdi;"
        "mov %1, %%rsi;"
        "mov %2, %%rdx;"
        "syscall;"
        : "=r" (fd)
        : "r" (filename),               // %0
          "r" ((int64_t)flags),         // %1
          "r" ((int64_t)mode)           // %2
        : "rax", "rdi", "rsi", "rdx"
    );

    tmp.fd = fd;

    return &tmp;
}
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "file.h"

int puts(const char * str)
{
    size_t count;
    const char newline = '\n';

    count = strlen(str);

    __asm__(
        "mov $1, %%rax;"
        "mov %0, %%rdi;"
        "mov %1, %%rsi;"
        "mov %2, %%rdx;"
        "syscall;"
        : 
        : "r" ((uint64_t)stdin->fd), "r" (str), "r" (count)
        : "rax", "rdi", "rsi", "rdx"
    );

    __asm__(
        "mov $1, %%rax;"
        "mov %0, %%rdi;"
        "mov %1, %%rsi;"
        "mov $1, %%rdx;"
        "syscall;"
        : 
        : "r" ((uint64_t)stdin->fd), "r" (&newline)
        : "rax", "rdi", "rsi", "rdx"
    );

    return 0;
}
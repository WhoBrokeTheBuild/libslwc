#include <stdint.h>

void exit(int status)
{
    __asm__(
        "mov $60, %%rax;"
        "mov %0, %%rdi;"
        "syscall;"
        : 
        : "r" ((uint64_t)status)
        : "rax", "rdi"
    );
}
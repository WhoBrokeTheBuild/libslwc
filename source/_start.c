#include <stdint.h>
#include <stddef.h>

extern int main(int, char **);

void _start() {

    int result = main(0, NULL);

    __asm__(
        "mov $60, %%rax;"
        "mov %0, %%rdi;"
        "syscall;"
        : 
        : "r" ((uint64_t)result)
        : "rax", "rdi"
    );
}
#include <stdio.h>

int main(int argc, char ** argv)
{
    FILE * f = fopen("LICENSE", "rt");
    fclose(f);

    puts("Hello, World!\n");
    return *(int *)(f);
}
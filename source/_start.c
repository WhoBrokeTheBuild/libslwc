#include <stdlib.h>

extern int main(int, char **);

void _start() {
    exit(main(0, NULL));
}
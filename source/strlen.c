#include <string.h>

size_t strlen(const char * str)
{
    const char * pch;
    for (pch = str; *pch; ++pch) { }
    return (pch - str);
}

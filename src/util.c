#include "util.h"

// (log10(2 ** 32) + 1) + 1
static char buf[12];

char *itoa(uint32_t n) {
    char *c = buf + sizeof(buf) - 1;
    *c      = '\0';
    c--;
    *c = '\n';

    if (n == 0) {
        c--;
        *c = '0';
        return c;
    }

    while (n) {
        c--;
        *c = n % 10 + '0';
        n /= 10;
    }

    return c;
}

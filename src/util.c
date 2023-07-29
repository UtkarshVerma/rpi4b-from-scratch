#include "util.h"

void *memcpy(void *dest, const void *src, size_t n) {
    unsigned char *d = dest;
    while (n--) *d++ = *(unsigned char *)src++;

    return dest;
}

void *memset(void *blk, int c, size_t n) {
    unsigned char *dst = blk;
    while (n--) *dst++ = (unsigned char)c;

    return blk;
}

#pragma once

#include <stddef.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void* memcpy(void* dest, const void* src, size_t n);
void* memset(void* blk, int c, size_t n);

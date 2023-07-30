#pragma once

#include <stddef.h>
#include <stdint.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void* memcpy(void* dest, const void* src, size_t n);
void* memset(void* blk, int c, size_t n);
char* itoa(uint32_t n);

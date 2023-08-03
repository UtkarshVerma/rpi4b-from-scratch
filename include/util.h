#pragma once

#include <stdint.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

char* itoa(uint32_t n);

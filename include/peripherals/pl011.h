#pragma once

#include "mem.h"

typedef struct {
    mem_ptr base_addr;
    unsigned int clock;
    unsigned int baudrate;
} pl011_context;

void pl011_init(const pl011_context* context);
void pl011_write(const pl011_context* context, const char* buffer);

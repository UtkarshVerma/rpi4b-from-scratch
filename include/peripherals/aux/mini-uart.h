#pragma once

#include "mem.h"

typedef struct {
    mem_ptr base_addr;
    unsigned int clock;
    unsigned int baudrate;
} mini_uart_context;

void mini_uart_init(const mini_uart_context* context);
void mini_uart_write(const mini_uart_context* context, const char* buffer);

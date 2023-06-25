#pragma once

#include "memory.h"

#define PL011_BASE_ADDR (MMIO_BASE_ADDR + 0x201000)

#define PL011_UART0_BASE_ADDR (PL011_BASE_ADDR + 0x000)
#define PL011_UART2_BASE_ADDR (PL011_BASE_ADDR + 0x400)
#define PL011_UART3_BASE_ADDR (PL011_BASE_ADDR + 0x600)
#define PL011_UART4_BASE_ADDR (PL011_BASE_ADDR + 0x800)
#define PL011_UART5_BASE_ADDR (PL011_BASE_ADDR + 0xA00)

void pl011_init(mem_addr base);
void pl011_write(mem_addr base, char* buffer);

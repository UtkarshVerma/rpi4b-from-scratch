#pragma once
#include <stdint.h>

#define MEM_REG(address) (*(mem_reg*)(address))

typedef volatile uint32_t mem_reg;

/*
 * NOTE:
 * Raspberry Pi 4B boots into low peripheral mode by default.
 * The addresses are specified in the BCM2711 peripherals datashseet in Fig 1.
 */

// Peripherals ----------------------------------------------------------------
#define MEM_PERIPHERAL_BASE 0xfc000000LL
#define MEM_PERIPHERAL_SIZE 0x3800000

// GPIO
#define MEM_GPIO_BASE (MEM_PERIPHERAL_BASE + 0x2200000)
#define MEM_GPIO_SIZE 0xf4

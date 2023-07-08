#pragma once
#include <stdint.h>

#define MEM_REG(address) (*(mem_reg*)(address))

typedef volatile uint32_t mem_reg;
typedef uintptr_t mem_ptr;

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

// AUX
#define MEM_AUX_BASE (MEM_PERIPHERAL_BASE + 0x2215000)
#define MEM_AUX_SIZE 0x100

// AUX: Mini UART
#define MEM_AUX_MU_BASE (MEM_AUX_BASE + 0x40)
#define MEM_AUX_MU_SIZE 0x40

#define MEM_UART1_BASE MEM_AUX_MU_BASE

// PL011 UARTs
#define MEM_PL011_BASE (MEM_PERIPHERAL_BASE + 0x2201000)
#define MEM_PL011_SIZE 0x200

#define MEM_UART0_BASE (MEM_PL011_BASE + 0x000)
#define MEM_UART2_BASE (MEM_PL011_BASE + 0x400)
#define MEM_UART3_BASE (MEM_PL011_BASE + 0x600)
#define MEM_UART4_BASE (MEM_PL011_BASE + 0x800)
#define MEM_UART5_BASE (MEM_PL011_BASE + 0xA00)

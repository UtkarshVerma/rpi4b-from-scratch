#pragma once

#define MEM_REG_VALUE(address) (*(volatile unsigned int*)(address))

#define MMIO_BASE_ADDR 0xfe000000
#define MMIO_REG_ADDR(peripheral, offset) \
    (MMIO_BASE_ADDR + MMIO_##peripheral##_BASE_OFFSET + offset)

#define MMIO_GPIO_BASE_OFFSET 0x200000

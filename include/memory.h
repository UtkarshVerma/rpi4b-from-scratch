#pragma once

typedef unsigned int mem_data;
typedef volatile mem_data* mem_ptr;

#define MEM_REG(address) (*(mem_ptr)(address))
#define MMIO_REG_ADDR(peripheral, offset) \
    (MMIO_BASE_ADDR + MMIO_##peripheral##_BASE_OFFSET + offset)
#define MMIO_REG(peripheral, offset) MEM_REG(MMIO_REG_ADDR(peripheral, offset))

#define MMIO_BASE_ADDR        0xfe000000
#define MMIO_GPIO_BASE_OFFSET 0x200000
#define MMIO_AUX_BASE_OFFSET  0x215000

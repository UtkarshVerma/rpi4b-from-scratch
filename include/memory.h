#pragma once

typedef unsigned long mem_addr;
typedef unsigned int mem_reg;
typedef volatile mem_reg* mem_ptr;

#define MEM_REG(base, offset) (*(mem_ptr)(base + offset))

#define MMIO_BASE_ADDR 0xfe000000

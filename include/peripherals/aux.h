#pragma once

#include "memory.h"

#define AUX_BASE_ADDR (MMIO_BASE_ADDR + 0x215000)
#define AUX_ENABLES   MEM_REG(AUX_BASE_ADDR, 0x04)

#pragma once

#include "mem.h"

#define AUX_ENABLES           MEM_REG(MEM_AUX_BASE + 0x04)
#define AUX_ENABLES_MINI_UART (1 << 0)
#define AUX_ENABLES_SPI1      (1 << 1)
#define AUX_ENABLES_SPI2      (1 << 2)

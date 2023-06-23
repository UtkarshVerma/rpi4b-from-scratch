#pragma once

#include "memory.h"

#define AUX_ENABLES MMIO_REG(AUX, 0x04)

void aux_init();

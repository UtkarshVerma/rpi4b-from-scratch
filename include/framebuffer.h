#pragma once

#include <stdint.h>

int frambuffer_init(unsigned int width, unsigned int height,
                    unsigned int depth);

void framebuffer_draw_pixel(unsigned int x, unsigned int y, uint32_t);

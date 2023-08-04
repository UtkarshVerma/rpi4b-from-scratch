#include "main.h"

#include "framebuffer.h"
#include "uart.h"
#include "util.h"

void main(void) {
    int i = frambuffer_init(100, 100, 32);
    uart_write(CONSOLE_UART, "---\n");
    uart_write(CONSOLE_UART, itoa(i));

    for (unsigned int x = 0; x < 100; x++)
        for (unsigned int y = 0; y < 100; y++)
            framebuffer_draw_pixel(x, y, 0xffffffff);

    uart_write(CONSOLE_UART, "Done\n");
}

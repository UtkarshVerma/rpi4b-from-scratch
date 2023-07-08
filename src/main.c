#include "uart.h"

#define CONSOLE_UART UART1

// Bust wait delay
void delay() {
    volatile int i = 0;
    while (i < 0xf0000) i++;
}

void main() {
    uart_init(CONSOLE_UART, 115200);

    while (1) {
        uart_write(CONSOLE_UART, "Hello, world!\n");
        delay();
    }
}

#include "uart.h"

#define LED_GPIO 17

// Bust wait delay
void delay() {
    volatile int i = 0;
    while (i < 0xf0000) i++;
}

void main() {
    uart_init(UART0);

    while (1) {
        uart_write(UART0, "Hello, world from UART0!\n");
        delay();
    }
}

#include "main.h"

#include "aux/mini_uart.h"

void main() {
    mini_uart_init();
    mini_uart_write("Hello, world!\n");
}

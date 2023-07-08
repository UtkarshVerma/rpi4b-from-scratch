#pragma once

typedef enum {
    UART0,
    UART1,
    UART2,
    UART3,
    UART4,
    UART5,

    UART_COUNT,
} uart_port;

void uart_init(uart_port port, unsigned int baudrate);
void uart_write(uart_port port, const char* buffer);

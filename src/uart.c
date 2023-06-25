#include "uart.h"

#include "peripherals/aux/mini_uart.h"
#include "peripherals/gpio.h"
#include "peripherals/pl011.h"

typedef struct {
    unsigned int tx_pin;
    unsigned int rx_pin;

    gpio_function alt_func;
    mem_addr base_addr;
} uart_config;

static const uart_config configs[] = {
    [UART0] = {14, 15, GPIO_AF0, PL011_UART0_BASE_ADDR},
    [UART1] = {14, 15, GPIO_AF5, -1                   },
    [UART2] = {0,  1,  GPIO_AF4, PL011_UART2_BASE_ADDR},
    [UART3] = {4,  5,  GPIO_AF4, PL011_UART3_BASE_ADDR},
    [UART4] = {8,  9,  GPIO_AF4, PL011_UART4_BASE_ADDR},
    [UART5] = {12, 13, GPIO_AF4, PL011_UART5_BASE_ADDR},
};

void uart_init(uart_port port) {
    const uart_config config = configs[port];
    gpio_set_function(config.tx_pin, config.alt_func);
    gpio_set_function(config.rx_pin, config.alt_func);
    gpio_set_pull(config.tx_pin, GPIO_PULL_NONE);
    gpio_set_pull(config.rx_pin, GPIO_PULL_NONE);

    switch (port) {
        case UART1:
            mini_uart_init();
            break;
        case UART0:
        case UART2:
        case UART3:
        case UART4:
        case UART5:
            pl011_init(config.base_addr);
            break;
    }
}

void uart_write(uart_port port, char* buffer) {
    const uart_config config = configs[port];

    switch (port) {
        case UART1:
            mini_uart_write(buffer);
            break;
        case UART0:
        case UART2:
        case UART3:
        case UART4:
        case UART5:
            pl011_write(config.base_addr, buffer);
            break;
    }
}

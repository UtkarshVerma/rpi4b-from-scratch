#include "uart.h"

#include "main.h"
#include "mem.h"
#include "peripherals/aux.h"
#include "peripherals/aux/mini-uart.h"
#include "peripherals/gpio.h"
#include "peripherals/pl011.h"

typedef struct {
    mem_ptr base_addr;
    unsigned int clock;
    unsigned int baudrate;
} uart_context;

typedef struct {
    unsigned int tx_pin;
    unsigned int rx_pin;
    gpio_function gpio_func;

    uart_context *context;
} uart_config;

static uart_context uart0 = {
    .base_addr = MEM_UART0_BASE,
    .clock     = UART_CLOCK_FREQ,
    .baudrate  = -1,
};
static uart_context uart1 = {MEM_UART1_BASE, SYSTEM_CLOCK_FREQ, -1};
static uart_context uart2 = {MEM_UART2_BASE, UART_CLOCK_FREQ, -1};
static uart_context uart3 = {MEM_UART3_BASE, UART_CLOCK_FREQ, -1};
static uart_context uart4 = {MEM_UART4_BASE, UART_CLOCK_FREQ, -1};
static uart_context uart5 = {MEM_UART5_BASE, UART_CLOCK_FREQ, -1};

static const uart_config configs[UART_COUNT] = {
    [UART0] = {14, 15, GPIO_AF0, &uart0},
    [UART1] = {14, 15, GPIO_AF5, &uart1},
    [UART2] = {0,  1,  GPIO_AF4, &uart2},
    [UART3] = {4,  5,  GPIO_AF4, &uart3},
    [UART4] = {8,  9,  GPIO_AF4, &uart4},
    [UART5] = {12, 13, GPIO_AF4, &uart5}
};

void uart_init(uart_port port, unsigned int baudrate) {
    const uart_config *config = &configs[port];
    gpio_set_function(config->tx_pin, config->gpio_func);
    gpio_set_function(config->rx_pin, config->gpio_func);
    gpio_set_pull(config->tx_pin, GPIO_PULL_NONE);
    gpio_set_pull(config->rx_pin, GPIO_PULL_NONE);

    config->context->baudrate = baudrate;

    if (port == UART1) {
        AUX_ENABLES |= AUX_ENABLES_MINI_UART;
        mini_uart_init((mini_uart_context *)configs[port].context);
        return;
    }

    pl011_init((pl011_context *)configs[port].context);
}

void uart_write(uart_port port, const char *buffer) {
    if (port == UART1) {
        mini_uart_write((mini_uart_context *)configs[port].context, buffer);
        return;
    }

    pl011_write((pl011_context *)configs[port].context, buffer);
}

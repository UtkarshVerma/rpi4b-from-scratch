#include "aux/mini_uart.h"

#include "aux/main.h"
#include "gpio.h"
#include "main.h"
#include "util.h"

#define TX_PIN 14
#define RX_PIN 15

#define AUX_MU_IO_REG   MMIO_REG(AUX, 0x40)
#define AUX_MU_IER_REG  MMIO_REG(AUX, 0x44)
#define AUX_MU_IIR_REG  MMIO_REG(AUX, 0x48)
#define AUX_MU_LCR_REG  MMIO_REG(AUX, 0x4c)
#define AUX_MU_MCR_REG  MMIO_REG(AUX, 0x50)
#define AUX_MU_LSR_REG  MMIO_REG(AUX, 0x54)
#define AUX_MU_CNTL_REG MMIO_REG(AUX, 0x60)
#define AUX_MU_BAUD_REG MMIO_REG(AUX, 0x68)

static unsigned int mini_uart_is_ready() {
    return AUX_MU_LSR_REG & (1 << 6);
}

static void mini_uart_write_byte(unsigned char byte) {
    while (!mini_uart_is_ready())
        ;

    AUX_MU_IO_REG = byte;
}

void mini_uart_init() {
    aux_init();

    AUX_MU_IER_REG  = 0b00;  // Disable interrupts for RX/TX
    AUX_MU_CNTL_REG = 0b00;  // Disable RX/TX

    AUX_MU_LCR_REG  = 0b11;  // Use 8-bit mode
    AUX_MU_MCR_REG  = 0;     // Assert RTS HIGH
    AUX_MU_BAUD_REG = SYSTEM_CLOCK_FREQ / (UART_BAUDRATE * 8) - 1;

    const unsigned int pins[] = {TX_PIN, RX_PIN};
    for (unsigned int i = 0; i < LEN(pins); i++) {
        gpio_set_pull(pins[i], GPIO_PULL_NONE);
        gpio_set_function(pins[i], GPIO_AF5);
    }

    AUX_MU_CNTL_REG = 0b11;  // Enable RX/TX
}

void mini_uart_write(char *buffer) {
    while (*buffer) {
        if (*buffer == '\n') mini_uart_write_byte('\r');
        mini_uart_write_byte(*buffer++);
    }
}

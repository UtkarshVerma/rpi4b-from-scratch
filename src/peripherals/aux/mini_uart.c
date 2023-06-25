#include "peripherals/aux/mini_uart.h"

#include "main.h"
#include "peripherals/aux.h"

#define AUX_MU_IO_REG   MEM_REG(AUX_BASE_ADDR, 0x40)
#define AUX_MU_IER_REG  MEM_REG(AUX_BASE_ADDR, 0x44)
#define AUX_MU_IIR_REG  MEM_REG(AUX_BASE_ADDR, 0x48)
#define AUX_MU_LCR_REG  MEM_REG(AUX_BASE_ADDR, 0x4c)
#define AUX_MU_MCR_REG  MEM_REG(AUX_BASE_ADDR, 0x50)
#define AUX_MU_LSR_REG  MEM_REG(AUX_BASE_ADDR, 0x54)
#define AUX_MU_CNTL_REG MEM_REG(AUX_BASE_ADDR, 0x60)
#define AUX_MU_BAUD_REG MEM_REG(AUX_BASE_ADDR, 0x68)

static void mini_uart_write_byte(unsigned char byte) {
    // Wait until TXFIFO is empty
    while (!(AUX_MU_LSR_REG & (1 << 6)))
        ;

    AUX_MU_IO_REG = byte;
}

void mini_uart_init() {
    AUX_ENABLES |= 0b1;  // Enable Mini UART

    AUX_MU_IER_REG  = 0b00;  // Disable interrupts for RX/TX
    AUX_MU_CNTL_REG = 0b00;  // Disable RX/TX

    AUX_MU_LCR_REG  = 0b11;  // Use 8-N-1 mode
    AUX_MU_MCR_REG  = 0;     // Assert RTS HIGH
    AUX_MU_BAUD_REG = SYSTEM_CLOCK_FREQ / (UART_BAUDRATE * 8) - 1;

    AUX_MU_CNTL_REG = 0b11;  // Enable RX/TX
}

void mini_uart_write(char *buffer) {
    while (*buffer) {
        if (*buffer == '\n') mini_uart_write_byte('\r');
        mini_uart_write_byte(*buffer);

        buffer++;
    }
}

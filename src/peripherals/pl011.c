#include "peripherals/pl011.h"

#include "main.h"

#define DR(base)   MEM_REG(base, 0x00)
#define FR(base)   MEM_REG(base, 0x18)
#define IBRD(base) MEM_REG(base, 0x24)
#define FBRD(base) MEM_REG(base, 0x28)
#define LCRH(base) MEM_REG(base, 0x2c)
#define CR(base)   MEM_REG(base, 0x30)
#define ICR(base)  MEM_REG(base, 0x44)

#define FR_BUSY   (1 << 3)
#define FR_TXFF   (1 << 5)
#define LCRH_FEN  (1 << 4)
#define CR_UARTEN (1 << 0)
#define CR_TXE    (1 << 8)
#define CR_RXE    (1 << 9)

#define LCRH_WLEN_8BITS (0b11 << 5)

static void pl011_write_byte(mem_addr base, unsigned char byte) {
    // Wait until the TX register is empy
    while (FR(base) & FR_TXFF)
        ;

    DR(base) = byte;
}

void pl011_init(mem_addr base) {
    unsigned int bauddiv = (UART_CLOCK_FREQ * 1000) / (UART_BAUDRATE * 16);
    unsigned int ibrd    = bauddiv / 1000;

    CR(base) &= ~CR_UARTEN;  // Disable UART

    // Wait for pending transactions, then flush the FIFOs
    while (FR(base) & FR_BUSY)
        ;
    LCRH(base) &= ~LCRH_FEN;

    // Set baudrate
    IBRD(base) = ibrd;
    FBRD(base) = ((bauddiv - ibrd * 1000) * 64 + 500) / 1000;

    LCRH(base) = LCRH_WLEN_8BITS;              // Use 8-N-1 mode, without FIFO
    CR(base)   = CR_UARTEN | CR_TXE | CR_RXE;  // Enable UART and RX/TX
}

void pl011_write(mem_addr base, char* buffer) {
    while (*buffer) {
        if (*buffer == '\n') pl011_write_byte(base, '\r');
        pl011_write_byte(base, *buffer);

        buffer++;
    }
}

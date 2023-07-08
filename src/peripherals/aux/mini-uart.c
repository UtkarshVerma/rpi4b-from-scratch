#include "peripherals/aux/mini-uart.h"

#include "mem.h"

#define IO_REG             MEM_REG(base + 0x00)
#define IO_REG_DATA_MASK   0xff
#define IER_REG            MEM_REG(base + 0x04)
#define IER_REG_TXE        (1 << 0)
#define IER_REG_RXE        (1 << 1)
#define IIR_REG            MEM_REG(base + 0x08)
#define LCR_REG            MEM_REG(base + 0x0c)
#define LCR_REG_WLEN_8     (1 << 0)
#define MCR_REG            MEM_REG(base + 0x10)
#define MCR_REG_RTS_LOW    (1 << 1)
#define LSR_REG            MEM_REG(base + 0x14)
#define LSR_REG_DATA_READY (1 << 0)
#define LSR_REG_TXIDLE     (1 << 6)
#define CNTL_REG           MEM_REG(base + 0x20)
#define CNTL_REG_TXE       (1 << 0)
#define CNTL_REG_RXE       (1 << 1)
#define BAUD_REG           MEM_REG(base + 0x28)

static void mini_uart_write_byte(const mini_uart_context* context,
                                 unsigned char byte) {
    const mem_ptr base = context->base_addr;

    // Wait until TXFIFO is empty
    while (!(LSR_REG & LSR_REG_TXIDLE))
        ;

    IO_REG = byte;
}

void mini_uart_init(const mini_uart_context* context) {
    const mem_ptr base = context->base_addr;

    // Disable RX/TX
    IER_REG &= ~(IER_REG_RXE | IER_REG_TXE);
    CNTL_REG &= ~(CNTL_REG_RXE | CNTL_REG_TXE);

    // Use 8-bit mode and assert RTS high
    LCR_REG |= LCR_REG_WLEN_8;
    MCR_REG &= ~MCR_REG_RTS_LOW;

    // Set the baudrate
    BAUD_REG = context->clock / (context->baudrate * 8) - 1;

    // Re-enable RX/TX, without interrupts
    CNTL_REG |= CNTL_REG_TXE | CNTL_REG_RXE;
}

void mini_uart_write(const mini_uart_context* context, const char* buffer) {
    while (*buffer) {
        if (*buffer == '\n') mini_uart_write_byte(context, '\r');
        mini_uart_write_byte(context, *buffer);

        buffer++;
    }
}

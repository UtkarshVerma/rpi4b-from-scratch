#include "peripherals/pl011.h"

#include <stdint.h>

#include "mem.h"

// From BCM2711 peripherals datasheet, section 11.5
#define DR              MEM_REG(base + 0x00)
#define DR_DATA_MASK    ((1 << 8) - 1)
#define FR              MEM_REG(base + 0x18)
#define FR_BUSY         (1 << 3)
#define FR_RXFE         (1 << 4)
#define FR_TXFF         (1 << 5)
#define IBRD            MEM_REG(base + 0x24)
#define FBRD            MEM_REG(base + 0x28)
#define LCRH            MEM_REG(base + 0x2c)
#define LCRH_FEN        (1 << 4)
#define LCRH_WLEN_8BITS (0b11 << 5)
#define CR              MEM_REG(base + 0x30)
#define CR_UARTEN       (1 << 0)
#define CR_TXE          (1 << 8)
#define CR_RXE          (1 << 9)
#define ICR             MEM_REG(base + 0x44)

static void pl011_write_byte(const pl011_context* context,
                             unsigned char byte) {
    const mem_ptr base = context->base_addr;

    // Wait until TX FIFO is empty
    while (FR & FR_TXFF)
        ;

    DR = byte;
}

void pl011_init(const pl011_context* context) {
    const mem_ptr base = context->base_addr;

    // Disable UART
    CR &= ~(CR_UARTEN | CR_TXE | CR_RXE);

    // Wait for pending transactions, then flush the FIFOs
    while (FR & FR_BUSY)
        ;
    LCRH &= ~LCRH_FEN;

    // Calculation documeneted ARM's technical reference manual for PL011
    const uint32_t scalar = 1e5;  // 5-digit decimal precision
    uint64_t bauddiv =
        ((uint64_t)context->clock * scalar) / (context->baudrate * 16);
    uint32_t ibrd = bauddiv / scalar;

    // Set the baudrate
    IBRD = ibrd;
    FBRD = ((bauddiv - (uint64_t)ibrd * scalar) * 64 + scalar / 2) / scalar;

    // Use 8-bit mode
    LCRH |= LCRH_WLEN_8BITS;

    // Re-enable UART
    CR |= CR_UARTEN | CR_TXE | CR_RXE;
}

void pl011_write(const pl011_context* context, const char* buffer) {
    while (*buffer) {
        if (*buffer == '\n')
            pl011_write_byte(context, '\r');
        pl011_write_byte(context, *buffer);

        buffer++;
    }
}

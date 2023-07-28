#include <stdint.h>

#include "peripherals/mbox.h"
#include "peripherals/mbox/property/message.h"
#include "peripherals/mbox/property/tags.h"
#include "uart.h"

#define CONSOLE_UART UART1

// Bust wait delay
void delay() {
    volatile int i = 0;
    while (i < 0xf0000) i++;
}

static char buf[100];

char* itoa(uint32_t n) {
    char* c = buf + sizeof(buf) - 1;
    *c      = '\0';
    c--;
    *c = '\n';

    if (n == 0) {
        c--;
        *c = '0';
        return c;
    }

    while (n) {
        c--;
        *c = n % 10 + '0';
        n /= 10;
    }

    return c;
}

void main() {
    uart_init(CONSOLE_UART, 115200);

    mbox_property_message_init(HARDWARE_GET_BOARD_REVISION);
    mbox_property_message_buffer* buffer =
        mbox_property_message_get_buffer_pointer();

    for (unsigned int i = 0; i < 7; i++) {
        uart_write(CONSOLE_UART, itoa(((uint32_t*)buffer)[i]));
    }

    uart_write(CONSOLE_UART, "Hello, world!\n");
    mbox_write(PROPERTY_TAGS_ARM_TO_VC, (uintptr_t)buffer);
    (void)mbox_read(PROPERTY_TAGS_ARM_TO_VC);

    for (unsigned int i = 0; i < 7; i++) {
        uart_write(CONSOLE_UART, itoa(((uint32_t*)buffer)[i]));
    }

    uint32_t revision =
        buffer->tag.buffer.hardware_get_board_revision.response.board_revision;
    uart_write(CONSOLE_UART, itoa(revision));
}

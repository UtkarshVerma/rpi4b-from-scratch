#include "main.h"

#include <stdint.h>

#include "peripherals/mbox.h"
#include "peripherals/mbox/property/message.h"
#include "peripherals/mbox/property/tags.h"
#include "uart.h"
#include "util.h"

static MBOX_PROPERTY_MESSAGE_BUFFER(buffer, 100);

void main() {
    uart_init(CONSOLE_UART, 115200);

    MBOX_PROPERTY_MESSAGE_BUFFER_LAYOUT(
        hardware_get_board_revision_tag a; hardware_get_board_revision_tag c;
        hardware_get_board_revision_tag d;
        hardware_get_board_revision_tag b;)* mbox_buffer = (void*)buffer;
    mbox_buffer->a.header.id = HARDWARE_GET_BOARD_REVISION;
    mbox_buffer->b.header.id = HARDWARE_GET_BOARD_REVISION;
    mbox_buffer->c.header.id = HARDWARE_GET_BOARD_REVISION;
    mbox_buffer->d.header.id = HARDWARE_GET_BOARD_REVISION;

    uart_write(CONSOLE_UART, ">---\n");
    for (unsigned int i = 0; i < sizeof(*mbox_buffer) / sizeof(buffer[0]);
         i++) {
        uart_write(CONSOLE_UART, itoa(buffer[i]));
    }
    uart_write(CONSOLE_UART, "---<\n");

    mbox_property_message_init(mbox_buffer, sizeof(*mbox_buffer));

    uart_write(CONSOLE_UART, ">---\n");
    for (unsigned int i = 0; i < sizeof(*mbox_buffer) / sizeof(buffer[0]);
         i++) {
        uart_write(CONSOLE_UART, itoa(buffer[i]));
    }
    uart_write(CONSOLE_UART, "---<\n");

    mbox_write(PROPERTY_TAGS_ARM_TO_VC, mbox_buffer);
    (void)mbox_read(PROPERTY_TAGS_ARM_TO_VC);

    uart_write(CONSOLE_UART, ">---\n");
    for (unsigned int i = 0; i < sizeof(*mbox_buffer) / sizeof(buffer[0]);
         i++) {
        uart_write(CONSOLE_UART, itoa(buffer[i]));
    }
    uart_write(CONSOLE_UART, "---<\n");
}

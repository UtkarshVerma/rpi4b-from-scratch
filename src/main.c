#include <stdint.h>

#include "peripherals/mbox.h"
#include "peripherals/mbox/property/message.h"
#include "peripherals/mbox/property/tags/hardware.h"
#include "uart.h"

#define CONSOLE_UART UART1

// Bust wait delay
void delay() {
    volatile int i = 0;
    while (i < 0xf0000) i++;
}

void main() {
    uart_init(CONSOLE_UART, 115200);

    mbox_property_message_init(HARDWARE_GET_BOARD_MODEL);
    mbox_property_message_buffer* buffer =
        mbox_property_message_get_buffer_pointer();
    mbox_write(PROPERTY_TAGS_ARM_TO_VC, (uintptr_t)buffer);
    (void)mbox_read(PROPERTY_TAGS_ARM_TO_VC);

    while (1) {
        uart_write(CONSOLE_UART, "Hello, world!\n");
        delay();
    }
}

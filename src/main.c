#include "main.h"

#include "peripherals/mbox.h"
#include "peripherals/mbox/property/message.h"
#include "peripherals/mbox/property/tags.h"
#include "peripherals/mbox/property/tags/hardware.h"
#include "uart.h"
#include "util.h"

static MBOX_PROPERTY_MESSAGE_BUFFER(buffer, 30);

void main(void) {
    uart_init(CONSOLE_UART, 115200);

#define TAGS(X, ...) X(HARDWARE_GET_CLOCKS_TAG, a, __VA_ARGS__)
    MBOX_PROPERTY_MESSAGE_BUFFER_INIT(mbox_buffer, TAGS, buffer);

    mbox_write(PROPERTY_TAGS_ARM_TO_VC, mbox_buffer);
    (void)mbox_read(PROPERTY_TAGS_ARM_TO_VC);

    for (unsigned int i = 0;
         i < ARRAY_SIZE(MBOX_PROPERTY_TAG_RESPONSE(mbox_buffer, a).clocks);
         i++)
        uart_write(
            CONSOLE_UART,
            itoa(MBOX_PROPERTY_TAG_RESPONSE(mbox_buffer, a).clocks[i].id));
}

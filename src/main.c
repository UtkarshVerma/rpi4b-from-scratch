#include "main.h"

#include <stdint.h>

#include "peripherals/mbox.h"
#include "peripherals/mbox/property/message.h"
#include "peripherals/mbox/property/tags.h"
#include "peripherals/mbox/property/tags/framebuffer.h"
#include "uart.h"
#include "util.h"

static MBOX_PROPERTY_MESSAGE_BUFFER(buffer, 20);

void mbox_call(void* buf, size_t size) {
    uart_write(CONSOLE_UART, ">---\n");
    for (unsigned int i = 0; i < size / sizeof(buffer[0]); i++) {
        uart_write(CONSOLE_UART, itoa(buffer[i]));
    }
    uart_write(CONSOLE_UART, "---<\n");

    mbox_write(PROPERTY_TAGS_ARM_TO_VC, buf);
    (void)mbox_read(PROPERTY_TAGS_ARM_TO_VC);

    uart_write(CONSOLE_UART, ">---\n");
    for (unsigned int i = 0; i < size / sizeof(buffer[0]); i++) {
        uart_write(CONSOLE_UART, itoa(buffer[i]));
    }
    uart_write(CONSOLE_UART, "---<\n");
}

void main(void) {
    uart_init(CONSOLE_UART, 115200);

#define TAGS(X, ...)                                           \
    X(FRAMEBUFFER_ALLOCATE_BUFFER_TAG, a, __VA_ARGS__)         \
    X(FRAMEBUFFER_SET_PHYSICAL_DIMENSIONS_TAG, b, __VA_ARGS__) \
    X(FRAMEBUFFER_SET_DEPTH_TAG, c, __VA_ARGS__)

    MBOX_PROPERTY_MESSAGE_BUFFER_INIT(mbox_buffer, TAGS, buffer);

    // const unsigned int width  = 1920;
    // const unsigned int height = 1080;
    // const unsigned int depth  = 24;

    // mbox_buffer->a.buffer.request.width = width;
    // mbox_buffer->a.buffer.request.height = height;

    // mbox_buffer->b.header.id = FRAMEBUFFER_SET_VIRTUAL_DIMENSIONS_TAG_ID;
    // mbox_buffer->b.buffer.request.width  = width;
    // mbox_buffer->b.buffer.request.height = height;

    // mbox_buffer->c.header.id = FRAMEBUFFER_SET_DEPTH_TAG_ID;
    // mbox_buffer->c.buffer.request.bits_per_pixel = depth;

    // mbox_call(mbox_buffer, sizeof(*mbox_buffer));

    // MBOX_PROPERTY_MESSAGE_BUFFER_LAYOUT(
    //     framebuffer_allocate_buffer_tag a;)* buf2 = (void*)buffer;
    // buf2->a.header.id                = FRAMEBUFFER_ALLOCATE_BUFFER_TAG_ID;
    // buf2->a.buffer.request.alignment = 16;

    // mbox_call(buf2, sizeof(*buf2));
}

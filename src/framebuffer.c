#include "framebuffer.h"

#include <stdint.h>

#include "main.h"
#include "peripherals/mbox.h"
#include "peripherals/mbox/property/message.h"
#include "peripherals/mbox/property/tags.h"
#include "peripherals/mbox/property/tags/framebuffer.h"
#include "uart.h"
#include "util.h"

static MBOX_PROPERTY_MESSAGE_BUFFER(buffer, 40);

static struct {
    unsigned int width;
    unsigned int height;
    unsigned int pitch;
    unsigned int depth;

    uint32_t* buffer;
} framebuffer;

// TODO: Should depth be flexible?
int frambuffer_init(unsigned int width, unsigned int height,
                    unsigned int depth) {
#define TAGS(X, ...)                                           \
    X(FRAMEBUFFER_SET_PHYSICAL_DIMENSIONS_TAG, a, __VA_ARGS__) \
    X(FRAMEBUFFER_SET_VIRTUAL_DIMENSIONS_TAG, b, __VA_ARGS__)  \
    X(FRAMEBUFFER_SET_VIRTUAL_OFFSET_TAG, c, __VA_ARGS__)      \
    X(FRAMEBUFFER_SET_DEPTH_TAG, d, __VA_ARGS__)               \
    X(FRAMEBUFFER_SET_PIXEL_ORDER_TAG, e, __VA_ARGS__)         \
    X(FRAMEBUFFER_ALLOCATE_BUFFER_TAG, f, __VA_ARGS__)         \
    X(FRAMEBUFFER_GET_PITCH_TAG, g, __VA_ARGS__)

    MBOX_PROPERTY_MESSAGE_BUFFER_INIT(mbox_buffer, TAGS, buffer);

    MBOX_PROPERTY_TAG_REQUEST(mbox_buffer, a).width  = width;
    MBOX_PROPERTY_TAG_REQUEST(mbox_buffer, a).height = height;

    MBOX_PROPERTY_TAG_REQUEST(mbox_buffer, b).width  = width;
    MBOX_PROPERTY_TAG_REQUEST(mbox_buffer, b).height = height;

    MBOX_PROPERTY_TAG_REQUEST(mbox_buffer, c).x = 0;
    MBOX_PROPERTY_TAG_REQUEST(mbox_buffer, c).y = 0;

    MBOX_PROPERTY_TAG_REQUEST(mbox_buffer, d).bits_per_pixel = depth;

    MBOX_PROPERTY_TAG_REQUEST(mbox_buffer, e).state = RGB;

    MBOX_PROPERTY_TAG_REQUEST(mbox_buffer, f).alignment = 8;

    for (unsigned int i = 0; i < sizeof(*mbox_buffer) / sizeof(buffer[0]); i++)
        uart_write(CONSOLE_UART, itoa(buffer[i]));

    if (mbox_call(PROPERTY_TAGS_ARM_TO_VC, mbox_buffer))
        return 1;

    for (unsigned int i = 0; i < sizeof(*mbox_buffer) / sizeof(buffer[0]); i++)
        uart_write(CONSOLE_UART, itoa(buffer[i]));

    framebuffer.width  = MBOX_PROPERTY_TAG_RESPONSE(mbox_buffer, a).width;
    framebuffer.height = MBOX_PROPERTY_TAG_RESPONSE(mbox_buffer, a).height;
    framebuffer.depth =
        MBOX_PROPERTY_TAG_RESPONSE(mbox_buffer, d).bits_per_pixel;
    framebuffer.buffer =
        (uint32_t*)(uintptr_t)MBOX_PROPERTY_TAG_RESPONSE(mbox_buffer, f)
            .base_address;
    framebuffer.pitch =
        MBOX_PROPERTY_TAG_RESPONSE(mbox_buffer, g).bytes_per_line;

    return 0;
}

void framebuffer_draw_pixel(unsigned int x, unsigned int y, uint32_t value) {
    unsigned int offset =
        y * (framebuffer.pitch) / sizeof(framebuffer.buffer[0]) + x;
    framebuffer.buffer[offset] = value;
}

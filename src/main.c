#include "main.h"

#include <stddef.h>
#include <stdint.h>

#include "peripherals/mbox.h"
#include "peripherals/mbox/property/message.h"
#include "peripherals/mbox/property/tags.h"
#include "peripherals/mbox/property/tags/framebuffer.h"
#include "peripherals/mbox/property/tags/hardware.h"
#include "uart.h"
#include "util.h"

static MBOX_PROPERTY_MESSAGE_BUFFER(buffer, 30);

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

    // #define TAGS(X, ...)                                           \
//     X(FRAMEBUFFER_ALLOCATE_BUFFER_TAG, a, __VA_ARGS__)         \
//     X(FRAMEBUFFER_SET_PHYSICAL_DIMENSIONS_TAG, b, __VA_ARGS__) \
//     X(FRAMEBUFFER_SET_VIRTUAL_DIMENSIONS_TAG, c, __VA_ARGS__)  \
//     X(FRAMEBUFFER_SET_DEPTH_TAG, d, __VA_ARGS__)

#define TAGS(X, ...)                                      \
    X(HARDWARE_GET_BOARD_MAC_ADDRESS_TAG, a, __VA_ARGS__) \
    X(HARDWARE_GET_BOARD_MAC_ADDRESS_TAG, b, __VA_ARGS__)

    MBOX_PROPERTY_MESSAGE_BUFFER_INIT(mbox_buffer, TAGS, buffer);

    // MBOX_PROPERTY_TAG_REQUEST(mbox_buffer, a).alignment = 16;

    // MBOX_PROPERTY_TAG_REQUEST(mbox_buffer, b).width  = 1920;
    // MBOX_PROPERTY_TAG_REQUEST(mbox_buffer, b).height = 1080;

    // MBOX_PROPERTY_TAG_REQUEST(mbox_buffer, c).width  = 1920;
    // MBOX_PROPERTY_TAG_REQUEST(mbox_buffer, c).height = 1080;

    // MBOX_PROPERTY_TAG_REQUEST(mbox_buffer, d).bits_per_pixel = 32;

    mbox_call(mbox_buffer, sizeof(*mbox_buffer));
    uint8_t* buf =
        MBOX_PROPERTY_TAG_RESPONSE(mbox_buffer, a).board_mac_address;
    for (int i = 0; i < 6; i++) uart_write(CONSOLE_UART, itoa(buf[i]));

    // const int width  = 50;
    // const int height = 50;

    // uint32_t* fb = (void*)(uintptr_t)MBOX_PROPERTY_TAG_RESPONSE(mbox_buffer,
    // a)
    //                    .base_address;

    // /* Produce a colour spread across the screen */
    // unsigned int pixel_value = 0xffffffff;
    // for (int y = 0; y < height; y++) {
    //     int line_offset = y * width;

    //     for (int x = 0; x < width; x++) {
    //         fb[line_offset + x] = pixel_value;
    //     }
    // }

    // uart_write(CONSOLE_UART, "done\n");
}

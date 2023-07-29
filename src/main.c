#include <stdint.h>

#include "peripherals/mbox.h"
#include "peripherals/mbox/property/message.h"
#include "peripherals/mbox/property/tags.h"
#include "peripherals/mbox/property/tags/framebuffer.h"
#include "peripherals/mbox/property/tags/hardware.h"
#include "peripherals/mbox/property/tags/videocore.h"
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

    struct {
        mbox_property_message_buffer_header header;
        framebuffer_set_physical_dimensions_tag a;
        // framebuffer_set_virtual_dimensions_tag b;
        // framebuffer_set_depth_tag c;
        uint32_t null_tag;
    } __attribute__((aligned(16), packed)) buffer = {
        .a =
            {
                .header.id = FRAMEBUFFER_SET_PHYSICAL_DIMENSIONS,
                .buffer    = {.request =
                                  {
                                   // FIXME: Passing two args freezes RPi
                                      .width  = 640,
                                      .height = 480,
                               }},
            },
        // .b =
        //     {
        //         .header.id = FRAMEBUFFER_SET_VIRTUAL_DIMENSIONS,
        //         .buffer    = {.request =
        //                           {
        //                               .width  = 640,
        //                               .height = 480,
        //                        }},
        //     },
        // .c =
        //     {
        //         .header.id = FRAMEBUFFER_SET_DEPTH,
        //         .buffer    = {.request =
        //                           {
        //                               .bits_per_pixel = 24,
        //                        }},
        //     },
        .null_tag = NULL_TAG_ID,
    };

    for (unsigned int i = 0; i < sizeof(buffer) / sizeof(uint32_t); i++)
        uart_write(CONSOLE_UART, itoa(((uint32_t*)&buffer)[i]));

    mbox_property_message_init(&buffer, sizeof(buffer));

    uart_write(CONSOLE_UART, "---\n");

    mbox_write(PROPERTY_TAGS_ARM_TO_VC, &buffer);
    (void)mbox_read(PROPERTY_TAGS_ARM_TO_VC);

    for (unsigned int i = 0; i < sizeof(buffer) / sizeof(uint32_t); i++)
        uart_write(CONSOLE_UART, itoa(((uint32_t*)&buffer)[i]));
}

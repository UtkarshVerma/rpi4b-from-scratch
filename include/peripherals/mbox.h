#pragma once

typedef enum {
    // POWER_MANAGEMENT = 0,
    // FRAMEBUFFER,
    // VIRTUAL_UART,
    // VCHIQ,
    // LEDS,
    // BUTTONS,
    // TOUCHSCREEN,
    PROPERTY_TAGS_ARM_TO_VC = 8,
    // PROPERTY_TAGS_VC_TO_ARM,
} mbox_channel;

int mbox_call(mbox_channel channel, void* buffer);

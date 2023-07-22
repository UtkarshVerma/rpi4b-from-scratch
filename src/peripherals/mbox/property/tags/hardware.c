#include "peripherals/mbox/property/tags/hardware.h"

#include "peripherals/mbox/property/tags.h"

#define HARDWARE_TAG_ID_BASE 0x00010000

const tag_metadata hardware_tag_metadata[HARDWARE_TAG_COUNT] = {
    [TAG_COMMAND(HARDWARE_GET_BOARD_MODEL)] =
        {
            .id          = HARDWARE_TAG_ID_BASE + 1,
            .buffer_size = sizeof(hardware_get_board_model_buffer),
        },
    [TAG_COMMAND(HARDWARE_GET_BOARD_REVISION)] =
        {
            .id          = HARDWARE_TAG_ID_BASE + 2,
            .buffer_size = sizeof(hardware_get_board_revision_buffer),
        },
    [TAG_COMMAND(HARDWARE_GET_BOARD_MAC_ADDRESS)] =
        {
            .id          = HARDWARE_TAG_ID_BASE + 3,
            .buffer_size = sizeof(hardware_get_board_mac_address_buffer),
        },
    [TAG_COMMAND(HARDWARE_GET_BOARD_SERIAL)] =
        {
            .id          = HARDWARE_TAG_ID_BASE + 4,
            .buffer_size = sizeof(hardware_get_board_serial_buffer),
        },
    [TAG_COMMAND(HARDWARE_GET_ARM_MEMORY)] =
        {
            .id          = HARDWARE_TAG_ID_BASE + 5,
            .buffer_size = sizeof(hardware_get_arm_memory_buffer),
        },
    [TAG_COMMAND(HARDWARE_GET_VC_MEMORY)] =
        {
            .id          = HARDWARE_TAG_ID_BASE + 6,
            .buffer_size = sizeof(hardware_get_vc_memory_buffer),
        },
};

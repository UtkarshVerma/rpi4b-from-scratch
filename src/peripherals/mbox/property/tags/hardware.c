#include "peripherals/mbox/property/tags/hardware.h"

#include "peripherals/mbox/property/tags.h"
#include "util.h"

#define TAG_ID_BASE      0x00010000
#define INDEX(tag)       TAG_COMMAND(HARDWARE_##tag)
#define BUFFER_SIZE(tag) MEMBER_SIZE(hardware_tag_buffer, tag)

const tag_metadata hardware_tag_metadata[HARDWARE_TAG_COUNT] = {
    [INDEX(GET_BOARD_MODEL)] =
        {
            .id          = TAG_ID_BASE + 1,
            .buffer_size = BUFFER_SIZE(get_board_model),
        },
    [INDEX(GET_BOARD_REVISION)] =
        {
            .id          = TAG_ID_BASE + 2,
            .buffer_size = BUFFER_SIZE(get_board_revision),
        },
    [INDEX(GET_BOARD_MAC_ADDRESS)] =
        {
            .id          = TAG_ID_BASE + 3,
            .buffer_size = BUFFER_SIZE(get_board_mac_address),
        },
    // [INDEX(GET_BOARD_SERIAL)] =
    //     {
    //         .id          = TAG_ID_BASE + 4,
    //         .buffer_size = BUFFER_SIZE(get_board_serial),
    //     },
    [INDEX(GET_ARM_MEMORY)] =
        {
            .id          = TAG_ID_BASE + 5,
            .buffer_size = BUFFER_SIZE(get_arm_memory),
        },
    [INDEX(GET_VC_MEMORY)] =
        {
            .id          = TAG_ID_BASE + 6,
            .buffer_size = BUFFER_SIZE(get_vc_memory),
        },
};

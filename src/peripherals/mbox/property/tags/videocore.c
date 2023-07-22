#include "peripherals/mbox/property/tags/videocore.h"

#include "peripherals/mbox/property/tags.h"

#define VIDEOCORE_TAG_ID_BASE 0x00000000

const tag_metadata videocore_tag_metadata[VIDEOCORE_TAG_COUNT] = {
    [TAG_COMMAND(VIDEOCORE_GET_FIRMWARE_REVISION)] =
        {
            .id          = VIDEOCORE_TAG_ID_BASE + 1,
            .buffer_size = sizeof(videocore_get_firmware_revision_buffer),
        },
};

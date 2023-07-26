#include "peripherals/mbox/property/tags/videocore.h"

#include "peripherals/mbox/property/tags.h"
#include "util.h"

#define TAG_ID_BASE      0x00000000
#define INDEX(tag)       TAG_COMMAND(VIDEOCORE_##tag)
#define BUFFER_SIZE(tag) MEMBER_SIZE(videocore_tag_buffer, tag)

const tag_metadata videocore_tag_metadata[VIDEOCORE_TAG_COUNT] = {
    [INDEX(GET_FIRMWARE_REVISION)] =
        {
            .id          = TAG_ID_BASE + 1,
            .buffer_size = BUFFER_SIZE(get_firmware_revision),
        },
};

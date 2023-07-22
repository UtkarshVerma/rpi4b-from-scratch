#include "peripherals/mbox/property/tags.h"

#include "peripherals/mbox/property/tags/hardware.h"
#include "peripherals/mbox/property/tags/videocore.h"

void tag_init(tag* t, uint32_t tag) {
    const tag_metadata* metadata;
    unsigned int tag_end;
    switch (TAG_BASE(tag)) {
        case VIDEOCORE_TAG_BASE:
            metadata = videocore_tag_metadata;
            tag_end  = VIDEOCORE_TAG_END;
            break;
        case HARDWARE_TAG_BASE:
            metadata = hardware_tag_metadata;
            tag_end  = HARDWARE_TAG_END;
            break;
        default:
            tag_end = 0;
    }

    if (tag >= tag_end)
        return;

    t->id          = metadata[TAG_COMMAND(tag)].id;
    t->buffer_size = metadata[TAG_COMMAND(tag)].buffer_size;
    t->status_code = 0;
}

#include "peripherals/mbox/property/tags.h"

#include <stddef.h>

#include "util.h"

#define TAG(enum, name, tag_id)                                     \
    [enum] = {                                                      \
        .id          = tag_id,                                      \
        .buffer_size = MEMBER_SIZE(mbox_property_tag_buffer, name), \
    },
// clang-format off
static const tag_metadata metadata[TAG_COUNT] = {
    TAGS
};
// clang-format on
#undef TAG

int mbox_property_tag_init(mbox_property_tag_id id, mbox_property_tag* tag) {
    if (id >= ARRAY_SIZE(metadata))
        return 1;

    const tag_metadata* m = &metadata[id];

    tag->id          = m->id;
    tag->buffer_size = m->buffer_size;
    tag->status_code = 0;

    return 0;
}

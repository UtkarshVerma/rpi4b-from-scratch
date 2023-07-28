#include "peripherals/mbox/property/tags.h"

#include "util.h"

#define TAG(enum, name, tag_id)                       \
    [enum] = {                                        \
        .id          = tag_id,                        \
        .buffer_size = MEMBER_SIZE(tag_buffer, name), \
    },
static const tag_metadata metadata[TAG_COUNT] = {TAGS};
#undef TAG

void tag_init(tag* t, tag_id tag) {
    if (tag >= ARRAY_SIZE(metadata))
        return;

    const tag_metadata* m = &metadata[tag];

    t->id          = m->id;
    t->buffer_size = m->buffer_size;
    t->status_code = 0;
}

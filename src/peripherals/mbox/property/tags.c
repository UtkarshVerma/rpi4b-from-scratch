#include "peripherals/mbox/property/tags.h"

#include "util.h"

typedef struct {
    uint32_t id;
    uint32_t buffer_size;
} tag_metadata;

#define TAG(NAME, name, tag_id)                   \
    [NAME##_TAG_ID] = {                           \
        .id          = tag_id,                    \
        .buffer_size = sizeof(name##_tag_buffer), \
    },
static const tag_metadata metadata[TAG_COUNT] = {TAGS};
#undef TAG

int mbox_property_tag_init(mbox_property_tag_id id,
                           mbox_property_tag_header* header) {
    if (id >= ARRAY_SIZE(metadata))
        return 1;

    const tag_metadata* m = &metadata[id];
    header->id            = m->id;
    if (id == NULL_TAG_ID)
        return 0;

    header->buffer_size = m->buffer_size;
    header->status_code = 0;

    return 0;
}

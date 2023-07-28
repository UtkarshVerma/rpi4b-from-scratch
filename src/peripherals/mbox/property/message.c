#include "peripherals/mbox/property/message.h"

#include <stdint.h>

#include "peripherals/mbox/property/tags.h"

#define NULL_TAG_ID 0

static mbox_property_message_buffer buffer = {
    .size     = sizeof(buffer),
    .null_tag = {.id = NULL_TAG_ID},
};

void mbox_property_message_init(tag_id tag_id) {
    buffer.status.request_code = PROCESS_REQUEST;

    tag* t = &buffer.tag;
    tag_init(t, tag_id);
}

mbox_property_message_buffer* mbox_property_message_get_buffer_pointer() {
    return &buffer;
}

#include "peripherals/mbox/property/message.h"

#include "peripherals/mbox/property/tags.h"

#define NULL_TAG_ID 0

mbox_property_message_buffer buffer;

// TODO: A better name
static mbox_property_tag* current_tag = buffer.tags;

void mbox_property_message_init() {
    buffer.status.request_code = PROCESS_REQUEST;
    buffer.size                = (void*)current_tag - (void*)&buffer;

    // Append the null tag
    *(uint32_t*)current_tag = NULL_TAG_ID;
    buffer.size += sizeof(uint32_t);
}

volatile mbox_property_tag_buffer* mbox_property_message_append_tag(
    mbox_property_tag_id id) {
    (void)mbox_property_tag_init(id, current_tag);
    mbox_property_tag* prev_tag = current_tag;

    current_tag = (void*)&current_tag->buffer + current_tag->buffer_size;

    return &prev_tag->buffer;
}

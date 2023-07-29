#include "peripherals/mbox/property/message.h"

#include "peripherals/mbox/property/tags.h"

void mbox_property_message_init(void* buffer, size_t size) {
    mbox_property_message_buffer_header* header = buffer;
    header->status.request_code                 = PROCESS_REQUEST;
    header->size                                = size;

    mbox_property_tag_header* tag_header = buffer + sizeof(*header);
    while (tag_header->id != NULL_TAG_ID) {
        mbox_property_tag_init(tag_header->id, tag_header);
        tag_header = (void*)(tag_header + 1) + tag_header->buffer_size;
    }
}

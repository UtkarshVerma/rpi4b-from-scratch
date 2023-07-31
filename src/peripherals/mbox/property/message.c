#include "peripherals/mbox/property/message.h"

#include <stdint.h>

#include "peripherals/mbox/property/tags.h"

#define NULL_TAG_ID 0

int mbox_property_message_init(void* buffer, size_t size) {
    // Append the null tag at the end of the buffer
    ((uint32_t*)buffer)[size / sizeof(uint32_t) - 1] = NULL_TAG;

    mbox_property_message_buffer_header* header = buffer;
    header->status.request_code                 = PROCESS_REQUEST;
    header->size                                = size;

    mbox_property_tag_header* tag_header = (void*)(header + 1);
    while ((void*)tag_header < buffer + size) {
        if (mbox_property_tag_init(tag_header->id, tag_header))
            return 1;
        tag_header = (void*)(tag_header + 1) + tag_header->buffer_size;
    }

    return 0;
}

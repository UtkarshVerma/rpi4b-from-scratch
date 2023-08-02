#include "peripherals/mbox/property/message.h"

#include <stdint.h>

#include "peripherals/mbox/property/tags.h"

int mbox_property_message_init(void* buffer, size_t size) {
    // Append the null tag at the end of the buffer
    uintptr_t null_tag_ptr   = (uintptr_t)buffer + size - sizeof(uint32_t);
    *(uint32_t*)null_tag_ptr = NULL_TAG_ID;

    mbox_property_message_buffer_header* header = buffer;
    header->status.request_code                 = PROCESS_REQUEST;
    header->size                                = size;

    mbox_property_tag_header* tag_header = (void*)(header + 1);
    while ((uintptr_t)tag_header <= null_tag_ptr) {
        if (mbox_property_tag_init(tag_header->id, tag_header))
            return 1;

        tag_header =
            (void*)((uintptr_t)(tag_header + 1) + tag_header->buffer_size);
    }

    return 0;
}

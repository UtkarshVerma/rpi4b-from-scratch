#include "peripherals/mbox/property/message.h"

#include <stdint.h>

#define PROCESS_REQUEST    0
#define REQUEST_SUCCESSFUL 0x80000000
#define REQUEST_ERROR      0x80000001

#define NULL_TAG_ID 0

void mbox_property_message_init(void* buffer, size_t size) {
    mbox_property_message_header* header = buffer;

    header->size   = size;
    header->status = PROCESS_REQUEST;

    uint32_t* null_tag =
        (uint32_t*)((uintptr_t)buffer + size - sizeof(uint32_t));
    *null_tag = NULL_TAG_ID;
}

int mbox_property_message_is_successful(void* buffer) {
    mbox_property_message_header* header = buffer;

    switch (header->status) {
        case PROCESS_REQUEST:
            // Message is not sent yet, so invalid invocation
            return -1;
        case REQUEST_SUCCESSFUL:
            return 0;
        case REQUEST_ERROR:
            // Message has some error as the GPU could not parse it
            return 1;
        default:
            // Undefined behaviour
            return 2;
    }
}

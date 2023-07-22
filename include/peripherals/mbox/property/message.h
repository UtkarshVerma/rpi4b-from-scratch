#pragma once

#include <stdint.h>

#include "tags.h"

typedef union {
    enum {
        PROCESS_REQUEST = 0,
    } request_code;

    enum {
        RESPONSE_SUCCESSFUL = 0x80000000,
        REPSONSE_ERROR      = 0x80000001,
    } response_code;
} message_buffer_status_code;

// This has to be 16-byte aligned as last nibble is discarded from the pointer
// while making the mailbox call
typedef volatile struct {
    const uint32_t size;
    message_buffer_status_code status;
    tag tag;  // TODO: Make this support multiple tags
    const tag null_tag;
} __attribute__((aligned(16))) mbox_property_message_buffer;

void mbox_property_message_init(uint32_t tag_id);
mbox_property_message_buffer* mbox_property_message_get_buffer_pointer();

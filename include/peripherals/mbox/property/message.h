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
typedef struct {
    uint32_t size;
    volatile message_buffer_status_code status;
} mbox_property_message_buffer_header;

void mbox_property_message_init(void* buffer, size_t size);

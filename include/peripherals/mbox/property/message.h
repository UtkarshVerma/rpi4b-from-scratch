#pragma once

#include <stdint.h>

#include "tags.h"

// This has to be 16-byte aligned as last nibble is discarded from the pointer
// while making the mailbox call
#define MBOX_PROPERTY_MESSAGE_BUFFER(name, size) \
    uint32_t name[size] __attribute__((aligned(16)))

// clang-format off
#define MBOX_PROPERTY_MESSAGE_BUFFER_LAYOUT(tags)   \
    struct {                                        \
        mbox_property_message_buffer_header header; \
        tags                                        \
        const uint32_t null_tag;                    \
    } __attribute__((packed))
// clang-format on

typedef union {
    enum {
        PROCESS_REQUEST = 0,
    } request_code;

    enum {
        RESPONSE_SUCCESSFUL = 0x80000000,
        REPSONSE_ERROR      = 0x80000001,
    } response_code;
} message_buffer_status_code;

typedef struct {
    uint32_t size;
    volatile message_buffer_status_code status;
} mbox_property_message_buffer_header;

int mbox_property_message_init(void* buffer, size_t size);

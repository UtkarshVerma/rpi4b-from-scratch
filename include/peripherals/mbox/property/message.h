#pragma once

#include <stdint.h>

#include "tags.h"

// This has to be 16-byte aligned as last nibble is discarded from the pointer
// while making the mailbox call
#define MBOX_PROPERTY_MESSAGE_BUFFER(name, size) \
    uint32_t name[size] __attribute__((aligned(16)))

#define MBOX_PROPERTY_MESSAGE_BUFFER_INIT(name, TAGS, dest) \
    struct {                                                \
        uint32_t size;                                      \
        volatile message_buffer_status_code status;         \
        TAGS(MBOX_PROPERTY_TAG_TYPE, name)                  \
        uint32_t null_tag;                                  \
    } *name = (void *)dest;                                 \
                                                            \
    TAGS(MBOX_PROPERTY_TAG_INIT, name)                      \
    name->size                = sizeof(*name);              \
    name->status.request_code = PROCESS_REQUEST;            \
    name->null_tag            = 0

// TODO: Make this internal to the init function
typedef union {
    enum {
        PROCESS_REQUEST = 0,
    } request_code;

    enum {
        RESPONSE_SUCCESSFUL = 0x80000000,
        REPSONSE_ERROR      = 0x80000001,
    } response_code;
} message_buffer_status_code;

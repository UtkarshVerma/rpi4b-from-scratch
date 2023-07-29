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
    mbox_property_tag tags[4];  // TODO: Make this configurable
} __attribute__((aligned(16))) mbox_property_message_buffer;

// TODO: Make this static?
extern mbox_property_message_buffer buffer;

void mbox_property_message_init();
volatile mbox_property_tag_buffer* mbox_property_message_append_tag(
    mbox_property_tag_id id);

#pragma once

#include <stddef.h>
#include <stdint.h>

#include "tags.h"

// This has to be 16-byte aligned as last nibble is discarded from the pointer
// while making the mailbox call
#define MBOX_PROPERTY_MESSAGE_BUFFER(name, size) \
    uint32_t name[size] __attribute__((aligned(16)))

#define MBOX_PROPERTY_MESSAGE_BUFFER_INIT(name, TAGS, dest) \
    struct {                                                \
        mbox_property_message_header header;                \
        TAGS(MBOX_PROPERTY_TAG_TYPE, name)                  \
        const uint32_t null_tag;                            \
    } *name = (void *)dest;                                 \
                                                            \
    TAGS(MBOX_PROPERTY_TAG_INIT, name)                      \
    mbox_property_message_init(name, sizeof(*name))

typedef struct {
    uint32_t size;
    volatile uint32_t status;
} mbox_property_message_header;

void mbox_property_message_init(void *buffer, size_t size);
int mbox_property_message_is_successful(void *buffer);

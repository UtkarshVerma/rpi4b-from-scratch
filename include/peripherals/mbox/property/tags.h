#pragma once

#include <stddef.h>
#include <stdint.h>

#include "tags/framebuffer.h"
#include "tags/hardware.h"
#include "tags/videocore.h"

#define TAGS       \
    VIDEOCORE_TAGS \
    HARDWARE_TAGS  \
    FRAMEBUFFER_TAGS

#define TAG(enum, name, id) enum,
// clang-format off
typedef enum {
    TAGS

    TAG_COUNT,
} mbox_property_tag_id;
// clang-format on
#undef TAG

typedef struct {
    mbox_property_tag_id id;
    uint32_t buffer_size;
    volatile uint32_t status_code;
} mbox_property_tag_header;

#define TAG(enum, name, id)                \
    typedef struct {                       \
        mbox_property_tag_header header;   \
        volatile name##_tag_buffer buffer; \
    } __attribute__((packed)) name##_tag;
TAGS;
#undef TAG

int mbox_property_tag_init(mbox_property_tag_id id,
                           mbox_property_tag_header* tag);

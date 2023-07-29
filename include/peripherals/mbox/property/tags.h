#pragma once

#include <stddef.h>
#include <stdint.h>

#include "tags/framebuffer.h"
#include "tags/hardware.h"
#include "tags/videocore.h"

typedef struct {
    uint32_t id;
    uint32_t buffer_size;
} tag_metadata;

#define TAGS       \
    VIDEOCORE_TAGS \
    HARDWARE_TAGS  \
    FRAMEBUFFER_TAGS

#define TAG(enum, name, id) name##_tag_buffer name;
// clang-format off
typedef union {
    TAGS
} mbox_property_tag_buffer;
// clang-format on
#undef TAG

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
    volatile mbox_property_tag_buffer buffer;
} __attribute__((packed)) mbox_property_tag;

int mbox_property_tag_init(mbox_property_tag_id id, mbox_property_tag* tag);

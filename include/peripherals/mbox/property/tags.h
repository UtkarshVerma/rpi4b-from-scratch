#pragma once

#include <stdint.h>

#include "tags/hardware.h"
#include "tags/videocore.h"

typedef struct {
    uint32_t id;
    uint32_t buffer_size;
} tag_metadata;

#define TAGS       \
    VIDEOCORE_TAGS \
    HARDWARE_TAGS

#define TAG(enum, name, id) name##_tag_buffer name;
// clang-format off
typedef union {
    TAGS
} tag_buffer;
// clang-format on
#undef TAG

#define TAG(enum, name, id) enum,
// clang-format off
typedef enum {
    TAGS
    TAG_COUNT,
} tag_id;
// clang-format on
#undef TAG

typedef struct {
    tag_id id;
    uint32_t buffer_size;
    volatile uint32_t status_code;
    volatile tag_buffer buffer;
} __attribute__((packed)) tag;

void tag_init(tag* t, tag_id tag_id);

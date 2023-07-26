#pragma once

#include <stdint.h>

typedef struct {
    uint32_t id;
    uint32_t buffer_size;
} tag_metadata;

#define TAG_KIND_BASE(kind) (kind << 16)
#define TAG_KIND(tag)       (tag >> 16)
#define TAG_COMMAND(tag)    (tag & 0xffff)

typedef enum {
    VIDEOCORE_TAG,
    HARDWARE_TAG,
} tag_kind;

#include "tags/hardware.h"
#include "tags/videocore.h"

typedef union {
    videocore_tag_buffer videocore;
    hardware_tag_buffer hardware;
} tag_buffer;

typedef struct {
    uint32_t id;
    uint32_t buffer_size;
    volatile uint32_t status_code;
    volatile tag_buffer buffer;
} tag;

void tag_init(tag* t, uint32_t tag_id);

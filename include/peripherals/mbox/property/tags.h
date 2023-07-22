#pragma once

#include <stdint.h>

typedef struct {
    uint32_t id;
    uint32_t buffer_size;
} tag_metadata;

#define TAG_COMMAND_MASK 0xffff
#define TAG_BASE_MASK    ~TAG_COMMAND_MASK
#define TAG_BASE(tag)    (tag & TAG_BASE_MASK)
#define TAG_COMMAND(tag) (tag & TAG_COMMAND_MASK)

typedef enum {
    VIDEOCORE_TAG_BASE = 0x00000000,
    HARDWARE_TAG_BASE  = 0x00010000,
} tag_base;

#include "tags/hardware.h"
#include "tags/videocore.h"

typedef union {
    videocore_tag_buffer videocore;
    hardware_tag_buffer hardware;
} tag_buffer;

typedef struct {
    uint32_t id;
    uint32_t buffer_size;
    uint32_t status_code;
    tag_buffer buffer;
} tag;

void tag_init(tag* t, uint32_t tag_id);

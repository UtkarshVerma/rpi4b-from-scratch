#pragma once

#include <stdint.h>

typedef union {
    struct {
    } request;
    struct {
        uint32_t firmware_revision;
    } response;
} videocore_get_firmware_revision_buffer;

typedef union {
    videocore_get_firmware_revision_buffer get_firmware_revision;
} videocore_tag_buffer;

#include "../tags.h"

typedef enum {
    VIDEOCORE_TAG_BASE = TAG_KIND_BASE(VIDEOCORE_TAG),

    VIDEOCORE_GET_FIRMWARE_REVISION,

    VIDEOCORE_TAG_END,
} videocore_tag;

#define VIDEOCORE_TAG_COUNT (VIDEOCORE_TAG_END - VIDEOCORE_TAG_BASE)

extern const tag_metadata videocore_tag_metadata[VIDEOCORE_TAG_COUNT];

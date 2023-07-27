#pragma once

#include <stdint.h>

#include "util/tags.h"

#define VIDEOCORE_TAGS \
    TAG(VIDEOCORE_GET_FIRMWARE_REVISION, get_firmware_revision, 1)

typedef union {
    struct {
    } request;
    struct {
        uint32_t firmware_revision;
    } response;
} videocore_get_firmware_revision_buffer;

#define TAG(enum, name, id) TAG_BUFFER(videocore, name)
typedef union {
    VIDEOCORE_TAGS
} videocore_tag_buffer;
#undef TAG

#include "../tags.h"

#define TAG(enum, name, id) TAG_ENUM(enum)
// clang-format off
typedef enum {
    VIDEOCORE_TAG_BASE = TAG_KIND_BASE(VIDEOCORE_TAG),

    VIDEOCORE_TAGS

    VIDEOCORE_TAG_END,
} videocore_tag;
// clang-format on
#undef TAG

extern const tag_metadata videocore_tag_metadata[TAG_COUNT(VIDEOCORE)];

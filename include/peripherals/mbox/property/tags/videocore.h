#pragma once

#include <stdint.h>

#define VIDEOCORE_TAGS                                                    \
    TAG(VIDEOCORE_GET_FIRMWARE_REVISION, videocore_get_firmware_revision, \
        0x00000001)

typedef union {
    struct {
    } request;
    struct {
        uint32_t firmware_revision;
    } response;
} videocore_get_firmware_revision_tag_buffer;

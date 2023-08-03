#pragma once

#include <stdint.h>

#define VIDEOCORE_GET_FIRMWARE_REVISION_TAG \
    videocore_get_firmware_revision_tag_buffer, 0x00000001

typedef union {
    struct {
        uint32_t firmware_revision;
    } response;
} videocore_get_firmware_revision_tag_buffer;

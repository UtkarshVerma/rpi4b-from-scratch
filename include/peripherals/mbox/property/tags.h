#pragma once

#include <stddef.h>
#include <stdint.h>

#include "tags/framebuffer.h"
#include "tags/hardware.h"
#include "tags/videocore.h"

#define TAGS           \
    TAG(NULL, null, 0) \
    VIDEOCORE_TAGS     \
    HARDWARE_TAGS      \
    FRAMEBUFFER_TAGS

typedef struct {
} null_tag_buffer;

#define TAG(NAME, name, id) NAME##_TAG_ID,
// clang-format off
typedef enum {
    TAGS

    TAG_COUNT,
} mbox_property_tag_id;
// clang-format on
#undef TAG

// Technically, only `status_code` gets modified by the GPU. However, the
// compiler optimizations try to assign `id` and `buffer_size` as a DWORD which
// may not always work as DWORD alignment in the buffer is not guaranteed.
// Hence, the whole struct is marked `voltatile` to disable memory access
// optimizations for the header.
typedef volatile struct {
    mbox_property_tag_id id;
    uint32_t buffer_size;
    uint32_t status_code;
} mbox_property_tag_header;

#define TAG(NAME, name, id)                \
    typedef struct {                       \
        mbox_property_tag_header header;   \
        volatile name##_tag_buffer buffer; \
    } __attribute__((packed)) name##_tag;
TAGS;
#undef TAG

int mbox_property_tag_init(mbox_property_tag_id id,
                           mbox_property_tag_header* tag);

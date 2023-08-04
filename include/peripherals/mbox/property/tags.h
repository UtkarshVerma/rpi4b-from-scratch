#pragma once

#include <stdint.h>

// A tag has to include padding in the end to make it 32-bit aligned. This is
// done implicity here due to other members being uint32_t.
#define MBOX_PROPERTY_TAG_TYPE(...) MBOX_PROPERTY_TAG_TYPE_(__VA_ARGS__)
#define MBOX_PROPERTY_TAG_TYPE_(type, tag_id, name, ...) \
    struct {                                             \
        uint32_t id;                                     \
        uint32_t buffer_size;                            \
        volatile uint32_t status_code;                   \
        volatile type buffer;                            \
    } name;

#define MBOX_PROPERTY_TAG_INIT(...) MBOX_PROPERTY_TAG_INIT_(__VA_ARGS__)
#define MBOX_PROPERTY_TAG_INIT_(type, tag_id, name, buffer) \
    buffer->name.id          = tag_id;                      \
    buffer->name.buffer_size = sizeof(type);                \
    buffer->name.status_code = 0;

#define MBOX_PROPERTY_TAG_REQUEST(buffer_name, child) \
    buffer_name->child.buffer.request

#define MBOX_PROPERTY_TAG_RESPONSE(buffer_name, child) \
    buffer_name->child.buffer.response

#pragma once

#include <stdint.h>

#define MBOX_PROPERTY_TAG_TYPE(...) MBOX_PROPERTY_TAG_TYPE_(__VA_ARGS__)
#define MBOX_PROPERTY_TAG_TYPE_(type, tag_id, name, ...) \
    struct {                                             \
        uint32_t id;                                     \
        uint32_t buffer_size;                            \
        volatile uint32_t status_code;                   \
        type buffer;                                     \
    } __attribute__((packed)) name;

#define MBOX_PROPERTY_TAG_INIT(...) MBOX_PROPERTY_TAG_INIT_(__VA_ARGS__)
#define MBOX_PROPERTY_TAG_INIT_(type, tag_id, name, buffer, ...) \
    buffer->name.buffer_size = sizeof(type);                     \
    buffer->name.id          = tag_id;

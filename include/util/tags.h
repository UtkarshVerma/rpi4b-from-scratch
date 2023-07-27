#pragma once

#include "../util.h"

#define TAG_COUNT(kind)          (kind##_TAG_END - kind##_TAG_BASE - 1)
#define TAG_BUFFER(prefix, name) prefix##_##name##_buffer name;
#define TAG_ENUM(enum)           enum,
#define TAG_METADATA_INDEX(enum) (TAG_COMMAND(enum) - 1)
#define TAG_METADATA_ITEM(kind_lc, enum, name, id_offset)       \
    [TAG_METADATA_INDEX(enum)] = {                              \
        .id          = TAG_ID_BASE + id_offset,                 \
        .buffer_size = MEMBER_SIZE(kind_lc##_tag_buffer, name), \
    },

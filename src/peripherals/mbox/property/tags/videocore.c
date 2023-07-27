#include "peripherals/mbox/property/tags/videocore.h"

#include "peripherals/mbox/property/tags.h"

#define TAG_ID_BASE 0x00000000

#define TAG(enum, name, tag_id) \
    TAG_METADATA_ITEM(videocore, enum, name, tag_id)
const tag_metadata videocore_tag_metadata[TAG_COUNT(VIDEOCORE)] = {
    VIDEOCORE_TAGS};
#undef TAG

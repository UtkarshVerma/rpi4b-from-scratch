#include "peripherals/mbox/property/tags/hardware.h"

#include "peripherals/mbox/property/tags.h"

#define TAG_ID_BASE 0x00010000

#define TAG(enum, name, id) TAG_METADATA_ITEM(hardware, enum, name, id)
const tag_metadata hardware_tag_metadata[TAG_COUNT(HARDWARE)] = {
    HARDWARE_TAGS};
#undef TAG

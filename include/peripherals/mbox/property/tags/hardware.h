#pragma once

#include <stdint.h>

#include "util/tags.h"

#define HARDWARE_TAGS                                             \
    TAG(HARDWARE_GET_BOARD_MODEL, get_board_model, 1)             \
    TAG(HARDWARE_GET_BOARD_REVISION, get_board_revision, 2)       \
    TAG(HARDWARE_GET_BOARD_MAC_ADDRESS, get_board_mac_address, 3) \
    TAG(HARDWARE_GET_BOARD_SERIAL, get_board_serial, 4)           \
    TAG(HARDWARE_GET_ARM_MEMORY, get_arm_memory, 5)               \
    TAG(HARDWARE_GET_VC_MEMORY, get_vc_memory, 6)

typedef union {
    struct {
    } request;
    struct {
        uint32_t board_model;
    } response;
} hardware_get_board_model_buffer;

typedef union {
    struct {
    } request;
    struct {
        uint32_t board_revision;
    } response;
} hardware_get_board_revision_buffer;

typedef union {
    struct {
    } request;
    struct {
        uint8_t board_mac_address[6];
    } response;
} hardware_get_board_mac_address_buffer;

typedef union {
    struct {
    } request;
    struct {
        uint64_t board_serial;
    } response;
} hardware_get_board_serial_buffer;

typedef union {
    struct {
    } request;
    struct {
        uint32_t base_addr;
        uint32_t size;
    } response;
} hardware_get_arm_memory_buffer;

typedef union {
    struct {
    } request;
    struct {
        uint32_t base_addr;
        uint32_t size;
    } response;
} hardware_get_vc_memory_buffer;

// TODO: This is a bit complex
// typedef union {
//     struct {
//     } request;
//     struct {
//         const volatile uint32_t base_addr;
//         const volatile uint32_t size;
//     } response;
// } hardware_get_clocks;

#define TAG(enum, name, id) TAG_BUFFER(hardware, name)
typedef union {
    HARDWARE_TAGS
} hardware_tag_buffer;
#undef TAG

#include "../tags.h"

#define TAG(enum, name, id) TAG_ENUM(enum)
// clang-format off
typedef enum {
    HARDWARE_TAG_BASE = TAG_KIND_BASE(HARDWARE_TAG),

    HARDWARE_TAGS

    HARDWARE_TAG_END
} hardware_tag;
// clang-format on
#undef TAG

extern const tag_metadata hardware_tag_metadata[TAG_COUNT(HARDWARE)];

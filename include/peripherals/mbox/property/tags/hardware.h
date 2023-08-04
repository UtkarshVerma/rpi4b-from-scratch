#pragma once

#include <stdint.h>

#define HARDWARE_GET_BOARD_MODEL_TAG \
    hardware_get_board_model_tag_buffer, 0x00010001
#define HARDWARE_GET_BOARD_REVISION_TAG \
    hardware_get_board_revision_tag_buffer, 0x00010002
#define HARDWARE_GET_BOARD_MAC_ADDRESS_TAG \
    hardware_get_board_mac_address_tag_buffer, 0x00010003
#define HARDWARE_GET_BOARD_SERIAL_TAG \
    hardware_get_board_serial_tag_buffer, 0x00010004
#define HARDWARE_GET_ARM_MEMORY_TAG \
    hardware_get_arm_memory_tag_buffer, 0x00010005
#define HARDWARE_GET_VC_MEMORY_TAG \
    hardware_get_vc_memory_tag_buffer, 0x00010006
#define HARDWARE_GET_CLOCKS_TAG hardware_get_clocks_tag_buffer, 0x00010007

typedef union {
    struct {
        uint32_t board_model;
    } response;
} hardware_get_board_model_tag_buffer;

typedef union {
    struct {
        uint32_t board_revision;
    } response;
} hardware_get_board_revision_tag_buffer;

typedef union {
    struct {
        uint8_t board_mac_address[6];
    } response;
} hardware_get_board_mac_address_tag_buffer;

typedef union {
    struct {
        uint64_t board_serial;
    } response;
} hardware_get_board_serial_tag_buffer;

typedef union {
    struct {
        uint32_t base_addr;
        uint32_t size;
    } response;
} hardware_get_arm_memory_tag_buffer;

typedef union {
    struct {
        uint32_t base_addr;
        uint32_t size;
    } response;
} hardware_get_vc_memory_tag_buffer;

// NOTE: The docs mention 15 kinds of clocks, but the 15 array length might
// need further investigation.
typedef union {
    struct {
        struct {
            uint32_t parent_id;
            uint32_t id;
        } clocks[15];
    } response;
} hardware_get_clocks_tag_buffer;

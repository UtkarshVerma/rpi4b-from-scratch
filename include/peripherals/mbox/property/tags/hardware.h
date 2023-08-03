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

// TODO: This is a bit complex
// typedef union {
//     struct {
//     } request;
//     struct {
//         const volatile uint32_t base_addr;
//         const volatile uint32_t size;
//     } response;
// } hardware_get_clocks;

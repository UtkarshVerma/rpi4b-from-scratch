#pragma once

#include <stdint.h>

#define HARDWARE_TAGS                                                         \
    TAG(HARDWARE_GET_BOARD_MODEL, hardware_get_board_model, 0x00010001)       \
    TAG(HARDWARE_GET_BOARD_REVISION, hardware_get_board_revision, 0x00010002) \
    TAG(HARDWARE_GET_BOARD_MAC_ADDRESS, hardware_get_board_mac_address,       \
        0x00010003)                                                           \
    TAG(HARDWARE_GET_BOARD_SERIAL, hardware_get_board_serial, 0x00010004)     \
    TAG(HARDWARE_GET_ARM_MEMORY, hardware_get_arm_memory, 0x00010005)         \
    TAG(HARDWARE_GET_VC_MEMORY, hardware_get_vc_memory, 0x00010006)

typedef union {
    struct {
    } request;
    struct {
        uint32_t board_model;
    } response;
} hardware_get_board_model_tag_buffer;

typedef union {
    struct {
    } request;
    struct {
        uint32_t board_revision;
    } response;
} hardware_get_board_revision_tag_buffer;

typedef union {
    struct {
    } request;
    struct {
        uint8_t board_mac_address[6];
    } response;
} hardware_get_board_mac_address_tag_buffer;

typedef union {
    struct {
    } request;
    struct {
        uint64_t board_serial;
    } response;
} hardware_get_board_serial_tag_buffer;

typedef union {
    struct {
    } request;
    struct {
        uint32_t base_addr;
        uint32_t size;
    } response;
} hardware_get_arm_memory_tag_buffer;

typedef union {
    struct {
    } request;
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

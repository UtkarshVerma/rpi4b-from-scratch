#pragma once

#include <stdint.h>

typedef union {
    struct {
    } request;
    struct {
        const volatile uint32_t board_model;
    } response;
} hardware_get_board_model_buffer;

typedef union {
    struct {
    } request;
    struct {
        const volatile uint32_t board_revision;
    } response;
} hardware_get_board_revision_buffer;

typedef union {
    struct {
    } request;
    struct {
        const volatile uint8_t board_mac_address[6];
    } response;
} hardware_get_board_mac_address_buffer;

typedef union {
    struct {
    } request;
    struct {
        const volatile uint64_t board_serial;
    } response;
} hardware_get_board_serial_buffer;

typedef union {
    struct {
    } request;
    struct {
        const volatile uint32_t base_addr;
        const volatile uint32_t size;
    } response;
} hardware_get_arm_memory_buffer;

typedef union {
    struct {
    } request;
    struct {
        const volatile uint32_t base_addr;
        const volatile uint32_t size;
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

typedef union {
    hardware_get_board_model_buffer get_board_model;
    hardware_get_board_revision_buffer get_board_revision;
    hardware_get_board_mac_address_buffer get_board_mac_address;
    hardware_get_board_serial_buffer get_board_serial;
    hardware_get_arm_memory_buffer get_arm_memory;
    hardware_get_vc_memory_buffer get_vc_memory;
} hardware_tag_buffer;

#include "../tags.h"

typedef enum {
    HARDWARE_GET_BOARD_MODEL = HARDWARE_TAG_BASE,
    HARDWARE_GET_BOARD_REVISION,
    HARDWARE_GET_BOARD_MAC_ADDRESS,
    HARDWARE_GET_BOARD_SERIAL,
    HARDWARE_GET_ARM_MEMORY,
    HARDWARE_GET_VC_MEMORY,
    HARDWARE_GET_CLOCKS,

    HARDWARE_TAG_END
} hardware_tag;

#define HARDWARE_TAG_COUNT (HARDWARE_TAG_END - HARDWARE_TAG_BASE)

extern const tag_metadata hardware_tag_metadata[HARDWARE_TAG_COUNT];

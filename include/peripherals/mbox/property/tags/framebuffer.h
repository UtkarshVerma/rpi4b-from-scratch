#pragma once

#include <stdint.h>

#define FRAMEBUFFER_TAGS                                                      \
    TAG(FRAMEBUFFER_ALLOCATE_BUFFER, framebuffer_allocate_buffer, 0x00040001) \
    TAG(FRAMEBUFFER_RELEASE_BUFFER, framebuffer_release_buffer, 0x000480001)  \
    TAG(FRAMEBUFFER_BLANK_SCREEN, framebuffer_blank_screen, 0x00040002)       \
    TAG(FRAMEBUFFER_GET_PHYSICAL_DIMENSIONS,                                  \
        framebuffer_get_physical_dimensions, 0x00040003)                      \
    TAG(FRAMEBUFFER_TEST_PHYSICAL_DIMENSIONS,                                 \
        framebuffer_test_physical_dimensions, 0x00044003)                     \
    TAG(FRAMEBUFFER_SET_PHYSICAL_DIMENSIONS,                                  \
        framebuffer_set_physical_dimensions, 0x00048003)                      \
    TAG(FRAMEBUFFER_GET_VIRTUAL_DIMENSIONS,                                   \
        framebuffer_get_virtual_dimensions, 0x00040004)                       \
    TAG(FRAMEBUFFER_TEST_VIRTUAL_DIMENSIONS,                                  \
        framebuffer_test_virtual_dimensions, 0x00044004)                      \
    TAG(FRAMEBUFFER_SET_VIRTUAL_DIMENSIONS,                                   \
        framebuffer_set_virtual_dimensions, 0x00048004)                       \
    TAG(FRAMEBUFFER_GET_DEPTH, framebuffer_get_depth, 0x00040005)             \
    TAG(FRAMEBUFFER_TEST_DEPTH, framebuffer_test_depth, 0x00044005)           \
    TAG(FRAMEBUFFER_SET_DEPTH, framebuffer_set_depth, 0x00048005)             \
    TAG(FRAMEBUFFER_GET_PIXEL_ORDER, framebuffer_get_pixel_order, 0x00040006) \
    TAG(FRAMEBUFFER_TEST_PIXEL_ORDER, framebuffer_test_pixel_order,           \
        0x00044006)                                                           \
    TAG(FRAMEBUFFER_SET_PIXEL_ORDER, framebuffer_set_pixel_order, 0x00048006) \
    TAG(FRAMEBUFFER_GET_ALPHA_MODE, framebuffer_get_alpha_mode, 0x00040007)   \
    TAG(FRAMEBUFFER_TEST_ALPHA_MODE, framebuffer_test_alpha_mode, 0x00044007) \
    TAG(FRAMEBUFFER_SET_ALPHA_MODE, framebuffer_set_alpha_mode, 0x00048007)   \
    TAG(FRAMEBUFFER_GET_PITCH, framebuffer_get_pitch, 0x00040008)             \
    TAG(FRAMEBUFFER_GET_VIRTUAL_OFFSET, framebuffer_get_virtual_offset,       \
        0x00040009)                                                           \
    TAG(FRAMEBUFFER_TEST_VIRTUAL_OFFSET, framebuffer_test_virtual_offset,     \
        0x00044009)                                                           \
    TAG(FRAMEBUFFER_SET_VIRTUAL_OFFSET, framebuffer_set_virtual_offset,       \
        0x00048009)                                                           \
    TAG(FRAMEBUFFER_GET_OVERSCAN, framebuffer_get_overscan, 0x0004000a)       \
    TAG(FRAMEBUFFER_TEST_OVERSCAN, framebuffer_test_overscan, 0x0004400a)     \
    TAG(FRAMEBUFFER_SET_OVERSCAN, framebuffer_set_overscan, 0x0004800a)       \
    TAG(FRAMEBUFFER_GET_PALETTE, framebuffer_get_palette, 0x0004000b)         \
    TAG(FRAMEBUFFER_TEST_PALETTE, framebuffer_test_palette, 0x0004400b)       \
    TAG(FRAMEBUFFER_SET_PALETTE, framebuffer_set_palette, 0x0004800b)         \
    TAG(FRAMEBUFFER_SET_CURSOR_INFO, framebuffer_set_cursor_info, 0x00008010) \
    TAG(FRAMEBUFFER_SET_CURSOR_STATE, framebuffer_set_cursor_state, 0x00008011)

typedef union {
    struct {
        uint32_t alignment;
    } request;
    struct {
        uint32_t base_address;
        uint32_t size;
    } response;
} framebuffer_allocate_buffer_tag_buffer;

typedef union {
    struct {
    } request;
    struct {
    } response;
} framebuffer_release_buffer_tag_buffer;

typedef union {
    struct {
        uint32_t state;
    } request;
    struct {
        uint32_t state;
    } response;
} framebuffer_blank_screen_tag_buffer;

typedef union {
    struct {
    } request;
    struct {
        uint32_t width;
        uint32_t height;
    } response;
} framebuffer_get_physical_dimensions_tag_buffer;

typedef union {
    struct {
        uint32_t width;
        uint32_t height;
    } request;
    struct {
        uint32_t width;
        uint32_t height;
    } response;
} framebuffer_test_physical_dimensions_tag_buffer;

typedef union {
    struct {
        uint32_t width;
        uint32_t height;
    } request;
    struct {
        uint32_t width;
        uint32_t height;
    } response;
} framebuffer_set_physical_dimensions_tag_buffer;

typedef union {
    struct {
    } request;
    struct {
        uint32_t width;
        uint32_t height;
    } response;
} framebuffer_get_virtual_dimensions_tag_buffer;

typedef union {
    struct {
        uint32_t width;
        uint32_t height;
    } request;
    struct {
        uint32_t width;
        uint32_t height;
    } response;
} framebuffer_test_virtual_dimensions_tag_buffer;

typedef union {
    struct {
        uint32_t width;
        uint32_t height;
    } request;
    struct {
        uint32_t width;
        uint32_t height;
    } response;
} framebuffer_set_virtual_dimensions_tag_buffer;

typedef union {
    struct {
    } request;
    struct {
        uint32_t bits_per_pixel;
    } response;
} framebuffer_get_depth_tag_buffer;

typedef union {
    struct {
        uint32_t bits_per_pixel;
    } request;
    struct {
        uint32_t bits_per_pixel;
    } response;
} framebuffer_test_depth_tag_buffer;

typedef union {
    struct {
        uint32_t bits_per_pixel;
    } request;
    struct {
        uint32_t bits_per_pixel;
    } response;
} framebuffer_set_depth_tag_buffer;

typedef enum {
    BGR,
    RGB,
} pixel_order;

typedef union {
    struct {
    } request;
    struct {
        pixel_order state;
    } response;
} framebuffer_get_pixel_order_tag_buffer;

typedef union {
    struct {
        pixel_order state;
    } request;
    struct {
        pixel_order state;
    } response;
} framebuffer_test_pixel_order_tag_buffer;

typedef union {
    struct {
        pixel_order state;
    } request;
    struct {
        pixel_order state;
    } response;
} framebuffer_set_pixel_order_tag_buffer;

typedef enum {
    ALPHA_CHANNEL_ENABLED,
    ALPHA_CHANNEL_REVERSED,
    ALPHA_CHANNEL_IGNORED,
} alpha_mode;

typedef union {
    struct {
    } request;
    struct {
        alpha_mode state;
    } response;
} framebuffer_get_alpha_mode_tag_buffer;

typedef union {
    struct {
        alpha_mode state;
    } request;
    struct {
        alpha_mode state;
    } response;
} framebuffer_test_alpha_mode_tag_buffer;

typedef union {
    struct {
        alpha_mode state;
    } request;
    struct {
        alpha_mode state;
    } response;
} framebuffer_set_alpha_mode_tag_buffer;

typedef union {
    struct {
    } request;
    struct {
        uint32_t bytes_per_line;
    } response;
} framebuffer_get_pitch_tag_buffer;

typedef union {
    struct {
    } request;
    struct {
        uint32_t x;
        uint32_t y;
    } response;
} framebuffer_get_virtual_offset_tag_buffer;

typedef union {
    struct {
        uint32_t x;
        uint32_t y;
    } request;
    struct {
        uint32_t x;
        uint32_t y;
    } response;
} framebuffer_test_virtual_offset_tag_buffer;

typedef union {
    struct {
        uint32_t x;
        uint32_t y;
    } request;
    struct {
        uint32_t x;
        uint32_t y;
    } response;
} framebuffer_set_virtual_offset_tag_buffer;

typedef union {
    struct {
    } request;
    struct {
        uint32_t top;
        uint32_t bottom;
        uint32_t left;
        uint32_t right;
    } response;
} framebuffer_get_overscan_tag_buffer;

typedef union {
    struct {
        uint32_t top;
        uint32_t bottom;
        uint32_t left;
        uint32_t right;
    } request;
    struct {
        uint32_t top;
        uint32_t bottom;
        uint32_t left;
        uint32_t right;
    } response;
} framebuffer_test_overscan_tag_buffer;

typedef union {
    struct {
        uint32_t top;
        uint32_t bottom;
        uint32_t left;
        uint32_t right;
    } request;
    struct {
        uint32_t top;
        uint32_t bottom;
        uint32_t left;
        uint32_t right;
    } response;
} framebuffer_set_overscan_tag_buffer;

typedef union {
    struct {
    } request;
    struct {
        uint32_t palette[256];
    } response;
} framebuffer_get_palette_tag_buffer;

typedef enum {
    VALID,
    INVALID,
} validity;

// TODO: Think about dynamically sizing this
typedef union {
    struct {
        uint32_t offset;
        uint32_t length;

        // NOTE: It should be of size `length` but that's not a constexpr.
        uint32_t palette[256];
    } request;
    struct {
        validity validity;
    } response;
} framebuffer_test_palette_tag_buffer;

typedef union {
    struct {
        uint32_t offset;
        uint32_t length;
        uint32_t palette[256];
    } request;
    struct {
        validity validity;
    } response;
} framebuffer_set_palette_tag_buffer;

typedef union {
    struct {
        uint32_t width;
        uint32_t height;
        uint32_t unused;
        uint32_t pixels;
        uint32_t hotspot_x;
        uint32_t hotspot_y;
    } request;
    struct {
        validity validity;
    } response;
} framebuffer_set_cursor_info_tag_buffer;

typedef union {
    struct {
        uint32_t enable;
        uint32_t x;
        uint32_t y;
        uint32_t flags;
    } request;
    struct {
        validity validity;
    } response;
} framebuffer_set_cursor_state_tag_buffer;

#pragma once

#include <stdint.h>

#define FRAMEBUFFER_ALLOCATE_BUFFER_TAG \
    framebuffer_allocate_buffer_tag_buffer, 0x00040001
#define FRAMEBUFFER_RELEASE_BUFFER_TAG \
    framebuffer_release_buffer_tag_buffer, 0x000480001
#define FRAMEBUFFER_BLANK_SCREEN_TAG \
    framebuffer_blank_screen_tag_buffer, 0x00040002
#define FRAMEBUFFER_GET_PHYSICAL_DIMENSIONS_TAG \
    framebuffer_get_physical_dimensions_tag_buffer, 0x00040003
#define FRAMEBUFFER_TEST_PHYSICAL_DIMENSIONS_TAG \
    framebuffer_test_physical_dimensions_tag_buffer, 0x00044003
#define FRAMEBUFFER_SET_PHYSICAL_DIMENSIONS_TAG \
    framebuffer_set_physical_dimensions_tag_buffer, 0x00048003
#define FRAMEBUFFER_GET_VIRTUAL_DIMENSIONS_TAG \
    framebuffer_get_virtual_dimensions_tag_buffer, 0x00040004
#define FRAMEBUFFER_TEST_VIRTUAL_DIMENSIONS_TAG \
    framebuffer_test_virtual_dimensions_tag_buffer, 0x00044004
#define FRAMEBUFFER_SET_VIRTUAL_DIMENSIONS_TAG \
    framebuffer_set_virtual_dimensions_tag_buffer, 0x00048004
#define FRAMEBUFFER_GET_DEPTH_TAG framebuffer_get_depth_tag_buffer, 0x00040005
#define FRAMEBUFFER_TEST_DEPTH_TAG \
    framebuffer_test_depth_tag_buffer, 0x00044005
#define FRAMEBUFFER_SET_DEPTH_TAG framebuffer_set_depth_tag_buffer, 0x00048005
#define FRAMEBUFFER_GET_PIXEL_ORDER_TAG \
    framebuffer_get_pixel_order_tag_buffer, 0x00040006
#define FRAMEBUFFER_TEST_PIXEL_ORDER_TAG \
    framebuffer_test_pixel_order_tag_buffer, 0x00044006
#define FRAMEBUFFER_SET_PIXEL_ORDER_TAG \
    framebuffer_set_pixel_order_tag_buffer, 0x00048006
#define FRAMEBUFFER_GET_ALPHA_MODE_TAG \
    framebuffer_get_alpha_mode_tag_buffer, 0x00040007
#define FRAMEBUFFER_TEST_ALPHA_MODE_TAG \
    framebuffer_test_alpha_mode_tag_buffer, 0x00044007
#define FRAMEBUFFER_SET_ALPHA_MODE_TAG \
    framebuffer_set_alpha_mode_tag_buffer, 0x00048007
#define FRAMEBUFFER_GET_PITCH_TAG framebuffer_get_pitch_tag_buffer, 0x00040008
#define FRAMEBUFFER_GET_VIRTUAL_OFFSET_TAG \
    framebuffer_get_virtual_offset_tag_buffer, 0x00040009
#define FRAMEBUFFER_TEST_VIRTUAL_OFFSET_TAG \
    framebuffer_test_virtual_offset_tag_buffer, 0x00044009
#define FRAMEBUFFER_SET_VIRTUAL_OFFSET_TAG \
    framebuffer_set_virtual_offset_tag_buffer, 0x00048009
#define FRAMEBUFFER_GET_OVERSCAN_TAG \
    framebuffer_get_overscan_tag_buffer, 0x0004000a
#define FRAMEBUFFER_TEST_OVERSCAN_TAG \
    framebuffer_test_overscan_tag_buffer, 0x0004400a
#define FRAMEBUFFER_SET_OVERSCAN_TAG \
    framebuffer_set_overscan_tag_buffer, 0x0004800a
#define FRAMEBUFFER_GET_PALETTE_TAG \
    framebuffer_get_palette_tag_buffer, 0x0004000b
#define FRAMEBUFFER_TEST_PALETTE_TAG \
    framebuffer_test_palette_tag_buffer, 0x0004400b
#define FRAMEBUFFER_SET_PALETTE_TAG \
    framebuffer_set_palette_tag_buffer, 0x0004800b
#define FRAMEBUFFER_SET_CURSOR_INFO_TAG \
    framebuffer_set_cursor_info_tag_buffer, 0x00008010
#define FRAMEBUFFER_SET_CURSOR_STATE_TAG \
    framebuffer_set_cursor_state_tag_buffer, 0x00008011

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

        // NOTE: It should be of size `length` but that's not a
        // constexpr.
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

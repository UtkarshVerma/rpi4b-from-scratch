#include "peripherals/mbox/property/tags.h"

#include "uart.h"
#include "util.h"

#define TAG(enum, name, tag_id)                       \
    [enum] = {                                        \
        .id          = tag_id,                        \
        .buffer_size = MEMBER_SIZE(tag_buffer, name), \
    },
static const tag_metadata metadata[TAG_COUNT] = {TAGS};
#undef TAG

static char buf[100];

static char* itoa(uint32_t n) {
    char* c = buf + sizeof(buf) - 1;
    *c      = '\0';
    c--;
    *c = '\n';

    if (n == 0) {
        c--;
        *c = '0';
        return c;
    }

    while (n) {
        c--;
        *c = n % 10 + '0';
        n /= 10;
    }

    return c;
}

void tag_init(tag* t, tag_id tag) {
    if (tag >= ARRAY_SIZE(metadata))
        return;

    const tag_metadata* m = &metadata[tag];

    t->id          = m->id;
    t->buffer_size = m->buffer_size;
    // HACK: Without this UART delay, the previous assignment gets stuck for
    // some reason
    uart_write(UART1, itoa(m->buffer_size));
    t->status_code = 0;
}

#include "peripherals/mbox.h"

#include <stdint.h>

#include "mem.h"
#include "peripherals/mbox/property/message.h"

#define MBOX_READ         MEM_REG(MEM_MBOX_BASE + 0x00)
#define MBOX_STATUS       MEM_REG(MEM_MBOX_BASE + 0x18)
#define MBOX_STATUS_EMPTY (1 << 30)
#define MBOX_STATUS_FULL  (1 << 31)
#define MBOX_WRITE        MEM_REG(MEM_MBOX_BASE + 0x20)

#define MBOX_MESSAGE_CHANNEL_MASK 0xf
#define MBOX_MESSAGE_DATA_MASK    ~MBOX_MESSAGE_CHANNEL_MASK

static unsigned int mbox_read(mbox_channel channel) {
    while (1) {
        // Wait until there is data to be read
        while (MBOX_STATUS & MBOX_STATUS_EMPTY)
            ;

        // Verify that the received data is for the requested channel
        unsigned int message = MBOX_READ;
        if ((message & MBOX_MESSAGE_CHANNEL_MASK) == channel)
            return message & MBOX_MESSAGE_DATA_MASK;
    }
}

static void mbox_write(mbox_channel channel, void* buffer) {
    // Wait until the mailbox is empty
    while (MBOX_STATUS & MBOX_STATUS_FULL)
        ;

    mem_reg message = (uintptr_t)buffer & MBOX_MESSAGE_DATA_MASK;
    message |= channel & MBOX_MESSAGE_CHANNEL_MASK;
    MBOX_WRITE = message;
}

int mbox_call(mbox_channel channel, void* buffer) {
    mbox_write(channel, buffer);
    (void)mbox_read(channel);

    switch (channel) {
        case PROPERTY_TAGS_ARM_TO_VC:
            return mbox_property_message_is_successful(buffer);
    }

    return 0;
}

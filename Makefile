.POSIX:

TARGET := kernel8
BUILD_DIR := build
SRC_DIR := src
INC_DIR := include
LDFILE := link.ld

VERBOSE := 0

# -----------------------------------------------------------------------------

CROSS_COMPILE := aarch64-linux-gnu
AS := $(CROSS_COMPILE)-as
AR := $(CROSS_COMPILE)-ar
CC := $(CROSS_COMPILE)-gcc
LD := $(CROSS_COMPILE)-ld
OBJCOPY := $(CROSS_COMPILE)-objcopy
OBJDUMP := $(CROSS_COMPILE)-objdump
SIZE := $(CROSS_COMPILE)-size
GDB := $(CROSS_COMPILE)-gdb

CFLAGS := -O2 -I. -I$(INC_DIR)
CFLAGS += -Wall -Wextra -ffreestanding -fdata-sections -ffunction-sections
LDFLAGS := -nostdlib -nostartfiles -static
LDFLAGS += -Wl,--build-id=none,--gc-sections
LDFLAGS += -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,-T$(LDFILE)

VPATH := $(SRC_DIR)

S_SRCS := startup.s
S_OBJS += $(addprefix $(BUILD_DIR)/,$(S_SRCS:.s=.o))

C_SRCS := $(subst $(SRC_DIR)/,,$(wildcard $(SRC_DIR)/*.c))
C_OBJS := $(addprefix $(BUILD_DIR)/,$(C_SRCS:.c=.o))

# Prettify output
PRINTF := @printf "%-8s %s\n"
ifeq ($(VERBOSE), 0)
	Q := @
endif

# -----------------------------------------------------------------------------

all: $(BUILD_DIR)/$(TARGET).img

$(BUILD_DIR):
	$(PRINTF) "MKDIR" $@
	$Qmkdir -p $@

$(S_OBJS): $(BUILD_DIR)/%.o: %.s | $(BUILD_DIR)
	$(PRINTF) "AS" $@
	$Q$(COMPILE.s) -o $@ $<

$(C_OBJS): $(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(PRINTF) "CC" $@
	$Q$(COMPILE.c) -o $@ $<

$(BUILD_DIR)/$(TARGET).elf: $(C_OBJS) $(S_OBJS)
	$(PRINTF) "LD" $@
	$Q$(LINK.o) $^ $(LDLIBS) -o $@
	$(PRINTF) "OBJDUMP" $(BUILD_DIR)/$(TARGET).lst
	$Q$(OBJDUMP) -St $@ >$(BUILD_DIR)/$(TARGET).lst
	$(PRINTF) "SIZE" $@
	$Q$(SIZE) $@

$(BUILD_DIR)/$(TARGET).img: $(BUILD_DIR)/$(TARGET).elf
	$(PRINTF) "OBJCOPY" $@
	$Q$(OBJCOPY) -O binary $< $@

clean:
	$(PRINTF) "CLEAN" $(BUILD_DIR)
	$Q$(RM) $(BUILD_DIR)/*

.PHONY: all clean

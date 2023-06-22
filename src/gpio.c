#include "gpio.h"

#include "memory.h"

#define GPIO_MAX_PIN 53

typedef enum {
    GPFSEL0                = MMIO_REG_ADDR(GPIO, 0x00),
    GPSET0                 = MMIO_REG_ADDR(GPIO, 0x1c),
    GPCLR0                 = MMIO_REG_ADDR(GPIO, 0x28),
    GPIO_PUP_PDN_CTRL_REG0 = MMIO_REG_ADDR(GPIO, 0xe4),
} gpio_reg;

typedef unsigned int gpio_reg_value;

static int gpio_set_reg(gpio_reg base_reg, unsigned int pin,
                        gpio_reg_value value, unsigned int field_size) {
    if (pin > GPIO_MAX_PIN) return 1;

    unsigned int field_mask = (1 << field_size) - 1;
    if (value > field_mask) return 1;

    // GPIO registers are uniformly subdivided
    unsigned int n_fields = sizeof(gpio_reg_value) * 8 / field_size;

    // Registers are sequentially mapped for each `n_field` GPIOs
    gpio_reg reg       = base_reg + (pin / n_fields) * sizeof(gpio_reg_value);
    unsigned int shift = (pin % n_fields) * field_size;

    unsigned int tmp = MEM_REG_VALUE(reg);
    tmp &= ~(field_mask << shift);  // Clear the field
    tmp |= value << shift;          // Set value to the field
    MEM_REG_VALUE(reg) = tmp;

    return 0;
}

int gpio_set_function(unsigned int pin, gpio_function value) {
    return gpio_set_reg(GPFSEL0, pin, value, 3);
}

int gpio_clear_pin(unsigned int pin) {
    return gpio_set_reg(GPCLR0, pin, 1, 1);
}

int gpio_set_pin(unsigned int pin) {
    return gpio_set_reg(GPSET0, pin, 1, 1);
}

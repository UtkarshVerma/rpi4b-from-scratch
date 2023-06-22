#pragma once

typedef enum {
    GPIO_INPUT,
    GPIO_OUTPUT,
    GPIO_AF5,
    GPIO_AF4,
    GPIO_AF0,
    GPIO_AF1,
    GPIO_AF2,
    GPIO_AF3,
} gpio_function;

int gpio_set_function(unsigned int pin, gpio_function value);
int gpio_set_pin(unsigned int pin);
int gpio_clear_pin(unsigned int pin);

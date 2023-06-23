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

typedef enum {
    GPIO_PULL_NONE,
    GPIO_PULL_UP,
    GPIO_PULL_DOWN,
} gpio_pull;

int gpio_set_pull(unsigned int pin, gpio_pull value);
int gpio_set_function(unsigned int pin, gpio_function value);
int gpio_set_pin(unsigned int pin);
int gpio_clear_pin(unsigned int pin);

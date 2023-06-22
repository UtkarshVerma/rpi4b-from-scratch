#include "gpio.h"

#define LED_GPIO 18

// Bust wait delay
void delay() {
    volatile int i = 0;
    while (i < 0x80000) i++;
}

void main() {
    gpio_set_function(LED_GPIO, GPIO_OUTPUT);

    while (1) {
        gpio_set_pin(LED_GPIO);
        delay();
        gpio_clear_pin(LED_GPIO);
        delay();
    }
}

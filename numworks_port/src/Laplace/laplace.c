#include "laplace.h"

void laplace_init(){
    // Enable the GPIO peripheral in RCC.
    enable_gpio_x_rcc(GPIO_B);
    led_init();
    //col (in)
    enable_gpio_x_rcc(GPIO_C);
    //row (out)
    enable_gpio_x_rcc(GPIO_A);
    keyboard_init();
}
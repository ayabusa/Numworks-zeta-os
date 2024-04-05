#include "laplace.h"

/* Initialize all needed peripherals, should be called early in your program */
void laplace_init(){
    /* led init */
    enable_gpio_x_rcc(GPIO_B);
    led_init();

    /* keyboard init */
    enable_gpio_x_rcc(GPIO_C); //column (in)
    enable_gpio_x_rcc(GPIO_A); //row (out)
    keyboard_init();
}
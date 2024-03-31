/** @file gpio_helper.h
 * 
 * @brief Control all the GPIO
 *
 */ 

#ifndef GPIO_HELPER_H
#define GPIO_HELPER_H

#include "stdbool.h"
#include "../device/stm32f730xx.h"

#define GPIO_A 0
#define GPIO_B 1
#define GPIO_C 2
#define GPIO_D 3
#define GPIO_E 4

void set_output_pin(uint8_t gpio_x, uint8_t pin, bool state);
void enable_gpio_x_rcc(uint8_t gpio_x);

#endif
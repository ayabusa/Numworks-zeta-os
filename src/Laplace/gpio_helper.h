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

/* Set a pin High (true) or Low (false) ie:
   set_output_pin(GPIO_B, 2, true);
   this sets the pin B2 to high */
void set_output_pin(uint8_t gpio_x, uint8_t pin, bool state);

/* Read the value of an input pin, it returns High (true) or Low (false) ie:
   bool state = read_input_pin(GPIO_C, 3);
   This stores the state of the pin C3 */
bool read_input_pin(uint8_t gpio_x, uint8_t pin);

/* Enable the specified GPIO */
void enable_gpio_x_rcc(uint8_t gpio_x);

#endif
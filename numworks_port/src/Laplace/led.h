/** @file led.h
 * 
 * @brief Control the led
 *
 */ 

#ifndef LED_H
#define LED_H

#define RED_LED_PIN    (4)
#define GREEN_LED_PIN  (5)
#define BLUE_LED_PIN  (0)

#include <stdbool.h>
#include "../device/stm32f730xx.h"
#include "gpio_helper.h"

void led_init();
void set_led_red(bool state);
void set_led_green(bool state);
void set_led_blue(bool state);
void set_led_all(bool state);

#endif
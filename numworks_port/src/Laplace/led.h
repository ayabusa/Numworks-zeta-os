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

/* This should be called before accessing any other led related feature
   as it sets up all led related peripherals */
void led_init();

/* Set the status of the red led
   true  -> ON
   false -> OFF */
void set_led_red(bool state);

/* Set the status of the green led
   true  -> ON
   false -> OFF */
void set_led_green(bool state);

/* Set the status of the blue led
   true  -> ON
   false -> OFF */
void set_led_blue(bool state);

/* Set the status of all 3 leds at the same time
   true  -> ON
   false -> OFF */
void set_led_all(bool state);

#endif
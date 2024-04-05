#include "led.h"

// GPIOB for all the leds
uint8_t gpio_b = GPIO_B;

/* This should be called before accessing any other led related feature
   as it sets up all led related peripherals */
void led_init(){
    // It should be set to push-pull low-speed output.

    // setup red led
    GPIOB->MODER  &= ~(0x3 << (RED_LED_PIN*2));
    GPIOB->MODER  |=  (0x1 << (RED_LED_PIN*2));
    GPIOB->OTYPER &= ~(1 << RED_LED_PIN);

    // setup green led
    GPIOB->MODER  &= ~(0x3 << (GREEN_LED_PIN*2));
    GPIOB->MODER  |=  (0x1 << (GREEN_LED_PIN*2));
    GPIOB->OTYPER &= ~(1 << GREEN_LED_PIN);

    // setup blue led
    GPIOB->MODER  &= ~(0x3 << (BLUE_LED_PIN*2));
    GPIOB->MODER  |=  (0x1 << (BLUE_LED_PIN*2));
    GPIOB->OTYPER &= ~(1 << BLUE_LED_PIN);
}

/* Set the status of the red led
   true  -> ON
   false -> OFF */
void set_led_red(bool state){
    set_output_pin(gpio_b, RED_LED_PIN, state);
}

/* Set the status of the green led
   true  -> ON
   false -> OFF */
void set_led_green(bool state){
    set_output_pin(gpio_b, GREEN_LED_PIN, state);
}

/* Set the status of the blue led
   true  -> ON
   false -> OFF */
void set_led_blue(bool state){
    set_output_pin(gpio_b, BLUE_LED_PIN, state);
}

/* Set the status of all 3 leds at the same time
   true  -> ON
   false -> OFF */
void set_led_all(bool state){
    set_output_pin(gpio_b, RED_LED_PIN, state);
    set_output_pin(gpio_b, GREEN_LED_PIN, state);
    set_output_pin(gpio_b, BLUE_LED_PIN, state);
}
#include "led.h"

// Variable to store the current state of LEDs
uint8_t led_state = 0;

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

void set_led_red(bool state){
    if(state){
        led_state |= (1 << RED_LED_PIN);
    }else{
        led_state &= ~(1 << RED_LED_PIN);
    }
    GPIOB->ODR = led_state;
}

void set_led_green(bool state){
    if(state){
        led_state |= (1 << GREEN_LED_PIN);
    }else{
        led_state &= ~(1 << GREEN_LED_PIN);
    }
    GPIOB->ODR = led_state;
}

void set_led_blue(bool state){
    if(state){
        led_state |= (1 << BLUE_LED_PIN);
    }else{
        led_state &= ~(1 << BLUE_LED_PIN);
    }
    GPIOB->ODR = led_state;
}

void set_led_all(bool state){
    if(state){
        led_state = (1 << RED_LED_PIN) | (1 << GREEN_LED_PIN) | (1 << BLUE_LED_PIN);
    }else{
        led_state = 0;
    }
    GPIOB->ODR = led_state;
}
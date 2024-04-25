/** @file keyboard.h
 * 
 * @brief All action related to keyboard scan
 *
 */ 

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "gpio_helper.h"
#include "time.h"

struct button{
	uint8_t column; // ie: 2
	char row; // ie: 'A'
	bool state; // true is pressed and false released
};

/* This should be called before accessing any other keyboard related feature
   as it sets up all keyboard related peripherals */
void keyboard_init();

/* Scans the current state of the keyboard and returns an array of buttons struct
   You can find the button struct definition in keyboard.h */
struct button* keyboard_scan();

/* Scans the specified key and return true if pressed 
   It's more performant that scanning the whole keyboard */
bool get_key(char row, uint8_t column);

#endif
/** @file keyboard.h
 * 
 * @brief All action related to keyboard scan
 *
 */ 

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "gpio_helper.h"

struct button{
	uint8_t column;
	char row;
	bool state;
};


void keyboard_init();
struct button* keyboard_scan();

#endif
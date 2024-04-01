/** @file keyboard.h
 * 
 * @brief All action related to keyboard scan
 *
 */ 

#ifndef KEYBOARD_H
#define KEYBOARD_H

enum PIN_ROW {
	A = 1,
	B = 0,
	C = 2,
    D = 3,
	E = 4,
	F = 5,
    G = 6,
	H = 7,
	I = 8
};

#include "gpio_helper.h"

void keyboard_init();
bool keyboard_scan();

#endif
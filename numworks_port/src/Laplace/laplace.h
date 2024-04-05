/** @file laplace.h
 * 
 * @brief Global function of Laplace
 *
 */ 

#ifndef LAPLACE_H
#define LAPLACE_H

#include "gpio_helper.h"
#include "led.h"
#include "keyboard.h"

/* Initialize all needed peripherals, should be called early in your program */
void laplace_init();

#endif
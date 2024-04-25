/** @file lcd.h
 * 
 * @brief Control the lcd
 *
 */ 

#ifndef LCD_H
#define LCD_H

#include <stdint.h>
#include "../device/stm32f730xx.h"

uint16_t volatile * const COMMAND_ADDRESS = (uint16_t *) 0x60000000;
uint16_t volatile * const DATA_ADDRESS = (uint16_t *) 0x60020000;
// to set them use : *COMMAND_ADDRESS = 0x1234;

// define the differents command
#define NOP 0x00
#define RESET 0x01
#define READ_DISPLAY_ID 0x04
#define SLEEP_IN 0x10
#define SLEEP_OUT 0x11
#define DISPLAY_INVERSION_OFF 0x20
#define DISPLAY_INVERSION_ON 0x21
#define DISPLAY_OFF 0x28
#define DISPLAY_ON 0x29
#define COLUMN_ADDRESS_SET 0x2A
#define PAGE_ADDRESS_SET 0x2B
#define MEMORY_WRITE 0x2C
#define MEMORY_READ 0x2E
#define TEARING_EFFECT_LINE_ON 0x35
#define MEMORY_ACCESS_CONTROL 0x36
#define PIXEL_FORMAT_SET 0x3A
#define FRAME_RATE_CONTROL 0xC6
#define POSITIVE_VOLTAGE_GAMMA_CONTROL 0xE0
#define NEGATIVE_VOLTAGE_GAMMA_CONTROL 0xE1

void lcd_init();

#endif
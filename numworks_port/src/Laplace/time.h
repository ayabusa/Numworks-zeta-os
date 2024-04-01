/** @file time.h
 * 
 * @brief Handle timer operation
 *
 */ 

#ifndef TIME_H
#define TIME_H

#define loops_per_microsecond 1
#define loops_per_millisecond 960

#include "stdint.h"

void us_wait(uint8_t micro_seconds);
void ms_wait(uint16_t milli_seconds);

#endif
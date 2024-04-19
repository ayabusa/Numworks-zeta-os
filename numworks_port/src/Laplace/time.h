/** @file time.h
 * 
 * @brief Handle timer operation
 *
 */ 

#ifndef TIME_H
#define TIME_H

#define loops_per_microsecond 1
#define loops_per_millisecond 12000

#include "stdint.h"

/* Pause the os for x micro seconds */
void us_wait(uint8_t micro_seconds);
/* Pause the os for x milli seconds */
void ms_wait(uint16_t milli_seconds);

#endif
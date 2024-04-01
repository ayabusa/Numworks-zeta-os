#include "time.h"

void us_wait(uint8_t micro_seconds) {
  for (volatile uint32_t i=0; i<loops_per_microsecond*micro_seconds; i++) {
    __asm volatile("nop");
  }
}

void ms_wait(uint16_t milli_seconds) {
  for (volatile uint32_t i=0; i<loops_per_millisecond*milli_seconds; i++) {
    __asm volatile("nop");
  }
}
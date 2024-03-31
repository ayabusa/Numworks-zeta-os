#include "vector_table.h"
#include <stddef.h>
#include <stdint.h>
#include "device/stm32f730xx.h"

#define LED_PIN    (4) // PC0

typedef void (*cxx_constructor)();

extern "C" {
  extern char _data_section_start_flash;
  extern char _data_section_start_ram;
  extern char _data_section_end_ram;
  extern char _bss_section_start_ram;
  extern char _bss_section_end_ram;
  extern cxx_constructor _init_array_start;
  extern cxx_constructor _init_array_end;
}


void* memcpy_custom(void* destination, const void* source, size_t num_bytes) {
    char* dest_ptr = (char*)destination;
    const char* src_ptr = (const char*)source;

    // Copy each byte from source to destination
    for (size_t i = 0; i < num_bytes; ++i) {
        dest_ptr[i] = src_ptr[i];
    }

    return destination;
}

void* memset_custom(void* ptr, int value, size_t num_bytes) {
    unsigned char* p = (unsigned char*)ptr;
    unsigned char v = (unsigned char)value;

    // Set each byte in the memory block to the specified value
    for (size_t i = 0; i < num_bytes; ++i) {
        p[i] = v;
    }

    return ptr;
}

void __attribute__((noinline)) start() {
    /* Copy data section to RAM
  * The data section is R/W but its initialization value matters. It's stored
  * in Flash, but linked as if it were in RAM. Now's our opportunity to copy
  * it. Note that until then the data section (e.g. global variables) contains
  * garbage values and should not be used. */
  size_t dataSectionLength = (&_data_section_end_ram - &_data_section_start_ram);
  memcpy_custom(&_data_section_start_ram, &_data_section_start_flash, dataSectionLength);

  /* Zero-out the bss section in RAM
  * Until we do, any uninitialized global variable will be unusable. */
  size_t bssSectionLength = (&_bss_section_end_ram - &_bss_section_start_ram);
  memset_custom(&_bss_section_start_ram, 0, bssSectionLength);

  // Enable the GPIOa and GPIOC peripheral in RCC.
  RCC->AHB1ENR   |= RCC_AHB1ENR_GPIOBEN ;

  // C0 is connected to the LED.
  // It should be set to push-pull low-speed output.
  GPIOB->MODER  &= ~(0x3 << (LED_PIN*2));
  GPIOB->MODER  |=  (0x1 << (LED_PIN*2));
  GPIOB->OTYPER &= ~(1 << LED_PIN);

  GPIOB->ODR = (1 << LED_PIN);

  while (0)
  {
    GPIOB->ODR = (1 << LED_PIN);
  }
}
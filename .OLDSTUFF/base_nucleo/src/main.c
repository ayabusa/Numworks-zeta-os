#include "main.h"

/**
 * Main program.
 */
int main(void) {
  // Enable the GPIOa and GPIOC peripheral in RCC.
  RCC->AHB1ENR   |= RCC_AHB1ENR_GPIOAEN ;
  RCC->AHB1ENR   |= RCC_AHB1ENR_GPIOCEN ;

  // Initialize the GPIOC pins.
  // C15 should be set to 'input' mode with pull-up.
  GPIOC->MODER  &= ~(0x3 << (BUTTON_PIN*2));
  GPIOC->PUPDR  &= ~(0x3 << (BUTTON_PIN*2));
  GPIOC->PUPDR  |=  (0x1 << (BUTTON_PIN*2));

  // A5 is connected to an LED on the 'Nucleo' board.
  // It should be set to push-pull low-speed output.
  GPIOA->MODER  &= ~(0x3 << (LED_PIN*2));
  GPIOA->MODER  |=  (0x1 << (LED_PIN*2));
  GPIOA->OTYPER &= ~(1 << LED_PIN);

  // Main loop
  while (1){
    // Invert the IDR register since '0' means 'pressed'.
    uint32_t idr_val = ~GPIOC->IDR;
    if (idr_val & (1 << BUTTON_PIN)) {
      GPIOA->ODR = (1 << LED_PIN);
    }
    else {
      GPIOA->ODR = (0 << LED_PIN);
    }
  }
}
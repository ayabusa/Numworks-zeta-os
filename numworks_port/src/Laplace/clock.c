#include "clock.h"

/* This should set the speed to 216MHz intead of just 48MHz */
void init_clock(){
    // ACR means flash Access control register
    FLASH->ACR |=  (FLASH_ACR_LATENCY_7WS | // 7 wait states
                  FLASH_ACR_PRFTEN |        // prefetch on
                  FLASH_ACR_ARTEN);         // ART on

    // enables HSE and wait for it to be ready
    RCC->CR    |=  (RCC_CR_HSEON);
    while (!(RCC->CR & RCC_CR_HSERDY)) {};

    // clear the specified bit

    // (8/4)*108 = 216MHz
    /*
    RCC->PLLCFGR  |=  (RCC_PLLCFGR_PLLSRC_HSE | // HSE: 8MHz
                  RCC_PLLCFGR_PLLN_108 |        // *108
                  RCC_PLLCFGR_PLLM_25);          // /4
    */
    RCC->PLLCFGR  =  0b00001000010000100110000000001000; // HSE: 8MHz*/

    // enable the RCC clock and wait for it to be ready
    RCC->CR    |=  (RCC_CR_PLLON);
    while (!(RCC->CR & RCC_CR_PLLRDY)) {};

    // set it as the system clock source
    RCC->CFGR  &= ~(RCC_CFGR_SW);
    RCC->CFGR  |=  (RCC_CFGR_SW_PLL);
    while (!(RCC->CFGR & RCC_CFGR_SWS_PLL)) {};
}
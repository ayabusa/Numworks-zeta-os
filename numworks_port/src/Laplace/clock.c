#include "clock.h"

/* This should set the speed to 216MHz intead of just 48MHz */
void init_clock(){
    // Enable the HSI and wait for it to be ready to use
    RCC->CR    |=  (RCC_CR_HSION);
    while (!(RCC->CR & RCC_CR_HSIRDY)) {};

    // Enable the HSE and wait for it to be ready to use
    RCC->CR    |=  (RCC_CR_HSEON);
    while (!(RCC->CR & RCC_CR_HSERDY)) {};

    // enable power interface clock
    RCC->APB1ENR |= (RCC_APB1ENR_PWREN);

    // SSGR stuf, paragraph taken from upsilon
    /* To pass electromagnetic compatibility tests, we activate the Spread
    * Spectrum clock generation, which adds jitter to the PLL clock in order to
    * "lower peak-energy on the central frequency" and its harmonics.
    * It must be done before enabling the PLL. */
   /* Modper = 250
    * Incstep = 25
    * SpreadSel = 0
    * SSCGEN = 1 */
    RCC->SSCGR = 0b10000000000000110010000011111010;

    // clear PLL_M, PLL_N ,PLL_Q and PLLSRC in PLLCFGR
    RCC->PLLCFGR &= ~(0b00001111010000000111111111111111);
    // Set the specified value to PLLCFGR
    /* PLL_M = 8 = 0b1000
     * PLL_N = 384 = 0b110000000
     * PLL_Q = 8 = 0b1000
     * PLL_SRC = HSE = 1 */
    RCC->PLLCFGR |= 0b00001000010000000110000000001000;

    // Now we can enable PLL
    RCC->CR |= RCC_CR_PLLON;

    // Enable Overdrive (idk what it is) and wait
    PWR->CR1 |= PWR_CR1_ODEN;
    while (!(PWR->CSR1 & PWR_CSR1_ODRDY)) {};
    // Same for ODSWEN
    PWR->CR1 |= PWR_CR1_ODSWEN;
    while (!(PWR->CSR1 & PWR_CSR1_ODSWRDY)) {};

    // Select voltage scale (scale 1 = 0b11)
    PWR->CR1 |= 0b00000000000000001100000000000000;
    while (!(PWR->CSR1 & PWR_CSR1_VOSRDY)) {};

    // Set Latency to 7 wait state (paragraph from Upsilon)
    // Enable Prefetching, and ART
    /* After reset the Flash runs as fast as the CPU. When we clock the CPU faster
     * the flash memory cannot follow and therefore flash memory accesses need to
     * wait a little bit.
     * The spec tells us that at 2.8V and over 210MHz the flash expects 7 WS. */
    // clear in first place
    FLASH->ACR &= ~(0b0000 0000 0000 0000
                      0000 0011 0000 1111);
}

/* OLD
// ACR means flash Access control register
    FLASH->ACR |=  (FLASH_ACR_LATENCY_7WS | // 7 wait states
                  FLASH_ACR_PRFTEN |        // prefetch on
                  FLASH_ACR_ARTEN);         // ART on
    
    FLASH->ACR &= ~(0b00000000000000000000101100001111);
    
    // enables HSE and wait for it to be ready
    RCC->CR    |=  (RCC_CR_HSEON);
    while (!(RCC->CR & RCC_CR_HSERDY)) {};

    // clear the specified bit

    // (8/4)*108 = 216MHz
    RCC->PLLCFGR  |=  (RCC_PLLCFGR_PLLSRC_HSE | // HSE: 8MHz
                  RCC_PLLCFGR_PLLN_108 |        // *108
                  RCC_PLLCFGR_PLLM_25);          // /4
    RCC->PLLCFGR  =  0b00001000010000100110000000001000; // HSE: 8MHz

    // enable the RCC clock and wait for it to be ready
    RCC->CR    |=  (RCC_CR_PLLON);
    while (!(RCC->CR & RCC_CR_PLLRDY)) {};

    // set it as the system clock source
    RCC->CFGR  &= ~(RCC_CFGR_SW);
    RCC->CFGR  |=  (RCC_CFGR_SW_PLL);
    while (!(RCC->CFGR & RCC_CFGR_SWS_PLL)) {};
*/
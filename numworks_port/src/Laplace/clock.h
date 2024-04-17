/** @file clock.h
 * 
 * @brief Handle clock init and all
 *
 */ 

#ifndef CLOCK_H
#define CLOCK_H

#include "stdint.h"
#include "../device/stm32f730xx.h"

#define PLL_N 384
#define PLL_M 8
#define PLL_P 2
#define PLL_Q 8

/*
RCC->PLLCFGR  |=  0b00001000010000100110000000001000; // HSE: 8MHz*/
    //0b0000/*<-null*/1000/*<-PLLQ*/0/*<-null*/1/*<-PLLPSRC(HSE)*/0000/*<-null*/10/*<-PLLP*/0/*<-null*/110000000/*<-PLLN*/001000/*<-PLLM*/


void init_clock();

#endif
/** @file clock.h
 * 
 * @brief Handle clock init and all
 *
 */ 

#ifndef CLOCK_H
#define CLOCK_H

#include "../device/stm32f730xx.h"
#include "stdint.h"
#include "led.h"

/*
RCC->PLLCFGR  |=  0b00001000010000100110000000001000; // HSE: 8MHz*/
    //0b0000/*<-null*/1000/*<-PLLQ*/0/*<-null*/1/*<-PLLPSRC(HSE)*/0000/*<-null*/10/*<-PLLP*/0/*<-null*/110000000/*<-PLLN*/001000/*<-PLLM*/


void init_clock();

#endif
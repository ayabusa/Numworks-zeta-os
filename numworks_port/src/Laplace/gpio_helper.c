#include "gpio_helper.h"

uint8_t GPIOA_state = 0;
uint8_t GPIOB_state = 0;
uint8_t GPIOC_state = 0;
uint8_t GPIOD_state = 0;
uint8_t GPIOE_state = 0;

void set_output_pin(uint8_t gpio_x, uint8_t pin, bool state){
    switch (gpio_x)
    {
    case GPIO_A:
        if(state){
            GPIOA_state |= (1 << pin);
        }else{
            GPIOA_state &= ~(1 << pin);
        }  
        GPIOA->ODR = GPIOA_state;
        break;

    case GPIO_B:
        if(state){
            GPIOB_state |= (1 << pin);
        }else{
            GPIOB_state &= ~(1 << pin);
        }  
        GPIOB->ODR = GPIOB_state;
        break;

    case GPIO_C:
        if(state){
            GPIOC_state |= (1 << pin);
        }else{
            GPIOC_state &= ~(1 << pin);
        }  
        GPIOC->ODR = GPIOC_state;
        break;
    
    case GPIO_D:
        if(state){
            GPIOD_state |= (1 << pin);
        }else{
            GPIOD_state &= ~(1 << pin);
        }  
        GPIOD->ODR = GPIOD_state;
        break;

    case GPIO_E:
        if(state){
            GPIOE_state |= (1 << pin);
        }else{
            GPIOE_state &= ~(1 << pin);
        }  
        GPIOE->ODR = GPIOE_state;
        break;
    
    default:
        break;
    }
}

bool read_input_pin(uint8_t gpio_x, uint8_t pin){
    // Invert the IDR register since '0' means 'pressed'.
    uint8_t idr_val = 0;
    switch (gpio_x)
    {
    case GPIO_A:
        idr_val = ~GPIOA->IDR;
        break;
    case GPIO_B:
        idr_val = ~GPIOB->IDR;
        break;
    case GPIO_C:
        idr_val = ~GPIOC->IDR;
        break;
    case GPIO_D:
        idr_val = ~GPIOD->IDR;
        break;
    case GPIO_E:
        idr_val = ~GPIOE->IDR;
        break;
    
    default:
        break;
    }

    return idr_val & (1 << pin);
}

void enable_gpio_x_rcc(uint8_t gpio_x){
    switch (gpio_x)
    {
        case GPIO_A:
            RCC->AHB1ENR   |= RCC_AHB1ENR_GPIOAEN ;
            break;
        case GPIO_B:
            RCC->AHB1ENR   |= RCC_AHB1ENR_GPIOBEN ;
            break;
        case GPIO_C:
            RCC->AHB1ENR   |= RCC_AHB1ENR_GPIOCEN ;
            break;
        case GPIO_D:
            RCC->AHB1ENR   |= RCC_AHB1ENR_GPIODEN ;
            break;
        case GPIO_E:
            RCC->AHB1ENR   |= RCC_AHB1ENR_GPIOEEN ;
            break;
        
        default:
            break;
    }
}
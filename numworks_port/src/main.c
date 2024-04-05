#include "main.h"

// this is our main function, I separated it from the c++ code because I don't like this language
void main_entry(){
    // init all the peripherals
    laplace_init();
    ms_wait(2000);
    set_led_green(true);
    while (1)
    {
        struct button * keyboard_state = keyboard_scan();
        for(int i =0; i < 54; i++){
            if(keyboard_state[i].column == 4 && keyboard_state[i].row == 'H'){
                if(keyboard_state[i].state){
                    set_led_green(true);
                }else{
                    set_led_green(false);
                }
                break;
            }
        }
    }
    
}
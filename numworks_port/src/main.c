#include "main.h"

// this is our main function, I separated it from the c++ code because I don't like this language
void main_entry(){
    // init all the peripherals
    laplace_init();
    ms_wait(2000);
    set_led_green(true);
    while (1)
    {
        /*if(keyboard_scan()){
            set_led_green(true);
        }else{
            set_led_green(false);
        }*/
    }
    
}
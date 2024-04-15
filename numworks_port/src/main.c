#include "main.h"

// this is our main function, I separated it from the c++ code because I don't like this language
void main_entry(){
    // init all the peripherals
    laplace_init();
    ms_wait(2000);

    // infinite loop
    while (1){
        /*
        struct button * keyboard_state = keyboard_scan();
        
        for(int i =0; i < 54; i++){
            if(keyboard_state[i].column == 4 && keyboard_state[i].row == 'H'){
                if(keyboard_state[i].state){
                    set_led_blue(true);
                }else{
                    set_led_blue(false);
                }
            }
            if(keyboard_state[i].column == 3 && keyboard_state[i].row == 'H'){
                if(keyboard_state[i].state){
                    set_led_green(true);
                }else{
                    set_led_green(false);
                }
            }
        }*/

        if(get_key('G', 3)){
            set_led_red(true);
        }else{
            set_led_red(false);
        }
    }
    
}
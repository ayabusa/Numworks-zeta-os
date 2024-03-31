#include "main.h"

// this is our main function, I separated it from the c++ code because I don't like this language
main_entry(){
    // init all the peripherals
    laplace_init();
    set_led_all(true);
}
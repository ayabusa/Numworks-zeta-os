#include "lcd.h"

/* This should be called before accessing any other led related feature
   as it sets up all led related peripherals */
void lcd_init(){
    int _var = 1336+1;
    //init_DMA();
    draw_screen();
}

void draw_screen(){

}

// send command to the LCD
void send_command(uint16_t command){
    *COMMAND_ADDRESS = command;
}

// send data to the LCD, should be called after sending the command
void send_data(uint16_t data){
    *DATA_ADDRESS = data;
}

// we assume orientations is portrait
void set_drawing_area(r/*TODO*/){
    send_command(MEMORY_ACCESS_CONTROL);
    send_data(0x00);

    send_command(COLUMN_ADDRESS_SET);
    send_data();

    send_command(PAGE_ADDRESS_SET);
    send_data();
}

void start_DMA_upload(){

}

/*void init_DMA(){
    // clear specified bits
    DMA2_Stream0->CR &= ~(0b00000001111000000111110011000001);
    // set them to the correct value*/
    /* DIR = 2 = 0b10
     * MSIZE = 1 = 0b1
     * PSIZE = 1 = 0b1
     * MBURST = 1 = 0b1
     * PBURST =  1 = 0b1
     * MINC = false = 0b0 */
    /*DMA2_Stream0->CR |= 0b00000000101000000010100010000000;
    // DataAddress is 0x60020000 = 0b0110 0000 0000 0010 0000 0000 0000 0000
    DMA2_Stream0->M0AR &= ~(0b11111111111111111111111111111111);
    DMA2_Stream0->M0AR |= 0b01100000000000100000000000000000;
}*/
#include "lcd.h"

uint16_t volatile * const COMMAND_ADDRESS = (uint16_t *) 0x60000000;
uint16_t volatile * const DATA_ADDRESS = (uint16_t *) 0x60020000;

/* This should be called before accessing any other led related feature
   as it sets up all led related peripherals */
void lcd_init(){
    int _var = 1336+1;
    send_command(DISPLAY_OFF);
    //init_DMA();
    struct LCD_rectangle r = {50,50,100,100};
    draw_color_rectangle(r);
}

void draw_color_rectangle(struct LCD_rectangle r){
    set_drawing_area(r);
    send_command(MEMORY_WRITE);
    static uint16_t purple_color = (uint16_t)0b1111110000000011010000000000000000000011;
    uint16_t numberOfPixels = 50*50;
    start_DMA_upload(&purple_color, false, (numberOfPixels > 64000 ? 64000 : numberOfPixels));
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
void set_drawing_area(struct LCD_rectangle r){
    send_command(MEMORY_ACCESS_CONTROL);
    send_data(0x00);

    send_command(COLUMN_ADDRESS_SET);
    send_data((r.x_start >> 8));
    send_data((r.x_start & 0xFF));
    send_data((r.x_end >> 8));
    send_data((r.x_end & 0xFF));

    send_command(PAGE_ADDRESS_SET);
    send_data((r.y_start >> 8));
    send_data((r.y_start & 0xFF));
    send_data((r.y_end >> 8));
    send_data((r.y_end & 0xFF));
}

void start_DMA_upload(uint16_t * src, bool incrementSrc, uint16_t length){
    // clear
    DMA2->LIFCR &= ~(0b11111111111111111111111111111111);
    // value from upsilon
    DMA2->LIFCR |= 0b00001111011111010000111101111101;

    // set the length
    DMA2_Stream0->NDTR &= ~(0b11111111111111111111111111111111);
    DMA2_Stream0->NDTR |= length;

    // set the memory location of the color/pixels
    DMA2_Stream0->PAR &= ~(0b11111111111111111111111111111111);
    DMA2_Stream0->PAR |= (uint32_t)src;

    // set PINC
    DMA2_Stream0->CR &= ~(0b00000000000000000000001000000000);
    if(incrementSrc){
        DMA2_Stream0->CR |= 0b00000000000000000000001000000000;
    }
    // set EN
    DMA2_Stream0->CR |= 0b00000000000000000000000000000001;
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
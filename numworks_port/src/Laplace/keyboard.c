/* The keyboard is a matrix that is laid out as follow:
 * (K_B2 and K_B3 are respectively specific to N0100 and N0110
 *
 *      |  PC0 |  PC1 | PC2  | PC3  | PC4  | PC5  |
 * -----+------+------+------+------+------+------+
 *  PE0 | K_A1 | K_A2 | K_A3 | K_A4 | K_A5 | K_A6 |
 * -----+------+------+------+------+------+------+
 *  PE1 | K_B1 |(K_B2)|(K_B3)|      |      |      |
 * -----+------+------+------+------+------+------+
 *  PE2 | K_C1 | K_C2 | K_C3 | K_C4 | K_C5 | K_C6 |
 * -----+------+------+------+------+------+------+
 *  PE3 | K_D1 | K_D2 | K_D3 | K_D4 | K_D5 | K_D6 |
 * -----+------+------+------+------+------+------+
 *  PE4 | K_E1 | K_E2 | K_E3 | K_E4 | K_E5 | K_E6 |
 * -----+------+------+------+------+------+------+
 *  PE5 | K_F1 | K_F2 | K_F3 | K_F4 | K_F5 |      |
 * -----+------+------+------+------+------+------+
 *  PE6 | K_G1 | K_G2 | K_G3 | K_G4 | K_G5 |      |
 * -----+------+------+------+------+------+------+
 *  PE7 | K_H1 | K_H2 | K_H3 | K_H4 | K_H5 |      |
 * -----+------+------+------+------+------+------+
 *  PE8 | K_I1 | K_I2 | K_I3 | K_I4 | K_I5 |      |
 * -----+------+------+------+------+------+------|
 *
 *  We decide to drive the rows (PE0-8) and read the columns (PC0-5).
 *
 *  To avoid short-circuits, the pins E0-E8 will not be standard outputs but
 *  only open-drain. Open drain means the pin is either driven low or left
 *  floating.
 *  When a user presses multiple keys, a connection between two rows can happen.
 *  If we don't use open drain outputs, this situation could trigger a short
 *  circuit between an output driving high and another driving low.
 *
 *  If the outputs are open-drain, this means that the input must be pulled up.
 *  So if the input reads "1", this means the key is in fact *not* pressed, and
 *  if it reads "0" it means that there's a short to an open-drain output. Which
 *  means the corresponding key is pressed.
 */

#include "keyboard.h"

const uint8_t number_of_rows = 9;
const uint8_t number_of_columns = 6;
const char row_list[9] = {'B', 'A', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};

void keyboard_init(){
    for (int i = 0; i < number_of_rows; i++){
        // setup rows (output open drain)
        GPIOA->MODER  &= ~(0x3 << (i*2));
        GPIOA->MODER  |=  (0x1 << (i*2));
        GPIOA->OTYPER |= (1 << i);
    }
    for (int i = 0; i < number_of_columns; i++){
        // setup columns (input pullup)
        GPIOC->MODER  &= ~(0x3 << (i*2));
        GPIOC->PUPDR  &= ~(0x3 << (i*2));
        GPIOC->PUPDR  |=  (0x1 << (i*2));
    }
}


void activate_row(uint8_t row_nb){
    // set all row to 0 and then reenable selected row
    for(int i =0; i < number_of_rows; i++){
        set_output_pin(GPIO_A, i, true);
    }
    set_output_pin(GPIO_A, row_nb, false);
    us_wait(100);
}

struct button* keyboard_scan(){
    static struct button result_button_list[54] = {};
    uint8_t i = 0;
    for(int r = 0; r < number_of_rows; r++){
        activate_row(r);
        
        for(int c = 0; c < number_of_columns; c++){
            bool key_state = read_input_pin(GPIO_C, c);
            result_button_list[i].row = row_list[r];
            result_button_list[i].column = c + 1;
            result_button_list[i].state = key_state;
            i++;
        }
    }
    return result_button_list;
}


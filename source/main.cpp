#include <avr/io.h>
#include <util/delay.h>
#include "SevenSegment.h"
#include "Button.h"

#define BUTTON_1_PIN    1
#define BUTTON_2_PIN    2

int main(void) {
    Button button_1;
    Button button_2;
    SevenSegment seg7;
    uint8_t cur_number = 0;
    
    button_1.configure(BUTTON_1_PIN);
    button_2.configure(BUTTON_2_PIN);
    seg7.init();
    seg7.display(cur_number);
    while(1) {
        if (button_1.is_pressed()) {
            cur_number ++;
            if (cur_number == 10) {
                cur_number = 0;
            }
            seg7.display(cur_number);
        }
        if (button_2.is_pressed()) {
            if (cur_number == 0) {
                cur_number = 10;
            }
            cur_number --;
            seg7.display(cur_number);
        }
    }
}
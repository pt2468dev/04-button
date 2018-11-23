#include <avr/io.h>
#include <util/delay.h>
#include "Button.h"

void Button::configure(uint8_t p_no) {
    // Set port as input port
    pin_number = p_no;
    DDRC &= ~(1<<pin_number);
    // Set pull up resistor
    PORTC |= (1<<pin_number);
}

bool Button::is_pressed(void) {
    bool is_pressed = false;
    // Debouncing
    _delay_ms(20);
    //Read again
    if ((PINC & (1<<pin_number)) == 0) {
        // Wait until button is released
        while ((PINC & (1<<pin_number)) == 0);
        is_pressed = true;
    }
    return is_pressed;
}
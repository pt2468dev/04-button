#ifndef BUTTON_H_
#define BUTTON_H_

#include <avr/io.h>

class Button {
    private:
        uint8_t pin_number;
    public:
        void configure(uint8_t p_no);
        bool is_pressed(void);
};

#endif // BUTTON_H_
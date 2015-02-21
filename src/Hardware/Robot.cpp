/* 
 * File:   Robot.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 */
#include <avr/io.h>

namespace Hardware {

    class Robot {
        void initilize() {
            //Set digital pins 0 and 1 to be output
            DDRD |= (1 << PORTD1) | (1 << PORTD2);
        }
        
        void setPort() {
            PORTD |= 0b10101000;
        }
    };
}
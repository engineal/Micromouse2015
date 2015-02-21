/***************
 * File:   Robot.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 * Defines and controls hardware elements of the robot
 **************/

#include <avr/io.h>


namespace Hardware {
    
    enum Sensor {rightb, rightf, leftb, leftf, frontl, frontr, backl, backr, encoder, encodel};
    
    class Robot {
        
        int readSensor (Sensor sensor) {
            
        void initilize() {
            //Set digital pins 0 and 1 to be output
            DDRD |= (1 << PORTD1) | (1 << PORTD2);
        }
        
        void setPort() {
            PORTD |= 0b10101000;
        }
    };
}

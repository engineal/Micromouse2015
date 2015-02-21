/*
 * File:   Robot.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 * Defines and controls hardware elements of the robot
 */

#include <avr/io.h>

namespace Hardware {
    class Robot {
        void initilize() {
            //Set digital pins for left and right motor to output
            DDRD |= (1 << Motor::motorL) | (1 << Motor::motorR);
            
            //Set analog pins to input
            DDRC = 0;
        }
        
        void setPort() {
            PORTD |= 0b10101000;
        }
        
        int readSensor (Sensor sensor) {
            
        }
    };
}

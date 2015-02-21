/* 
 * File:   Control.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 */
#include "Hardware/Robot.h";

namespace Control {
    class Control {
        Robot robot;
        
        Control() {
            robot = new Robot();
        }
        
        void moveForward() {
            robot.setPort();
        }
    };
}
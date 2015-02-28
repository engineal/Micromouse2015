/* 
 * File:   Control.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 */
 
#include "Control.h"
#include <util/delay.h>

Control::Control() {
	robot = new Robot();
	maze = new Maze();
}

void Control::go() {
	robot->straight(100, true);
	// Wait 1 second
	_delay_ms(1000);
	robot->stop();
}
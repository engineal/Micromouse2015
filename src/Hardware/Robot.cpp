/*
 * File:   Robot.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 * Defines and controls hardware elements of the robot
 */

#include "Robot.h"
#include <avr/io.h>

void Robot::initilize() {
	//Set digital pins for left and right motor to output
	DDRD |= (1 << motorL) | (1 << motorR);

	//Set analog pins to input
	DDRC = 0;
}

void Robot::setPort(Motor motor, bool value) {
	if (value) {
		PORTD |= (1 << motor);
	} else {
		PORTD &= ~(1 << motor);
	}
}

int Robot::readSensor(Sensor sensor) {
	return 0;
}
/*
 * File:   Robot.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 * Defines and controls hardware elements of the robot
 */

#include "Robot.h"
#include "io.h"

/*
 * Create a new robot object
 */
Robot::Robot() {
	position = new Position(0, 0, EAST);
}

/*
 * Destroy the robot object
 */
Robot::~Robot() {
	delete position;
}

/*
 * Set the initial states of the pins
 */
void Robot::initilize() {
	//Set digital pins for left and right motor to output
	pinMode(motorL, OUTPUT);
	pinMode(motorR, OUTPUT);
}

/*
 * Get the current position of the robot
 */
Position* Robot::getPosition() {
	return position;
}

/*
 * Move to the next cell in the direction
 */
void Robot::moveCell(Direction facing) {
	digitalWrite(motorL, true);
	digitalWrite(motorR, true);
	
	switch (facing) {
	case NORTH:
		position->setY(position->getY() - 1);
		break;
	case SOUTH:
		position->setY(position->getY() + 1);
		break;
	case EAST:
		position->setX(position->getX() - 1);
		break;
	case WEST:
		position->setX(position->getX() + 1);
		break;
	}
	
	position->setFacing(facing);
}

/*
 * Stop moving
 */
void Robot::stop() {
	digitalWrite(motorL, false);
	digitalWrite(motorR, false);
}

/*
 * Read sensors and interpret as walls
 */
Cell Robot::getCell() {
	bool north = true;
	bool south = true;
	bool east = false;
	bool west = true;
	return Cell(north, south, east, west);
}
/*
 * File:   Robot.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 * Defines and controls hardware elements of the robot
 */

#include "Robot.h"
#include "io.h"

Robot::Robot() {
	position = new Position(0, 0, EAST);
}

Robot::~Robot() {
	delete position;
}

void Robot::initilize() {
	//Set digital pins for left and right motor to output
	pinMode(motorL, OUTPUT);
	pinMode(motorR, OUTPUT);
}

Position* Robot::getPosition() {
	return position;
}

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

void Robot::stop() {
	digitalWrite(motorL, false);
	digitalWrite(motorR, false);
}

Cell Robot::getCell() {
	bool north = true;
	bool south = true;
	bool east = false;
	bool west = true;
	return Cell(north, south, east, west);
}
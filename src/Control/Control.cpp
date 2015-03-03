/* 
 * File:   Control.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 */
 
#include "Control.h"
#include <util/delay.h>

Control::Control(Maze* maze) {
	robot = new Robot();
	this->maze = maze;
}

Control::~Control() {
	delete robot;
}

void Control::go(Algorithm* algorithm, Position position) {
	while (!reachedDest(position)) {
		robot->moveCell(algorithm->nextMove(robot->getPosition()));
		maze->setCell(robot->getPosition(), robot->getCell());
		maze->printDebug();
		// Wait 1 second
		_delay_ms(1000);
	}
	robot->stop();
}

bool Control::reachedDest(Position position) {
	bool dest = true;
	dest &= position.getX() == robot->getPosition()->getX();
	dest &= position.getY() == robot->getPosition()->getY();
	return dest;
}
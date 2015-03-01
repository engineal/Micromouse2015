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

void Control::go(Algorithm* algorithm) {
	while (true) {
		robot->moveCell(algorithm->nextMove(robot->getPosition()));
		maze->setCell(robot->getPosition(), robot->getCell());
		// Wait 1 second
		_delay_ms(1000);
	}
	robot->stop();
}
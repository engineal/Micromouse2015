/* 
 * File:   Position.cpp
 * Author: Aaron Lucia
 *
 * Created on February 21, 2015, 11:31 PM
 */

#include "Position.h"

Position::Position(int x, int y, Direction facing) {
	this->x = x;
	this->y = y;
	this->facing = facing;
}

int Position::getX() {
	return x;
}

void Position::setX(int x) {
	this->x = x;
}

int Position::getY() {
	return y;
}

void Position::setY(int y) {
	this->y = y;
}

Direction Position::getFacing() {
	return facing;
}

void Position::setFacing(Direction facing) {
	this->facing = facing;
}

Direction leftOf(Direction direction) {
	switch (direction) {
	case NORTH:
		return WEST;
	case SOUTH:
		return EAST;
	case EAST:
		return NORTH;
	case WEST:
		return SOUTH;
	default:
		return NORTH;
	}
}

Direction rightOf(Direction direction) {
	switch (direction) {
	case NORTH:
		return EAST;
	case SOUTH:
		return WEST;
	case EAST:
		return SOUTH;
	case WEST:
		return NORTH;
	default:
		return NORTH;
	}
}
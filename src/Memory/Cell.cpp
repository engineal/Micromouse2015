/* 
 * File:   Cell.cpp
 * Author: Aaron Lucia
 *
 * Created on February 21, 2015, 11:10 PM
 */
 
#include "Cell.h"

Cell::Cell(bool north, bool south, bool east, bool west) {
	this->north = north;
	this->south = south;
	this->east = east;
	this->west = west;
}

bool Cell::getWall(Direction wall) {
	switch (wall) {
	case NORTH:
		return north;
	case SOUTH:
		return south;
	case EAST:
		return east;
	case WEST:
		return west;
	default:
		return false;
	}
}
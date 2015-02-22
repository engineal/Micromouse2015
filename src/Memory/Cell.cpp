/* 
 * File:   Cell.cpp
 * Author: Aaron Lucia
 *
 * Created on February 21, 2015, 11:10 PM
 */
 
#include "Cell.h"

bool Cell::getWall(Wall wall) {
	switch (wall) {
	case northWall:
		return north;
	case southWall:
		return south;
	case eastWall:
		return east;
	case westWall:
		return west;
	default:
		return false;
	}
}

void Cell::setWall(Wall wall) {
	switch (wall) {
	case northWall:
		north = true;
		break;
	case southWall:
		south = true;
		break;
	case eastWall:
		east = true;
		break;
	case westWall:
		west = true;
		break;
	}
}
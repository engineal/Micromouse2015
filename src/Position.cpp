/* 
 * File:   Position.cpp
 * Author: Aaron Lucia
 *
 * Created on February 21, 2015, 11:31 PM
 */

#include "Position.h"

Position::Position(int x, int y) {
	this->x = x;
	this->y = y;
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
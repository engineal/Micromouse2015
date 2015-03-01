/* 
 * File:   FloodFill.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 */

#include "FloodFill.h"

Direction FloodFill::nextMove(Position* position) {
	return position->getFacing();
}
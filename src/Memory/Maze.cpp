/* 
 * File:   Maze.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 */
 
#include "Maze.h"

Maze::Maze() {
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			cells[x][y] = new Cell();
		}
	}
}

Cell* Maze::getCell(Position position) {
	return cells[position.getX()][position.getY()];
}
/* 
 * File:   Maze.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 */
 
#include "Maze.h"

Maze::Maze() {
	for (int x = 0; x < 16; x++)
		for (int y = 0; y < 15; y++)
			nsWalls[x][y] = false;

	for (int x = 0; x < 16; x++)
		for (int y = 0; y < 15; y++)
			ewWalls[x][y] = false;
}

Cell Maze::getCell(Position* position) {
	bool north;
	if (position->getY() == 0)
		north = true;
	else
		north = nsWalls[position->getX()][position->getY() - 1];
	bool south;
	if (position->getY() == 15)
		south = true;
	else
		south = nsWalls[position->getX()][position->getY()];
	bool east;
	if (position->getX() == 15)
		east = true;
	else
		east = ewWalls[position->getX()][position->getY()];
	bool west;
	if (position->getX() == 0)
		west = true;
	else
		west = ewWalls[position->getX() - 1][position->getY()];
	return Cell(north, south, east, west);
}

void Maze::setCell(Position* position, Cell cell) {
	if (position->getY() > 0)
		nsWalls[position->getX()][position->getY() - 1] = cell.getWall(NORTH);
	if (position->getY() < 15)
		nsWalls[position->getX()][position->getY()] = cell.getWall(SOUTH);
	if (position->getX() < 15)
		ewWalls[position->getX()][position->getY()] = cell.getWall(EAST);
	if (position->getX() > 0)
		ewWalls[position->getX() - 1][position->getY()] = cell.getWall(WEST);
}
/* 
 * File:   Maze.h
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 */

#ifndef MAZE_H
#define	MAZE_H

#include "Cell.h"
#include "../Position.h"

class Maze {
private:
	Cell* cells[16][16];
public:
	Maze();
    Cell* getCell(Position position);
};

#endif	/* MAZE_H */


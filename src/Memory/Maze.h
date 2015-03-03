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
	unsigned short nsWalls[15];
	unsigned short ewWalls[16];
	bool isException(Position* position, Cell cell);
	bool getNSWall(int x, int y);
	bool getEWWall(int x, int y);
	void setNSWall(int x, int y);
	void setEWWall(int x, int y);
public:
	Maze();
    Cell getCell(Position* position);
    void setCell(Position* position, Cell cell);
	void readEEPROM();
	void writeEEPROM();
	void printDebug();
};

#endif	/* MAZE_H */

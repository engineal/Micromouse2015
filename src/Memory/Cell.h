/* 
 * File:   Cell.h
 * Author: Aaron Lucia
 *
 * Created on February 21, 2015, 11:10 PM
 */

#ifndef CELL_H
#define	CELL_H

#include "../Position.h"

class Cell {
private:
	bool north;
	bool south;
	bool east;
	bool west;
public:
	Cell(bool north, bool south, bool east, bool west);
    bool getWall(Direction wall);
	void setWall(Direction wall);
};

#endif	/* CELL_H */


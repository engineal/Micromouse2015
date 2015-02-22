/* 
 * File:   Cell.h
 * Author: Aaron Lucia
 *
 * Created on February 21, 2015, 11:10 PM
 */

#ifndef CELL_H
#define	CELL_H

enum Wall {
	northWall,
	southWall,
	eastWall,
	westWall
};

class Cell {
private:
	bool north;
	bool south;
	bool east;
	bool west;
public:
    bool getWall(Wall wall);
	void setWall(Wall wall);
};

#endif	/* CELL_H */


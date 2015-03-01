/* 
 * File:   Position.h
 * Author: Aaron Lucia
 *
 * Created on February 21, 2015, 11:31 PM
 */
 
#ifndef POSITION_H
#define	POSITION_H

enum Direction {
	NORTH,
	SOUTH,
	EAST,
	WEST
};

class Position {
private:
	int x;
	int y;
	Direction facing;
public:
	Position(int x, int y, Direction facing);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	Direction getFacing();
	void setFacing(Direction facing);
};

Direction leftOf(Direction direction);
Direction rightOf(Direction direction);

#endif
/* 
 * File:   Position.h
 * Author: Aaron Lucia
 *
 * Created on February 21, 2015, 11:31 PM
 */
 
#ifndef POSITION_H
#define	POSITION_H

class Position {
private:
	int x;
	int y;
public:
	Position(int x, int y);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
};

#endif
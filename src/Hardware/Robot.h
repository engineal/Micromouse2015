/* 
 * File:   Robot.h
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 */

#ifndef ROBOT_H
#define	ROBOT_H

#include "../Position.h"
#include "../Memory/Cell.h"

class Robot {
private:
	Position* position;
public:
	Robot();
    void initilize();
	Position* getPosition();
    void moveCell(Direction facing);
    void stop();
	Cell* getCell();
};

#endif	/* ROBOT_H */

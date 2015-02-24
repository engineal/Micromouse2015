/* 
 * File:   Control.h
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:50 AM
 */

#ifndef CONTROL_H
#define	CONTROL_H

#include "../Hardware/Robot.h"
#include "../Memory/Maze.h"

class Control {
private:
	Robot* robot;
	Maze* maze;
public:
    Control();
};

#endif	/* CONTROL_H */

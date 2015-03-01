/* 
 * File:   Control.h
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:50 AM
 */

#ifndef CONTROL_H
#define	CONTROL_H

#include "../Algorithm/Algorithm.h"
#include "../Hardware/Robot.h"
#include "../Memory/Maze.h"

class Control {
private:
	Robot* robot;
	Maze* maze;
public:
    Control(Maze* maze);
	~Control();
	void go(Algorithm* algorithm);
};

#endif	/* CONTROL_H */

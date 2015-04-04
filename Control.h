/*
 * File:   Control.h
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:50 AM
 */

#ifndef CONTROL_H
#define	CONTROL_H

#include "Algorithm.h"
#include "Robot.h"
#include "Maze.h"

class Control {
  private:
    Robot* robot;
    Maze* maze;
    bool reachedDest(Position position);
  public:
    Control(Maze* maze);
    ~Control();
    void go(Algorithm* algorithm);
};

#endif	/* CONTROL_H */


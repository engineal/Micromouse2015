/*
 * File:   Algorithm.h
 * Author: Aaron Lucia
 *
 * Created on March 1, 2015, 2:28 PM
 */

#ifndef ALGORITHM_H
#define	ALGORITHM_H

#include "Position.h"
#include "Maze.h"

class Algorithm {
  protected:
    Maze* maze;
    Position* destination;
  public:
    Algorithm(Maze* maze, Position* destination);
    virtual Direction nextMove(Position* position);
    bool reachedDest(Position* position);
};

#endif	/* ALGORITHM_H */


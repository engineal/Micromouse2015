/*
 * File:   FloodFill.h
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:50 AM
 */

#ifndef FLOODFILL_H
#define	FLOODFILL_H

#include "Position.h"
#include "Algorithm.h"
#include "Maze.h"

class FloodFill : public Algorithm {
  private:
    unsigned int distances[16][16];
    void cellDistance(Position* destination);
  public:
    FloodFill(Maze* maze, Position* destination);
    Direction nextMove(Position* position);
    void printDebug();
};

#endif	/* FLOODFILL_H */


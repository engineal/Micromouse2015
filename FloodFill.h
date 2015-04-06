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
    byte distances[16][16];
    void cellDistance(byte x, byte y, byte distance);
  public:
    FloodFill(Maze* maze, Position* destination);
    Direction nextMove(Position* position);
    void printDebug();
};

#endif	/* FLOODFILL_H */


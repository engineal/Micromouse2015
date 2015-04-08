/*
 * File:   Maze.h
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 */

#ifndef MAZE_H
#define	MAZE_H

#include "Cell.h"
#include "Position.h"
#include <Arduino.h>

class Maze {
  private:
    unsigned int nsWalls[16];
    unsigned int ewWalls[15];
    bool isException(Position* position, Cell cell);
    bool getNSWall(int x, int y);
    bool getEWWall(int x, int y);
    void setNSWall(int x, int y);
    void setEWWall(int x, int y);
  public:
    Maze();
    Cell getCell(int x, int y);
    void setCell(int x, int y, Cell cell);
    void readEEPROM();
    void writeEEPROM();
    void makeFake();
    void printDebug();
};

#endif	/* MAZE_H */


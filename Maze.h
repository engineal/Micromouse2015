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
    unsigned int nsWalls[15];
    unsigned int ewWalls[16];
    bool isException(Position* position, Cell cell);
    bool getNSWall(byte x, byte y);
    bool getEWWall(byte x, byte y);
    void setNSWall(byte x, byte y);
    void setEWWall(byte x, byte y);
  public:
    Maze();
    Cell getCell(byte x, byte y);
    void setCell(byte x, byte y, Cell cell);
    void readEEPROM();
    void writeEEPROM();
    void printDebug();
};

#endif	/* MAZE_H */


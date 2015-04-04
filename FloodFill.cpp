/*
 * File:   FloodFill.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 */

#include "FloodFill.h"

/*
 * Create a new floodfill algorithm
 */
FloodFill::FloodFill(Maze* maze, Position* destination) : Algorithm(maze, destination) {
  for (int x = 0; x < 16; x++) {
    for (int y = 0; y < 16; y++) {
      distances[x][y] = 0;
    }
  }
}

/*
 * Impliments a floodfill algorithm
 */
Direction FloodFill::nextMove(Position* position) {
  return position->getFacing();
}


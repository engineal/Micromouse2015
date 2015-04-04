/*
 * File:   Algorithm.cpp
 * Author: Aaron Lucia
 *
 * Created on March 1, 2015, 2:28 PM
 */

#include "Algorithm.h"

/*
 * Create a new algorithm
 */
Algorithm::Algorithm(Maze* maze) {
  this->maze = maze;
}

/*
 * Default function for nextMove
 * Impliments a basic wall following algorithm
 */
Direction Algorithm::nextMove(Position* position) {
  Cell cell = maze->getCell(position);

  if (cell.getWall(position->getFacing())) {
    Direction facing = leftOf(position->getFacing());
    if (!cell.getWall(facing))
      return facing;
    facing = rightOf(position->getFacing());
    if (!cell.getWall(facing))
      return facing;
    return rightOf(facing);
  } else {
    return position->getFacing();
  }
}


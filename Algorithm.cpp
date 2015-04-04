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
Algorithm::Algorithm(Maze* maze, Position* destination) {
  this->maze = maze;
  this->destination = destination;
}

/*
 * Default function for nextMove
 * Impliments a basic wall following algorithm
 */
Direction Algorithm::nextMove(Position* position) {
  Cell cell = maze->getCell(position->getX(), position->getY());

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

/*
 * Check if robot has reached the destination position
 */
bool Algorithm::reachedDest(Position* position) {
  bool dest = true;
  dest &= destination->getX() == position->getX();
  dest &= destination->getY() == position->getY();
  return dest;
}

/*
 * File:   FloodFill.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 */

#include "FloodFill.h"

/*
 * Initialization of maze array
 */
FloodFill::FloodFill(Maze* maze, Position* destination) : Algorithm(maze, destination) {
  for (int x = 0; x < 16; x++) {
    for (int y = 0; y < 16; y++) {
      distances[x][y] = 0;
    }
  }
}

/*
 * Find the distance to destination
 */
void FloodFill::cellDistance(short x, short y, short distance) {
  distances[x][y] = distance;
  // Fills out maze with distance values, assuming no internal walls
  Cell cell = maze->getCell(new Position(x, y, NORTH));
  if (!cell.getWall(NORTH))
    cellDistance(x, y - 1, distance + 1);
  if (!cell.getWall(SOUTH))
    cellDistance(x, y + 1, distance + 1);
  if (!cell.getWall(EAST))
    cellDistance(x + 1, y, distance + 1);
  if (!cell.getWall(WEST))
    cellDistance(x - 1, y, distance + 1);
}

/*
 * At current position, get the robot's facing and find distance values of adjacent squares
 */
Direction FloodFill::nextMove(Position* position) {
  cellDistance(destination->getX(),destination->getY(), 0);
  Cell cell = maze->getCell(position);
  short distance;
  short smallestDistance = 255;
  Direction smallestFacing = NORTH;
  if (!cell.getWall(NORTH)) {
    distance = distances[position->getX()-1][position->getY()];
    if (distance < smallestDistance) {
      smallestDistance = distance;
      smallestFacing = NORTH;
    }
  }
  if (!cell.getWall(SOUTH)) {
    distance = distances[position->getX()+1][position->getY()];
    if (distance < smallestDistance) {
      smallestDistance = distance;
      smallestFacing = SOUTH;
    }
  }
  if (!cell.getWall(WEST)) {
    distance = distances[position->getX()][position->getY()-1];
    if (distance < smallestDistance) {
      smallestDistance = distance;
      smallestFacing = WEST;
    }
  }
  if (!cell.getWall(EAST)) {
    distance = distances[position->getX()][position->getY()+1];
    if (distance < smallestDistance) {
      smallestDistance = distance;
      smallestFacing = EAST;
    }
  }
  return smallestFacing;
}



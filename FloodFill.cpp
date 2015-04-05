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
  for (byte x = 0; x < 16; x++) {
    for (byte y = 0; y < 16; y++) {
      distances[x][y] = 255;
    }
  }
}

/*
 * Find the distance to destination
 */
void FloodFill::cellDistance(byte x, byte y, byte distance) {
  if (distance < distances[x][y]) {
    distances[x][y] = distance;
    // Fills out maze with distance values, assuming no internal walls
    Cell cell = maze->getCell(x, y);
    if (!cell.getWall(NORTH))
      cellDistance(x, y - 1, distance + 1);
    if (!cell.getWall(SOUTH))
      cellDistance(x, y + 1, distance + 1);
    if (!cell.getWall(EAST))
      cellDistance(x + 1, y, distance + 1);
    if (!cell.getWall(WEST))
      cellDistance(x - 1, y, distance + 1);
  }
}

/*
 * At current position, get the robot's facing and find distance values of adjacent squares
 */
Direction FloodFill::nextMove(Position* position) {
  // Reset cell distances so that we can calculate them fresh
  for (byte x = 0; x < 16; x++) {
    for (byte y = 0; y < 16; y++) {
      distances[x][y] = 255;
    }
  }
  cellDistance(destination->getX(), destination->getY(), 0);

  Cell cell = maze->getCell(position->getX(), position->getY());
  byte x = position->getX();
  byte y = position->getY();
  byte distance = 255;
  Direction smallestFacing = NORTH;
  if (!cell.getWall(NORTH) && distances[x - 1][y] < distance) {
    distance = distances[x - 1][y];
    smallestFacing = NORTH;
  }
  if (!cell.getWall(SOUTH) && distances[x + 1][y] < distance) {
    distance = distances[x + 1][y];
    smallestFacing = SOUTH;
  }
  if (!cell.getWall(EAST) && distances[x][y + 1] < distance) {
    distance = distances[x][y + 1];
    smallestFacing = EAST;
  }
  if (!cell.getWall(WEST) && distances[x][y - 1] < distance) {
    distance = distances[x][y - 1];
    smallestFacing = WEST;
  }
  return smallestFacing;
}


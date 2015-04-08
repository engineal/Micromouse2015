/*
 * File:   FloodFill.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 */

#include "FloodFill.h"
#include "MemoryFree.h"

/*
 * Initialization of maze array
 */
FloodFill::FloodFill(Maze* maze, Position* destination) : Algorithm(maze, destination) {
  for (int x = 0; x < 16; x++) {
    for (int y = 0; y < 16; y++) {
      distances[x][y] = 1000;
    }
  }
}

/*
 * Find the distance to destination
 */
void FloodFill::cellDistance(Position* destination) {
  // Reset cell distances so that we can calculate them fresh
  for (int x = 0; x < 16; x++) {
    for (int y = 0; y < 16; y++) {
      distances[x][y] = 1000;
    }
  }

  Position* stack1[150];
  int stack1Size = 0;
  Position* stack2[150];
  int stack2Size = 0;

  int distance = 0;
  stack1[stack1Size++] = destination;

  while (stack1Size > 0) {
    while (stack1Size > 0) {
      Position* pos = stack1[--stack1Size];

      if (distances[pos->getX()][pos->getY()] > distance) {
        distances[pos->getX()][pos->getY()] = distance;

        Cell cell = maze->getCell(pos->getX(), pos->getY());
        if (!cell.getWall(NORTH))
          stack2[stack2Size++] = new Position(pos->getX(), pos->getY() - 1);
        if (!cell.getWall(SOUTH))
          stack2[stack2Size++] = new Position(pos->getX(), pos->getY() + 1);
        if (!cell.getWall(EAST))
          stack2[stack2Size++] = new Position(pos->getX() + 1, pos->getY());
        if (!cell.getWall(WEST))
          stack2[stack2Size++] = new Position(pos->getX() - 1, pos->getY());
      }

      delete pos;
    }
    distance++;

    for (int i = 0; i < stack2Size; i++) {
      stack1[i] = stack2[i];
    }
    stack1Size = stack2Size;
    stack2Size = 0;
  }
}

/*
 * At current position, get the robot's facing and find distance values of adjacent squares
 */
Direction FloodFill::nextMove(Position* position) {
  cellDistance(destination);

  printDebug();

  Cell cell = maze->getCell(position->getX(), position->getY());
  int x = position->getX();
  int y = position->getY();
  int distance = 1000;
  Direction smallestFacing = NORTH;
  if (!cell.getWall(NORTH) && distances[x][y - 1] < distance) {
    distance = distances[x - 1][y];
    smallestFacing = NORTH;
  }
  if (!cell.getWall(SOUTH) && distances[x][y + 1] < distance) {
    distance = distances[x + 1][y];
    smallestFacing = SOUTH;
  }
  if (!cell.getWall(EAST) && distances[x + 1][y] < distance) {
    distance = distances[x][y + 1];
    smallestFacing = EAST;
  }
  if (!cell.getWall(WEST) && distances[x - 1][y] < distance) {
    distance = distances[x][y - 1];
    smallestFacing = WEST;
  }
  Serial.println(smallestFacing);
  return smallestFacing;
}

/*
 * Print the maze to the serial connection
 */
void FloodFill::printDebug() {
  for (int y = 0; y < 16; y++) {
    for (int x = 0; x < 16; x++) {
      Serial.print(" ");
      Serial.print(distances[x][y]);
      if (distances[x][y] < 10)
        Serial.print(" ");
      Serial.print(" ");
    }
    Serial.println();
  }
  Serial.println();
}

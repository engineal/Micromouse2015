/*
 * File:   Maze.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 */

#include "Maze.h"
#include <EEPROM.h>

/*
 * Create a new maze with no walls
 */
Maze::Maze() {
  for (byte y = 0; y < 15; y++)
    nsWalls[y] = 0;

  for (byte y = 0; y < 16; y++)
    ewWalls[y] = 0;
}

/*
 * Get the cell at position
 */
Cell Maze::getCell(byte x, byte y) {
  bool north = getEWWall(x, y - 1);
  bool south = getEWWall(x, y);
  bool east = getNSWall(x, y);
  bool west = getNSWall(x - 1, y);
  return Cell(north, south, east, west);
}

/*
 * Update cell walls at position
 */
void Maze::setCell(byte x, byte y, Cell cell) {
  if (cell.getWall(NORTH))
    setEWWall(x, y - 1);
  if (cell.getWall(SOUTH))
    setEWWall(x, y);
  if (cell.getWall(EAST))
    setNSWall(x, y);
  if (cell.getWall(WEST))
    setNSWall(x - 1, y);
}

/*
 * Binary operations to read a wall pointing North-South at x, y
 */
bool Maze::getNSWall(byte x, byte y) {
  return (x < 0) || (x > 14) || (nsWalls[y] & (1 << x));
}

/*
 * Binary operations to read a wall pointing East-West at x, y
 */
bool Maze::getEWWall(byte x, byte y) {
  return (y < 0) || (y > 14) || (ewWalls[y] & (1 << x));
}

/*
 * Binary operations to write a wall pointing North-South at x, y
 */
void Maze::setNSWall(byte x, byte y) {
  if (x > -1 || x < 15) {
    nsWalls[y] |= (1 << x);
  }
}

/*
 * Binary operations to write a wall pointing East-West at x, y
 */
void Maze::setEWWall(byte x, byte y) {
  if (y > -1 || y < 15) {
    ewWalls[y] |= (1 << x);
  }
}

/*
 * Read stored wall data from the EEPROM
 */
void Maze::readEEPROM() {
  int address = 0;
  for (byte y = 0; y < 15; y++) {
    nsWalls[y] = EEPROM.read(address++) << 8;
    nsWalls[y] |= EEPROM.read(address++);
  }

  for (byte y = 0; y < 16; y++) {
    ewWalls[y] = EEPROM.read(address++) << 8;
    ewWalls[y] |= EEPROM.read(address++);
  }
}

/*
 * Store current wall data to the EEPROM
 */
void Maze::writeEEPROM() {
  int address = 0;
  for (byte y = 0; y < 15; y++) {
    EEPROM.update(address++, (nsWalls[y] >> 8) & 0xFF);
    EEPROM.update(address++, nsWalls[y] & 0xFF);
  }

  for (byte y = 0; y < 16; y++) {
    EEPROM.update(address++, (ewWalls[y] >> 8) & 0xFF);
    EEPROM.update(address++, ewWalls[y] & 0xFF);
  }
}

/*
 * Print the maze to the serial connection
 */
void Maze::printDebug() {
  Serial.write(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
  for (byte y = 0; y < 16; y++) {
    Serial.write("|");
    for (byte x = 0; x < 16; x++) {
      if (getEWWall(x, y))
        Serial.write("_");
      else
        Serial.write(" ");
      if (getNSWall(x, y))
        Serial.write("|");
      else
        Serial.write(" ");
    }
    Serial.write("\n");
  }
}


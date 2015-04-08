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
  for (int y = 0; y < 16; y++)
    nsWalls[y] = 0;

  for (int y = 0; y < 15; y++)
    ewWalls[y] = 0;
}

/*
 * Get the cell at position
 */
Cell Maze::getCell(int x, int y) {
  bool north = getEWWall(x, y - 1);
  bool south = getEWWall(x, y);
  bool east = getNSWall(x, y);
  bool west = getNSWall(x - 1, y);
  return Cell(north, south, east, west);
}

/*
 * Update cell walls at position
 */
void Maze::setCell(int x, int y, Cell cell) {
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
bool Maze::getNSWall(int x, int y) {
  if (x > -1 && x < 15 && y > -1 && y < 16)
    return (nsWalls[y] & (1 << x));
  return true;
}

/*
 * Binary operations to read a wall pointing East-West at x, y
 */
bool Maze::getEWWall(int x, int y) {
  if (x > -1 && x < 16 && y > -1 && y < 15)
    return (ewWalls[y] & (1 << x));
  return true;
}

/*
 * Binary operations to write a wall pointing North-South at x, y
 */
void Maze::setNSWall(int x, int y) {
  if (x > -1 && x < 15 && y > -1 && y < 16) {
    nsWalls[y] |= (1 << x);
  }
}

/*
 * Binary operations to write a wall pointing East-West at x, y
 */
void Maze::setEWWall(int x, int y) {
  if (x > -1 && x < 16 && y > -1 && y < 15) {
    ewWalls[y] |= (1 << x);
  }
}

/*
 * Read stored wall data from the EEPROM
 */
void Maze::readEEPROM() {
  int address = 0;
  for (int y = 0; y < 15; y++) {
    nsWalls[y] = EEPROM.read(address++) << 8;
    nsWalls[y] |= EEPROM.read(address++);
  }

  for (int y = 0; y < 16; y++) {
    ewWalls[y] = EEPROM.read(address++) << 8;
    ewWalls[y] |= EEPROM.read(address++);
  }
}

/*
 * Store current wall data to the EEPROM
 */
void Maze::writeEEPROM() {
  int address = 0;
  for (int y = 0; y < 15; y++) {
    EEPROM.update(address++, (nsWalls[y] >> 8) & 0xFF);
    EEPROM.update(address++, nsWalls[y] & 0xFF);
  }

  for (int y = 0; y < 16; y++) {
    EEPROM.update(address++, (ewWalls[y] >> 8) & 0xFF);
    EEPROM.update(address++, ewWalls[y] & 0xFF);
  }
}

/*
 * Generate a fake maze for testing
 */
void Maze::makeFake() {
  nsWalls[0] = 0b0;
  nsWalls[1] = 0b100000000000000;
  nsWalls[2] = 0b110000000000001;
  nsWalls[3] = 0b110000000000011;
  nsWalls[4] = 0b110000000000011;
  nsWalls[5] = 0b110000000000011;
  nsWalls[6] = 0b110000000000011;
  nsWalls[7] = 0b110000000000011;
  nsWalls[8] = 0b110000000000011;
  nsWalls[9] = 0b110000000000011;
  nsWalls[10] = 0b110000000000011;
  nsWalls[11] = 0b110000000000011;
  nsWalls[12] = 0b110000000000011;
  nsWalls[13] = 0b110000000000011;
  nsWalls[14] = 0b100000000000001;
  nsWalls[15] = 0b0;

  ewWalls[0] = 0b0111111111111110;
  ewWalls[1] = 0b0011111111111110;
  ewWalls[2] = 0b0;
  ewWalls[3] = 0b0;
  ewWalls[4] = 0b0;
  ewWalls[5] = 0b0;
  ewWalls[6] = 0b0;
  ewWalls[7] = 0b0;
  ewWalls[8] = 0b0;
  ewWalls[9] = 0b0;
  ewWalls[10] = 0b0;
  ewWalls[11] = 0b0;
  ewWalls[12] = 0b0;
  ewWalls[13] = 0b0011111111111100;
  ewWalls[14] = 0b0111111111111110;
}

/*
 * Print the maze to the serial connection
 */
void Maze::printDebug() {
  Serial.println(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
  for (int y = 0; y < 16; y++) {
    Serial.print("|");
    for (int x = 0; x < 16; x++) {
      if (getEWWall(x, y))
        Serial.print("_");
      else
        Serial.print(" ");
      if (getNSWall(x, y))
        Serial.print("|");
      else
        Serial.print(" ");
    }
    Serial.println();
  }
  Serial.println();
}


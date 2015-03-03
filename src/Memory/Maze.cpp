/* 
 * File:   Maze.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 */
 
#include "Maze.h"
#include "../Hardware/USART.h"
#include <avr/eeprom.h>

/*
 * Create a new maze with no walls
 */
Maze::Maze() {
	for (int y = 0; y < 15; y++)
		nsWalls[y] = 0;

	for (int y = 0; y < 16; y++)
		ewWalls[y] = 0;
}

/*
 * Get the cell at position
 */
Cell Maze::getCell(Position* position) {
	bool north = getEWWall(position->getX(), position->getY() - 1);
	bool south = getEWWall(position->getX(), position->getY());
	bool east = getNSWall(position->getX(), position->getY());
	bool west = getNSWall(position->getX() - 1, position->getY());
	return Cell(north, south, east, west);
}

/*
 * Update cell walls at position
 */
void Maze::setCell(Position* position, Cell cell) {
	if (cell.getWall(NORTH))
		setEWWall(position->getX(), position->getY() - 1);
	if (cell.getWall(SOUTH))
		setEWWall(position->getX(), position->getY());
	if (cell.getWall(EAST))
		setNSWall(position->getX(), position->getY());
	if (cell.getWall(WEST))
		setNSWall(position->getX() - 1, position->getY());
}

/*
 * Binary operations to read a wall pointing North-South at x, y
 */
bool Maze::getNSWall(int x, int y) {
	return (x < 0) || (x > 14) || (nsWalls[y] & (1 << x));
}

/*
 * Binary operations to read a wall pointing East-West at x, y
 */
bool Maze::getEWWall(int x, int y) {
	return (y < 0) || (y > 14) || (ewWalls[y] & (1 << x));
}

/*
 * Binary operations to write a wall pointing North-South at x, y
 */
void Maze::setNSWall(int x, int y) {
	if (x > -1 || x < 15) {
		nsWalls[y] |= (1 << x);
	}
}

/*
 * Binary operations to write a wall pointing East-West at x, y
 */
void Maze::setEWWall(int x, int y) {
	if (y > -1 || y < 15) {
		ewWalls[y] |= (1 << x);
	}
}

/*
 * Read stored wall data from the EEPROM
 */
void Maze::readEEPROM() {
	uint8_t* address = 0;
	for (int y = 0; y < 15; y++) {
		nsWalls[y] = eeprom_read_byte(address++) << 8;
		nsWalls[y] |= eeprom_read_byte(address++);
	}

	for (int y = 0; y < 16; y++) {
		ewWalls[y] = eeprom_read_byte(address++) << 8;
		ewWalls[y] |= eeprom_read_byte(address++);
	}
}

/*
 * Store current wall data to the EEPROM
 */
void Maze::writeEEPROM() {
	uint8_t* address = 0;
	for (int y = 0; y < 15; y++) {
		eeprom_write_byte(address++, (nsWalls[y] >> 8) & 0xFF);
		eeprom_write_byte(address++, nsWalls[y] & 0xFF);
	}

	for (int y = 0; y < 16; y++) {
		eeprom_write_byte(address++, (ewWalls[y] >> 8) & 0xFF);
		eeprom_write_byte(address++, ewWalls[y] & 0xFF);
	}
}

/*
 * Print the maze to the serial connection
 */
void Maze::printDebug() {
	char* row = (char*)" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n";
	printStr(row);
	for (int y = 0; y < 16; y++) {
		row = (char*)"|";
		for (int x = 0; x < 16; x++) {
			if (getEWWall(x,y)) {
				strcat(row, "_");
			}
			if (getNSWall(x, y)) {
				strcat(row, "|");
			}
		}
		strcat(row, "\n");
		printStr(row);
	}
}
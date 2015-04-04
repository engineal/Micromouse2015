/*
 * File:   Position.cpp
 * Author: Aaron Lucia
 *
 * Created on February 21, 2015, 11:31 PM
 */

#include "Position.h"

/*
 * Create a new position object
 */
Position::Position(byte x, byte y, Direction facing) {
  this->x = x;
  this->y = y;
  this->facing = facing;
}

/*
 * Get the x coordinate
 */
byte Position::getX() {
  return x;
}

/*
 * Set the x coordinate
 */
void Position::setX(byte x) {
  this->x = x;
}

/*
 * Get the y coordinate
 */
byte Position::getY() {
  return y;
}

/*
 * Set the y coordinate
 */
void Position::setY(byte y) {
  this->y = y;
}

/*
 * Get the facing direction
 */
Direction Position::getFacing() {
  return facing;
}

/*
 * Set the facing direction
 */
void Position::setFacing(Direction facing) {
  this->facing = facing;
}

/*
 * Get the direction to the left of direction
 */
Direction leftOf(Direction direction) {
  switch (direction) {
    case NORTH:
      return WEST;
    case SOUTH:
      return EAST;
    case EAST:
      return NORTH;
    case WEST:
      return SOUTH;
    default:
      return NORTH;
  }
}

/*
 * Get the direction to the right of direction
 */
Direction rightOf(Direction direction) {
  switch (direction) {
    case NORTH:
      return EAST;
    case SOUTH:
      return WEST;
    case EAST:
      return SOUTH;
    case WEST:
      return NORTH;
    default:
      return NORTH;
  }
}


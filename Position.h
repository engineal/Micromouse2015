/*
 * File:   Position.h
 * Author: Aaron Lucia
 *
 * Created on February 21, 2015, 11:31 PM
 */

#ifndef POSITION_H
#define	POSITION_H

#include <Arduino.h>

enum Direction {
  NORTH,
  SOUTH,
  EAST,
  WEST
};

class Position {
  private:
    byte x;
    byte y;
    Direction facing;
  public:
    Position(byte x, byte y, Direction facing);
    byte getX();
    void setX(byte x);
    byte getY();
    void setY(byte y);
    Direction getFacing();
    void setFacing(Direction facing);
};

Direction leftOf(Direction direction);
Direction rightOf(Direction direction);

#endif


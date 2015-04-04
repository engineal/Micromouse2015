/*
 * File:   Robot.h
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 */

#ifndef ROBOT_H
#define	ROBOT_H

#include "Position.h"
#include "Cell.h"

//Left motor: 3, 5
//Right motor: 6, 13
//Sensor select: 4, 7, 8
//Sensor read: A0
//Sensor emit: A5
//Left motor encoder: A1, A2
//Right motor encoder: A3, A4
//Switch: 9, 10, 11, 12
//Button: 2
enum Sensor {
  frontL = 0,
  frontR,
  leftF,
  rightF,
  leftB,
  rightB,
  backL,
  backR
};

enum Motor {
  motorL,
  motorR
};

class Robot {
  private:
    Position* position;
    int readSensor(Sensor sensor);
    void move(int speed, int turn);
  public:
    Robot();
    ~Robot();
    void initilize();
    Position* getPosition();
    void moveCell(Direction facing);
    Cell getCell();
};

#endif	/* ROBOT_H */


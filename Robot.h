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

//Left motor: A1, A2
//Right motor: A3, A4
//Sensor select: 4, 7, 8
//Sensor read: A0
//Sensor emit: A5
//Left motor encoder: 6, 13
//Right motor encoder: 3, 5
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
    void move();
    void turn(int degrees);
  public:
    Robot();
    ~Robot();
    Position* getPosition();
    void moveCell(Direction facing);
    Cell getCell();
};

void leftTrigger();
void rightTrigger();

#endif	/* ROBOT_H */


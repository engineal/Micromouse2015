/*
 * File:   Robot.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 * Defines and controls hardware elements of the robot
 */

#include "Robot.h"
#include <Arduino.h>
#include <PID_v1.h>

double leftCount;
double rightCount;

/*
 * Create a new robot object
 */
Robot::Robot() {
  position = new Position(0, 0, EAST);
}

/*
 * Destroy the robot object
 */
Robot::~Robot() {
  delete position;
}

/*
 * Get the current position of the robot
 */
Position* Robot::getPosition() {
  return position;
}

/*
 * Motor control
 */
int Robot::readSensor(Sensor sensor) {
  digitalWrite(4, bitRead(sensor, 0));
  digitalWrite(7, bitRead(sensor, 1));
  digitalWrite(8, bitRead(sensor, 2));

  digitalWrite(A5, HIGH);
  delay(50);
  int value = analogRead(A0);
  delay(10);
  digitalWrite(A5, LOW);
  return A0;
}

/*
 * Motor control
 */
void Robot::move() {
  double leftSetPoint, rightSetPoint, leftSpeed, rightSpeed;

  PID leftPID(&leftCount, &leftSpeed, &leftSetPoint, 2, 5, 1, DIRECT);
  leftPID.SetMode(AUTOMATIC);
  PID rightPID(&rightCount, &rightSpeed, &rightSetPoint, 2, 5, 1, DIRECT);
  rightPID.SetMode(AUTOMATIC);

  while (leftCount < 1000) {
    leftPID.Compute();
    rightPID.Compute();

    if (leftSpeed > 0) {
      analogWrite(3, leftSpeed);
      digitalWrite(5, LOW);
    } else {
      digitalWrite(3, LOW);
      analogWrite(5, -leftSpeed);
    }

    if (rightSpeed > 0) {
      analogWrite(6, rightSpeed);
      digitalWrite(13, LOW);
    } else {
      digitalWrite(6, LOW);
      analogWrite(13, -rightSpeed);
    }
  }

  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(13, LOW);
}

/*
 * Move to the next cell in the direction
 */
void Robot::moveCell(Direction facing) {
  if (facing == position->getFacing()) {
    move();
  } else if (facing == leftOf(position->getFacing())) {
    move();
  } else if (facing == rightOf(position->getFacing())) {
    move();
  } else {
    move();
  }

  switch (facing) {
    case NORTH:
      position->setY(position->getY() - 1);
      break;
    case SOUTH:
      position->setY(position->getY() + 1);
      break;
    case EAST:
      position->setX(position->getX() - 1);
      break;
    case WEST:
      position->setX(position->getX() + 1);
      break;
  }

  position->setFacing(facing);
}

/*
 * Read sensors and interpret as walls
 */
Cell Robot::getCell() {
  bool front = (readSensor(frontL) + readSensor(frontR)) > 100;
  bool back = false;
  bool left = readSensor(leftF) > 50;
  bool right = readSensor(rightF) > 50;

  switch (position->getFacing()) {
    case NORTH:
      return Cell(front, back, right, left);
    case SOUTH:
      return Cell(back, front, left, right);
    case EAST:
      return Cell(left, right, front, back);
    case WEST:
      return Cell(right, left, back, front);
  }
}

void leftTrigger() {
  leftCount++;
}

void rightTrigger() {
  rightCount++;
}


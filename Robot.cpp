/*
 * File:   Robot.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 * Defines and controls hardware elements of the robot
 */

#include "Robot.h"
#include <Arduino.h>

volatile long leftCount;
volatile long rightCount;

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
  delay(100);
  int value = analogRead(A0);
  delay(100);
  digitalWrite(A5, LOW);
  return A0;
}

/*
 * Motor control
 */
void Robot::move(int speed, int turn) {
  int leftSpeed = constrain(speed + turn, 0, 255);
  int rightSpeed = constrain(speed - turn, 0, 255);

  leftCount = 0;
  rightCount = 0;

  if (speed > 0) {
    analogWrite(3, leftSpeed);
    digitalWrite(5, LOW);
    analogWrite(6, rightSpeed);
    digitalWrite(13, LOW);
  } else if (speed < 0) {
    digitalWrite(3, LOW);
    analogWrite(5, leftSpeed);
    digitalWrite(6, LOW);
    analogWrite(13, rightSpeed);
  } else {
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(13, LOW);
  }

  while (leftCount < 1000)
    delay(100);

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
    move(100, 0);
  } else if (facing == leftOf(position->getFacing())) {
    move(100, -90);
  } else if (facing == rightOf(position->getFacing())) {
    move(100, 90);
  } else {
    move(-100, 180);
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
  bool front = (readSensor(frontL) + readSensor(frontR)) < 1000;
  bool back = (readSensor(backL) + readSensor(backR)) < 1000;
  bool left = (readSensor(leftF) + readSensor(leftB)) < 1000;
  bool right = (readSensor(rightF) + readSensor(rightB)) < 1000;

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


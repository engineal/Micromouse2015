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

  int values[5];

  digitalWrite(A5, HIGH);
  delay(50);
  values[0] = analogRead(A0);
  values[1] = analogRead(A0);
  values[2] = analogRead(A0);
  values[3] = analogRead(A0);
  values[4] = analogRead(A0);

  int least = values[0];
  for (int i = 1; i < 5; i++) {
    if (values[i] < least) {
      least = values[i];
    }
  }
  digitalWrite(A5, LOW);
  return least;
}

/*
 * Motor control
 */
void Robot::move() {
  int leftCount = 0;
  int rightCount = 0;
  Serial.println("Moving");
  //double leftSetPoint, rightSetPoint, leftSpeed, rightSpeed;

  //PID leftPID(&leftCount, &leftSpeed, &leftSetPoint, 2, 5, 1, DIRECT);
  //leftPID.SetMode(AUTOMATIC);
  //PID rightPID(&rightCount, &rightSpeed, &rightSetPoint, 2, 5, 1, DIRECT);
  //rightPID.SetMode(AUTOMATIC);

  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);

  digitalWrite(A3, HIGH);
  digitalWrite(A4, LOW);

  while (leftCount < 100) {
    //leftPID.Compute();
    //rightPID.Compute();

    /*if (readSensor(leftF) - readSensor(rightF) > 5) {
      Serial.println("Fix right");
      digitalWrite(A2, LOW);
      delay(50);
      digitalWrite(A2, HIGH);
    }
    if (readSensor(leftF) - readSensor(rightF) < -5) {
      Serial.println("Fix left");
      digitalWrite(A3, LOW);
      delay(50);
      digitalWrite(A3, HIGH);
    }*/

    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
    delay(5);
    digitalWrite(A3, HIGH);
    digitalWrite(A2, HIGH);

    delay(5);
    leftCount++;
  }

  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
}

/*
 * Motor control
 */
void Robot::turn(int degrees) {
  int leftCount = 0;
  int rightCount = 0;
  Serial.println("Turning");

  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);

  if (degrees > 0) {
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    while (leftCount < degrees) {
      digitalWrite(A2, LOW);
      delay(5);
      digitalWrite(A2, HIGH);
      delay(10);
      leftCount++;
    }
  } else if (degrees < 0) {
    digitalWrite(A3, HIGH);
    digitalWrite(A4, LOW);
    while (rightCount < -degrees) {
      digitalWrite(A3, LOW);
      delay(5);
      digitalWrite(A3, HIGH);
      delay(10);
      rightCount++;
    }
  }

  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
}

/*
 * Move to the next cell in the direction
 */
void Robot::moveCell(Direction facing) {
  Serial.print(position->getX());
  Serial.print(", ");
  Serial.print(position->getY());
  Serial.print(", ");
  Serial.print(position->getFacing());
  Serial.print(", ");
  if (facing == position->getFacing()) {
    move();
  } else if (facing == leftOf(position->getFacing())) {
    Serial.println("Left");
    turn(-90);
    move();
  } else if (facing == rightOf(position->getFacing())) {
    Serial.println("Right");
    turn(90);
    move();
  } else {
    Serial.println("Reverse");
    turn(180);
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
      position->setX(position->getX() + 1);
      break;
    case WEST:
      position->setX(position->getX() - 1);
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
  bool left = readSensor(leftF) > 0;
  bool right = readSensor(rightF) > 0;

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


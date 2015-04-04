/*
 * File:   Control.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 */

#include "Control.h"
#include <Arduino.h>

/*
 * Create a new control object using a maze
 */
Control::Control(Maze* maze) {
  robot = new Robot();
  this->maze = maze;
}

/*
 * Destroy the control object, releasing control of the robot
 */
Control::~Control() {
  delete robot;
}

/*
 * Navigate to the destination position using the specified algorithm
 */
void Control::go(Algorithm* algorithm, Position position) {
  Serial.write("Run started\n");
  maze->printDebug();

  while (!reachedDest(position)) {
    //Update the walls at the robots current position
    maze->setCell(robot->getPosition(), robot->getCell());
    //Move to the next position specified by the algorithm
    robot->moveCell(algorithm->nextMove(robot->getPosition()));

    maze->printDebug();
    // Wait 1 second
    delay(1000);
  }
  robot->stop();

  Serial.write("Run finished\n");
  maze->printDebug();
}

/*
 * Check if robot has reached the destination position
 */
bool Control::reachedDest(Position position) {
  bool dest = true;
  dest &= position.getX() == robot->getPosition()->getX();
  dest &= position.getY() == robot->getPosition()->getY();
  return dest;
}


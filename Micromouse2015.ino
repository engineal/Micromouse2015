/*
 * File:   main.ino
 * Author: Aaron Lucia
 *
 * Created on November 11, 2014, 11:11 AM
 */
#include "Control.h"
#include <EEPROM.h>
#include <SoftwareSerial.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial connected");
}

void loop() {
  // put your main code here, to run repeatedly:
  int mode = (digitalRead(9) ? B1 : 0) | (digitalRead(10) ? B10 : 0) | (digitalRead(11) ? B100 : 0);
  Serial.println(mode);
  delay(500);

  Maze* maze = new Maze();
  //maze->readEEPROM();
  Control* control = new Control(maze);
  control->go(new Algorithm(maze), Position(7, 7, NORTH));
  //maze->writeEEPROM();
}


/*
 * File:   main.ino
 * Author: Aaron Lucia
 *
 * Created on November 11, 2014, 11:11 AM
 */
#include "Control.h"
#include <EEPROM.h>
#include <SoftwareSerial.h>

int mode;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial connected");
  
  mode = 0;
  digitalWrite(A5, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  //int mode = (digitalRead(9) ? B1 : 0) | (digitalRead(10) ? B10 : 0) | (digitalRead(11) ? B100 : 0) | (digitalRead(12) ? B1000 : 0);
  Serial.println(mode);
  digitalWrite(4, bitRead(mode, 0));
  digitalWrite(7, bitRead(mode, 1));
  digitalWrite(8, bitRead(mode, 2));
  mode++;
  if (mode == 8) {
    mode = 0;
  }

  delay(500);

  //Maze* maze = new Maze();
  //maze->readEEPROM();
  //Control* control = new Control(maze);
  //Position* destination = new Position(7, 7, NORTH);
  //control->go(new Algorithm(maze, destination));
  //maze->writeEEPROM();
}


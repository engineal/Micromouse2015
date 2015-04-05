/*
 * File:   Micromouse2015.ino
 * Author: Aaron Lucia
 *
 * Created on November 11, 2014, 11:11 AM
 */
#include "Control.h"
#include "Floodfill.h"
#include <EEPROM.h>
#include <SoftwareSerial.h>

int mode;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial connected");

  //Set digital pins for left and right motor to output
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, OUTPUT);

  attachInterrupt(A1, leftTrigger, RISING);
  attachInterrupt(A3, rightTrigger, RISING);

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

  // wait for button push
  while (!digitalRead(2))
    delay(100);

  Maze* maze = new Maze();
  maze->printDebug();
  //maze->readEEPROM();
  Control* control = new Control(maze);
  //control->go(new FloodFill(maze, new Position(7, 7, NORTH)));
  //maze->writeEEPROM();
  delete control;
  delete maze;
  delay(10000);
}


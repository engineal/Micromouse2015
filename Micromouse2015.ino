/*
 * File:   Micromouse2015.ino
 * Author: Aaron Lucia
 *
 * Created on November 11, 2014, 11:11 AM
 */
#include "Control.h"
#include "Floodfill.h"
#include "MemoryFree.h"
#include <EEPROM.h>
#include <SoftwareSerial.h>
#include <PID_v1.h>

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
}

void loop() {
  // put your main code here, to run repeatedly:
  int mode = (digitalRead(9) ? B1 : 0) | (digitalRead(10) ? B10 : 0) | (digitalRead(11) ? B100 : 0) | (digitalRead(12) ? B1000 : 0);
  Serial.println(mode);
  digitalWrite(4, bitRead(mode, 0));
  digitalWrite(7, bitRead(mode, 1));
  digitalWrite(8, bitRead(mode, 2));
  digitalWrite(A5, HIGH);

  // wait for button push
  while (!digitalRead(2)) {
    Serial.println(analogRead(A0));
    delay(100);
  }

  //Maze* maze = new Maze();
  //maze->makeFake();
  //makeFakeMaze(maze);
  //maze->readEEPROM();
  //Control* control = new Control(maze);
  //Serial.println(freeMemory());
  //control->go(new FloodFill(maze, new Position(7, 7, NORTH)));
  //maze->writeEEPROM();
  //delete control;
  //delete maze;
  delay(1000);
}

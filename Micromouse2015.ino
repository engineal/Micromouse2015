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

  //Set digital pins for left and right motor to output
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  //attachInterrupt(3, leftTrigger, RISING);
  //attachInterrupt(6, rightTrigger, RISING);
}

void loop() {
  int encoderCount = 0;
  while (encoderCount < 100) {
    Serial.println(encoderCount);
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
    delayMicroseconds(900);
    digitalWrite(A3, HIGH);
    digitalWrite(A2, HIGH);
    delayMicroseconds(100);
    encoderCount++;
  }
  
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  
  while (true);
  //digitalWrite(4, HIGH);
  //digitalWrite(7, LOW);
  //digitalWrite(8, LOW);
  //int values[5];

  // wait for button push
  while (!digitalRead(2)) {
    //digitalWrite(A2, LOW);
    //digitalWrite(A3, LOW);
    //delay(1);
    //digitalWrite(A3, HIGH);
    //digitalWrite(A2, HIGH);

    //pulseIn(6, HIGH);
    //digitalWrite(A5, HIGH);
    //delay(50);
    //values[0] = analogRead(A0);
    //values[1] = analogRead(A0);
    //values[2] = analogRead(A0);
    //values[3] = analogRead(A0);
    //values[4] = analogRead(A0);

    //int least = values[0];
    //for (int i = 1; i < 5; i++) {
    //  if (values[i] < least) {
    //    least = values[i];
    //  }
    //}
    //Serial.println(least);
    //digitalWrite(A5, LOW);
    //delay(100);
  }

  Maze* maze = new Maze();
  //maze->makeFake();
  //maze->readEEPROM();
  Control* control = new Control(maze);
  Serial.println(freeMemory());
  control->go(new FloodFill(maze, new Position(7, 7, NORTH)));
  //maze->writeEEPROM();
  delete control;
  delete maze;
  delay(1000);
}

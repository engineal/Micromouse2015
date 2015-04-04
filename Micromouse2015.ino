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
  //Left motor: 3, 5
  //Right motor: 6, 13
  //Sensor select: 4, 7, 8
  //Sensor read: A0
  //Sensor emit: A5
  //Left motor encoder: A1, A2
  //Right motor encoder: A3, A4
  //Switch: 9, 10, 11, 12
  //Button: 2
  Serial.begin(9600);
  Serial.println("Serial connected");

  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A5, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int mode = (digitalRead(9) ? B1 : 0) | (digitalRead(10) ? B10 : 0) | (digitalRead(11) ? B100 : 0);
  Serial.println(mode);
  digitalWrite(4, bitRead(mode, 0));
  digitalWrite(7, bitRead(mode, 1));
  digitalWrite(8, bitRead(mode, 2));
  delay(500);

  Maze* maze = new Maze();
  //maze->readEEPROM();
  Control* control = new Control(maze);
  control->go(new Algorithm(maze), Position(7, 7, NORTH));
  //maze->writeEEPROM();
}


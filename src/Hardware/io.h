/* 
 * File:   io.h
 * Author: Aaron Lucia
 *
 * Created on February 23, 2015, 9:24 PM
 */
 
#ifndef IO_H
#define	IO_H

enum Mode {
	INPUT,
	OUTPUT
};

enum Sensor {
    frontL = 0,
    frontR = 1,
    leftF = 2,
    rightF = 3,
    leftB = 4,
    rightB = 5,
    backL = 6,
    backR = 7,
    encodeL = 8,
    encodeR = 9
};

enum Motor {
    motorL = 9,
    motorR = 10
};

void pinMode(int pin, Mode mode);

void analogWrite(int pin, int value);
int analogRead(int pin);

void digitalWrite(int pin, bool value);
int digitalRead(int pin);

#endif	/* IO_H */

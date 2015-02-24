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

void pinMode(int pin, Mode mode);

void analogWrite(int pin, int value);
int analogRead(int pin);

void digitalWrite(int pin, bool value);
int digitalRead(int pin);

#endif	/* IO_H */

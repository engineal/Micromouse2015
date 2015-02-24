/* 
 * File:   io.cpp
 * Author: Aaron Lucia
 *
 * Created on February 23, 2015, 9:24 PM
 */
 
#include "io.h"
#include <avr/io.h>

void pinMode(int pin, Mode mode) {
	if (mode) {
		DDRD |= (1 << pin);
	} else {
		DDRD &= ~(1 << pin);
	}
}

void analogWrite(int pin, int value) {
}

int analogRead(int pin) {
	return -1;
}

void digitalWrite(int pin, bool value){
	if (value) {
		PORTD |= (1 << pin);
	} else {
		PORTD &= ~(1 << pin);
	}
}

int digitalRead(int pin){
	return -1;
}
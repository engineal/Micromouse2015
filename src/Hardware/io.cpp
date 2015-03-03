/* 
 * File:   io.cpp
 * Author: Aaron Lucia
 *
 * Created on February 23, 2015, 9:24 PM
 */
 
#include "io.h"
#include <avr/io.h>

/*
 * Set the pin mode for the pin
 */
void pinMode(int pin, Mode mode) {
	if (mode) {
		DDRD |= (1 << pin);
	} else {
		DDRD &= ~(1 << pin);
	}
}

/*
 * Read an analog signal from pin
 */
int analogRead(int pin) {
   //Select ADC Channel ch must be 0-7
   int ch = pin & 0b00000111;
   ADMUX = (1 << REFS0) | ch;
   
   //Start Single conversion
   ADCSRA |= (1<<ADSC);

   //Wait for conversion to complete
   while(!(ADCSRA & (1<<ADIF)));

   ADCSRA |= (1<<ADIF);

   return(ADC);
}

/*
 * Write an analog value to the pin
 */
void analogWrite(int pin, int value) {
}

/*
 * Read a digital signal from the pin
 */
int digitalRead(int pin){
	return -1;
}

/*
 * Write a digital signal to the pin
 */
void digitalWrite(int pin, bool value){
	if (value) {
		PORTD |= (1 << pin);
	} else {
		PORTD &= ~(1 << pin);
	}
}
/*
 * File:   Robot.cpp
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 * Defines and controls hardware elements of the robot
 */

#include "Robot.h"
#include "io.h"
#include <avr/io.h>

Robot::Robot() {
	position = new Position(0, 0);
}

void Robot::initilize() {
	//Set digital pins for left and right motor to output
	pinMode(motorL, OUTPUT);
	pinMode(motorR, OUTPUT);

	//Set analog pins to input
	DDRC = 0;
	
	//Set 
	ADMUX = (1 << REFS0);// | (1 << MUX0) | (1 << MUX1) | (1 << MUX2);
	ADCSRA = (1 << ADEN) | (1 << ADPS0) /*  | (1 << ADPS1) */  | (1 << ADPS2)  ;	
	
	//IR Triggers
	DDRD |= (1 << PORTD4) | (1 << PORTD7);
	DDRC |= (1 << PORTC6);
	
	//LED's
	DDRB |= (1 << PORTB4);
	DDRB |= (1 << PORTB5);
	DDRE |= (1 << PORTE6);
}

void Robot::straight(int speed, bool direction) {
	digitalWrite(motorL, true);
	digitalWrite(motorR, true);
}

void Robot::stop() {
	digitalWrite(motorL, false);
	digitalWrite(motorR, false);
}

int Robot::readSensor(Sensor sensor) {
   //Select ADC Channel ch must be 0-7
   int ch = sensor & 0b00000111;
   ADMUX = (1 << REFS0) | ch;
   
   //Start Single conversion
   ADCSRA |= (1<<ADSC);

   //Wait for conversion to complete
   while(!(ADCSRA & (1<<ADIF)));

   ADCSRA |= (1<<ADIF);

   return(ADC);
}
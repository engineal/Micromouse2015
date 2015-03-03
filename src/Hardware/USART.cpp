/* 
 * File:   USART.cpp
 * Author: Aaron Lucia
 *
 * Created on March 3, 2015, 10:51 AM
 */

#include <stdio.h>
#include <avr/io.h>
#include "USART.h"

#define F_CPU 16000000UL
#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)

/*
 * Initilize serial connection
 */
void USART_init() {
	UBRR1H = (uint8_t)(BAUD_PRESCALLER>>8);
	UBRR1L = (uint8_t)(BAUD_PRESCALLER);
	UCSR1B = (1<<RXEN1)|(1<<TXEN1);
	UCSR1C = (3<<UCSZ10);
}

/*
 * Receive a char via serial
 */
unsigned char USART_receive() {
	while(!(UCSR1A & (1<<RXC1)));
	return UDR1;
}

/*
 * Send a char via serial
 */
void USART_send(unsigned char data) {
	while(!(UCSR1A & (1<<UDRE1)));
	UDR1 = data;
}

char str[16];
/*
 * Send a double value via serial
 */
void printDouble(double value) {
	sprintf(str,"%f",value);
	printStr(str);
	printStr("\n\r");
}

/*
 * Send an int value via serial
 */
void printInt(int value) {
	sprintf(str,"%d",value);
	printStr(str);
}

/*
 * Send a string via serial
 */
void printStr(const char* stringPtr) {
	while(*stringPtr != 0x00) {
		USART_send(*stringPtr);
		stringPtr++;
	}
}
/* 
 * File:   USART.h
 * Author: Aaron Lucia
 *
 * Created on March 3, 2015, 10:51 AM
 */

#ifndef USART_H
#define USART_H

#include <string.h>

void USART_init();
unsigned char USART_receive();
void USART_send(unsigned char data);
void printDouble(float value);
void printInt(int value);
void printStr(const char* StringPtr);

#endif
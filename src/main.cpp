/* 
 * File:   main.cpp
 * Author: Aaron Lucia
 *
 * Created on November 11, 2014, 11:11 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Control/Control.h"
#include "Hardware/USART.h"

void * operator new(size_t size)
{
	return malloc(size);
}

void operator delete(void * ptr)
{
	free(ptr);
}

/*
 * Start
 */
int main(int argc, char** argv) {
	//initilize serial communication
	USART_init();
	printStr("Serial connected");
	
	Maze* maze = new Maze();
	//maze->readEEPROM();
    Control* control = new Control(maze);
	control->go(new Algorithm(maze), Position(7, 7, NORTH));
	//maze->writeEEPROM();
}
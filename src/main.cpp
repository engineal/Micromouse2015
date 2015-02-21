/* 
 * File:   main.cpp
 * Author: Aaron Lucia
 *
 * Created on November 11, 2014, 11:11 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Control/Control.h"

void * operator new(size_t size)
{
  return malloc(size);
}

void operator delete(void * ptr)
{
  free(ptr);
}

/*
 * 
 */
int main(int argc, char** argv) {
    Control* control = new Control();
    control->moveForward();
}
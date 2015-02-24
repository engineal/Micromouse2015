/* 
 * File:   Robot.h
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:51 AM
 */

#ifndef ROBOT_H
#define	ROBOT_H

#include "../Position.h"

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

class Robot {
private:
	Position* position;
public:
	Robot();
    void initilize();
    void straight(int speed, bool direction);
    void stop();
    int readSensor(Sensor sensor);
};

#endif	/* ROBOT_H */


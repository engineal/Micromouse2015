/* 
 * File:   FloodFill.h
 * Author: Aaron Lucia
 *
 * Created on February 7, 2015, 10:50 AM
 */

#ifndef FLOODFILL_H
#define	FLOODFILL_H

#include "../Position.h"
#include "Algorithm.h"

class FloodFill : public Algorithm {
public:
	Direction nextMove(Position* position);
};

#endif	/* FLOODFILL_H */

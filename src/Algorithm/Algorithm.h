/* 
 * File:   Algorithm.h
 * Author: Aaron Lucia
 *
 * Created on March 1, 2015, 2:28 PM
 */

#ifndef ALGORITHM_H
#define	ALGORITHM_H

#include "../Position.h"
#include "../Memory/Maze.h"

class Algorithm {
private:
	Maze* maze;
public:
	Algorithm(Maze* maze);
	virtual Direction nextMove(Position* position);
};

#endif	/* ALGORITHM_H */


/*
 * Ball.h
 *
 *  Created on: 23.09.2014 ã.
 *      Author:
 */

#ifndef BALL_H_
#define BALL_H_

#include "GlobalVariables.h"

using namespace std;

class Ball
{
public:
	Ball();

	void shuffle();
	void printBall();

	virtual ~Ball();
	int getBallNum();

private:
	void create();

	vector <int> newVector;
};

#endif /* BALL_H_ */

/*
 * Ball.cpp
 *
 *  Created on: 23.09.2014 ã.
 *      Author:
 */

#include "Ball.h"

Ball::Ball()
{
}

void Ball::shuffle()
{
	create();
	random_shuffle(newVector.begin(), newVector.end());
}

void Ball::printBall()
{
	for (size_t i = 0; i < newVector.size(); ++i)
	{
		cout<<newVector[i]<<" ";
	}
}

void Ball::create()
{
	while (!newVector.empty())
	{
		newVector.pop_back();
	}

	for (size_t i = 0; i < 75; ++i)
	{
		newVector.push_back(i+1);
	}
}

Ball::~Ball()
{
}

int Ball::getBallNum()
{
	int temp = newVector.back();
	newVector.pop_back();
	return temp;
}

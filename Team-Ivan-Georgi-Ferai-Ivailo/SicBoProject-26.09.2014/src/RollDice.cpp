/*
 * RollDice.cpp
 *
 *  Created on: 19.09.2014 ã.
 *      Author: msi
 */

#include "RollDice.h"

RollDice::RollDice(){}

RollDice::~RollDice() {}

void RollDice::rollAllDices()
{
	setFirstDice();
	setSecondDice();
	setThirdDice();
}
void RollDice::setFirstDice()
{
	int random = rand() % 6 + 1;
	diceNumbers[0] = random;
}

void RollDice::setSecondDice()
{
	int random = rand() % 6 + 1;
	diceNumbers[1] = random;
}

void RollDice::setThirdDice()
{
	int random = rand() % 6 + 1;
	diceNumbers[2] = random;
}


int RollDice::getFirstDice()
{
	return diceNumbers[0];
}
int RollDice::getSecondDice()
{
	return diceNumbers[1];
}
int RollDice::getThirdDice()
{
	return diceNumbers[2];
}

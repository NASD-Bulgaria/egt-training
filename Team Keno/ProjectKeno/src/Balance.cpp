#include "Balance.h"
#include <iostream>
using namespace std;


Balance::Balance(int balance)
{
	setFirstCredit(balance);
	setBet(10);
}


void Balance::setFirstCredit(int first)
{
	if(first < 10)
		{
			this->credit=500;
		}
		else{
			this->credit=first;
		}
}

int Balance::getCredit() const
{
	return credit;
}

void Balance::calculateWin(int spots , int catches, const int coefficient[][11])
{

	this->credit = credit + (coefficient[spots][catches] * bet);
}

void Balance::setCredit() {
	this->credit -= bet;
}

Balance::~Balance() {
}

void Balance::setBet(int setBet) {
	bet = setBet;
}

int Balance::getBet() {
	return bet;
}

#include "Statistics.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

Statistics::Statistics(int numb, int win,int lost, int payout)
{
	this->maxPayout=0;
	setWinningGames(win);
	setLostGames(lost);
	setMaxPayout(payout);
	setNumberOfGames(numb);

}

void Statistics::setMaxPayout(int a)
{
	maxPayout = (a > maxPayout ? a : maxPayout);
}
int Statistics::getMaxPayout()
{
	return maxPayout;
}


void Statistics::setNumberOfGames(int a)
{
	numberOfGames = a;
}

int Statistics::getNumberOfGames()
{
	return numberOfGames;
}

void Statistics::setWinningGames(int count)
{
	winningGames = count;
}

int Statistics::getWinningGames()
{
	return winningGames;
}

void Statistics::setLostGames(int count)
{
	lostGames = count;
}

int Statistics::getLostGames()
{
	return lostGames;
}


Statistics::~Statistics() {

}


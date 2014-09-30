/*
 * Bets.h
 *
 *  Created on: Sep 19, 2014
 *      Author: vasko
 */

#ifndef BETS_H_
#define BETS_H_
#include <iostream>
#include <map>
#include <iterator>
using namespace std;
#include "Game.h"

 const int BET=20;

class Bets
{
friend class Game;

public:
	Bets();
	virtual ~Bets();

	int wins(int);
	string handName(int);
private:
	map<int, int> myBets;
	map<int, string> betsName;
};

#endif /* BETS_H_ */

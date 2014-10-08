/*
 * Game.h
 *
 *  Created on: Sep 16, 2014
 *      Author: Keen
 */

#ifndef GAME_H_
#define GAME_H_

#include "Deck.h"
#include "Card.h"


#include <vector>
#include <algorithm>
using namespace std;

class Game
{
private:
	Deck deck;
	vector<Card> hand;
	vector<bool> hold;

public:
	Game();
	virtual ~Game();

	void deal();
	int draw();

	void print();
};

#endif /* GAME_H_ */

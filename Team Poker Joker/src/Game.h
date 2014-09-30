/*
 * Game.h
 *
 *  Created on: 17.09.2014 г.
 *      Author: Kateto
 */

#ifndef GAME_H_
#define GAME_H_

#include "Card.h"
#include "Bets.h"
#include "Statistics.h"
#include "Credits.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int countFace = 14;

class Game
{
	friend class Card;
	friend class Texture;


private:
	int counts[countFace];
	int deck[4][14];
	int winType;

//	vector<int> wins;
	static bool cardCompare(Card first, Card second);
	Statistics stats;
	Credits credit;

public:
	Game();
	vector<Card> hand;
	bool isKingOrBetterJoker();
	bool isKingOrBetter();
	bool isTwoPair();
	bool isThreeOfAKindJoker();
	bool isThreeOfAKind();
	bool isStraightJoker();
	bool isStraight();
	bool isFlushJoker();
	bool isFlush();
	bool isfullHouseJoker();
	bool isfullHouse();
	bool isFourOfAKindJoker();
	bool isFourOfAKind();
	bool isStraightFlush();
	bool isStraightFlushJoker();
	bool isWildRoyalFlush();
	bool isFiveOfAKind();
	bool isNaturalRoyalFlush();



	void autoHold();
	void shuffle();
	void dealCards();
	void secondDealCards();
	void checkHand();

	void showHand();// not need
	void holdCards(); // not need
	int getWinType();
};

#endif /* GAME_H_ */

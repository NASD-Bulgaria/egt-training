/*
 * Dealer.h
 *
 *  Created on: Aug 11, 2014
 *      Author: NandM
 */

#ifndef DEALER_H_
#define DEALER_H_
#include <vector>
#include "Card.h"
#include "Player.h"
class Dealer {
private:
	static bool compareHandsOfPlayers(Player first, Player second);
public:
	Dealer();
	static vector<Card> generateDeck();
	static void dealCard(Card &, Player &);
	static void shuffleDeck(vector<Card> &);
	static void declareWinner(vector<Player>);
	virtual ~Dealer();
};

#endif /* DEALER_H_ */

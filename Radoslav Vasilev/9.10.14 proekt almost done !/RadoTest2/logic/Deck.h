/*
 * Deck.h
 *
 *  Created on: Sep 16, 2014
 *      Author: Keen
 */

#ifndef DECK_H_
#define DECK_H_

#include "Card.h"

#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Deck
{
private:
    vector<Card>deck;

public:

	Deck();
	virtual ~Deck();
    void DeckInit();
    void shuffle();
    void save(ofstream &);
    void load(ifstream &);

	Card getCard();
};




#endif /* DECK_H_ */

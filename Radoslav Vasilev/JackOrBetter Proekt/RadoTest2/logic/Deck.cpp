/*
 * Deck.cpp
 *
 *  Created on: Sep 16, 2014
 *      Author: Keen
 */

#include "Deck.h"



Deck::Deck()
{
   DeckInit();
}

void Deck::DeckInit()
{
    deck.clear();

    for(unsigned i = 0 ;i<52;++i)
    {
      Card cardId(i);
      deck.push_back(cardId);
    }
}

void Deck::shuffle()
{
	random_shuffle(deck.begin(), deck.end());
}

Card Deck::getCard()
{
	Card temp = deck[deck.size()-1];
	deck.pop_back();
	return temp;
}


Deck::~Deck()
{
	// TODO Auto-generated destructor stub
}


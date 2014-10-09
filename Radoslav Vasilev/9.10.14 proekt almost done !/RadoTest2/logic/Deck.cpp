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

void Deck::save(ofstream & file)
{
    int size = deck.size();
    int* temp = new int[size];
    for(int i=0; i<size; i++)
        temp[i] = deck[i].getId();


    file.write(reinterpret_cast<char*>(&size),sizeof(int));
    file.write(reinterpret_cast<char*>(temp),sizeof(int)*size);

    delete [] temp;
}

void Deck::load(ifstream & file)
{
    int size;
    file.read(reinterpret_cast<char*>(&size),sizeof(int));


    int* temp = new int[size];


    file.read(reinterpret_cast<char*>(temp),sizeof(int)*size);
    for(int i=0; i<size; i++)
        deck[i].setId(temp[i]);
    delete [] temp;
    shuffle();
}


Deck::~Deck()
{
	// TODO Auto-generated destructor stub
}


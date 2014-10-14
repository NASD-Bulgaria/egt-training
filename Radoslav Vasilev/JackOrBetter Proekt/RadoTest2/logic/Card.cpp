/*
 * Card.cpp
 *
 *  Created on: Sep 16, 2014
 *      Author: Keen
 */

#include "Card.h"


unsigned Card::getId() const
{
    return id;
}

void Card::setId(const unsigned &value)
{
    id = value;
    suit = id/13;
    face = id%13;
}
Card::Card(int face, int suit):
    face(face),
    suit(suit)
{ 
    CalculateID();
}

Card::Card(unsigned id)
{
    setId(id);
}

int Card::getFace() const
{
	return face;
}

int Card::getSuit() const
{
	return suit;
}

string Card::getImagePath()
{
	ostringstream out;
	out<<suit<<face<<".png";
	return out.str();

}



Card::~Card() {
    // TODO Auto-generated destructor stub
}

void Card::CalculateID()
{
   id= suit*13+face;
}


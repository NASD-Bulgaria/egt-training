/*
 * Card.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: NandM
 */

#include "Card.h"

Card::Card() {
	this->face = noFace;
	this->suit = noSuit;
}

Card::Card(Suit suit, Face face) {
	this->face = face;
	this->suit = suit;
}

Face Card::getFace() const {
	return this->face;
}

void Card::setFace(Face face) {
	this->face = face;
}

Suit Card::getSuit() const {
	return this->suit;
}

void Card::setSuit(Suit suit) {
	this->suit = suit;
}

Card::~Card() {
	// TODO Auto-generated destructor stub
}

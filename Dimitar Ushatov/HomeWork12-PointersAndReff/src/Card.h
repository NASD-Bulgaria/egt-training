/*
 * Card.h
 *
 *  Created on: Aug 11, 2014
 *      Author: NandM
 */

#ifndef CARD_H_
#define CARD_H_
#include "Enumerations.h"
using namespace std;

class Card {
public:
	Card();

	Card(Suit, Face);

	virtual ~Card();

	Face getFace() const;

	void setFace(Face);

	Suit getSuit() const;

	void setSuit(Suit);

private:
	Suit suit;
	Face face;
};

#endif /* CARD_H_ */

/*
 * DeckOfCards.h
 *
 *  Created on: Sep 3, 2014
 *      Author: Student
 */

#ifndef DECKOFCARDS_H_
#define DECKOFCARDS_H_

struct Card {
	char *face;
	char *suit;
	char *color;
};

class DeckOfCards {
public:
	DeckOfCards();
	void shuffle();
	void deal();

private:
	Card deck[52];
};

#endif /* DECKOFCARDS_H_ */

/*
 * DeckOfCards.h
 *
 *  Created on: 3.09.2014 ã.
 *      Author: D00M
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

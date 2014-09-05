#include <iostream>
using namespace std;
#include "DeckOfCards.h"

int main() {
	DeckOfCards deckOfCards;

	cout << "The deck is : " << endl;
	deckOfCards.deal();
	cout << endl;
	cout << "Afte the shuffle: " << endl;
	deckOfCards.shuffle();
	deckOfCards.deal();
	return 0;
}


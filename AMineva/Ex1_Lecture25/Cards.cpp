//============================================================================
// Name        : Cards.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "DeckOfCards.h"

using namespace std;

int main() {

	DeckOfCards deck;
	deck.shuffle();
	deck.deal();

	return 0;
}

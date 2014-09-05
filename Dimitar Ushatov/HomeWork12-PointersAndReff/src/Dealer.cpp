/*
 * Dealer.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: NandM
 */

#include "Dealer.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

Dealer::Dealer() {
	// TODO Auto-generated constructor stub

}

vector<Card> Dealer::generateDeck() {
	vector<Card> initialDeck;
	vector<Card> deck;
	Suit currentSuit;
	Face currentFace;

	for (int suit = 0; suit <= Spade; suit++) {
		for (int face = 0; face <= Ace; face++) {
			currentSuit = static_cast<Suit>(suit);
			currentFace = static_cast<Face>(face);
			initialDeck.push_back(Card(currentSuit, currentFace));
		}
	}

	int index;
	srand(time(NULL));

	while(initialDeck.size() != 0) {
		index = rand() % initialDeck.size();
		deck.push_back(initialDeck.at(index));
		initialDeck.erase(initialDeck.begin() + index);
	}

	return deck;
}

void Dealer::dealCard(Card& card, Player& player) {
	player.addCard(card);
}

void Dealer::shuffleDeck(vector<Card> & deck) {
	int firstCardIndex;
	int secondCardIndex;
	srand(time(NULL));
	int shuffleCount = 50 + rand() % 101;
	for (int shuffle = 0; shuffle < shuffleCount; shuffle++) {
		firstCardIndex = rand() % deck.size();
		secondCardIndex = rand() % deck.size();
		swap(deck[firstCardIndex], deck[secondCardIndex]);
	}
}

Dealer::~Dealer() {
	// TODO Auto-generated destructor stub
}

bool Dealer::compareHandsOfPlayers(Player first, Player second) {
	return second.getPowerOfHand() < first.getPowerOfHand();
}

void Dealer::declareWinner(vector<Player> players) {
	sort(players.begin(), players.end(), compareHandsOfPlayers);

}

//============================================================================
// Name        : HomeWork12-PointersAndReff.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "Dealer.h"
#include "Card.h"
#include "Enumerations.h"

using namespace std;

string stringifyCard(Card);
string stringifyHand(PowerOfHands);

int main() {
	vector<Card> deck = Dealer::generateDeck();

	vector<Player> players;
	players.push_back(Player());
	players.push_back(Player());
	players.push_back(Player());
	players.push_back(Player());
	players.push_back(Player());
	players.push_back(Player());
	players.push_back(Player());
	players.push_back(Player());
	players.push_back(Player());

	for (int card = 0; card < 5; ++card) {
		for (unsigned int player = 0; player < players.size(); ++player) {
			Dealer::dealCard(deck[deck.size() - 1], players[player]);
			deck.erase(deck.begin() + (deck.size() - 1));
		}
	}

	for (unsigned int player = 0; player < players.size(); ++player) {
		for (unsigned int card = 0; card < players[player].getHand().size();
				++card) {
			cout << stringifyCard(players[player].getHand().at(card)) << endl;
		}
		cout << stringifyHand(players[player].getPowerOfHand()) << endl << endl;
	}
	return 0;
}

string stringifyHand(PowerOfHands hand) {
	string suitStr[] = {
			"High Card", "One Pair" , "Two Pair", "Three Of A Kind"
			, "Straight", "Flush", "Full House", "Four Of A Kind", "Straight Flush"};

	return suitStr[hand];
}

string stringifyCard(Card card) {
	string result = "";

	string faceStr[] = { "Deuce", "Two", "Four", "Five", "Six", "Seven",
			"Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };

	string suitStr[] = { "Clubs", "Diamonds", "Hearts", "Spades" };

	result = faceStr[card.getFace()] + " of " + suitStr[card.getSuit()];

	return result;
}

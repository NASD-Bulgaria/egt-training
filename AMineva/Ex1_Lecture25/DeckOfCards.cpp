/*
 * DeckOfCards.cpp
 *
 *  Created on: Sep 3, 2014
 *      Author: Student
 */

#include "DeckOfCards.h"
#include <iostream>
using std::endl;
using std::cout;
using std::cin;
using std::left;
using std::right;

#include <iomanip>
using std::setw;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

DeckOfCards::DeckOfCards() {

	static char *suit[4] = {"Hearts" , "Diamonds", "Clubs", "Spades"};

	static char *face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
								"Eight", "Nine", "Ten", "Jack", "Queen", "King"};

	static char *color[2] = {"Red" , "Black" };

	for(int i = 0; i < 52; i++) {
		deck[i].face = face[i % 13];
		deck[i].suit = suit[i / 13];
		deck[i].color = color[i / 26];
	}


	srand(time(0));
}

void DeckOfCards::shuffle() {
	for(int i = 0; i < 52; i++) {
		int j = rand() % 52;
		Card temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}


void DeckOfCards::deal() {
	for(int i = 0; i < 52; i++) {
		cout<<right << setw(5)<<deck[i].color<<" "<<deck[i].face <<" of "
				<<left << setw(15) << deck[i].suit
				<<((i + 1) % 2 ? '\t' : '\n');
	}
}

/*
 * DeckOfCards.cpp
 *
 *  Created on: 3.09.2014 ã.
 *      Author: D00M
 */
#include <iostream>
using std::cout;
using std::left;
using std::right;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstdlib>
using std::srand;
using std::rand;

#include <ctime>
using std::time;

#include "DeckOfCards.h"

DeckOfCards::DeckOfCards() {

//	const char heart = 'U+2661';


	static char *suit[4] = {"Hearts","Diamonds","Clubs","Spades"};

	static char *face[13] = {"A", "2", "3", "4", "5", "6", "7",
			 "8", "9", "10", "J", "Q", "K"};



	static char *color[2] = {"Red","Black"};

	for(int i = 0; i < 52; i++) {
		deck[i].face = face[i % 13];
		deck[i].suit = suit[i / 13];
		deck[i].color = color[i / 26];
	}
	srand(time(NULL));
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
		cout << right << setw( 5 )<<deck[i].color<<" "<< deck[ i ].face << " of "
		 << left << setw( 15 ) << deck[ i ].suit
		 << ( ( i + 1 ) % 2 ? '\t' : '\n' );
	}
}

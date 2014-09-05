/*
 * Enumerations.h
 *
 *  Created on: Aug 11, 2014
 *      Author: NandM
 */

#ifndef ENUMERATIONS_H_
#define ENUMERATIONS_H_
using namespace std;

enum Face {
	Deuce,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace,
	noFace
};

enum Suit {
	Club,
	Diamond,
	Heart,
	Spade,
	noSuit
};

enum PowerOfHands {
	HighCard,
	OnePair,
	TwoPair,
	ThreeOfAKind,
	Straight,
	Flush,
	FullHouse,
	FourOfAKind,
	StraightFlush,
	noPower
};




#endif /* ENUMERATIONS_H_ */

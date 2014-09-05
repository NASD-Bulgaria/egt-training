/*
 * HandCondition.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: NandM
 */

#include "HandCondition.h"
#include <algorithm>

HandCondition::~HandCondition() {
	// TODO Auto-generated destructor stub
}

bool HandCondition::compareCards(Card first, Card second) {
	return first.getFace() < second.getFace();
}

bool HandCondition::hasFlush(vector<Card> cards) {
	Suit firstSuit = cards[0].getSuit();
	for (unsigned int card = 1; card < cards.size(); ++card) {
		if (firstSuit != cards[card].getSuit()) {
			return false;
		}
	}
	return true;
}

bool HandCondition::hasStaight(vector<Card> cards) {
	sort(cards.begin(), cards.end(), compareCards);
	if (cards[0].getFace() == Deuce && cards[1].getFace() == Three && cards[2].getFace() == Four
		&& cards[3].getFace() == Five && cards[4].getFace() == Ace){
		return true;
	}
	for (unsigned int card = 1; card < cards.size(); ++card) {
		if (cards[card].getFace() - cards[card - 1].getFace() != 1) {
			return false;
		}
	}
	return true;
}

bool HandCondition::hasStaightFlush(vector<Card> cards) {
	if (hasFlush(cards) && hasStaight(cards)) {
		return true;
	}
	return false;
}

bool HandCondition::hasFourOfAKind(vector<Card> cards) {
	sort(cards.begin(), cards.end(), compareCards);
	if (cards[0].getFace() != cards[1].getFace()) {
		if (cards[1].getFace() == cards[2].getFace()
				&& cards[2].getFace() == cards[3].getFace()
				&& cards[3].getFace() == cards[4].getFace()) {
			return true;
		}
	} else if (cards[0].getFace() == cards[1].getFace()
			&& cards[1].getFace() == cards[2].getFace()
			&& cards[2].getFace() == cards[3].getFace()) {
		return true;
	}
	return false;
}

bool HandCondition::hasFullHouse(vector<Card> cards) {
	sort(cards.begin(), cards.end(), compareCards);
	if (cards[0].getFace() == cards[1].getFace()
			&& cards[1].getFace() != cards[2].getFace()
			&& cards[2].getFace() == cards[3].getFace()
			&& cards[3].getFace() == cards[4].getFace()) {
		return true;
	}
	if (cards[0].getFace() == cards[1].getFace()
			&& cards[1].getFace() == cards[2].getFace()
			&& cards[2].getFace() != cards[3].getFace()
			&& cards[3].getFace() == cards[4].getFace()) {
		return true;
	}
	return false;
}

bool HandCondition::hasThreeOfAKind(vector<Card> cards) {
	sort(cards.begin(), cards.end(), compareCards);
	if (cards[0].getFace() == cards[1].getFace()
			&& cards[1].getFace() == cards[2].getFace()){
		return true;
	}
	if (cards[1].getFace() == cards[2].getFace()
			&& cards[2].getFace() == cards[3].getFace()){
		return true;
	}
	if (cards[2].getFace() == cards[3].getFace()
			&& cards[3].getFace() == cards[4].getFace()){
		return true;
	}
	return false;
}

bool HandCondition::hasTwoPairs(vector<Card> cards) {
	sort(cards.begin(), cards.end(), compareCards);
	if (cards[0].getFace() == cards[1].getFace()
			&& cards[2].getFace() == cards[3].getFace()){
		return true;
	}
	if (cards[0].getFace() == cards[1].getFace()
			&& cards[3].getFace() == cards[4].getFace()){
		return true;
	}
	if (cards[1].getFace() == cards[2].getFace()
			&& cards[3].getFace() == cards[4].getFace()){
		return true;
	}
	return false;
}

bool HandCondition::hasOnePair(vector<Card> cards){
	sort(cards.begin(), cards.end(), compareCards);
	if (cards[0].getFace() == cards[1].getFace()
			|| cards[1].getFace() == cards[2].getFace()
		    || cards[2].getFace() == cards[3].getFace()
			|| cards[3].getFace() == cards[4].getFace()){
		return true;
	}
	return false;
}

HandCondition HandCondition::Checker() {
	return HandCondition();
}

void HandCondition::declareWinner() {
}

HandCondition::HandCondition() {
	this->conditions.push_back(hasStaightFlush);
	this->conditions.push_back(hasFourOfAKind);
	this->conditions.push_back(hasFullHouse);
	this->conditions.push_back(hasFlush);
	this->conditions.push_back(hasStaight);
	this->conditions.push_back(hasThreeOfAKind);
	this->conditions.push_back(hasTwoPairs);
	this->conditions.push_back(hasOnePair);
}

const vector<bool (*)(vector<Card>)>& HandCondition::getConditions() const {
	return this->conditions;
}

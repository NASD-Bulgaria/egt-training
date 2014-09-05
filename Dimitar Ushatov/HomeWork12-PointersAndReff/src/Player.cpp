/*
 * Player.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: NandM
 */

#include "Player.h"
#include <algorithm>
#include <iostream>
using namespace std;

Player::Player() {
	this->powerOfHand = noPower;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

PowerOfHands Player::getPowerOfHand() const {
	return this->powerOfHand;
}

void Player::addCard(Card& card) {
	if (this->hand.size() < 5) {
		this->hand.push_back(card);
	}
	if (this->hand.size() == 5) {
		this->setPowerOfHand(HandCondition::Checker().getConditions());
	}
}

void Player::setPowerOfHand(vector<bool (*)(vector<Card>)> conditions) {
	for (unsigned int condition = 0; condition < conditions.size();
			++condition) {
		if (conditions[condition](this->hand)) {
			this->powerOfHand = static_cast<PowerOfHands>(
					conditions.size() - condition);
			return;
		}
	}
	this->powerOfHand = HighCard;
}

const vector<Card> Player::getHand() const {
	return this->hand;
}

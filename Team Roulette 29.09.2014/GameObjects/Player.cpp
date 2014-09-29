/*
 * Player.cpp
 *
 *  Created on: Sep 22, 2014
 *      Author: NandM
 */

#include "Player.h"

namespace GameObjects {

Player::Player(int balance) {
	this->balance = balance;
}

void Player::addToBalance(int amount) {
	this->balance += amount;
}

NumberBet Player::createNumberBet(short number,int amount) {
	if (this->creditBalance(amount)) {
		return NumberBet(number, amount);
	} else {
		exit(1);
	}
}

ColorBet Player::createColorBet(Color color,int amount) {
	if (this->creditBalance(amount)) {
		return ColorBet(color, amount);
	} else {
		exit(1);
	}
}

TypeBet Player::createTypeBet(Type type, int amount) {
	if (this->creditBalance(amount)) {
		return TypeBet(type, amount);
	} else {
		exit(1);
	}
}

HalfBet Player::createHalfBet(Half half, int amount) {
	if (this->creditBalance(amount)) {
		return HalfBet(half, amount);
	} else {
		exit(1);
	}
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

int Player::getBalance() {
	return balance;
}

bool Player::creditBalance(int amount) {
	if (this->balance >= 0 + amount) {
		balance -= amount;
		return true;
	}

	return false;
}

} /* namespace GameObjects */

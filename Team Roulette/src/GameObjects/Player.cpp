/*
 * Player.cpp
 *
 *  Created on: Sep 22, 2014
 *      Author: NandM
 */

#include "Player.h"

namespace GameObjects {

Player::Player(int balance)
	:BET_AMOUNT(5){
	this->balance = balance;
	totalBet = 0;
}

void Player::addToBalance(int amount) {
	this->balance += amount;
}

Bet * Player::createNumberBet() {
	if (totalBet + BET_AMOUNT <= balance) {
		increaseBet();
		return new Bet(36, BET_AMOUNT);
	}
	return NULL;
}

Bet * Player::createNormalBet() {
	if (totalBet + BET_AMOUNT <= balance) {
		increaseBet();
		return new Bet(2, BET_AMOUNT);
	}
	return NULL;
}

Player::~Player() {
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

void Player::increaseBet() {
	totalBet += BET_AMOUNT;
}

void Player::decreaseBet() {
	if (totalBet - BET_AMOUNT >= 0) {
		totalBet -= BET_AMOUNT;
	}
}

int Player::getTotalBet() {
	return totalBet;
}

void Player::clearBet() {
	totalBet = 0;
}

}

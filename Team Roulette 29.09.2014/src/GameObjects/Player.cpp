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
	oldBet = 0;
	colorBet = NULL;
	numberBet = NULL;
	typeBet = NULL;
	halfBet = NULL;
}

void Player::addToBalance(int amount) {
	this->balance += amount;
}

NumberBet * Player::createNumberBet(short number,int amount) {
	if (this->creditBalance(amount)) {
		numberBet->setCredits(amount);
		numberBet->setNumber(number);
		return numberBet;
	} else {
		exit(1);
	}
}

ColorBet * Player::createColorBet(Color color,int amount) {
	if (this->creditBalance(amount)) {
		colorBet->setColor(color);
		colorBet->setCredits(amount);
		return colorBet;
	} else {
		exit(1);
	}
}

TypeBet * Player::createTypeBet(Type type, int amount) {
	if (this->creditBalance(amount)) {
		typeBet->setCredits(amount);
		typeBet->setType(type);
		return typeBet;
	} else {
		exit(1);
	}
}

HalfBet * Player::createHalfBet(Half half, int amount) {
	if (this->creditBalance(amount)) {
		halfBet->setCredits(amount);
		halfBet->setHalf(half);
		return halfBet;
	} else {
		exit(1);
	}
}

Player::~Player() {
	if (numberBet) {
		numberBet->free();
		delete numberBet;
		numberBet = NULL;
	}
	if (typeBet) {
		typeBet->free();
		delete typeBet;
		typeBet = NULL;
	}
	if (halfBet) {
		halfBet->free();
		delete halfBet;
		halfBet = NULL;
	}
	if (colorBet) {
		colorBet->free();
		delete colorBet;
		colorBet = NULL;
	}
}

int Player::getBalance() {
	return balance;
}

int Player::getOldBet() const {
	return oldBet;
}

void Player::setOldBet(int oldBet) {
	this->oldBet = oldBet;
}

bool Player::creditBalance(int amount) {
	if (this->balance >= 0 + amount) {
		balance -= amount;
		return true;
	}

	return false;
}

} /* namespace GameObjects */

bool GameObjects::Player::initPlayer(SDL_Renderer* gRenderer,
		std::string betImgPath) {
	bool success = true;
	oldBet = 0;
	colorBet = new ColorBet(RedColor, 5);
	typeBet = new TypeBet(EvenType, 5);
	halfBet = new HalfBet(LowHalf, 5);
	numberBet = new NumberBet(0, 5);
	success = success & colorBet->loadFromFile(gRenderer, betImgPath);
	success = success & typeBet->loadFromFile(gRenderer, betImgPath);
	success = success & halfBet->loadFromFile(gRenderer, betImgPath);
	success = success & numberBet->loadFromFile(gRenderer, betImgPath);
	return success;
}

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
	totalBet = 0;
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
		totalBet += amount;
		return numberBet;
	}
	return NULL;
}

ColorBet * Player::createColorBet(Color color,int amount) {
	if (this->creditBalance(amount)) {
		colorBet->setColor(color);
		colorBet->setCredits(amount);
		totalBet += amount;
		return colorBet;
	}
	return NULL;
}

TypeBet * Player::createTypeBet(Type type, int amount) {
	if (this->creditBalance(amount)) {
		typeBet->setCredits(amount);
		typeBet->setType(type);
		totalBet += amount;
		return typeBet;
	}
	return NULL;
}

HalfBet * Player::createHalfBet(Half half, int amount) {
	if (this->creditBalance(amount)) {
		halfBet->setCredits(amount);
		halfBet->setHalf(half);
		totalBet += amount;
		return halfBet;
	}
	return NULL;
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

int Player::getTotalBet() const {
	return totalBet;
}

void Player::resetBet() {
	this->totalBet = 0;
}

bool Player::creditBalance(int amount) {
	if (this->balance >= 0 + amount) {
		balance -= amount;
		return true;
	}

	return false;
}

bool Player::initPlayer(SDL_Renderer* gRenderer,
		std::string betImgPath) {
	bool success = true;
	totalBet = 0;
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

int Player::getOldBet() const {
	return oldBet;
}

void Player::setOldBet(int oldBet) {
	this->oldBet = oldBet;
}

}

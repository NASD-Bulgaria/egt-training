/*
 * Player.cpp
 *
 *  Created on: Sep 19, 2014
 *      Author:
 */

#include "Player.h"

Player::Player()
{
	setCredit(250);
	setWins(0);
	setGamesCount(0);
}

Player::~Player()
{
}

void Player::setCredit(int inpCredit)
{
	credit = inpCredit;
}

int Player::getCredit() const
{
	return credit;
}

int Player::getGamesCount() const
{
	return gamesCount;
}

void Player::setGamesCount(int gamesCount)
{
	this->gamesCount = gamesCount;
}

int Player::getWins() const
{
	return wins;
}

void Player::setWins(int wins)
{
	this->wins = wins;
}

void Player::CounterWins()
{
	setGamesCount(getGamesCount() + 1);
	setWins(getWins() + 1);
}

void Player::CounterLoss()
{
	setGamesCount(getGamesCount() + 1);
}

/*
 * Player.cpp
 *
 *  Created on: 20.09.2014 �.
 *      Author: msi
 */

#include "Player.h"
Player::Player(){}

Player::Player(int credit,int bet,int win)
{
	this->credit = credit;
	this->bet = bet;
	this->win = win;
}


Player::~Player() {}

void Player::setCredit(int k)
{
	credit=k;
}

void Player::nullBetAndWin()
{
	this->bet = 0;
	this->win = 0;
}
void Player::setBet(int playerBet)
{
	bet += playerBet;
}
void Player::setWin(int playerWins)
{
	win += playerWins;
}

int Player::getCredit()
{
	int difference = win - bet;
	credit += difference;
	return credit;
}
int Player::getBet()
{
	return bet;
}
int Player::getWin()
{
	return win;
}

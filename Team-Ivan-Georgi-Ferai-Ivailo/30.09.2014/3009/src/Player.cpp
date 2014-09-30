/*
 * Player.cpp
 *
 *  Created on: 20.09.2014 �.
 *      Author: msi
 */

#include "Player.h"
Player::Player()
{
	credit = 0;
	bet = 0;
	win = 0;
	showWin = 0;
}

Player::Player(int credit,int bet,int win)
{
	this->credit = credit;
	this->bet = bet;
	this->win = win;
	this->showWin = 0;
}


Player::~Player() {}

void Player::nullWin()
{
	this->win = 0;
}
void Player::setShowWin(int integer)
{
	showWin = integer;
}

int Player::getShowWin()
{
	return showWin;
}

void Player::setCredit(int k)
{
	credit = k;
}

void Player::nullBet()
{
	this->bet = 0;
}
void Player::setBet(int playerBet)
{
	bet += playerBet;
}
void Player::setWin(int playerWins)
{
	win += playerWins;
}

int Player::showCredit()
{
	return credit;
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

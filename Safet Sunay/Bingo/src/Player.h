/*
 * Player.h
 *
 *  Created on: Sep 19, 2014
 *      Author:
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "BingoTicket.h"

class Player
{
public:
	Player();
	virtual ~Player();
	void setCredit(int);
	int getCredit() const;
	int getGamesCount() const;
	void setGamesCount(int gamesCount);
	int getWins() const;
	void setWins(int wins);
	void CounterWins();
	void CounterLoss();

private:
	int credit;
	int wins;
	int gamesCount;
};

#endif /* PLAYER_H_ */

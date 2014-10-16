/*
 * Player.h
 *
 *  Created on: Sep 22, 2014
 *      Author: NandM
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Bet.h"
#include <String>

namespace GameObjects {

class Player {
	friend class RouletteApplication;
public:
	Player(int balance);
	void addToBalance(int amount);
	bool creditBalance(int amount);
	Bet * createNumberBet();
	Bet * createNormalBet();
	int getBalance();
	virtual ~Player();
	const int BET_AMOUNT;
	void increaseBet();
	void decreaseBet();
	int getTotalBet();
	void clearBet();
private:
	int balance;
	int totalBet;
};

} /* namespace GameObjects */

#endif /* PLAYER_H_ */

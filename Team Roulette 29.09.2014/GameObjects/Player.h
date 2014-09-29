/*
 * Player.h
 *
 *  Created on: Sep 22, 2014
 *      Author: NandM
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "NumberBet.h"
#include "ColorBet.h"
#include "TypeBet.h"
#include "HalfBet.h"

namespace GameObjects {

class Player {
public:
	Player(int balance);
	void addToBalance(int amount);
	NumberBet createNumberBet(short number, int amount);
	ColorBet createColorBet(Color color, int amount);
	TypeBet createTypeBet(Type type, int amount);
	HalfBet createHalfBet(Half half, int amount);
	int getBalance();
	virtual ~Player();
private:
	int balance;
	bool creditBalance(int amount);
};

} /* namespace GameObjects */

#endif /* PLAYER_H_ */

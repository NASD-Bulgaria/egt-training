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
#include <String>

namespace GameObjects {

class Player {
	friend class RouletteApplication;
public:
	Player(int balance);
	void addToBalance(int amount);
	bool creditBalance(int amount);
	bool initPlayer(SDL_Renderer*, std::string betImgPath);
	NumberBet * createNumberBet(short number, int amount);
	ColorBet * createColorBet(Color color, int amount);
	TypeBet* createTypeBet(Type type, int amount);
	HalfBet* createHalfBet(Half half, int amount);
	int getBalance();
	virtual ~Player();
	int getTotalBet() const;
	void resetBet();
	int getOldBet() const;
	void setOldBet(int oldBet);

private:
	int balance;
	int totalBet;
	int oldBet;
	ColorBet * colorBet;
	NumberBet * numberBet;
	TypeBet * typeBet;
	HalfBet * halfBet;
};

} /* namespace GameObjects */

#endif /* PLAYER_H_ */

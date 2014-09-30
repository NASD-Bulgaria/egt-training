/*
 * RouletteApplication.h
 *
 *  Created on: Sep 22, 2014
 *      Author: NandM
 */

#ifndef ROULETTEAPPLICATION_H_
#define ROULETTEAPPLICATION_H_

#include "GameBoard.h"
#include "RouletteWheel.h"
#include "Player.h"

namespace GameObjects {

class RouletteApplication {
public:
	RouletteApplication(GameBoard* board, Player* player, RouletteWheel* wheel);
	virtual ~RouletteApplication();
	void handleBetCreation(int mouseX, int mouseY);
	void loadMedia();
	void init();
//private:
	RouletteWheel* wheel;
	GameBoard* board;
	Player* player;
};

} /* namespace GameObjects */

#endif /* ROULETTEAPPLICATION_H_ */

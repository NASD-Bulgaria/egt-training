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
#include "Statistics.h"

namespace GameObjects {

class RouletteApplication {
public:
	RouletteApplication(GameBoard* board, Player* player, RouletteWheel* wheel,
			IRendable* bet, IRendable* win, IRendable* balance);
	virtual ~RouletteApplication();
	void handleBetCreation(int mouseX, int mouseY);
	void loadMedia();
	void init();
	void changeInfoValues(SDL_Renderer* gRenderer);
//private:
	RouletteWheel* wheel;
	GameBoard* board;
	Player* player;
	IRendable* infoFields[3];
};

} /* namespace GameObjects */

#endif /* ROULETTEAPPLICATION_H_ */

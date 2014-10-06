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
	RouletteApplication(RouletteWheel* wheel, GameBoard* board, Player* player);
	virtual ~RouletteApplication();
	void handleMouseEvent(SDL_MouseButtonEvent e, SDL_Renderer* gRenderer);
	void loadMedia();
	void init(SDL_Renderer * gRenderer);
	void changeInfoValues(SDL_Renderer* gRenderer);
//private:
	RouletteWheel* wheel;
	GameBoard* board;
	Player* player;
	vector<IRendable> infoFields;
	vector<IRendable> infoButtons;
	vector<IRendable> rouletteButtons;
	IRendable lastNumbers;
	IRendable winnNumber;
	void handleBetCreation(int x, int y, SDL_Renderer* gRenderer);
	void handleBetDeletion(int x, int y, SDL_Renderer* gRenderer);
	void initInfoButtons(SDL_Renderer* gRenderer);
	void intiRouletteButtons(SDL_Renderer* gRenderer);
	void initInfoFields(SDL_Renderer* gRenderer);
};

} /* namespace GameObjects */

#endif /* ROULETTEAPPLICATION_H_ */

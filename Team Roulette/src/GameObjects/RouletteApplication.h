/*
 * RouletteApplication.h
 *
 *  Created on: Sep 22, 2014
 *      Author: NandM
 */

#ifndef ROULETTEAPPLICATION_H_
#define ROULETTEAPPLICATION_H_

#include "GameBoard.h"
#include "RouletteBoard.h"
#include "Player.h"
#include "Statistics.h"
#include "Recovery.h"
#include <map>
#include <algorithm>

namespace GameObjects {

class RouletteApplication {
public:
	RouletteApplication(SDL_Renderer* gRenderer);
	virtual ~RouletteApplication();
	void handleMouseEvent(SDL_MouseButtonEvent e, SDL_Renderer* gRenderer);
	void init(SDL_Renderer * gRenderer);
	void initElements(SDL_Renderer * gRenderer);
	void changeBetInfo(SDL_Renderer* gRenderer, int totalBet);
	void changeBalanceInfo(SDL_Renderer* gRenderer, int balanceAmount);
	void changeWinInfo(SDL_Renderer* gRenderer, int winAmount);
	void setStatisticLines(SDL_Renderer* gRenderer, vector<PlayerRecord> *);
	void drawStatisticLines(SDL_Renderer* gRenderer);
	void setLast12(SDL_Renderer* gRenderer, vector<StatisticRecord>*);
	void handleSpinState(SDL_Renderer* gRenderer);
	void drawLast12(SDL_Renderer* gRenderer);
	void drawMaxOccurrences(SDL_Renderer* gRenderer);
	void draw(SDL_Renderer* grenderer);
//private:
	RouletteBoard* rouletteBoard;
	GameBoard* board;
	Player* player;
	Recovery* recovery;
	Statistics* stats;
	map<string, Button *> allButtons;
	map<string, IRendable *> simpleElements;
	map<string, Mix_Chunk*> musicChunks;
	Mix_Music* music;
	void handleBetCreation(int x, int y, SDL_Renderer* gRenderer);
	void handleBetDeletion(int x, int y, SDL_Renderer* gRenderer);
	void handleNumberHit(SDL_Renderer * gRenderer);
	void drawStatScreen(SDL_Renderer* gRenderer);
	void drawGameScreen(SDL_Renderer* gRenderer);
	void drawInitialScreen(SDL_Renderer* gRenderer);
	void drawInfoScreen(SDL_Renderer* gRenderer);
	void drawAboutUsScreen(SDL_Renderer* gRenderer);
	void setMaxOccurrences(SDL_Renderer* gRenderer, int*);
	void handleButtonClick(SDL_Renderer* gRenderer, int x, int y);
	void drawBonusMsg(SDL_Renderer* gRenderer);
	bool statChange;
	void initMusic();
	static bool compareRecords(pair<int,int> first,pair<int,int> second);
	GameState currentGameState;
	bool musicOn, soundfxOn;
	unsigned int bonusShowTicks;
	static string colors[3];
	static int elementCoords[31][2];
	static string elementloadPats[31];
	static string elementNames[31];
	static string statElementNames[15];
	static string lastTenNumbersNames[12];
	static int lastTenNumbersCoords[12][2];
	static GameState allowedGameStates[16];
};

} /* namespace GameObjects */

#endif /* ROULETTEAPPLICATION_H_ */

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
	RouletteApplication();
	virtual ~RouletteApplication();
	void start();
private:
	SDL_Renderer* gRenderer = NULL;
	SDL_Window* gWindow = NULL;

	RouletteBoard* rouletteBoard;
	GameBoard* board;
	Player* player;
	Statistics* stats;
	Recovery* recovery;

	IRendable* gCursorDefault;
	IRendable* gCursor;
	IRendable* gCursorClicked;
	map<string, Button *> allButtons;
	map<string, IRendable *> simpleElements;
	map<string, Mix_Chunk*> musicChunks;
	Mix_Music* music;

	GameState currentGameState;
	bool musicOn, soundfxOn;
	unsigned int bonusShowTicks;
	bool statChange;

	void handleBetCreation(int x, int y);
	void handleBetDeletion(int x, int y);
	void handleNumberHit();
	void drawStatScreen();
	void drawGameScreen();
	void drawInitialScreen();
	void drawInfoScreen();
	void drawAboutUsScreen();
	void setMaxOccurrences(int*);
	void handleButtonClick(int x, int y);
	void drawBonusMsg();
	void initSDL();
	void initMusic();
	void handleMouseEvent(SDL_MouseButtonEvent e);
	void init();
	void initElements();
	void changeBetInfo(int totalBet);
	void changeBalanceInfo(int balanceAmount);
	void changeWinInfo(int winAmount);
	void setStatisticLines(vector<PlayerRecord> *);
	void drawStatisticLines();
	void setLast12(vector<StatisticRecord>*);
	void handleSpinState();
	void drawLast12();
	void drawMaxOccurrences();
	void draw();

	static string colors[3];
	static int elementCoords[31][2];
	static string elementloadPats[31];
	static string elementNames[31];
	static string statElementNames[15];
	static string lastTenNumbersNames[12];
	static int lastTenNumbersCoords[12][2];
	static GameState allowedGameStates[16];

	static bool compareRecords(pair<int,int> first,pair<int,int> second);
};

} /* namespace GameObjects */

#endif /* ROULETTEAPPLICATION_H_ */

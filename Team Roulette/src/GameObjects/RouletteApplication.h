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
#include <algorithm>

namespace GameObjects {

class RouletteApplication {
public:
	RouletteApplication();
	virtual ~RouletteApplication();
	void handleMouseEvent(SDL_MouseButtonEvent e, SDL_Renderer* gRenderer);
	void loadMedia(SDL_Renderer * gRenderer);
	void init(SDL_Renderer * gRenderer);
	void changeInfoValues(SDL_Renderer* gRenderer);
	void setStatisticLines(SDL_Renderer* gRenderer,
			vector<PlayerRecord>& records);
	void drawStatisticLines(SDL_Renderer* gRenderer);
	void setLast10(SDL_Renderer* gRenderer,
			vector<StatisticRecord>& records);
	void drawLast10(SDL_Renderer* gRenderer);
	void drawMaxOccurrences(SDL_Renderer* gRenderer);
	void draw(SDL_Renderer* grenderer);
//private:
	RouletteBoard* rouletteBoard;
	GameBoard* board;
	Player* player;
	Recovery* recovery;
	Statistics* stats;
	vector<IRendable> infoFields;
	vector<IRendable> infoButtons;
	vector<IRendable> rouletteButtons;
	vector<IRendable*> last10;
	vector<IRendable*> statisticLines;
	vector<IRendable*> maxOccurrences;
	vector<Mix_Chunk*> musicChunks;
	vector<Mix_Music*> numSounds;
	Mix_Music* music;
	IRendable * lastNumbers;
	IRendable * statBackground;
	IRendable * startBackground;
	IRendable * infoBackground;
	IRendable * mainBackground;
	bool buttonLocks[9];
	void handleBetCreation(int x, int y, SDL_Renderer* gRenderer);
	void handleBetDeletion(int x, int y, SDL_Renderer* gRenderer);
	bool handleButtonLocks(int x, int y);
	void handleRouletteButtonClick(int x, int y);
	void handleNumberHit(SDL_Renderer * gRenderer);
	void drawHomeScreen(SDL_Renderer* gRenderer);
	void drawMainScreen(SDL_Renderer* gRenderer);
	void drawInfoScreen(SDL_Renderer* gRenderer);
	void drawStatScreen(SDL_Renderer* gRenderer);
	void initInfoButtons(SDL_Renderer* gRenderer);
	void setMaxOccurrences(SDL_Renderer* gRenderer, int*);
	void initRouletteButtons(SDL_Renderer* gRenderer);
	void initMusic();
	void initInfoFields(SDL_Renderer* gRenderer);
	static bool compareRecords(pair<int,int> first,pair<int,int> second);
	static string colors[3];
};

} /* namespace GameObjects */

#endif /* ROULETTEAPPLICATION_H_ */

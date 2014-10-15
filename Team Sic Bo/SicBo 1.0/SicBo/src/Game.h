#ifndef GAME_H_
#define GAME_H_
#include "TrueTypeFont.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "Music.h"
using namespace std;

enum{
		GAMETABLE=1,
		HELPFIRST,
		HELPSECOND,
		HELPTHIRD,
		STATSMENU
};

class Game : public TrueTypeFont, Music
{
protected:
	bool running;
	bool soundOffOn;
	int switchScreen;
//	int menu;
public:
	Game();

	virtual ~Game();

	bool init(string title,int x,int y,int w,int h);

	bool loadMedia();

	void drawTable();

	void handleGameEvents();
	void handleEvents();
	void handleHelpEvent();
	void handleHelpFirst();

	void handleRollButton(SDL_Event &);
	void handleClearButton(SDL_Event &);
	void handleNewGameButton(SDL_Event &);
	void handleSoundsButtons(SDL_Event &event);
	void handleHelpButton(SDL_Event &event);

	void handleNextFirstButton(SDL_Event &event);
	void handlePrevButton(SDL_Event &event);

	void handleBackToGameButton(SDL_Event &event);
	void handleStatsMenuButton(SDL_Event &event);
	void helpWindowScreen();
	void helpSecondScreen();
	void helpThirdScreen();
	void statsWindowScreen();

	void leftMouseSetBet(SDL_Event &event);
	void rightMouseRemoveBet(SDL_Event &event);

	void free();

	void reduceFPS();

	bool isRunning(){return running;}
};

#endif /* GAME_H_ */

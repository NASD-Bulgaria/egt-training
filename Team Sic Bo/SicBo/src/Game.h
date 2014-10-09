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

class Game : public TrueTypeFont, Music
{
private:
	bool running;
	bool helpWindow;
	bool soundoffon;
public:
	Game();

	virtual ~Game();

	bool init(string title,int x,int y,int w,int h);

	bool loadMedia();

	void drawTable();

	void handleGameEvents();
	void handleEvents();
	void handleRollButton(SDL_Event &);
	void handleClearButton(SDL_Event &);
	void handleNewGameButton(SDL_Event &);
	void handleSoundsButtons(SDL_Event &event);
	void handleHelpButton(SDL_Event &event);
	void handleBackToGameButton(SDL_Event &event);
	void helpWindowScreen();
	void free();

	void reduceFPS();

	bool isRunning(){return running;}



};

#endif /* GAME_H_ */

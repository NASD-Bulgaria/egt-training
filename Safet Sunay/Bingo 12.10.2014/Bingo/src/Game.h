/*
 * Game.h
 *
 *  Created on: Sep 28, 2014
 *      Author:
 */

#ifndef GAME_H_
#define GAME_H_

#include "GlobalVariables.h"
#include "Sound.h"
#include "Button.h"
#include "BingoBallCalls.h"
#include "BingoEfect.h"

const int 	START_POSITION_LAFIN = 335;

struct ButtonSwitch
{
	unsigned rulesSwitch : 1;
	unsigned infoSwitch :1;
	unsigned muteSounds : 1;
	unsigned stopMusic : 1;
	unsigned overFifty : 1;
	unsigned PlayerComputer : 1;
};

enum SwitchStatus
{
	OFF = 0,
	ON = 1
};

enum Buttons
{
	NEW_GAME = 0,
	RULES = 1,
	INFO = 2,
	QUIT = 3,
	PLAY = 4,
	MUSIC_BUTTON = 5,
	SOUND_BUTTON = 6
};

enum LaFinBalls
{
	B = 0,
	I = 1,
	N = 2,
	G = 3,
	O = 4
};

class Game
{
public:
	Game();
	virtual ~Game();

	void renderScreen();
	void playgameVars();
	void gameChecks();
	int win(bool hor, bool vert, bool diag);
	bool renderBall(Uint32);
	void buttonPress(SDL_Event&);
	bool getQuit();
	void setQuit(bool);
	SDL_Rect*spriteclip(int i, int height);
	void setBallNum(int ballNum);
	int getBallNum();
	void gameStatus(bool);

	void laFin();
	void laFinEffect(bool);


	bool searchButton(int&, int&, SDL_Event&);
	void renderButtonsGlow();

	bool isPlay();
	void setPlay(bool);

	void displayCredit(int);
	void displayBet(int);

	int getRuleSwitch();
	int getScoreSwitch();
	int getGamesCount() const;
	int getPlayerWins() const;

	ButtonSwitch switches;
private:
	BingoBallCalls calls;
	vector<BingoBallCalls> chunkList;

	BingoEfect efects;
	vector<BingoEfect> efectList;

	vector<Button> panel;
	Button button;

	bool mouseOverGlow;

	int renderingButton;

	bool spriteRender(int &moveVert, int &hideHeight, int &h, SDL_Rect* clip, Uint32);

	int i;
	int height;
	int h;

	bool quit;
	bool play;
	int ballNum;
	float stop;

	Uint32 startTime;

	bool gameStatusWin;

	bool winGame;

	string status;

	Sound beep;
};

#endif /* GAME_H_ */

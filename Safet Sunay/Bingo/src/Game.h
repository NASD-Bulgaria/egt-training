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

struct ButtonSwitch
{
	unsigned rulesSwitch : 1;
	unsigned scoreSwitch :1;
	unsigned muteSounds : 1;
	unsigned stopMusic : 1;
	unsigned overFifty : 1;
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
	void buttonPress(SDL_Event);
	bool getQuit();
	void setQuit(bool);
	SDL_Rect*spriteclip(int i, int height);
	void setBallNum(int ballNum);
	int getBallNum();
	void gameStatus(bool);


	bool isPlay();
	void setPlay(bool);

	void displayCredit(int);
	void displayBet(int);

	bool getbPlay();
	void setbPlay(bool);

	bool getbHighScore();
	void setbHighScore(bool);

	bool getbRules();
	void setbRules(bool);


	bool getbQuit();
	void setbQuit(bool);

	bool getbSound();
	void setbSound(bool);

	bool getbMusic();
	void setbMusic(bool);


	bool getbNewGame();
	void setbNewGame(bool);


	int getRuleSwitch();
	int getScoreSwitch();
	int getGamesCount() const;
	int getPlayerWins() const;

	ButtonSwitch switches;
private:
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

	bool bNewgame;
	bool bHighscore;
	bool bRules;
	bool bQuit;
	bool bPlay;
	bool bSound;
	bool bMusic;

	bool winGame;

	string status;

	Sound beep;
};

#endif /* GAME_H_ */

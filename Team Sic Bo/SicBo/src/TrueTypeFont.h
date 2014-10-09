/*
 * TrueTypeFont.h
 *
 *  Created on: 2.10.2014 �.
 *      Author: msi
 */

#ifndef TRUETYPEFONT_H_
#define TRUETYPEFONT_H_
#include "Draw.h"
#include "Player.h"
#include "RollDice.h"
#include "stdio.h"
#include "SDL.h"
#include "SDL2/SDL_ttf.h"
#include <string>
#include <sstream>
using namespace std;

class TrueTypeFont : public Draw, public Recovery
{
protected:
	RollDice testDice;

	Recovery record;
	TTF_Font* gFont = NULL;
	SDL_Surface* result = NULL;
public:
	TrueTypeFont();
	virtual ~TrueTypeFont();
	void load();

	TTF_Font* loadfont(string file,int size);
	SDL_Surface* createImageFromString(string text);

	void drawAllTTF();
	void drawBetText(int);

	void loadChipText(int,SDL_Surface* stringImage);
	void loadYellowChip(int);
	void loadBlueChip(int);
	void loadRedChip(int);

	void choiceChipColor(int);
	int choiceChipBetbyColor(int bet);

	void onScreenBet();
	void onScreenWin(Player &ob);
	void onScreenCredit(Player &ob);
	void onHighScore(Recovery &high);
	void dicesVisual();
	void fakeDiceRoll();

	void closeFont();

};

#endif /* TRUETYPEFONT_H_ */

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
#include "Statistic.h"
#include "RollDice.h"
#include "stdio.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include <string>
#include <sstream>
using namespace std;

class TrueTypeFont : public Draw, public Recovery
{
protected:
	RollDice testDice;
	string fullStatisticData[16];
	Statistic printStatistic;

	Recovery record;
	TTF_Font* gFont = NULL;
	TTF_Font* statisticFont = NULL;
	SDL_Surface* result = NULL;
public:
	TrueTypeFont();
	virtual ~TrueTypeFont();
	void load();

	TTF_Font* loadfont(string file,int size);
	// loadfont - function to load a ttf font.
	// @param string - path do the ttf font.
	// @param int - size of the font.

	SDL_Surface* createImageFromString(TTF_Font* ,string text);
	// createImageFromString - function to draw image from string on the screen
	// @param string - text to draw on the screen.

	void printStatisticData();
	// printStatisticData - function to print statistic on the statistic screen.

	void drawAllTTF();
	// drawAllTTF - function to draw all TTF in the game.

	void drawBetText(int);
	// drawBetText - function to draw Bet over the chip.
	// @param int - size of the bet.

	void loadChipText(int,SDL_Surface* stringImage);
	// loadChipText - function to load chip and bet over the chip.
	// @param int -
	// param SDL_Surface* -

	void loadYellowChip(int);
	// loadYellowChip - function to load a yellow chip.
	// @param int -

	void loadBlueChip(int);
	// loadBlueChip - function to load a blue chip.
	// @param int -

	void loadRedChip(int);
	// loadRedChip - function to load a red chip.
	// @param int -

	void choiceChipColor(int);
	// choiceChipColor - function which change chip color.
	// @param int -

	int choiceChipBetbyColor(int bet);
	// choiceChipbyColor - function to change text over the chip.
	// @param int -

	void onScreenBet();
	// onScreenBet - function to display current bet from all positions.

	void onScreenWin(Player &ob);
	// onScreenWin - function to display current win if there is any after the roll.
	// @param Player& -

	void onScreenCredit(Player &ob);
	// onScreenCredit - function to display current credits of the player.
	// @param Player& -

	void onHighScore(Recovery &high);
	// onHighScore - function to display max Win from 1 roll from all games so far.
	// @param Recovery& -

	void dicesVisual();
	// dicesVisual - function to display right dices after the roll.

	void fakeDiceRoll();
	// fakeDiceRoll - function to display dices when player hit roll button.

	void closeFont();
	// closeFont - function to close all ttf objects we create.

};

#endif /* TRUETYPEFONT_H_ */

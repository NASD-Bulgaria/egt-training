/*
 * Draw.h
 *
 *  Created on: 1.10.2014 �.
 *      Author: msi
 */

#ifndef DRAW_H_
#define DRAW_H_
#include "RollDice.h"
#include "Player.h"
#include "Recovery.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "stdio.h"
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Draw : public RollDice
{
public:
	Draw();
	virtual ~Draw();

	//DRAW FUNCTION
	bool loadMediaImages();
	SDL_Surface* loadSurface(std::string path);

	void draw();
	void freeSurface(SDL_Surface* image);
	SDL_Surface* getImage();
	SDL_Rect getButtonRect();
	SDL_Surface* getSurface();

	void CreateObjects();
	void addButtonInformation(int ID,int,int, SDL_Surface* image,SDL_Surface* screen);
	void objectFiller(int ID,int,int, SDL_Surface* image_name,SDL_Surface* screen);
	void menuFiller(int ID,int,int, SDL_Surface* image_name,SDL_Surface* screen);

	void drawImages();
	void freeImages();
	void rollButtonOn();
	void newGameButtonOn();
	void clearButtonOn();

	void soundImageOffOn( bool sound );
	void musicImageOffOn();

	void mouseCursor();

	bool checkEvents(SDL_Event *);
	int getID();

	// MATH FUNCTION
	void checkWinner(int ID,int a,int b, int c);
	void checkSmall(int unique,int a,int b,int c);
	void checkBig(int unique,int a,int b,int c);

	void calculateDouble(int unique, int a,int b,int c);

	void calculateTriple(int unique,int a,int b, int c);
	void calculateAnyTriple(int a,int b,int c);

	void calculateSum(int unique,int a,int b,int c);
	void coeff_4_17(int unique);
	void coeff_5_16(int unique);
	void coeff_6_15(int unique);
	void coeff_7_14(int unique);
	void coeff_8_13(int unique);
	void coeff_9_12(int unique);
	void coeff_10_11(int unique);

	void calculateStraigth(int unique,int a,int b, int c);
	void calculateAnyStraigth(int a,int b, int c);

	void calculateTwo_pair(int first,int second,int a,int b, int c);

	void calculateOne_pair(int unique,int a,int b,int c);

	//PLAYER FUNCTION
	void setBet(int);
	void check1000();
	void check200();
	void check175();
	void check125();
	void check100();
	void check60();
	void check50();
	void check25();
	void check10();

	int getBet();
	int getWin();

	void nullBetAndWin();
	void winningPosition();
	void clearButtonsMODE();
protected:
	SDL_Window* window;
	enum { SMALL = 0, BIG, DOUBLE_1, DOUBLE_2, DOUBLE_3, DOUBLE_4, DOUBLE_5,
		   DOUBLE_6, ANY_TRIPLE, TRIPLE_1, TRIPLE_2, TRIPLE_3, TRIPLE_4, TRIPLE_5,
		   TRIPLE_6, SUM_4, SUM_5, SUM_6, SUM_7, SUM_8, SUM_9, SUM_10, SUM_11,
		   SUM_12, SUM_13, SUM_14, SUM_15, SUM_16, SUM_17, PAIR_1_2, PAIR_1_3,
		   PAIR_1_4, PAIR_1_5, PAIR_1_6, PAIR_2_3, PAIR_2_4, PAIR_2_5, PAIR_2_6,
		   PAIR_3_4, PAIR_3_5, PAIR_3_6, PAIR_4_5, PAIR_4_6, PAIR_5_6, ANYSTRAIGHT,
		   STR_1_2_3, STR_2_3_4, STR_3_4_5, STR_4_5_6, ONE, TWO, THREE, FOUR, FIVE, SIX };
	enum {D_1 = 1,D_2,D_3,D_4,D_5,D_6};
	int bet;
	int win;
	int ID;
	int totalPlayerBet;

	vector<Draw> buttonImages;
	vector<Draw> menuButtons;
	SDL_Surface* image;
	SDL_Surface* surface;
	SDL_Rect image_rect;

	SDL_Surface* backGround = NULL;
//bet info images.
	SDL_Surface *topInfo = NULL;
	SDL_Surface *eachDiceInfo = NULL;
	SDL_Surface* creditButton = NULL;
	SDL_Surface* betButton = NULL;
	SDL_Surface* pairInfo = NULL;
	SDL_Surface* chipInfo = NULL;
//non bet button images.
	SDL_Surface* newGame = NULL;
	SDL_Surface* newGameOn = NULL;
	SDL_Surface* highScore = NULL;
	SDL_Surface* help = NULL;
	SDL_Surface* next = NULL;
	SDL_Surface* prev = NULL;
	SDL_Surface* statsButton = NULL;
	SDL_Surface* backToGame = NULL;
	SDL_Surface* backToMenu = NULL;
	SDL_Surface* clear = NULL;
	SDL_Surface* clearOn = NULL;
	SDL_Surface* roll = NULL;
	SDL_Surface* rollOn = NULL;
//surface for winning dice.
	SDL_Surface *rollDiceOne = NULL;
	SDL_Surface *rollDiceTwo = NULL;
	SDL_Surface *rollDiceThree = NULL;
	SDL_Surface *rollDiceFour = NULL;
	SDL_Surface *rollDiceFive = NULL;
	SDL_Surface *rollDiceSix = NULL;
//surfaces for bets.
	SDL_Surface* small = NULL;
	SDL_Surface* big = NULL;
	SDL_Surface* doubleOne = NULL;
	SDL_Surface* doubleTwo = NULL;
	SDL_Surface* doubleThree = NULL;
	SDL_Surface* doubleFour = NULL;
	SDL_Surface* doubleFive = NULL;
	SDL_Surface* doubleSix = NULL;
	SDL_Surface* tripleOne = NULL;
	SDL_Surface* tripleTwo = NULL;
	SDL_Surface* tripleThree = NULL;
	SDL_Surface* tripleFour = NULL;
	SDL_Surface* tripleFive = NULL;
	SDL_Surface* tripleSix = NULL;
	SDL_Surface* anyTriple = NULL;
	SDL_Surface* sumFour = NULL;
	SDL_Surface* sumFive = NULL;
	SDL_Surface* sumSix = NULL;
	SDL_Surface* sumSeven = NULL;
	SDL_Surface* sumEight = NULL;
	SDL_Surface* sumNine = NULL;
	SDL_Surface* sumTen = NULL;
	SDL_Surface* sumEleven = NULL;
	SDL_Surface* sumTwelve = NULL;
	SDL_Surface* sumThirteen = NULL;
	SDL_Surface* sumFourteen = NULL;
	SDL_Surface* sumFifteen = NULL;
	SDL_Surface* sumSixteen = NULL;
	SDL_Surface* sumSeventeen = NULL;
	SDL_Surface* pairOneTwo = NULL;
	SDL_Surface* pairOneThree = NULL;
	SDL_Surface* pairOneFour = NULL;
	SDL_Surface* pairOneFive = NULL;
	SDL_Surface* pairOneSix = NULL;
	SDL_Surface* pairTwoThree = NULL;
	SDL_Surface* pairTwoFour = NULL;
	SDL_Surface* pairTwoFive = NULL;
	SDL_Surface* pairTwoSix = NULL;
	SDL_Surface* pairThreeFour = NULL;
	SDL_Surface* pairThreeFive = NULL;
	SDL_Surface* pairThreeSix = NULL;
	SDL_Surface* pairFourFive = NULL;
	SDL_Surface* pairFourSix = NULL;
	SDL_Surface* pairFiveSix = NULL;
	SDL_Surface* anyStraight = NULL;
	SDL_Surface* oneTwoThree = NULL;
	SDL_Surface* TwoThreeFour = NULL;
	SDL_Surface* ThreeFourFive = NULL;
	SDL_Surface* FourFiveSix = NULL;
	SDL_Surface* one = NULL;
	SDL_Surface* two = NULL;
	SDL_Surface* three = NULL;
	SDL_Surface* four = NULL;
	SDL_Surface* five = NULL;
	SDL_Surface* six = NULL;
//Chips
	SDL_Surface* yellowChip = NULL;
	SDL_Surface* redChip = NULL;
	SDL_Surface* blueChip = NULL;
//sound
	SDL_Surface* soundOn = NULL;
	SDL_Surface* soundOff = NULL;
	SDL_Surface* musicOn = NULL;
	SDL_Surface* musicOff = NULL;
//start menu buttons
	SDL_Surface* startContinue = NULL;
	SDL_Surface* startNewGame = NULL;
	SDL_Surface* startQuickGuide = NULL;
	SDL_Surface* startCred = NULL;
	SDL_Surface* startQuit = NULL;
};

#endif /* DRAW_H_ */

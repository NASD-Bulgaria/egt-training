/*
 * Double.h
 *
 *  Created on: 7.10.2014 �.
 *      Author: Emil
 */

#ifndef DOUBLE_H_
#define DOUBLE_H_
#include "SDL.h"
#include "Buttons.h"
#include "Game.h"
#include <cstdlib>
#include <ctime>

class Double
{
public:

	Buttons doubleButton;

	Double();

	void drawDoubleCard(SDL_Renderer *, int, Statistics &stat, Credits &credit,
			Game &game, bool &);
	void drawDoubleButton(SDL_Renderer * gRenderer, int x, int y, int w, int h);
	bool loadDoubleFromFile(SDL_Renderer* gRender, string path);
	bool checkDoubleButton(int mouseX, int mouseY);

	int getSuit() const;
	void setSuit();
	int getFace() const;
	void setFace();

private:
	int face;
	int suit;
	Bets bet;
};

#endif /* DOUBLE_H_ */

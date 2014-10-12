/*
 * BingoEfect.h
 *
 *  Created on: 9.10.2014 ã.
 *      Author: sony
 */

#ifndef BINGOEFECT_H_
#define BINGOEFECT_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct ColorBitCut
{
	unsigned r : 7;
	unsigned g : 7;
	unsigned b : 7;
	unsigned reverse : 1;
};

class BingoEfect
{
public:
	BingoEfect();
	void loadBingoEfects(string);
	void fillEfects(string efectPath, int x, int y, vector<BingoEfect>& efectContainer, BingoEfect temp);
	void fillEfectsInVector(vector<BingoEfect>& efectContainer, BingoEfect obj);
	void setEfectRect(int, int);
	void setEfectRectWH(int, int);
	void makeEffect(int, int);
	void setRenderer(SDL_Renderer*);
	void moveLaFinEffect(int, int);
	bool shrink();
	bool moveDown();
	bool chooseDirection(int, int);
	bool moveWhileSpining(int);
	void setColor( Uint8 red, Uint8 green, Uint8 blue );
	void colorEffect(int);
	void returnDefaultValuesEffect(int);

	virtual ~BingoEfect();

private:
	static SDL_Renderer* renderer;
	SDL_Texture* efectTexture;
	SDL_Rect m_Rect;
	string path;
	int degrees;
	int process;
	ColorBitCut cuttingColor;
	static int cutColor;
};

#endif /* BINGOEFECT_H_ */

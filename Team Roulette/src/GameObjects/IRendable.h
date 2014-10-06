/*
 * IRendable.h
 *
 *  Created on: Sep 29, 2014
 *      Author: NandM
 */

#ifndef IRENDABLE_H_
#define IRENDABLE_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>

using namespace std;
namespace GameObjects {

class IRendable {
public:
	IRendable(int x = 0, int y = 0);
	virtual bool loadFromFile(SDL_Renderer* gRenderer, std::string path);
	virtual ~IRendable();
	virtual void draw(SDL_Renderer*, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	virtual bool isClicked(int x, int y);
	virtual void free();
	int getHeight() const;
	void setHeight(int height);
	int getWidth() const;
	void setWidth(int width);
	int getX() const;
	int getY() const;
	virtual void setPosition(int x, int y);
	void setTextRectX(int x);
	void setTextRectY(int y);
	void setTextRectW(int w);
	void setTextRectH(int h);
	int getTextRectX();
	int getTextRectY();
	void setRenderedText(SDL_Renderer* gRenderer, string text, int size = 24,
			Uint8 r = 255, Uint8 g = 255, Uint8 b = 255,string fontPath = "Roulette/rio.ttf");

protected:
	SDL_Texture * mTexture;
	SDL_Texture * textTexture;
	SDL_Rect textRect;
	SDL_Rect rect;

};

} /* namespace GameObjects */

#endif /* IRENDABLE_H_ */

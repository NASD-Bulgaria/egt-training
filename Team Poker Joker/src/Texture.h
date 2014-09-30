/*
 * Texture.h
 *
 *  Created on: Sep 24, 2014
 *      Author: vasko
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>
using namespace std;
#include "Game.h"
class Texture
{
	friend class Buttons;
public:
	Texture();
	virtual ~Texture();
	bool loadFromFile(SDL_Renderer* gRender, string path); // to do virtual
	bool loadFromRenderedText(SDL_Renderer* gRenderer, TTF_Font* gFont,
			string textureText, SDL_Color textColor);

	void free();
	void card(SDL_Renderer* gRender, int srcX, int srcY, int destX, int destY);
	void button(SDL_Renderer* gRender, int destX, int destY, int srcW,
			int srcH);
	void render(SDL_Renderer* gRenderer, int x, int y);

	int getWidth();
	int getHeight();
	SDL_Texture* getTexture();

private:
	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;
};

#endif /* TEXTURE_H_ */

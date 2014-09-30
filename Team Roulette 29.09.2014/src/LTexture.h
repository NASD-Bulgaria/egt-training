#ifndef LTEXTURE_H_
#define LTEXTURE_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

class LTexture
{
public:
	LTexture();

	~LTexture();

	bool loadFromFile(SDL_Renderer * gRenderer, std::string path);

	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);

	void free();

	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	void setBlendMode(SDL_BlendMode blending);

	void setAlpha(Uint8 alpha);

	void render(SDL_Renderer * gRenderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	int getWidth();
	int getHeight();

protected:
	SDL_Texture* mTexture;

	int mWidth;
	int mHeight;
};

#endif 

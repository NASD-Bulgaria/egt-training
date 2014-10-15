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

public:
	Texture();
	virtual ~Texture();

	bool loadFromRenderedText(SDL_Renderer* gRenderer, TTF_Font* gFont,
			string textureText, SDL_Color textColor);
	void free();
	void render(SDL_Renderer* gRenderer, int x, int y);
	bool loadFromFile(SDL_Renderer* gRender, string path);
	int getWidth();
	int getHeight();
	SDL_Texture* getTexture();

private:
	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;
};

#endif /* TEXTURE_H_ */

#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>

#ifndef KTEXTURE_H_
#define KTEXTURE_H_

using namespace std;

class KTexture
{
public:

	//Initializes variables
	KTexture();

	//Deallocates memory
	~KTexture();

	//Loads image at specified path
	bool loadFromFile(SDL_Renderer* gRenderer, std::string path );

	//Deallocates texture
	void free();


	//Renders texture at given point
	void render(SDL_Renderer* gRenderer, int x, int y, SDL_Rect* clip = NULL );
	void button(SDL_Renderer* gRender, int destX, int destY, int srcW, int srcH);
	void buttonMusic(SDL_Renderer* gRender, int destX, int destY, int srcW, int srcH);
	void buttonClear(SDL_Renderer* gRender, int destX, int destY, int srcW, int srcH);
	void buttonQuickPick(SDL_Renderer* gRender, int destX, int destY, int srcW, int srcH);
	void help(SDL_Renderer* gRender, int destX, int destY, int srcW, int srcH);
	void ballRender(SDL_Renderer* gRender, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

	bool loadFromRenderedText(SDL_Renderer*, TTF_Font*, string, SDL_Color);
	void renderText(SDL_Renderer*, int x, int y);

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};

#endif

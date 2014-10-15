#ifndef BUTTONS_H_
#define BUTTONS_H_
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
using namespace std;

class Buttons
{
public:
	Buttons();

	virtual ~Buttons();

	bool checkButton(int mouseX, int mouseY);
	bool loadFromFile(SDL_Renderer* gRender, string path);
	void drawCard(SDL_Renderer* gRender, int srcX, int srcY, int destX,
			int destY,int width);
	void drawButton(SDL_Renderer* gRender, int destX, int destY, int srcW,
			int srcH);
//	void updateCardWidth(SDL_Renderer* gRender, Buttons &gCard, int cardX,int width);
	void free();

	int getButtonH();
	void setButtonH(int h);

	int getButtonW();
	void setButtonW(int w);

	int getButtonX();
	void setButtonX(int x);

	int getButtonY();
	void setButtonY(int y);

	int getWidth();
	int getHeight();
	SDL_Texture* getTexture();

private:

	int buttonX; //cardX
	int buttonY; //cardY
	int buttonW;
	int buttonH;
	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;
};

#endif /* BUTTONS_H_ */

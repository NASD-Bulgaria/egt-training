#include "Buttons.h"

Buttons::Buttons()
{
	buttonX = 0;
	buttonY = 0;
	buttonW = 0;
	buttonH = 0;
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

Buttons::~Buttons()
{
	free();
}

int Buttons::getButtonH()
{
	return buttonH;
}

void Buttons::setButtonH(int h)
{
	this->buttonH = h;
}

int Buttons::getButtonW()
{
	return buttonW;
}

void Buttons::setButtonW(int w)
{
	this->buttonW = w;
}

int Buttons::getButtonX()
{
	return buttonX;
}

void Buttons::setButtonX(int x)
{
	this->buttonX = x;
}

int Buttons::getButtonY()
{
	return buttonY;
}

void Buttons::setButtonY(int y)
{
	this->buttonY = y;
}

bool Buttons::checkButton(int mouseX, int mouseY)
{
	return (mouseX > getButtonX() && mouseX < getButtonX() + getButtonW()
			&& mouseY > getButtonY() && mouseY < getButtonY() + getButtonH());
}

bool Buttons::loadFromFile(SDL_Renderer* gRender, string path)
{
	free();

	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	SDL_Surface* optimizedSuraface = NULL;
	if (loadedSurface == NULL)
	{
		cout << "Could not load the Texture	" << SDL_GetError();
	}
	else
	{
		optimizedSuraface = SDL_ConvertSurface(loadedSurface,
				loadedSurface->format, 0);
		newTexture = SDL_CreateTextureFromSurface(gRender, optimizedSuraface);
		if (newTexture == NULL)
		{
			cout << "Texture could not be created !!! " << SDL_GetError();
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}
	mTexture = newTexture;
	return mTexture != NULL;
}
void Buttons::drawCard(SDL_Renderer* gRender, int X, int Y, int destX,
		int destY, int width)
{

	SDL_Rect src =
	{ X, Y, 79, 123 };
	SDL_Rect dest =
	{ destX, destY, width, 190 };
	SDL_RenderCopy(gRender, mTexture, &src, &dest);

	setButtonX(137);
	setButtonY(400);
	setButtonW(750);
	setButtonH(190);
}
void Buttons::drawButton(SDL_Renderer* gRender, int destX, int destY, int destW,
		int destH)
{
	SDL_Rect src =
	{ 0, 0, 109, 65 };
	SDL_Rect dest =
	{ destX, destY, destW, destH };
	SDL_RenderCopy(gRender, mTexture, &src, &dest);

	setButtonX(destX);
	setButtonY(destY);
	setButtonW(destW);
	setButtonH(destH);
}
void Buttons::free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}
int Buttons::getWidth()
{
	return mWidth;
}

int Buttons::getHeight()
{
	return mHeight;
}

//void Buttons::updateCardWidth(SDL_Renderer* gRender, Buttons &gCard, int cardX,
//		int width)
//{
//
//	SDL_Rect src =
//	{ 158, 492, 79, 123 };
//	SDL_Rect dest =
//	{ cardX, 400, width, 190 };
//	SDL_RenderCopy(gRender, mTexture, &src, &dest);
//	cardX += 150;
//
//}

SDL_Texture* Buttons::getTexture()
{
	return mTexture;
}

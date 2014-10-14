/*
 * LTexture.h
 *
 *  Created on: 25.09.2014
 *      Author:
 */

#ifndef LTEXTURE_H_
#define LTEXTURE_H_

#include "GlobalVariables.h"

using namespace std;

class LTexture
{
public:
	LTexture();
	bool loadFromFile( std::string path );
	void free();
	void render( int x, int y);
	void render( int x, int y, SDL_Rect* clip );
	void renderScreen(int x, int y);
	bool loadFromRenderedText( string textureText, SDL_Color textColor );
	bool loadFromRenderedTextStatistics( string textureText, SDL_Color textColor );
	virtual ~LTexture();
	int getHeight() const;
	int getWidth() const;
	void setHeight(int height);
	void setWidth(int width);

private:
	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;
};

#endif /* LTEXTURE_H_ */

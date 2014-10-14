/*
 * LTexture.cpp
 *
 *  Created on: 25.09.2014
 *      Author:
 */

#include "LTexture.h"

LTexture::LTexture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;

}

LTexture::~LTexture()
{
	free();
}

bool LTexture::loadFromFile(std::string path) //Load images
{
	free();
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0xFF, 0x00, 0x00 ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

bool LTexture::loadFromRenderedText( string textureText, SDL_Color textColor ) //Convert fonts to textures
{
	//Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* surface = TTF_RenderText_Solid( font, textureText.c_str(), textColor );
	if( surface == NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, surface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth =  surface->w;
			mHeight = surface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( surface );
	}

	//Return success
	return mTexture != NULL;
}

void LTexture::free()
{
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render(int x, int y) //Render loaded texture at certain position (x, y)
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	SDL_RenderCopy( gRenderer, mTexture, NULL, &renderQuad );
}

void LTexture::render( int x, int y, SDL_Rect* clip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
	//	renderQuad.w = clip->w;
	//	renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad );
}

int LTexture::getHeight() const //Get image height
{
	return mHeight;
}

int LTexture::getWidth() const //Get image width
{
	return mWidth;
}

void LTexture::renderScreen(int x, int y) //Render background
{
	SDL_Rect renderQuad = { x, y, SCREEN_WIDTH, SCREEN_HEIGHT };
	SDL_RenderCopy( gRenderer, mTexture, NULL, &renderQuad );
}

void LTexture::setHeight(int height)
{
	mHeight = height;
}

bool LTexture::loadFromRenderedTextStatistics(string textureText,
		SDL_Color textColor)
{
	//Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* surface = TTF_RenderText_Solid( statis, textureText.c_str(), textColor );
	if( surface == NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, surface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth =  surface->w;
			mHeight = surface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( surface );
	}

	//Return success
	return mTexture != NULL;
}

void LTexture::setWidth(int width)
{
	mWidth = width;
}

#include "KTexture.h"

KTexture::KTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

KTexture::~KTexture()
{
	//Deallocate
	free();
}

bool KTexture::loadFromFile(SDL_Renderer* gRenderer, std::string path )
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

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

void KTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}



void KTexture::render(SDL_Renderer* gRenderer, int x, int y, SDL_Rect* clip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad );
}

void KTexture::buttonPlay(SDL_Renderer* gRender, int destX, int destY, int srcW,
		int srcH)
{
	SDL_Rect src =
	{ 0, 0, 216, 216 };
	SDL_Rect dest =
	{ destX, destY, srcW, srcH };
	SDL_RenderCopy(gRender, mTexture, &src, &dest);
}

void KTexture::buttonClear(SDL_Renderer* gRender, int destX, int destY, int srcW, int srcH)
{
	SDL_Rect src = { 0, 0, 143, 117 };
	SDL_Rect dest = { destX, destY, srcW, srcH };
	SDL_RenderCopy(gRender, mTexture, &src, &dest);
}

void KTexture::buttonQuickPick(SDL_Renderer* gRender, int destX, int destY, int srcW, int srcH)
{
	SDL_Rect src = { 0, 0, 95, 54 };
	SDL_Rect dest = { destX, destY, srcW, srcH };
	SDL_RenderCopy(gRender, mTexture, &src, &dest);
}


void KTexture::help(SDL_Renderer* gRender, int destX, int destY, int srcW, int srcH)
{
	SDL_Rect src = { 0, 0, 878, 640 };
	SDL_Rect dest = { destX, destY, srcW, srcH };
	SDL_RenderCopy(gRender, mTexture, &src, &dest);
}

int KTexture::getWidth()
{
	return mWidth;
}

int KTexture::getHeight()
{
	return mHeight;
}

bool KTexture::loadFromRenderedText(SDL_Renderer* gRenderer, TTF_Font* gFont, string Text, SDL_Color textColor )
{
	free();

	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, Text.c_str(), textColor );
	if( textSurface == NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}

	//Return success
	return mTexture != NULL;
}

void KTexture::renderText(SDL_Renderer* gRenderer, int x, int y)
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	SDL_RenderCopy( gRenderer, mTexture, NULL, &renderQuad);
}



void KTexture::ballRender(SDL_Renderer* gRender, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{

	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopyEx( gRender, mTexture, clip, &renderQuad, angle, center, flip );
}



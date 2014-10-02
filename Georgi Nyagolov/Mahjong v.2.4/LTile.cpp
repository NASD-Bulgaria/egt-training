#include "LTile.h"
#include <iostream>

LTile::LTile(faceType face)
{
    blocked = true;
    this->face = face;
}

LTile::~LTile()
{
    freeTile();
}

bool LTile::getblocked()
{
    return blocked;
}
void LTile::setblocked(bool checking)
{
    blocked = checking;
}

faceType LTile::getFace() const
{
    return face;
}

void LTile::setFace(faceType face)
{
    this->face = face;
}

void LTile::freeTile()
{
    freeButton();
}

bool LTile::handleEvent( SDL_Event e )
{
    bool temp = false;
	//If mouse event happened
	if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if( x < getPositionX() )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > getPositionX() + getWidth() )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < getPositionY() )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > getPositionY() + getHeight() )
		{
			inside = false;
		}

		//Mouse is outside button
		if( !inside )
		{
		    LTexture::setTexture(getTextureBase());
		}
		//Mouse is inside button
		else
		{
		    //Set mouse over sprite
			switch( e.type )
			{
				case SDL_MOUSEMOTION:
				    if(getblocked())
                    {
                        LTexture::setTexture(getTextureMotion());
                    }
                    break;

				case SDL_MOUSEBUTTONDOWN:
				    if(getblocked())
                    {
                        LTexture::setTexture(getTextureDown());
                    }
                    break;

				case SDL_MOUSEBUTTONUP:
				    if(getblocked())
                    {
                        LTexture::setTexture(getTextureUp());
                    }
//				    temp = true;
                    break;
			}
		}
	}
	return temp;
}



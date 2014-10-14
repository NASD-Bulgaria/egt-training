/*
 * Logo.cpp
 *
 *  Created on: Oct 11, 2014
 *      Author: Keen
 */

#include "Logo.h"

Logo::Logo(SDL_Texture* image_display, SDL_Rect destination):
		image_display(image_display),
		destination(destination)
{
}

void Logo::Draw(SDL_Renderer *renderer)
{
	SDL_RenderCopyEx ( renderer, image_display, NULL, &destination, 0, NULL, SDL_FLIP_NONE );
}

void Logo::SetImage(SDL_Texture *image)
{
    this->image_display = image;
}

bool Logo::HandleMouseEvent(Uint32, int, int)
{
    return false;
}

Logo::~Logo() {
	// TODO Auto-generated destructor stub
}


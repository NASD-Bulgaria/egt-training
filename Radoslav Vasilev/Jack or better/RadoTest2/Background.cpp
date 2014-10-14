#include "Background.h"
#include <SDL2/SDL.h>

Background::Background()
{
	this->image = NULL;
}

Background::~Background()
{
}

void Background::Draw(SDL_Renderer *renderer)
{
    SDL_RenderCopyEx ( renderer, image, NULL, NULL, 0, NULL, SDL_FLIP_NONE );
}

void Background::SetImage(SDL_Texture *image)
{
    this->image = image;
}

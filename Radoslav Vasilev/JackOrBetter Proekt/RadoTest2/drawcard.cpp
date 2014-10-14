#include "drawcard.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

DrawCard::DrawCard()
{
    original_dimension.x = 0;
    original_dimension.y = 0;
    original_dimension.w = 230;
    original_dimension.h = 320;
}

DrawCard::~DrawCard()
{

}

void DrawCard::Draw(SDL_Renderer *renderer)
{
    SDL_RenderCopyEx ( renderer,image,NULL,&original_dimension,0,NULL,SDL_FLIP_NONE );
}

const SDL_Rect &DrawCard::GetPosition()
{
    return original_dimension;
}

void DrawCard::SetPosition(int x, int y)
{
    original_dimension.x = x;
    original_dimension.y = y;
}

void DrawCard::SetImage(SDL_Texture *image)
{
    this->image = image;
}

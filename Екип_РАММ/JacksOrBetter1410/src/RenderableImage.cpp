#include "RenderableImage.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

RenderableImage::RenderableImage()
{
    original_dimension.x = 0;
    original_dimension.y = 0;
    original_dimension.w = 57;
    original_dimension.h = 57;
}

RenderableImage::~RenderableImage()
{

}

void RenderableImage::Draw(SDL_Renderer *renderer)
{
    SDL_RenderCopyEx ( renderer,image,NULL,&original_dimension,0,NULL,SDL_FLIP_NONE );
}

bool RenderableImage::HandleMouseEvent(Uint32 , int , int )
{
    return false;
}

const RenderableImage &RenderableImage::operator=(const RenderableImage &rhs)
{
    this->image = rhs.image;

    return *this;
}

const SDL_Rect &RenderableImage::GetPosition()
{
    return original_dimension;
}

void RenderableImage::SetPosition(int x, int y)
{
    original_dimension.x = x;
    original_dimension.y = y;
}

void RenderableImage::SetImage(SDL_Texture *image)
{
    this->image = image;
}

void RenderableImage::SetSize(int w, int h)
{
    original_dimension.w = w;
    original_dimension.h = h;
}



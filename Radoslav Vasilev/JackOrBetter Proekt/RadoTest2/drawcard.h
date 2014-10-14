#ifndef DRAWCARD_H
#define DRAWCARD_H

#include "IRenderable.h"
#include <SDL2/SDL_rect.h>


class SDL_Texture;

class DrawCard :public IRenderable
{
public:
    DrawCard();
    ~DrawCard();
    void Draw(SDL_Renderer* renderer);

    const SDL_Rect& GetPosition();
    void SetPosition(int x, int y);
    void SetImage(SDL_Texture* image);

private:
    SDL_Texture* image;
    SDL_Rect original_dimension;
};

#endif // DRAWCARD_H

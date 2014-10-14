#ifndef IWIDGET_H
#define IWIDGET_H

#include <SDL2/SDL_stdinc.h>

class SDL_Renderer;


class IWidget
{
public:
    virtual void Draw(SDL_Renderer*) = 0;
    virtual bool HandleMouseEvent(Uint32 ,int ,int) = 0;

    virtual ~IWidget();
};

#endif // IWIDGET_H

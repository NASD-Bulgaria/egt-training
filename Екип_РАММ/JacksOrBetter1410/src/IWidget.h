#ifndef IWIDGET_H
#define IWIDGET_H

#include <SDL2/SDL_stdinc.h>

class SDL_Renderer;


class IWidget
{
public:
    IWidget();

    virtual void Draw(SDL_Renderer* renderer) = 0;
    virtual bool HandleMouseEvent(Uint32 mouse_button_state,int x,int y) = 0;
};

#endif // IWIDGET_H

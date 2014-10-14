#ifndef WIDGETBUTTONBASE_H
#define WIDGETBUTTONBASE_H

#include "IWidget.h"
#include <SDL2/SDL_rect.h>

class SDL_Texture;

class WidgetButtonBase:public IWidget
{
public:
    WidgetButtonBase(SDL_Texture*, SDL_Texture*, SDL_Rect);
    virtual ~WidgetButtonBase();

    void Draw(SDL_Renderer*);
    bool HandleMouseEvent(Uint32, int, int);

    virtual void ButtonPressed(Uint32);
    virtual void ButtonReleased(Uint32);

    bool PointInRect(const SDL_Rect &, int, int);
    void HandleInButtonEvents(Uint32);
    void HandleOutButtonEvents();
    void SetLocation(SDL_Rect);
    const SDL_Rect& GetLocation() const;

    SDL_Rect* getDestination();
    void setDestination(const SDL_Rect &);
    void setDefault_image(SDL_Texture *);
    void setClicked_image(SDL_Texture *);

protected:
    SDL_Texture* current_image;
    SDL_Texture* default_image;
    SDL_Texture* clicked_image;
    SDL_Rect destination;

    enum ButtonState
    {
        StateNone = 0,
        StateMouseOver = 1,
        StateMousePressed = 2
    }current_button_state;
    Uint32 old_button_state;

};

#endif // WIDGETBUTTONBASE_H

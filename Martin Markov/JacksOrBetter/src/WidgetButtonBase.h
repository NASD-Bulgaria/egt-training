#ifndef WIDGETBUTTONBASE_H
#define WIDGETBUTTONBASE_H

#include "IWidget.h"
#include <SDL2/SDL_rect.h>

class SDL_Texture;

class WidgetButtonBase:public IWidget
{
public:
    WidgetButtonBase(SDL_Texture* default_image,SDL_Texture* mouse_over_image,SDL_Texture* clicked_image,SDL_Rect destination);
    virtual ~WidgetButtonBase();

    void Draw(SDL_Renderer* renderer);
    bool HandleMouseEvent(Uint32 mouse_button_state, int x, int y);

    virtual void MouseOverBecome();
    virtual void MouseOverEnds();
    virtual void ButtonPressed(Uint32 mouse_button_state);
    virtual void ButtonReleased(Uint32);

    bool PointInRect(const SDL_Rect &, int x ,int y);
    void HandleInButtonEvents(Uint32 mouse_button_state);
    void HandleOutButtonEvents();
    void SetLocation(SDL_Rect destination);
    const SDL_Rect& GetLocation() const;

    SDL_Rect* getDestination();
    void setDestination(const SDL_Rect &value); 
    void setDefault_image(SDL_Texture *value);
    void setMouse_over_image(SDL_Texture *value);
    void setClicked_image(SDL_Texture *value);

private:
    SDL_Texture* current_image;
    SDL_Texture* default_image;
    SDL_Texture* mouse_over_image;
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

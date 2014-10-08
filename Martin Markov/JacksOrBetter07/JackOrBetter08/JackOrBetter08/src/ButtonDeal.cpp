#include "ButtonDeal.h"
#include "Application.h"

ButtonDeal::ButtonDeal(SDL_Texture *default_image, SDL_Texture *mouse_over_image, SDL_Texture *clicked_image, SDL_Rect destination, Application *app, Mix_Chunk *sound)
    :WidgetButtonBase(default_image,mouse_over_image,clicked_image,destination),
      app(app),
      sound(sound)
{
}

void ButtonDeal::ButtonReleased(Uint32 mouse_button_state)
{
    WidgetButtonBase::ButtonReleased(mouse_button_state);
    if(!app->getCards_flip_delay())
    {
        app->Play();
    }
}

void ButtonDeal::SetButtonState(bool button_state)
{
    if(!button_state)
    {
        WidgetButtonBase::ButtonReleased(1);
    }
}

void ButtonDeal::ButtonPressed(Uint32 mouse_button_state)
{
    WidgetButtonBase::ButtonPressed(mouse_button_state);
    Mix_PlayChannel( -1, sound, 0 );
}


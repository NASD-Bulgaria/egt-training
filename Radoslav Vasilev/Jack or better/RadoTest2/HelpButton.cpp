#include "HelpButton.h"
#include "Application.h"
HelpButton::HelpButton(SDL_Texture *default_image, SDL_Texture *clicked_image, SDL_Rect destination, Application *app, Mix_Chunk* sound_effect):
    WidgetButtonBase(default_image, clicked_image, destination),
    app(app),
    sound_effect(sound_effect)

{
}

void HelpButton::ButtonPressed(Uint32 mouse_button_state)
{
    WidgetButtonBase::ButtonPressed(mouse_button_state);
    Mix_PlayChannel( -1, sound_effect, 0 );
}

void HelpButton::ButtonReleased(Uint32 mouse_button_state)
{
    WidgetButtonBase::ButtonReleased(mouse_button_state);

    app->setIn_main(!app->getIn_main());

}

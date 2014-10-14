#include "SoundButton.h"
#include <SDL2/SDL_mixer.h>
SoundButton::SoundButton(SDL_Texture *default_image, SDL_Texture *clicked_image, SDL_Rect destination, Mix_Chunk* sound_effect_select):
    WidgetButtonBase(default_image, clicked_image, destination),
    sound_on(true),
    sound_effect_select(sound_effect_select)
{
}

void SoundButton::ButtonPressed(Uint32 mouse_button_state)
{
    WidgetButtonBase::ButtonPressed(mouse_button_state);
    Mix_PlayChannel( -1, sound_effect_select, 0 );
}

void SoundButton::ButtonReleased(Uint32 mouse_button_state)
{
    WidgetButtonBase::ButtonReleased(mouse_button_state);

    sound_on=!sound_on;
    if(sound_on)
    {
        Mix_Volume(-1,128);
        Mix_ResumeMusic();
    }
    else
    {
        Mix_Volume(-1,0);
        Mix_PauseMusic();
    }
}

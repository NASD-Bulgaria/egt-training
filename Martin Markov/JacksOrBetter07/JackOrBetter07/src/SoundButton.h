#ifndef SOUNDBUTTON_H
#define SOUNDBUTTON_H
#include "WidgetButtonBase.h"

class SoundButton :public WidgetButtonBase
{
public:
    SoundButton(SDL_Texture* default_image, SDL_Texture* mouse_over_image, SDL_Texture* clicked_image, SDL_Rect destination);

    void MouseOverBecome();
    void MouseOverEnds();
    void ButtonPressed(Uint32 mouse_button_state);
    void ButtonReleased(Uint32 mouse_button_state);
private:
    bool sound_on;
};

#endif // SOUNDBUTTON_H

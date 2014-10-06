#ifndef HELPBUTTON_H
#define HELPBUTTON_H
#include "WidgetButtonBase.h"

class Application;
class HelpButton :public WidgetButtonBase
{
public:
    HelpButton(SDL_Texture* default_image, SDL_Texture* mouse_over_image, SDL_Texture* clicked_image, SDL_Rect destination, Application *app);

    void MouseOverBecome();
    void MouseOverEnds();
    void ButtonPressed(Uint32 mouse_button_state);
    void ButtonReleased(Uint32 mouse_button_state);
private:
    Application* app;
};

#endif // HELPBUTTON_H

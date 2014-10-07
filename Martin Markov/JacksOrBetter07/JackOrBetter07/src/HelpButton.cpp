#include "HelpButton.h"
#include "Application.h"
HelpButton::HelpButton(SDL_Texture *default_image, SDL_Texture *mouse_over_image, SDL_Texture *clicked_image, SDL_Rect destination,Application *app):
    WidgetButtonBase(default_image,mouse_over_image,clicked_image,destination),
    app(app)

{
}

void HelpButton::MouseOverBecome()
{
    WidgetButtonBase::MouseOverBecome();
}

void HelpButton::MouseOverEnds()
{
    WidgetButtonBase::MouseOverEnds();
}

void HelpButton::ButtonPressed(Uint32 mouse_button_state)
{
    WidgetButtonBase::ButtonPressed(mouse_button_state);
}

void HelpButton::ButtonReleased(Uint32 mouse_button_state)
{
    WidgetButtonBase::ButtonReleased(mouse_button_state);

    app->setIn_main(!app->getIn_main());

}

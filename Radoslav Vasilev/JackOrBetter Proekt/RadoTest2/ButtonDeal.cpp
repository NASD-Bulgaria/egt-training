#include "ButtonDeal.h"
#include "Application.h"

ButtonDeal::ButtonDeal(SDL_Texture *default_image, SDL_Texture *mouse_over_image, SDL_Texture *clicked_image, SDL_Rect destination, Application *app)
    :WidgetButtonBase(default_image,mouse_over_image,clicked_image,destination),
      app(app)
{
}

void ButtonDeal::ButtonReleased(Uint32 mouse_button_state)
{
    WidgetButtonBase::ButtonReleased(mouse_button_state);
    app->Play();
}

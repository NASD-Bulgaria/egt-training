#include "CardButton.h"
#include <SDL2/SDL.h>
#include <Application.h>
CardButton::CardButton(SDL_Texture *card_image, SDL_Texture *held_image, SDL_Rect destination, Application *app):WidgetButtonBase(card_image,card_image,card_image,destination),
    app(app),
    held_image(held_image),
    held(false)
{
    RecalculateHeldDestination();
}

void CardButton::MouseOverBecome()
{

}

void CardButton::MouseOverEnds()
{

}

void CardButton::ButtonPressed(Uint32 mouse_button_state)
{

}

void CardButton::ButtonReleased(Uint32 mouse_button_state)
{
    SetHeld(!held);
    //held=!held;
}

void CardButton::Draw(SDL_Renderer *renderer)
{
    WidgetButtonBase::Draw(renderer);
    if(held)
    {
        SDL_RenderCopyEx ( renderer,held_image,NULL, &held_destination,0,NULL,SDL_FLIP_NONE );
    }
}
bool CardButton::GetHeld() const
{
    return held;
}

void CardButton::SetImage(SDL_Texture *image)
{
    WidgetButtonBase::setDefault_image(image);
    WidgetButtonBase::setClicked_image(image);
    WidgetButtonBase::setMouse_over_image(image);
}

void CardButton::SetHeld(bool value)
{
    if(!app->getNew_game())
    {
        held = value;
    }
}

void CardButton::HeldReset()
{
    held=false;
}

void CardButton::RecalculateHeldDestination()
{
    held_destination.x=GetLocation().x+GetLocation().w/4;
    held_destination.y= GetLocation().y;
    held_destination.w=GetLocation().w/2;
    held_destination.h=GetLocation().h/14;
}


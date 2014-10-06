#include "CardButton.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "Application.h"
CardButton::CardButton(SDL_Texture *card_image, SDL_Texture *held_image, SDL_Rect destination, Application *app, Mix_Chunk *sound):WidgetButtonBase(card_image,card_image,card_image,destination),
    app(app),
    held_image(held_image),
    held(false),
    sound(sound)
{
    RecalculateHeldDestination();
}

void CardButton::MouseOverBecome()
{

}

void CardButton::MouseOverEnds()
{

}

void CardButton::ButtonPressed(Uint32 )
{

}

void CardButton::ButtonReleased(Uint32 )
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
{cout<<"set held "<<endl;
    if(!app->getNew_game() && !app->getCards_flip_delay())
    {
        Mix_PlayChannel( -1, sound, 0 );
        held = value;
    }
}

void CardButton::HeldReset()
{cout<<"held reset"<<endl;
    held=false;
}

void CardButton::AutoHeldSet()
{
    cout<<"auto reset"<<endl;
    held=true;
}

void CardButton::RecalculateHeldDestination()
{
    held_destination.x=GetLocation().x+GetLocation().w/4;
    held_destination.y= GetLocation().y;
    held_destination.w=GetLocation().w/2;
    held_destination.h=GetLocation().h/14;
}


#include "DisplayButton.h"


int DisplayButton::getCheck() const
{
    return check;
}

void DisplayButton::setCheck(int value)
{
    check = value;
}

void DisplayButton::SetCurrentScore(int value)
{
    score=value;
}

void DisplayButton::CalculateDestinations()
{
    int parts = 10;
    int parts_minus_one = parts -1 ;
    destination_text.y=destination.y;
    destination_profit.y=destination.y;
    destination_text.x=destination.x;
    destination_profit.x=destination.x+(destination.w/parts)*parts_minus_one;
    destination_profit.h=destination.h;
    destination_text.h=20;
    destination_text.w=destination.w-20;
    destination_profit.w=destination.w/parts;
}


DisplayButton::DisplayButton(SDL_Texture* image_display,SDL_Texture* image_background, SDL_Rect destination, int check):
    image_display(image_display),
    image_background(image_background),  
    destination(destination),
    check(check) //da se mahne
{
    CalculateDestinations();
}

void DisplayButton::Draw(SDL_Renderer *renderer)
{
    destination_text.h=22;
    destination_text.w=250;
    destination_text.x=142;

    switch (score)
    {
    case 1:
        destination_text.y=328;
        SDL_RenderCopyEx ( renderer,image_background,NULL,&destination,0,NULL,SDL_FLIP_NONE );
        SDL_RenderCopyEx ( renderer,image_display,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );
        break;
    case 2:
        destination_text.y=304;
        SDL_RenderCopyEx ( renderer,image_background,NULL,&destination,0,NULL,SDL_FLIP_NONE );
        SDL_RenderCopyEx ( renderer,image_display,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );
        break;
    case 3:
        destination_text.y=279;
        SDL_RenderCopyEx ( renderer,image_background,NULL,&destination,0,NULL,SDL_FLIP_NONE );
        SDL_RenderCopyEx ( renderer,image_display,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );
        break;
    case 4:
        destination_text.y=256;
        SDL_RenderCopyEx ( renderer,image_background,NULL,&destination,0,NULL,SDL_FLIP_NONE );
        SDL_RenderCopyEx ( renderer,image_display,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );
        break;
    case 6:
        destination_text.y=231;
        SDL_RenderCopyEx ( renderer,image_background,NULL,&destination,0,NULL,SDL_FLIP_NONE );
        SDL_RenderCopyEx ( renderer,image_display,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );
        break;
    case 9:
        destination_text.y=210;
         SDL_RenderCopyEx ( renderer,image_background,NULL,&destination,0,NULL,SDL_FLIP_NONE );
         SDL_RenderCopyEx ( renderer,image_display,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );

        break;
    case 25:
        destination_text.y=183;
        SDL_RenderCopyEx ( renderer,image_background,NULL,&destination,0,NULL,SDL_FLIP_NONE );
        SDL_RenderCopyEx ( renderer,image_display,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );
        break;
    case 50:
        destination_text.y=159;
        SDL_RenderCopyEx ( renderer,image_background,NULL,&destination,0,NULL,SDL_FLIP_NONE );
        SDL_RenderCopyEx ( renderer,image_display,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );
        break;
    case 250:
        destination_text.y=135;
        SDL_RenderCopyEx ( renderer,image_background,NULL,&destination,0,NULL,SDL_FLIP_NONE );
        SDL_RenderCopyEx ( renderer,image_display,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );
        break;

    default:
        SDL_RenderCopyEx ( renderer,image_background,NULL,&destination,0,NULL,SDL_FLIP_NONE );
        break;
    }

}

bool DisplayButton::HandleMouseEvent(Uint32,int,int)
{
    return false;
}




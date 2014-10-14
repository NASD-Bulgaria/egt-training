#include "WinDisplay.h"

WinDisplay::WinDisplay(SDL_Texture* image_display, SDL_Rect destination):
    image_display(image_display),
    destination(destination)
{
	score=0;
}

void WinDisplay::SetCurrentScore(int value)
{
    score=value;
}

void WinDisplay::Draw(SDL_Renderer *renderer)
{
    destination_text.h=22;
    destination_text.w=250;
    destination_text.x=144;

    switch (score)
    {
    case 1:
        destination_text.y=327;
        SDL_RenderCopyEx ( renderer,image_display,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );
        break;
    case 2:
        destination_text.y=303;
        SDL_RenderCopyEx ( renderer,image_display,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );
        break;
    case 3:
        destination_text.y=279;
        SDL_RenderCopyEx ( renderer,image_display,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );
        break;
    case 4:
        destination_text.y=256;
        SDL_RenderCopyEx ( renderer,image_display,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );
        break;
    case 6:
        destination_text.y=231;
        SDL_RenderCopyEx ( renderer,image_display,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );
        break;
    case 9:
        destination_text.y=210;
         SDL_RenderCopyEx ( renderer,image_display,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );

        break;
    case 25:
        destination_text.y=185;
        SDL_RenderCopyEx ( renderer,image_display,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );
        break;
    case 50:
        destination_text.y=162;
        SDL_RenderCopyEx ( renderer,image_display,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );
        break;
    case 250:
        destination_text.y=140;
        SDL_RenderCopyEx ( renderer,image_display,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );
        break;
    }

}

bool WinDisplay::HandleMouseEvent(Uint32,int,int)
{
    return false;
}

WinDisplay::~WinDisplay()
{
}

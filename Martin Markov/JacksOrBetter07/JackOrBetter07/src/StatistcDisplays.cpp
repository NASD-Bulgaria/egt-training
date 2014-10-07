#include "StatistcDisplays.h"
#include <sstream>
#include <string>
#include <iostream>

StatistcDisplays::StatistcDisplays(SDL_Rect destination_text):
   // background(background),
    text(NULL),
//    destination_bg(destination_bg),
    destination_text(destination_text)

{

}

StatistcDisplays::~StatistcDisplays()
{

}

void StatistcDisplays::UpdateText(int value,TTF_Font* font,SDL_Renderer* renderer)
{

  if(text)
  {
      SDL_DestroyTexture(text);
  }
  std::stringstream temp;
  temp<<value;
  SDL_Color textColor = { 255, 0, 255, 255 };
  SDL_Surface* textSurface = TTF_RenderText_Solid( font, temp.str().c_str(), textColor );
  text = SDL_CreateTextureFromSurface( renderer, textSurface );

  destination_text.w=temp.str().length()*24/2;
  destination_text.h=24;
  SDL_FreeSurface(textSurface);
}

void StatistcDisplays::Draw(SDL_Renderer *renderer)
{

   // SDL_RenderCopyEx ( renderer,background,NULL,&destination_bg,0,NULL,SDL_FLIP_NONE );
   // SDL_RenderCopyEx ( renderer,text,NULL,&destination_text,0,NULL,SDL_FLIP_NONE );
     SDL_RenderCopy( renderer, text, NULL, &destination_text );

}

bool StatistcDisplays::HandleMouseEvent(Uint32,int, int)
{

    return false;
}




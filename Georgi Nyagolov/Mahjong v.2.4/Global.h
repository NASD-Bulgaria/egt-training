#ifndef GLOBAL_H
#define GLOBAL_H

//#include <SDL.h>
//#include <SDL_image.h>
#include <SDL_ttf.h>

class LTexture;

extern SDL_Renderer* gRenderer;
extern TTF_Font* gFont;
extern SDL_Color buttonColor;
//extern const int NUMBER_OF_TILE;
//extern LTexture gTile[];
enum faceType
{
    FIRST,SECOND,THIRD,FOURTH,FIFTH,SIXTH,SEVENTH,EIGTH,NINGTH,TENTH,EVELEND,TWELVED,THIRTEENTH,FOURTEENTH,FIFTEENTH,NONE
};


#endif // GLOBAL_H

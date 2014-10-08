#ifndef GLOBAL_H
#define GLOBAL_H

#include <SDL_ttf.h>
#include <SDL_mixer.h>

extern SDL_Renderer* gRenderer;
extern TTF_Font* gFont;
extern Mix_Chunk *gLow;
extern bool chunk;
enum faceType
{
    FIRST,SECOND,THIRD,FOURTH,FIFTH,SIXTH,SEVENTH,EIGTH,NINGTH,TENTH,EVELENTH,TWELVETH,THIRTEENTH,FOURTEENTH,FIFTEENTH,NONE
};


#endif // GLOBAL_H

/*
 * GlobalVariables.h
 *
 *  Created on: 25.09.2014
 *      Author:
 */

#ifndef GLOBALVARIABLES_H_
#define GLOBALVARIABLES_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <fstream>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <map>

#include "LTexture.h"
#include "BingoTicket.h"
#include "Ball.h"
#include "CheckForBingo.h"
#include "Game.h"
#include "Player.h"
#include "ToFile.h"

using namespace std;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 600;

const int FPS = 30;
const int DELAY_TIME = 1000.0f / FPS;

class LTexture;

class BingoTicket;

class CheckForBingo;

class Game;

class Ball;

class Player;

class ToFile;

extern CheckForBingo check;
extern CheckForBingo checkComp;

//Background Texture
extern LTexture background;

//Texture for the ticket numbers
extern LTexture ticket1Nums;
extern LTexture gBackgroundTexture;
extern SDL_Renderer* gRenderer;
extern SDL_Window *window;

//Font for numbers
extern TTF_Font *font;
extern TTF_Font *statis;
extern SDL_Surface *surface;
extern SDL_Texture *texture;

extern LTexture gMark;
extern LTexture stats;

extern Ball ball;
extern Player player1;
extern Game game;

extern ToFile file;

extern SDL_Rect gSpriteClips;
extern LTexture gSpriteSheetTexture;

extern LTexture gRulesTexture;
extern LTexture gInfoTexture;
extern LTexture musicStop;

//tickets
extern BingoTicket playerTicket;
extern BingoTicket compTicket;


#endif /* GLOBALVARIABLES_H_ */

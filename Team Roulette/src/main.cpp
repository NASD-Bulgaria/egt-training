#include <sstream>
#include "../src/GameObjects/RouletteApplication.h"
#include "../src/GameObjects/RouletteBoard.h"

using namespace GameObjects;
using namespace std;

//Screen Dimensions
const int SCREEN_WIDTH = 1192;
const int SCREEN_HEIGHT = 460;

bool init();
bool loadMedia();
void initPositions();
void close();

//Key Disable after press
bool musicActive = true;
bool fxActive = true;

//Global Mouse
int cX, cY;

SDL_Renderer* gRenderer = NULL;
SDL_Window* gWindow = NULL;
IRendable gMusicPic;
IRendable gNoMusicPic;
IRendable gPlayerStat;
IRendable gFxPic;
IRendable gNoFxPic;
IRendable gCursorDefault;
IRendable gCursor;
IRendable gCursorClicked;
RouletteApplication app;

int main(int argc, char* args[]) {
	//Load SDL, Media and Positions
	srand(time(NULL));
	init();
	loadMedia();
	initPositions();

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//Hide system cursor
	SDL_ShowCursor(0);

	//x,y  mouse
	int x, y;
	stringstream ss;
	app.stats->read();
	app.setLast10(gRenderer, app.stats->lastTenNumbers);
	app.setStatisticLines(gRenderer, app.stats->lastTenPlayerRecords);
	app.setMaxOccurrences(gRenderer,app.stats->numberCount);
	//While application is running
	while (!quit) {
		//Handle mouse cursor
		SDL_GetMouseState(&cX, &cY);
		gCursorDefault.setPosition(cX, cY);
		gCursor.setPosition(cX, cY);
		gCursorClicked.setPosition(cX, cY);
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0) {

			//User requests quit
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			app.handleMouseEvent(e.button, gRenderer);

			if (e.type == SDL_MOUSEBUTTONUP) {
				gCursorDefault = gCursor;
			}

			if (e.type == SDL_MOUSEBUTTONDOWN) {
				SDL_GetMouseState(&x, &y);

				gCursorDefault = gCursorClicked;
			}
//
//				//Table Screen
//				else {
//			     	 	 	Home Sound
//							if (fxActive) {
//								Mix_PlayChannel(0, app.musicChunks[3], 0);
//							}
//			 			Info Sound
//							if (fxActive) {
//								Mix_PlayChannel(0, app.musicChunks[4], 0);
//							}
//						Statistics Sound
//							if (fxActive) {
//								Mix_PlayChannel(0, app.musicChunks[4], 0);
//							}
//							stat = false;
//
//					//Music button
//					if (info && stat) {
//						if (app.infoButtons[0].isClicked(x, y)) {
//
//							if (musicActive) {
//								app.infoButtons[0] = gNoMusicPic;
//								Mix_PauseMusic();
//								musicActive = false;
//							}
//							else {
//								if (fxActive) {
//									Mix_PlayChannel(0, app.musicChunks[0], 0);
//								}
//								app.infoButtons[0] = gMusicPic;
//								Mix_ResumeMusic();
//								musicActive = true;
//							}
//						}
//
//							About Sound
//							if (fxActive) {
//								Mix_PlayChannel(0, app.musicChunks[4], 0);
//							}
//							Chip Sound
//							if (x > 460 && x < 1110 && y > 60 && y < 290) {
//								if (fxActive) {
//									Mix_PlayChannel(0, app.musicChunks[1], 0);
//								}
//							}
//							Info and Stat Home Sound
////						if (fxActive) {
////							Mix_PlayChannel(0, app.musicChunks[3], 0);
////						}
		}
		if (!app.rouletteBoard->stoped) {
			if (fxActive)
			{
				Mix_VolumeChunk(app.musicChunks[2],10);
				Mix_PlayChannel(-1, app.musicChunks[2], 0);
			}
		} else {
			Mix_VolumeChunk(app.musicChunks[2],0);
		}
		app.changeInfoValues(gRenderer);
		app.handleNumberHit(gRenderer);
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

//		if (start) {
////			gPlayerStat.draw(gRenderer);
//		}

		//Render Table elements
		app.draw(gRenderer);

		//Render Cursor
		gCursorDefault.draw(gRenderer);

		//Update screen
		SDL_RenderPresent(gRenderer);

	}

	//Free resources and close SDL
	close();

	return 0;
}

bool init() {
	bool success = true;

	SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1");

	gWindow = SDL_CreateWindow("European Roulette", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	gRenderer = SDL_CreateRenderer(gWindow, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	int imgFlags = IMG_INIT_PNG;

	IMG_Init(imgFlags);
	TTF_Init();
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);

	return success;
}

bool loadMedia() {
	bool success = true;
	gMusicPic.loadFromFile(gRenderer, "Roulette/music.png");
	gNoMusicPic.loadFromFile(gRenderer, "Roulette/nomusic.png");
	gPlayerStat.loadFromFile(gRenderer, "Roulette/playerstat.png");
	gFxPic.loadFromFile(gRenderer, "Roulette/fx.png");
	gNoFxPic.loadFromFile(gRenderer, "Roulette/nofx.png");
	gCursorDefault.loadFromFile(gRenderer, "Roulette/cursor.png");
	gCursor.loadFromFile(gRenderer, "Roulette/cursor.png");
	gCursorClicked.loadFromFile(gRenderer, "Roulette/cursorclicked.png");
	app.loadMedia(gRenderer);

	return success;
}

void close() {
	gMusicPic.free();
	gNoMusicPic.free();
	gPlayerStat.free();
	gFxPic.free();
	gNoFxPic.free();

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
//	Mix_FreeMusic(music);
	gWindow = NULL;
	gRenderer = NULL;
//	gMusic = NULL;

	IMG_Quit();
	Mix_Quit();
	TTF_Quit();
	SDL_Quit();
}

void initPositions() {
	app.rouletteBoard->setPosition(44, 65);
	gMusicPic.setPosition(1112, 35);
	gNoMusicPic.setPosition(1112, 35);
	gPlayerStat.setPosition(450, 280);
	gFxPic.setPosition(1112, 90);
	gNoFxPic.setPosition(1112, 90);
	app.board->setPosition(456, 58);
}

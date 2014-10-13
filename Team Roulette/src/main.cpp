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
void close();

//Key Disable after press
bool musicActive = true;
bool fxActive = true;

//Global Mouse
int cX, cY;

SDL_Renderer* gRenderer = NULL;
SDL_Window* gWindow = NULL;
IRendable gCursorDefault;
IRendable gCursor;
IRendable gCursorClicked;

int main(int argc, char* args[]) {
	//Load SDL, Media and Positions
	srand(time(NULL));
	init();
	loadMedia();
	RouletteApplication app(gRenderer);
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//Hide system cursor
	SDL_ShowCursor(0);

	//x,y  mouse
	int x, y;
	stringstream ss;
	app.setLast12(gRenderer, app.stats->lastTenNumbers);
	app.setStatisticLines(gRenderer, app.stats->lastTenPlayerRecords);
	app.setMaxOccurrences(gRenderer, app.stats->numberCount);
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
		}
		app.handleSpinState(gRenderer);
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);
		app.draw(gRenderer);

		//Render Cursor
		gCursorDefault.draw(gRenderer);

		//Update screen
		SDL_RenderPresent(gRenderer);

	}

	//Free resources and close SDL
	close();

	exit(1);
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
	gCursorDefault.loadFromFile(gRenderer, "Roulette/cursor.png");
	gCursor.loadFromFile(gRenderer, "Roulette/cursor.png");
	gCursorClicked.loadFromFile(gRenderer, "Roulette/cursorclicked.png");

	return success;
}

void close() {
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	Mix_Quit();
	TTF_Quit();
	SDL_Quit();
}

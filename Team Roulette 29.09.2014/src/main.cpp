#include <sstream>
#include "../GameObjects/RouletteWheel.h"
#include "../GameObjects/GameBoard.h"
#include "LTexture.h"

using namespace std;
using namespace GameObjects;

//Screen Dimensions
const int SCREEN_WIDTH = 1192;
const int SCREEN_HEIGHT = 460;

//Start-Stop spin
int spin = 0;
int stop = 1;
GameBoard board;
//Random number Z
int z = 0;

//Key Disable after press
bool press = true;

//Wheel Degrees
double degrees = 0;

bool init();
bool loadMedia();
void close();

SDL_Renderer* gRenderer = NULL;
SDL_Window* gWindow = NULL;
Mix_Music* gMusic = NULL;
Mix_Chunk* gTick = NULL;
LTexture gTable;
LTexture gWheel;
LTexture gGalaxynet;
LTexture gSpinButton;
LTexture gClearButton;
LTexture gChipButton;
LTexture gNumber;
LTexture gWin;
LTexture gBet;
LTexture gBalance;
LTexture gArrow;
LTexture gChipPressed;
LTexture gChipUnpressed;
LTexture gChipontable;

LTexture g[37];

int main(int argc, char* args[]) {

	init();

	loadMedia();

	srand(time(0));

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//x,y  mouse
	int x, y;

	//mouse button press
	bool chipbutton = false;

	//chips on table
	bool chip[37] = { false };

	//Flip type
	SDL_RendererFlip flipType = SDL_FLIP_NONE;

	//Initialize music
	Mix_PlayMusic(gMusic, -1);
	board.initSectorPositions();
	GameObjects::RouletteWheel wheel;
	//While application is running
	while (!quit) {
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0) {

			//User requests quit
			if (e.type == SDL_QUIT) {
				quit = true;
			}

			if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {

				case SDLK_SPACE:
					degrees += 1;
					break;
				}
			}
			//return current mouse x and y on the screen
			SDL_GetMouseState(&x, &y);

			if (e.type == SDL_MOUSEBUTTONDOWN) {
				//Chip Button
				if (x > 780 && x < 840 && y > 320 && y < 370) {

					if (chipbutton) {
						gChipButton = gChipUnpressed;
						chipbutton = false;
					}

					else {
						gChipButton = gChipPressed;
						chipbutton = true;

					}
				}

				//Alienware picture
				if (x > 1121 && x < 1163 && y > 318 && y < 373) {
					SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
							"About", "SDL by GalaxyNET\nLogic by NAND", NULL);
				}

				//Spin button
				if (press) {
					if (chipbutton) {
						if (x > 1043 && x < 1146 && y > 399 && y < 445) {
							wheel.initiate();
							press = false;
							break;
						}
					}
				}
				if (press) {
					//Clear button
					if (x > 443 && x < 548 && y > 399 && y < 439) {
						board.clearAllBets();

						gChipButton = gChipUnpressed;
						chipbutton = false;
					}

				}

				//Chips on table
				if (true) {
					if (board.isClicked(x, y)) {
						int num = board.getClickedSectorValue(x, y);
						cout << num << endl;
						NumberBet bet(num, 5);
						board.placeNumberBet(bet);
					}
				}

			}

		}

		if (wheel.getSpinSpeed() != Stoped) {
			wheel.spin();
		} else {
			press = true;
			gNumber = g[wheel.getWiningNumber()];
		}

		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		//Render Table elements
		gTable.render(gRenderer, (SCREEN_WIDTH - gTable.getWidth()) / 2,
				(SCREEN_HEIGHT - gTable.getHeight()) / 2, NULL, 0, NULL,
				flipType);
		gWheel.render(gRenderer, 80, 101, NULL, wheel.getCurrentDegrees(), NULL,
				flipType);
		gGalaxynet.render(gRenderer, 1100, 315, NULL, 0, NULL, flipType);
		gSpinButton.render(gRenderer, 1040, 396, NULL, 0, NULL, flipType);
		gClearButton.render(gRenderer, 440, 396, NULL, 0, NULL, flipType);
		gChipButton.render(gRenderer, 780, 320, NULL, 0, NULL, flipType);
		gNumber.render(gRenderer, 370, 394, NULL, 0, NULL, flipType);
		gBet.render(gRenderer, 720, 395, NULL, 0, NULL, flipType);
		gWin.render(gRenderer, 560, 395, NULL, 0, NULL, flipType);
		gBalance.render(gRenderer, 877, 395, NULL, 0, NULL, flipType);
		gArrow.render(gRenderer, 185, 40, NULL, 0, NULL, flipType);
		board.draw(gRenderer);

		if (chip[15]) {
			gChipontable.render(gRenderer, 708, 66, NULL, 0, NULL, flipType);
		}

		//Update screen
		SDL_RenderPresent(gRenderer);

	}

	//Free resources and close SDL
	close();

	return 0;
}

bool init() {
	bool success = true;

	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	} else {
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("Chess", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
				SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			printf("Window could not be created! SDL Error: %s\n",
					SDL_GetError());
			success = false;
		} else {
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n",
						SDL_GetError());
				success = false;
			} else {
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					printf(
							"SDL_image could not initialize! SDL_image Error: %s\n",
							IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia() {
	bool success = true;
	board.loadFromFile(gRenderer, "Roulette/proba.png");
	gTable.loadFromFile(gRenderer, "Roulette/table.png");
	gMusic = Mix_LoadMUS("Roulette/roulette.mp3");
	gTick = Mix_LoadWAV("Roulette/tick.wav");
	gWheel.loadFromFile(gRenderer, "Roulette/wheel.png");
	gGalaxynet.loadFromFile(gRenderer, "Roulette/galaxynet.png");
	gSpinButton.loadFromFile(gRenderer, "Roulette/spin_button.png");
	gClearButton.loadFromFile(gRenderer, "Roulette/clear_button.png");
	gChipButton.loadFromFile(gRenderer, "Roulette/chip_button_unpressed.png");
	gNumber.loadFromFile(gRenderer, "Roulette/number_from_roulette.png");
	gWin.loadFromFile(gRenderer, "Roulette/winning_amount.png");
	gBet.loadFromFile(gRenderer, "Roulette/total_bet.png");
	gBalance.loadFromFile(gRenderer, "Roulette/balance_amount.png");
	gArrow.loadFromFile(gRenderer, "Roulette/arrow.png");
	gChipPressed.loadFromFile(gRenderer, "Roulette/chip_button_pressed.png");
	gChipUnpressed.loadFromFile(gRenderer,
			"Roulette/chip_button_unpressed.png");
	gChipontable.loadFromFile(gRenderer, "Roulette/chip_on_table.png");

	//Load Winning numbers
	stringstream ss;
	for (int i = 0; i < 37; i++) {
		ss << i;
		g[i].loadFromFile(gRenderer, "Roulette/numbers/" + ss.str() + ".png");
		ss.str("");
	}

	return success;
}

void close() {
	gTable.free();
	gWheel.free();
	gGalaxynet.free();
	gSpinButton.free();
	gClearButton.free();
	gChipButton.free();
	gNumber.free();
	gWin.free();
	gBet.free();
	gBalance.free();
	gArrow.free();
	gChipPressed.free();
	gChipontable.free();

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	Mix_FreeMusic(gMusic);
	gWindow = NULL;
	gRenderer = NULL;
	gMusic = NULL;

	IMG_Quit();
	SDL_Quit();
}


#include <sstream>
#include "../src/GameObjects/RouletteApplication.h"
#include "LTexture.h"

using namespace GameObjects;
using namespace std;

//Screen Dimensions
const int SCREEN_WIDTH = 1192;
const int SCREEN_HEIGHT = 460;

bool init();
bool loadMedia();
void close();

//Key Disable after press
bool press = true;
bool music = true;
bool info = true;
bool stat = true;

SDL_Renderer* gRenderer = NULL;
SDL_Window* gWindow = NULL;
Mix_Music* gMusic = NULL;
Mix_Chunk* gTick = NULL;
LTexture gTable;
LTexture gWheel;
LTexture gSpinButton;
LTexture gClearButton;
LTexture gNumber;
LTexture gWin;
LTexture gBet;
LTexture gBalance;
LTexture gArrow;
LTexture gMusicPic;
LTexture gNoMusicPic;
LTexture gMusicDefault;
LTexture gInfo;
LTexture gStat;
LTexture gInfoBackground;
LTexture gBack;
LTexture gAbout;
LTexture gStatBackground;
GameBoard board;
RouletteWheel wheel;
Player player(1000);
RouletteApplication app(&board, &player, &wheel);
LTexture g[37];

int main(int argc, char* args[])
{

	init();

	loadMedia();

	srand(time(0));

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//x,y  mouse
	int x, y;
	int winningNum = -1;
	//Flip type
	SDL_RendererFlip flipType = SDL_FLIP_NONE;

	//Initialize music
	Mix_PlayMusic(gMusic, -1);

	app.board->initSectorPositions();

	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{

			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				SDL_GetMouseState(&x, &y);

				//Info Screen home button
				if (!info || !stat)
				{
					if (x > 1135 && x < 1180 && y > 0 && y < 55)
					{
						info = true;
						stat = true;
					}
				}

				//Info button
				if (info)
				{
					if (x > 1115 && x < 1165 && y > 210 && y < 255)
					{
						info = false;
					}
				}

				//Statistics button
				if (stat)
				{
					if (x > 1115 && x < 1165 && y > 150 && y < 195)
					{
						stat = false;
					}
				}

				//Music button
				if (info && stat)
				{
					if (x > 1115 && x < 1155 && y > 35 && y < 75)
					{

						if (music)
						{
							gMusicDefault = gNoMusicPic;
							Mix_PauseMusic();
							music = false;

						}

						else
						{
							gMusicDefault = gMusicPic;
							Mix_ResumeMusic();
							music = true;

						}
					}
				}

				//About
				if (info && stat)
				{
					if (x > 1121 && x < 1163 && y > 318 && y < 373)
					{
						SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
								"About",
								"SDL by GalaxyNET and Kamelia\nLogic by NAND and Stan",
								NULL);
					}
				}

				//Spin button
				if (info && stat)
				{
					if (app.wheel->getSpinSpeed() == Stoped)
					{
						//Spin button
						if (x > 1043 && x < 1146 && y > 399 && y < 445
								&& app.board->getAllBetValue() > 0)
						{
							app.wheel->initiate();
							app.player->creditBalance(app.player->getOldBet());
							winningNum = -1;
							break;
						}

						//Clear Button
						if (x > 443 && x < 548 && y > 399 && y < 439)
						{
							app.board->clearAllBets();
							app.player->setOldBet(0);
						}
						app.handleBetCreation(x, y);
					}
				}

			}
		}

		if (app.wheel->getSpinSpeed() != Stoped)
		{
			app.wheel->spin();
			if (music)
			{
				Mix_PlayChannel(-1, gTick, 0);
			}
		}

		else if (app.wheel->getWiningNumber() != -1)
		{
			if (winningNum != app.wheel->getWiningNumber())
			{
				winningNum = app.wheel->getWiningNumber();
				app.board->setWiningNumberSector(winningNum);
				cout << "The old player balance is: "
						<< app.player->getBalance() << endl
						<< "The winning value is: "
						<< app.board->collectWinings() << endl
						<< "The total bet is: " << app.board->getAllBetValue()
						<< endl << "The new balance is: ";
				app.player->setOldBet(app.board->getAllBetValue());
				app.player->addToBalance(app.board->collectWinings());
				cout << app.player->getBalance() << endl;
				gNumber = g[winningNum];
			}
		}

		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		//Render Table elements
		if (info && stat)
		{
			gTable.render(gRenderer, (SCREEN_WIDTH - gTable.getWidth()) / 2,
					(SCREEN_HEIGHT - gTable.getHeight()) / 2, NULL, 0, NULL,
					flipType);
			gWheel.render(gRenderer, 80, 101, NULL, wheel.getCurrentDegrees(),
			NULL, flipType);
			gSpinButton.render(gRenderer, 1040, 396, NULL, 0, NULL, flipType);
			gClearButton.render(gRenderer, 440, 396, NULL, 0, NULL, flipType);
			gNumber.render(gRenderer, 370, 394, NULL, 0, NULL, flipType);
			gBet.render(gRenderer, 720, 395, NULL, 0, NULL, flipType);
			gWin.render(gRenderer, 560, 395, NULL, 0, NULL, flipType);
			gBalance.render(gRenderer, 877, 395, NULL, 0, NULL, flipType);
			gArrow.render(gRenderer, 185, 40, NULL, 0, NULL, flipType);
			app.board->draw(gRenderer);
			gMusicDefault.render(gRenderer, 1115, 27, NULL, 0, NULL, flipType);
			gStat.render(gRenderer, 1115, 145, NULL, 0, NULL, flipType);
			gInfo.render(gRenderer, 1112, 205, NULL, 0, NULL, flipType);
			gAbout.render(gRenderer, 1115, 328, NULL, 0, NULL, flipType);

		}

		if (!info)
		{
			gInfoBackground.render(gRenderer,
					(SCREEN_WIDTH - gTable.getWidth()) / 2,
					(SCREEN_HEIGHT - gTable.getHeight()) / 2, NULL, 0, NULL,
					flipType);
			gBack.render(gRenderer, 1135, 5, NULL, 0, NULL, flipType);

		}

		if (!stat)
		{
			gStatBackground.render(gRenderer,
					(SCREEN_WIDTH - gTable.getWidth()) / 2,
					(SCREEN_HEIGHT - gTable.getHeight()) / 2, NULL, 0, NULL,
					flipType);
			gBack.render(gRenderer, 1135, 5, NULL, 0, NULL, flipType);

		}
		//Update screen
		SDL_RenderPresent(gRenderer);

	}

	//Free resources and close SDL
	close();

	return 0;
}

bool init()
{
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

	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);

	return success;
}

bool loadMedia()
{
	bool success = true;
	board.loadFromFile(gRenderer, "Roulette/proba.png");
	gTable.loadFromFile(gRenderer, "Roulette/table.png");
	gMusic = Mix_LoadMUS("Roulette/roulette.mp3");
	gTick = Mix_LoadWAV("Roulette/tick.wav");
	gWheel.loadFromFile(gRenderer, "Roulette/wheel.png");
	gSpinButton.loadFromFile(gRenderer, "Roulette/spin_button.png");
	gClearButton.loadFromFile(gRenderer, "Roulette/clear_button.png");
	gNumber.loadFromFile(gRenderer, "Roulette/number_from_roulette.png");
	gWin.loadFromFile(gRenderer, "Roulette/winning_amount.png");
	gBet.loadFromFile(gRenderer, "Roulette/total_bet.png");
	gBalance.loadFromFile(gRenderer, "Roulette/balance_amount.png");
	gArrow.loadFromFile(gRenderer, "Roulette/arrow.png");
	player.initPlayer(gRenderer, "Roulette/chip_on_table.png");
	gMusicDefault.loadFromFile(gRenderer, "Roulette/music.png");
	gMusicPic.loadFromFile(gRenderer, "Roulette/music.png");
	gNoMusicPic.loadFromFile(gRenderer, "Roulette/nomusic.png");
	gInfo.loadFromFile(gRenderer, "Roulette/info.png");
	gStat.loadFromFile(gRenderer, "Roulette/stat.png");
	gInfoBackground.loadFromFile(gRenderer, "Roulette/instruction.png");
	gBack.loadFromFile(gRenderer, "Roulette/back.png");
	gAbout.loadFromFile(gRenderer, "Roulette/about.png");
	gStatBackground.loadFromFile(gRenderer, "Roulette/statistics.png");

	//Load Winning numbers
	stringstream ss;
	for (int i = 0; i < 37; i++)
	{
		ss << i;
		g[i].loadFromFile(gRenderer, "Roulette/numbers/" + ss.str() + ".png");
		ss.str("");
	}

	return success;
}

void close()
{
	board.clearAllBets();
	app.board->free();
	gTable.free();
	gWheel.free();
	gSpinButton.free();
	gClearButton.free();
	gNumber.free();
	gWin.free();
	gBet.free();
	gBalance.free();
	gArrow.free();

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	Mix_FreeMusic(gMusic);
	gWindow = NULL;
	gRenderer = NULL;
	gMusic = NULL;

	IMG_Quit();
	SDL_Quit();
}


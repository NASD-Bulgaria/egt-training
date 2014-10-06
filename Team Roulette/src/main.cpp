#include <sstream>
#include "../src/GameObjects/RouletteApplication.h"

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
bool press = true;
bool music = true;
bool fx = true;
bool info = true;
bool stat = true;
bool start = true;

//Global Mouse
int cX, cY;

SDL_Renderer* gRenderer = NULL;
SDL_Window* gWindow = NULL;
Mix_Music* gMusic = NULL;
Mix_Chunk* gPlay = NULL;
Mix_Chunk* gChip = NULL;
Mix_Chunk* gTick = NULL;
Mix_Chunk* gBackFx = NULL;
Mix_Chunk* gInfoFx = NULL;
Mix_Chunk* gSpinFx = NULL;
Mix_Chunk* gClearFx = NULL;
IRendable gTable;
IRendable gWheel;
IRendable gSpinButton;
IRendable gSpinDefault;
IRendable gSpinLocked;
IRendable gClearButton;
IRendable gClearDefault;
IRendable gClearLocked;
IRendable gArrow;
IRendable gMusicPic;
IRendable gNoMusicPic;
IRendable gInfoBackground;
IRendable gBack;
IRendable gStartScreen;
IRendable gPlayButton;
IRendable gPlayerStat;
IRendable gGetChips;
IRendable gHomeDefault;
IRendable gHome;
IRendable gHomeLocked;
IRendable gFxPic;
IRendable gNoFxPic;
IRendable gCursorDefault;
IRendable gCursor;
IRendable gCursorClicked;
IRendable gLast10;
GameBoard board;
RouletteWheel wheel;
Player player(1000);
RouletteApplication app(&wheel, &board, &player);
Statistics gameStatistics("stats.txt",1000);

int main(int argc, char* args[])
{
    //Load SDL, Media and Positions
	init();
    loadMedia();
    initPositions();

	srand(time(0));

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//Hide system cursor
	SDL_ShowCursor(0);

	//x,y  mouse
	int x, y;
	stringstream ss;
	gameStatistics.read(gRenderer);
	//While application is running
	while (!quit)
	{
		//Handle mouse cursor
		SDL_GetMouseState(&cX, &cY);
		gCursorDefault.setPosition(cX, cY);
		gCursor.setPosition(cX, cY);
		gCursorClicked.setPosition(cX, cY);

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{

			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			if (e.type == SDL_MOUSEBUTTONUP)
			{
				gCursorDefault = gCursor;
			}

			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				SDL_GetMouseState(&x, &y);

				gCursorDefault = gCursorClicked;

				//Start Screen
				if (start)
				{
					if (gPlayButton.isClicked(x, y))
					{
						start = false;

						//Initialize music
						if (fx)
						{
							Mix_PlayChannel(0, gPlay, 0);
						}

						if (Mix_PlayingMusic() == 0)
						{
							Mix_PlayMusic(gMusic, -1);
						}

					}
				}

				//Table Screen
				else
				{
					//Home button
					if (!start && app.wheel->getSpinSpeed() == Stoped)
					{
						if (gHome.isClicked(x, y))
						{
							if (fx)
							{
								Mix_PlayChannel(0, gBackFx, 0);
							}

							start = true;
						}
					}

					//Info button
					if (info)
					{
						if (app.infoButtons[3].isClicked(x, y))
						{
							if (fx)
							{
								Mix_PlayChannel(0, gInfoFx, 0);
							}

							info = false;
						}
					}

					//Statistics button
					if (stat)
					{
						if (app.infoButtons[2].isClicked(x, y))
						{
							if (fx)
							{
								Mix_PlayChannel(0, gInfoFx, 0);
							}
							stat = false;
						}
					}

					//Music button
					if (info && stat)
					{
						if (app.infoButtons[0].isClicked(x, y))
						{

							if (music)
							{
								app.infoButtons[0] = gNoMusicPic;
								Mix_PauseMusic();
								music = false;

							}

							else
							{

								if (fx)
								{
									Mix_PlayChannel(0, gPlay, 0);
								}

								app.infoButtons[0] = gMusicPic;
								Mix_ResumeMusic();
								music = true;
							}
						}

						//FX button
						if (info && stat)
						{
							if (app.infoButtons[1].isClicked(x, y))
							{

								if (fx)
								{
									app.infoButtons[1] = gNoFxPic;
									fx = false;

								}

								else
								{
									Mix_PlayChannel(0, gPlay, 0);

									app.infoButtons[1] = gFxPic;
									fx = true;
								}
							}

							//About button
							if (app.infoButtons[4].isClicked(x, y))
							{
								if (fx)
								{
									Mix_PlayChannel(0, gInfoFx, 0);
								}

								SDL_ShowSimpleMessageBox(
										SDL_MESSAGEBOX_INFORMATION, "About",
										"SDL by GalaxyNET and Kamelia\nLogic by NAND and Stan",
										NULL);
							}

							if (app.wheel->getSpinSpeed() == Stoped)
							{
								//Spin button
								if (gSpinButton.isClicked(x, y) && app.player->getTotalBet())
								{
									if (fx)
									{
										Mix_PlayChannel(0, gSpinFx, 0);
									}
									app.player->creditBalance(player.getTotalBet());
									//Lock Buttons
									gHomeDefault = gHomeLocked;
									gClearDefault = gClearLocked;
									gSpinDefault = gSpinLocked;

									app.wheel->initiate();
									app.board->setWiningNumberSector(app.wheel->getWiningNumber());
									break;
								}

								//Clear Button
								if (gClearButton.isClicked(x, y))
								{
									if (fx)
									{
										Mix_PlayChannel(0, gClearFx, 0);
									}
									if (app.player->getTotalBet()) {
										app.player->addToBalance(app.player->getTotalBet());
									}
									app.player->clearBet();
									app.board->clearAllBets();
								}

								//Chip Sound
								if (x > 460 && x < 1110 && y > 60 && y < 290)
								{
									if (fx)
									{
										Mix_PlayChannel(0, gChip, 0);
									}
								}

								app.handleMouseEvent(e.button,gRenderer);
							}

						}
					}
					//Info and Stat Home button
					if (!info || !stat)
					{
						if (gBack.isClicked(x, y))
						{
							if (fx)
							{
								Mix_PlayChannel(0, gBackFx, 0);
							}

							info = true;
							stat = true;
						}
					}
				}

			}
		}

		if (app.wheel->getSpinSpeed() != Stoped)
		{
			app.wheel->spin();

			if (fx)
			{
				Mix_PlayChannel(-1, gTick, 0);
			}

		} else if (app.wheel->getWiningNumber() != -1) {
				//Unlock Buttons
				gHomeDefault = gHome;
				gClearDefault = gClearButton;
				gSpinDefault = gSpinButton;
				app.board->setWiningNumberSector(app.wheel->getWiningNumber());
				app.player->addToBalance(app.board->collectWinings());
				gameStatistics.write(app.wheel->getWiningNumber(),
						app.board->getWiningNumberSector()->getColor(),
						app.player->getTotalBet(),
						app.board->collectWinings(), app.player->getBalance());
				gameStatistics.read(gRenderer);
				if (app.player->getBalance() == 0) {
					app.board->clearAllBets();
					app.player->clearBet();
				}
				app.wheel->resetWiningNumber();
				ss.str("");
		}

		app.changeInfoValues(gRenderer);
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		if (start)
		{
			gStartScreen.draw(gRenderer);
			gPlayButton.draw(gRenderer);
			gPlayerStat.draw(gRenderer);
			gGetChips.draw(gRenderer);
		}

		//Render Table elements
		if (!start)
		{
			if (info && stat)
			{
				gTable.draw(gRenderer);
				gWheel.draw(gRenderer, wheel.getCurrentDegrees());
				gSpinDefault.draw(gRenderer);
				gClearDefault.draw(gRenderer);
				gArrow.draw(gRenderer);
				app.board->draw(gRenderer);
				for (unsigned int i = 0; i < app.infoButtons.size(); ++i) {
					app.infoButtons[i].draw(gRenderer);
				}
				for (unsigned int i = 0; i < app.infoFields.size(); ++i) {
					app.infoFields[i].draw(gRenderer);
				}
				gHomeDefault.draw(gRenderer);
				gameStatistics.drawLast10(gRenderer, &gLast10);
			}

			if (!info)
			{
				gInfoBackground.draw(gRenderer);
				gBack.draw(gRenderer);

			}

			if (!stat)
			{
				gameStatistics.draw(gRenderer);
				gBack.draw(gRenderer);
			}
		}

		//Render Cursor
		gCursorDefault.draw(gRenderer);

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
	TTF_Init();
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);

	return success;
}

bool loadMedia()
{
	bool success = true;
	board.loadFromFile(gRenderer, "Roulette/proba.png");
	gTable.loadFromFile(gRenderer, "Roulette/table.png");
	gMusic = Mix_LoadMUS("Roulette/roulette.mp3");
	gPlay = Mix_LoadWAV("Roulette/play.wav");
	gChip = Mix_LoadWAV("Roulette/chip.wav");
	gTick = Mix_LoadWAV("Roulette/tick.wav");
	gBackFx = Mix_LoadWAV("Roulette/back.wav");
	gInfoFx = Mix_LoadWAV("Roulette/info.wav");
	gSpinFx = Mix_LoadWAV("Roulette/spin.wav");
	gClearFx = Mix_LoadWAV("Roulette/clear.wav");
	gWheel.loadFromFile(gRenderer, "Roulette/wheel.png");
	gSpinDefault.loadFromFile(gRenderer, "Roulette/spin_button.png");
	gSpinButton.loadFromFile(gRenderer, "Roulette/spin_button.png");
	gSpinLocked.loadFromFile(gRenderer, "Roulette/spin_button_pressed.png");
	gClearDefault.loadFromFile(gRenderer, "Roulette/clear_button.png");
	gClearButton.loadFromFile(gRenderer, "Roulette/clear_button.png");
	gClearLocked.loadFromFile(gRenderer, "Roulette/clear_button_pressed.png");
	gArrow.loadFromFile(gRenderer, "Roulette/arrow.png");
	gMusicPic.loadFromFile(gRenderer, "Roulette/music.png");
	gNoMusicPic.loadFromFile(gRenderer, "Roulette/nomusic.png");
	gInfoBackground.loadFromFile(gRenderer, "Roulette/instruction.png");
	gBack.loadFromFile(gRenderer, "Roulette/back.png");
	gStartScreen.loadFromFile(gRenderer, "Roulette/startscreen.png");
	gPlayButton.loadFromFile(gRenderer, "Roulette/play.png");
	gPlayerStat.loadFromFile(gRenderer, "Roulette/playerstat.png");
	gGetChips.loadFromFile(gRenderer, "Roulette/getchips.png");
	gHomeDefault.loadFromFile(gRenderer, "Roulette/home.png");
	gHome.loadFromFile(gRenderer, "Roulette/home.png");
	gHomeLocked.loadFromFile(gRenderer, "Roulette/home_pressed.png");
	gameStatistics.loadFromFile(gRenderer, "Roulette/statistics.png");
	gFxPic.loadFromFile(gRenderer, "Roulette/fx.png");
	gNoFxPic.loadFromFile(gRenderer, "Roulette/nofx.png");
	gCursorDefault.loadFromFile(gRenderer, "Roulette/cursor.png");
	gCursor.loadFromFile(gRenderer, "Roulette/cursor.png");
	gCursorClicked.loadFromFile(gRenderer, "Roulette/cursorclicked.png");
	gLast10.loadFromFile(gRenderer, "Roulette/last10.png");
	app.init(gRenderer);

	return success;
}

void close()
{
	gTable.free();
	gWheel.free();
	gSpinButton.free();
	gClearButton.free();
	gArrow.free();
	gMusicPic.free();
	gNoMusicPic.free();
	gInfoBackground.free();
	gBack.free();
	gameStatistics.free();
	gStartScreen.free();
	gPlayButton.free();
	gPlayerStat.free();
	gGetChips.free();
	gHome.free();
	gFxPic.free();
	gNoFxPic.free();
	gLast10.free();

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	Mix_FreeMusic(gMusic);
	gWindow = NULL;
	gRenderer = NULL;
	gMusic = NULL;

	IMG_Quit();
	Mix_Quit();
	TTF_Quit();
	SDL_Quit();
}

void initPositions()
{
	gWheel.setPosition(80,101);
	gSpinDefault.setPosition(1040,396);
	gSpinButton.setPosition(1040,396);
	gSpinLocked.setPosition(1040,396);
	gClearDefault.setPosition(440,396);
	gClearButton.setPosition(440,396);
	gClearLocked.setPosition(440,396);
	gArrow.setPosition(185,40);
	gMusicPic.setPosition(1112,30);
	gNoMusicPic.setPosition(1112,30);
	gBack.setPosition(1135, 5);
	gPlayButton.setPosition(950, 395);
	gPlayerStat.setPosition(450,280);
	gGetChips.setPosition(40,395);
	gHomeDefault.setPosition(298,395);
	gHome.setPosition(298,395);
	gHomeLocked.setPosition(298,395);
	gFxPic.setPosition(1112,85);
	gNoFxPic.setPosition(1112,85);
	gLast10.setPosition(395,315);
	app.board->setPosition(456,58);
}

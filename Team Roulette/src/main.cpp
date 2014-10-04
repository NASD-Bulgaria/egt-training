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
IRendable gNumber;
IRendable gWin;
IRendable gBet;
IRendable gBalance;
IRendable gArrow;
IRendable gMusicPic;
IRendable gNoMusicPic;
IRendable gMusicDefault;
IRendable gInfo;
IRendable gStat;
IRendable gInfoBackground;
IRendable gBack;
IRendable gAbout;
IRendable gStartScreen;
IRendable gPlayButton;
IRendable gPlayerStat;
IRendable gGetChips;
IRendable gHomeDefault;
IRendable gHome;
IRendable gHomeLocked;
IRendable gFxDefault;
IRendable gFxPic;
IRendable gNoFxPic;
IRendable gCursorDefault;
IRendable gCursor;
IRendable gCursorClicked;
IRendable gLast10;
GameBoard board;
RouletteWheel wheel;
Player player(1000);
RouletteApplication app(&board, &player, &wheel, &gBet, & gWin, & gBalance);
Statistics gameStatistics("stats.txt", 1000);

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
	int winningNum = -1;

	app.board->initSectorPositions();
	stringstream ss;
	//While application is running
	while (!quit)
	{
		//Handle mouse cursor
		SDL_GetMouseState(&cX, &cY);
		gCursorDefault.setX(cX);
		gCursorDefault.setY(cY);
		gCursor.setX(cX);
		gCursor.setY(cY);
		gCursorClicked.setX(cX);
		gCursorClicked.setY(cY);

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
						if (gInfo.isClicked(x, y))
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
						if (gStat.isClicked(x, y))
						{
							if (fx)
							{
								Mix_PlayChannel(0, gInfoFx, 0);
							}

							stat = false;
							gameStatistics.read(gRenderer);
						}
					}

					//Music button
					if (info && stat)
					{
						if (gMusicDefault.isClicked(x, y))
						{

							if (music)
							{
								gMusicDefault = gNoMusicPic;
								Mix_PauseMusic();
								music = false;

							}

							else
							{

								if (fx)
								{
									Mix_PlayChannel(0, gPlay, 0);
								}

								gMusicDefault = gMusicPic;
								Mix_ResumeMusic();
								music = true;
							}
						}

						//FX button
						if (info && stat)
						{
							if (gFxDefault.isClicked(x, y))
							{

								if (fx)
								{
									gFxDefault = gNoFxPic;
									fx = false;

								}

								else
								{
									Mix_PlayChannel(0, gPlay, 0);

									gFxDefault = gFxPic;
									fx = true;
								}
							}

							//About button
							if (gAbout.isClicked(x, y))
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
								if (gSpinButton.isClicked(x, y) && (app.player->getTotalBet() || app.player->getOldBet()))
								{
									if (fx)
									{
										Mix_PlayChannel(0, gSpinFx, 0);
									}

									//Lock Buttons
									gHomeDefault = gHomeLocked;
									gClearDefault = gClearLocked;
									gSpinDefault = gSpinLocked;

									app.player->creditBalance(app.player->getOldBet());
									app.wheel->initiate();
									winningNum = -1;
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
										app.player->setOldBet(0);
									}
									app.board->clearAllBets();
									app.player->resetBet();
								}

								//Chip Sound
								if (x > 460 && x < 1110 && y > 60 && y < 290)
								{
									if (fx)
									{
										Mix_PlayChannel(0, gChip, 0);
									}
								}

								app.handleBetCreation(x, y);
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

		}

		else if (app.wheel->getWiningNumber() != -1)
		{
			if (winningNum != app.wheel->getWiningNumber())
			{

				//Unlock Buttons
				gHomeDefault = gHome;
				gClearDefault = gClearButton;
				gSpinDefault = gSpinButton;

				winningNum = app.wheel->getWiningNumber();
				app.board->setWiningNumberSector(winningNum);
				app.player->addToBalance(app.board->collectWinings());
				gameStatistics.write(winningNum,
						app.board->getWiningNumberSector()->getColor(),
						app.player->getTotalBet(),
						app.board->collectWinings(), app.player->getBalance());
				ss << winningNum;
				gNumber.setRenderedText(gRenderer, ss.str());
				gNumber.setTextRectSize(
						gNumber.getX() + (gNumber.getWidth() - (ss.str().length() * 20)) / 2,
						gNumber.getY() + (gNumber.getHeight() - 34 ) / 2,
						ss.str().length() * 20, 34);
				ss.str("");
				app.player->setOldBet(app.player->getTotalBet());
				app.player->resetBet();
			}
		}

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
				app.changeInfoValues(gRenderer);
				gArrow.draw(gRenderer);
				app.board->draw(gRenderer);
				gMusicDefault.draw(gRenderer);
				gStat.draw(gRenderer);
				gInfo.draw(gRenderer);
				gAbout.draw(gRenderer);
				gHomeDefault.draw(gRenderer);
				gFxDefault.draw(gRenderer);
				gLast10.draw(gRenderer);
				gNumber.draw(gRenderer);
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
	gStartScreen.loadFromFile(gRenderer, "Roulette/startscreen.png");
	gPlayButton.loadFromFile(gRenderer, "Roulette/play.png");
	gPlayerStat.loadFromFile(gRenderer, "Roulette/playerstat.png");
	gGetChips.loadFromFile(gRenderer, "Roulette/getchips.png");
	gHomeDefault.loadFromFile(gRenderer, "Roulette/home.png");
	gHome.loadFromFile(gRenderer, "Roulette/home.png");
	gHomeLocked.loadFromFile(gRenderer, "Roulette/home_pressed.png");
	gameStatistics.loadFromFile(gRenderer, "Roulette/statistics.png");
	gFxDefault.loadFromFile(gRenderer, "Roulette/fx.png");
	gFxPic.loadFromFile(gRenderer, "Roulette/fx.png");
	gNoFxPic.loadFromFile(gRenderer, "Roulette/nofx.png");
	gCursorDefault.loadFromFile(gRenderer, "Roulette/cursor.png");
	gCursor.loadFromFile(gRenderer, "Roulette/cursor.png");
	gCursorClicked.loadFromFile(gRenderer, "Roulette/cursorclicked.png");
	gLast10.loadFromFile(gRenderer, "Roulette/last10.png");

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
	gMusicPic.free();
	gNoMusicPic.free();
	gMusicDefault.free();
	gInfo.free();
	gStat.free();
	gInfoBackground.free();
	gBack.free();
	gAbout.free();
	gameStatistics.free();
	gStartScreen.free();
	gPlayButton.free();
	gPlayerStat.free();
	gGetChips.free();
	gHome.free();
	gFxDefault.free();
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
	gWheel.setX(80);
	gWheel.setY(101);
	gSpinDefault.setX(1040);
	gSpinDefault.setY(396);
	gSpinButton.setX(1040);
	gSpinButton.setY(396);
	gSpinLocked.setX(1040);
	gSpinLocked.setY(396);
	gClearDefault.setX(440);
	gClearDefault.setY(396);
	gClearButton.setX(440);
	gClearButton.setY(396);
	gClearLocked.setX(440);
	gClearLocked.setY(396);
	gBet.setX(720);
	gBet.setY(395);
	gWin.setX(560);
	gWin.setY(395);
	gBalance.setX(877);
	gBalance.setY(395);
	gArrow.setX(185);
	gArrow.setY(40);
	gMusicDefault.setX(1112);
	gMusicDefault.setY(30);
	gMusicPic.setX(1112);
	gMusicPic.setY(30);
	gNoMusicPic.setX(1112);
	gNoMusicPic.setY(30);
	gStat.setX(1112);
	gStat.setY(141);
	gInfo.setX(1112);
	gInfo.setY(197);
	gAbout.setX(1112);
	gAbout.setY(253);
	gameStatistics.setX(0);
	gameStatistics.setY(0);
	gBack.setX(1135);
	gBack.setY(5);
	gStartScreen.setX(0);
	gStartScreen.setY(0);
	gPlayButton.setX(950);
	gPlayButton.setY(395);
	gPlayerStat.setX(450);
	gPlayerStat.setY(280);
	gGetChips.setX(40);
	gGetChips.setY(395);
	gHomeDefault.setX(298);
	gHomeDefault.setY(395);
	gHome.setX(298);
	gHome.setY(395);
	gHomeLocked.setX(298);
	gHomeLocked.setY(395);
	gFxDefault.setX(1112);
	gFxDefault.setY(85);
	gFxPic.setX(1112);
	gFxPic.setY(85);
	gNoFxPic.setX(1112);
	gNoFxPic.setY(85);
	gLast10.setX(395);
	gLast10.setY(315);
	gNumber.setX(gLast10.getX() + gLast10.getWidth());
	gNumber.setY(gLast10.getY());
}

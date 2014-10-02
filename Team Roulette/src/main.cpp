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
IRendable gTable;
IRendable gWheel;
IRendable gSpinButton;
IRendable gClearButton;
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
IRendable gHome;
IRendable gFxDefault;
IRendable gFxPic;
IRendable gNoFxPic;
IRendable gCursorDefault;
IRendable gCursor;
IRendable gCursorClicked;
GameBoard board;
RouletteWheel wheel;
Player player(1000);
RouletteApplication app(&board, &player, &wheel);
Statistics gameStatistics("stats.txt", 1000);
IRendable g[37];

int main(int argc, char* args[])
{

	init();

	if (loadMedia())
	{
		initPositions();
	}

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

						SDL_Delay(500);

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
								Mix_PlayChannel(0, gPlay, 0);
							}

							start = true;
						}
					}

					//Info button
					if (info)
					{
						if (gInfo.isClicked(x, y))
						{
							info = false;
						}
					}

					//Statistics button
					if (stat)
					{
						if (gStat.isClicked(x, y))
						{
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
									gFxDefault = gFxPic;
									fx = true;
								}
							}

							//About button
							if (gAbout.isClicked(x, y))
							{
								SDL_ShowSimpleMessageBox(
										SDL_MESSAGEBOX_INFORMATION, "About",
										"SDL by GalaxyNET and Kamelia\nLogic by NAND and Stan",
										NULL);
							}

							if (app.wheel->getSpinSpeed() == Stoped)
							{
								//Spin button
								if (gSpinButton.isClicked(x, y)
										&& app.board->getAllBetValue() > 0)
								{
									app.wheel->initiate();
									app.player->creditBalance(
											app.player->getOldBet());
									winningNum = -1;
									break;
								}

								//Clear Button
								if (gClearButton.isClicked(x, y))
								{
									app.board->clearAllBets();
									app.player->setOldBet(0);
								}

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
						//Info Screen home button
						if (!info || !stat)
						{
							if (gBack.isClicked(x, y))
							{
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
					winningNum = app.wheel->getWiningNumber();
					app.board->setWiningNumberSector(winningNum);
					cout << "The old player balance is: "
							<< app.player->getBalance() << endl
							<< "The winning value is: "
							<< app.board->collectWinings() << endl
							<< "The total bet is: "
							<< app.board->getAllBetValue() << endl
							<< "The new balance is: ";
					app.player->setOldBet(app.board->getAllBetValue());
					app.player->addToBalance(app.board->collectWinings());
					cout << app.player->getBalance() << endl;
					gameStatistics.write(winningNum,
							app.board->getWiningNumberSector()->getColor(),
							app.board->getAllBetValue(),
							app.board->collectWinings(),
							app.player->getBalance());
					gNumber = g[winningNum];
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
					gSpinButton.draw(gRenderer);
					gClearButton.draw(gRenderer);
					gNumber.draw(gRenderer);
					gBet.draw(gRenderer);
					gWin.draw(gRenderer);
					gBalance.draw(gRenderer);
					gArrow.draw(gRenderer);
					app.board->draw(gRenderer);
					gMusicDefault.draw(gRenderer);
					gStat.draw(gRenderer);
					gInfo.draw(gRenderer);
					gAbout.draw(gRenderer);
					gHome.draw(gRenderer);
					gFxDefault.draw(gRenderer);
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
	gStartScreen.loadFromFile(gRenderer, "Roulette/startscreen.png");
	gPlayButton.loadFromFile(gRenderer, "Roulette/play.png");
	gPlayerStat.loadFromFile(gRenderer, "Roulette/playerstat.png");
	gGetChips.loadFromFile(gRenderer, "Roulette/getchips.png");
	gHome.loadFromFile(gRenderer, "Roulette/back.png");
	gameStatistics.loadFromFile(gRenderer, "Roulette/statistics.png");
	gFxDefault.loadFromFile(gRenderer, "Roulette/fx.png");
	gFxPic.loadFromFile(gRenderer, "Roulette/fx.png");
	gNoFxPic.loadFromFile(gRenderer, "Roulette/nofx.png");
	gCursorDefault.loadFromFile(gRenderer, "Roulette/cursor.png");
	gCursor.loadFromFile(gRenderer, "Roulette/cursor.png");
	gCursorClicked.loadFromFile(gRenderer, "Roulette/cursorclicked.png");

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
	gSpinButton.setX(1040);
	gSpinButton.setY(396);
	gClearButton.setX(440);
	gClearButton.setY(396);
	gNumber.setX(370);
	gNumber.setY(394);
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
	gStat.setY(145);
	gInfo.setX(1112);
	gInfo.setY(205);
	gAbout.setX(1112);
	gAbout.setY(320);
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
	gHome.setX(20);
	gHome.setY(395);
	gFxDefault.setX(1112);
	gFxDefault.setY(87);
	gFxPic.setX(1112);
	gFxPic.setY(87);
	gNoFxPic.setX(1112);
	gNoFxPic.setY(87);

	for (int i = 0; i < 37; ++i)
	{
		g[i].setX(gNumber.getX());
		g[i].setY(gNumber.getY());
	}
}

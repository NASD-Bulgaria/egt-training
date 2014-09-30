//============================================================================
// Name        : FlippingCards.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "Texture.h"
#include "Game.h"
#include "Bets.h"
#include "Buttons.h"
#include <sstream>
using namespace std;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 683;

bool init();

bool loadMedia();

void loadText(Game &game, Credits &credit, Statistics &);

void close();

SDL_Window* gWindow = NULL;

TTF_Font *gFont = NULL;

SDL_Renderer* gRenderer = NULL;

Texture gBackground;
Texture gCard;
Texture gDeal;
Texture gButtonMusic;
Texture gButtonMusicX;
Texture gDeal2;
Texture gAutoHold;
Texture gDraw;
Texture gDraw2;
Texture gInfo;
Texture gHelp;
Texture gCredit;
Texture gWins;
Texture gHand;
Texture gStatTotalPlayed;
Texture gStatWinGames;
Texture gStatLoseGames;
Texture gStatTotalCreditIn;
Texture gStatTotalCreditsWon;

Mix_Music *gMusic = NULL;
Mix_Chunk *gBeat = NULL;

int main(int args, char* argc[])
{
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = SCREEN_WIDTH;
	rect.h = SCREEN_HEIGHT;

	Game game;
	Credits credit;
	Statistics stat;
	Buttons dealButton(700, 620, 100, 50);
	Buttons drawButton(830, 620, 100, 50);
	Buttons card(137, 400, 750, 190);
	Buttons bInfo(10, 620, 50, 50);
	Buttons music(950, 620, 50, 50);
	int cardX = 137;

	if (!init())
	{
		cout << "failed to initialize ";
	}
	else
	{
		if (!loadMedia())
		{
			cout << "Error media ";
		}
		else
		{
			Mix_PlayMusic(gMusic, -1);

			bool quit = false;
			SDL_Event e;
			bool info = false;
			int soundButton = 0;
			int x, y;
			int countPressButton = 0;
			while (!quit)
			{
				SDL_RenderClear(gRenderer);
				while (SDL_PollEvent(&e) != 0)
				{
					switch (e.type)
					{
					case SDL_QUIT:
						quit = true;
						break;
					case SDL_MOUSEBUTTONDOWN:
						SDL_GetMouseState(&x, &y);
						if (countPressButton != 1
								&& dealButton.checkButton(x, y))
						{
							game.dealCards();
							credit.readCreaditsFromFile(credit);
							loadText(game, credit, stat);

							game.autoHold();
							countPressButton = 1;
						}

						if (countPressButton == 1
								&& drawButton.checkButton(x, y))
						{
							game.secondDealCards();
							credit.readCreaditsFromFile(credit);
							loadText(game, credit, stat);
							countPressButton = 2;
						}

						if (card.checkButton(x, y) && countPressButton == 1)
						{
							if (game.hand[(x - 137) / 150].isHold())
							{
								game.hand[(x - 137) / 150].Unhold();
							}
							else
							{
								game.hand[(x - 137) / 150].Hold();
							}
						}

						if (bInfo.checkButton(x, y))
						{
							info = !info;
						}

						if (music.checkButton(x, y))
						{

							if (soundButton == 1)
							{
								soundButton = 0;
								if (Mix_PlayingMusic() == 1)
								{
									Mix_ResumeMusic();
								}
							}
							else
							{
								soundButton = 1;
								if (Mix_PlayingMusic() == 1)
								{
									Mix_PauseMusic();
									gButtonMusic.button(gRenderer, 950, 620, 50,
											50);
								}
								soundButton = 1;
							}
						}
						break;
					}
				}
				SDL_RenderCopy(gRenderer, gBackground.getTexture(), &rect,
				NULL);

				SDL_Rect outlineRect =
				{ 65, 625, 380, 40 };
				SDL_SetRenderDrawColor(gRenderer, 0xff, 0x00, 0x00, 0xFF);
// button
				gDeal.button(gRenderer, 700, 620, 100, 50);
				gInfo.button(gRenderer, 10, 620, 50, 50);
				gDraw.button(gRenderer, 830, 620, 100, 50);
// statistic
				gStatTotalPlayed.render(gRenderer, 670, 60);
				gStatWinGames.render(gRenderer, 670, 105);
				gStatLoseGames.render(gRenderer, 670, 150);
				gStatTotalCreditIn.render(gRenderer, 670, 190);
				gStatTotalCreditsWon.render(gRenderer, 670, 231);
				switch (countPressButton)
				{
				case 0:
					for (int i = 0; i < 5; i++)
					{
						gCard.card(gRenderer, 158, 492, cardX, 400);
						cardX += 150;
					}

					loadText(game, credit, stat);
					credit.readCreaditsFromFile(credit);
					gStatTotalPlayed.render(gRenderer, 670, 60);
					gStatWinGames.render(gRenderer, 670, 105);
					gStatLoseGames.render(gRenderer, 670, 150);
					gStatTotalCreditIn.render(gRenderer, 670, 190);
					gStatTotalCreditsWon.render(gRenderer, 670, 231);
					gCredit.render(gRenderer, 400, 310);
					cardX = 137;
					break;
				case 1:
					for (unsigned i = 0; i < game.hand.size(); i++)
					{

						int y = game.hand[i].getSuit() * 123;
						int x = game.hand[i].getFace() * 79;
						gCard.card(gRenderer, x, y, cardX, 400);

						if (game.hand[i].isHold())
						{
							gAutoHold.button(gRenderer, cardX + 30, 477, 90,
									35);
						}

						cardX += 150;
					}

					cardX = 137;
					SDL_RenderDrawRect(gRenderer, &outlineRect);
					gDeal2.button(gRenderer, 700, 620, 100, 50);
					gCredit.render(gRenderer, 400, 310);
					break;
				case 2:
					for (unsigned i = 0; i < game.hand.size(); i++)
					{

						int y = game.hand[i].getSuit() * 123;
						int x = game.hand[i].getFace() * 79;
						gCard.card(gRenderer, x, y, cardX, 400);

						cardX += 150;
					}
					cardX = 137;
					SDL_RenderDrawRect(gRenderer, &outlineRect);
					gCredit.render(gRenderer, 400, 310);
					gDraw2.button(gRenderer, 830, 620, 100, 50);
					gWins.render(gRenderer, 720, 305);
					gHand.render(gRenderer, 200, 635);

					countPressButton = 0;
					SDL_RenderPresent(gRenderer);
					SDL_Delay(3000);
					break;
				default:
					break;
				}

				if (info == true)
				{
					SDL_Rect help;
					help.x = 0;
					help.y = 0;
					help.w = SCREEN_WIDTH;
					help.h = SCREEN_HEIGHT;
					SDL_RenderCopy(gRenderer, gHelp.getTexture(), &help,
					NULL);

					gInfo.button(gRenderer, 10, 620, 50, 50);
				}

				if (soundButton == 0)
				{
					gButtonMusic.button(gRenderer, 950, 620, 50, 50);
				}
				else
				{
					gButtonMusicX.button(gRenderer, 950, 620, 50, 50);
				}

				SDL_RenderPresent(gRenderer);
			}
		}
	}
	return 0;
}

bool init()
{
	bool success = true;

	if (SDL_Init( SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		gWindow = SDL_CreateWindow("Joker Poker", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n",
					SDL_GetError());
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1,
					SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n",
						SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf(
							"SDL_image could not initialize! SDL_image Error: %s\n",
							IMG_GetError());
					success = false;
				}

				Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
			}
		}
	}
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n",
		TTF_GetError());
		success = false;
	}

	return success;
}

void loadText(Game &game, Credits &credit, Statistics &stat)
{
	gFont = TTF_OpenFont("textFont.ttf", 31);
	if (gFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		SDL_Color textColor1 =
		{ 255, 255, 102 };
		stringstream cc;
		cc << credit.getCredits();
		if (!gCredit.loadFromRenderedText(gRenderer, gFont, cc.str(),
				textColor1))

		{
			printf("Failed to render text texture!\n");
		}
		cc << "";

		stat.readFromFile();
		stringstream tp;
		stringstream wg;
		stringstream lg;
		stringstream tc;
		stringstream tcw;

		tp << stat.getTotalPlayed();
		if (!gStatTotalPlayed.loadFromRenderedText(gRenderer, gFont, tp.str(),
				textColor1))
		{
			printf("Failed to render text texture!\n");
		}
		tp << "";

		wg << stat.getWinGames();
		if (!gStatWinGames.loadFromRenderedText(gRenderer, gFont, wg.str(),
				textColor1))
		{
			printf("Failed to render text texture!\n");
		}
		wg << "";

		lg << stat.getLostGames();
		if (!gStatLoseGames.loadFromRenderedText(gRenderer, gFont, lg.str(),
				textColor1))
		{
			printf("Failed to render text texture!\n");
		}
		lg << "";

		tc << stat.getTotalCreditsIn();
		if (!gStatTotalCreditIn.loadFromRenderedText(gRenderer, gFont, tc.str(),
				textColor1))
		{
			printf("Failed to render text texture!\n");

		}
		tc << "";

		tcw << stat.getTotalCreditsWon();
		if (!gStatTotalCreditsWon.loadFromRenderedText(gRenderer, gFont,
				tcw.str(), textColor1))
		{
			printf("Failed to render text texture!\n");

		}
		tcw << "";

		Bets bet;
		int a = game.getWinType();
		bet.wins(a);
		stringstream ss;
		ss << bet.wins(a);
		if (!gWins.loadFromRenderedText(gRenderer, gFont, ss.str(), textColor1))

		{
			printf("Failed to render text texture!\n");
		}
		ss << "";

		SDL_Color textColor2 =
		{ 0, 0, 255 };
		stringstream hh;
		hh << bet.handName(a);
		if (!gHand.loadFromRenderedText(gRenderer, gFont, hh.str(), textColor2))
		{
			printf("Failed to render text texture!\n");
		}
		hh << "";
	}
}
bool loadMedia()
{

	bool success = true;
	gMusic = Mix_LoadMUS("Modest Intentions - Cold Autumn.mp3");
	if (gMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	if (!gButtonMusic.loadFromFile(gRenderer, "MusicButton2.png"))
	{
		printf("Failed to load background' texture image!\n");
		success = false;
	}
	if (!gButtonMusicX.loadFromFile(gRenderer, "MusicButton.png"))
	{
		printf("Failed to load background' texture image!\n");
		success = false;
	}

	if (!gBackground.loadFromFile(gRenderer, "backGround.png"))
	{
		printf("Failed to load background' texture image!\n");
		success = false;
	}

	if (!gCard.loadFromFile(gRenderer, "Cards.png"))
	{
		printf("Failed to load Cards texture image!\n");
		success = false;
	}

	if (!gHelp.loadFromFile(gRenderer, "info.PNG"))
	{
		printf("Failed to load info texture image!\n");
		success = false;
	}
	if (!gDeal.loadFromFile(gRenderer, "deal.png"))
	{
		printf("Failed to load deal.png texture image!\n");
		success = false;
	}
	if (!gDeal2.loadFromFile(gRenderer, "deal2.png"))
	{
		printf("Failed to load deal2 texture image!\n");
		success = false;
	}
	if (!gInfo.loadFromFile(gRenderer, "i.png"))
	{
		printf("Failed to load i.png texture image!\n");
		success = false;
	}
	if (!gAutoHold.loadFromFile(gRenderer, "hold.png"))
	{
		printf("Failed to load hold texture image!\n");
		success = false;
	}

	if (!gDraw.loadFromFile(gRenderer, "draw.png"))
	{
		printf("Failed to load draw texture image!\n");
		success = false;
	}

	if (!gDraw2.loadFromFile(gRenderer, "draw2.png"))
	{
		printf("Failed to load draw2 texture image!\n");
		success = false;
	}

	return success;
}

void close()
{
	gBackground.free();
	gButtonMusic.free();
	gCard.free();
	gDeal.free();
	gDeal2.free();
	gAutoHold.free();
	gDraw.free();
	gDraw2.free();
	gInfo.free();
	gHelp.free();
	gCredit.free();
	gWins.free();
	gHand.free();
	gStatTotalPlayed.free();
	gStatWinGames.free();
	gStatLoseGames.free();
	gStatTotalCreditIn.free();
	gStatTotalCreditsWon.free();

	TTF_CloseFont(gFont);
	gFont = NULL;

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

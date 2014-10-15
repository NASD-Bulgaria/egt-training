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
#include "Double.h"
#include <sstream>
using namespace std;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 683;

Game game;
Credits credit;
Statistics stat;

int cardX = 137;
int newCredits;
int width = 150;

static bool checkCredits = false;
static bool checkEnter = false;
static bool checkDouble = false;
static bool switchBackFace = false;
static bool checkChunkButton = false;
static bool win = false;
static bool checkBorB = false;
static bool info = false;

static int infoPages = 1;
static int soundButton = 0;
static int checkSuit = -1;
static int countPressButton = 0;

bool init();
bool loadMedia();
void loadText(Credits &credit, Statistics &, TTF_Font*);
void loadGameText(Game &game, TTF_Font* gFont);
void drawStats();
void drawButtons();
void playGame();
void doubleGame();

void checkButtons(int &x, int &y);
void numberEvent(SDL_Event &e);
void help();
void close();

SDL_Window* gWindow = NULL;

TTF_Font *gFont = NULL;

TTF_Font *gWinTypeFont = NULL;

SDL_Renderer* gRenderer = NULL;

Buttons gBackground;
Buttons gCard;
Buttons gDeal;
Buttons gButtonMusic;
Buttons gButtonMusicX;
Buttons gButtonChunk;
Buttons gButtonChunkX;
Buttons gDeal2;
Buttons gAutoHold;
Buttons gDraw;
Buttons gDraw2;
Buttons gInfo;

Double gDouble;
Double gCancel;
Double gRed;
Double gBlack;
Double gDoubleCard;

Texture gHelp;
Texture gHelp2;
Texture gCursorDefault;
Texture gEnterCredit;
Texture gCredit;
Texture gReadCredit;
Texture gWins;
Texture gWinDouble;
Texture gHand;
Texture gStatTotalPlayed;
Texture gStatWinGames;
Texture gStatLoseGames;
Texture gStatTotalCreditIn;
Texture gStatTotalCreditsWon;
Texture gYouWin;
Texture gYouLose;
Texture gRectHand;
Texture gDoubleBackground1;
Texture gDoubleBackground2;
Texture gJoker;

Mix_Chunk *gButtonDraw = NULL;
Mix_Chunk *gButtonMusicInfo = NULL;
Mix_Chunk *gMusicBtton = NULL;
Mix_Music *gMusic = NULL;
Mix_Chunk *gBeat = NULL;
Mix_Chunk *gWinSound = NULL;
Mix_Chunk *gLoseSound = NULL;

int main(int args, char* argc[])
{

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
			SDL_ShowCursor(0);
			int x, y;

			gFont = TTF_OpenFont("textFont.ttf", 31);

			credit.readCreaditsFromFile(credit);
			stat.readFromFile();
			loadText(credit, stat, gFont);

			game.recovery(countPressButton);
			loadGameText(game, gFont);
			while (!quit)
			{

				SDL_GetMouseState(&x, &y);
				credit.readCreaditsFromFile(credit);
				stat.readFromFile();
				loadText(credit, stat, gFont);

				if (credit.getCredits() < 20 && countPressButton == 0
						&& checkEnter == false)
				{

					checkCredits = true;
					loadText(credit, stat, gFont);
				}
				else
				{

					checkCredits = false;
					if (checkEnter == true)
					{

						credit.setCredits(newCredits);
						stat.readFromFile();
						stat.addCreditsIn(newCredits);
						stat.writeToFile();
						checkEnter = false;
						newCredits = 0;
						loadText(credit, stat, gFont);
					}
					credit.writeCreditsToFile(credit);
				}

				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_KEYDOWN && checkCredits == true)
					{
						numberEvent(e);
					}

					switch (e.type)
					{
					case SDL_QUIT:
						quit = true;
						break;

					case SDL_MOUSEBUTTONDOWN:
						if (checkCredits == false)
						{
							checkButtons(x, y);
						}

						break;
					}
				}

				SDL_RenderCopy(gRenderer, gBackground.getTexture(),
				NULL, NULL);

				drawButtons();
				playGame();
				if (checkCredits == true)
				{
					gReadCredit.render(gRenderer, 260, 310); // show entered credit
					gEnterCredit.render(gRenderer, 5, 65);
				}
				else
				{
					drawStats();
				}
				help();
				gCursorDefault.render(gRenderer, x, y);

				SDL_Delay(10);

				SDL_RenderPresent(gRenderer);

			}
		}
	}
	close();
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

		gWindow = SDL_CreateWindow("Joker Poker",
		SDL_WINDOWPOS_UNDEFINED,
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

void loadText(Credits &credit, Statistics &stat, TTF_Font* gFont)
{

	if (gFont == NULL)
	{
		printf("Failed to load textFont font! SDL_ttf Error: %s\n",
		TTF_GetError());
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
		stringstream rc;

		rc << newCredits;
		if (!gReadCredit.loadFromRenderedText(gRenderer, gFont, rc.str(),
				textColor1))
		{
			printf("Failed to render text texture!\n");
		}
		rc << "";

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

	}
}
void loadGameText(Game &game, TTF_Font* gFont)
{

	if (gFont == NULL)
	{
		printf("Failed to load textFont font! SDL_ttf Error: %s\n",
		TTF_GetError());
	}
	else
	{
		SDL_Color textColor1 =
		{ 255, 255, 102 };
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
		{ 41, 41, 41 };
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
	gMusic = Mix_LoadMUS("sounds\\Modest Intentions - Cold Autumn.mp3");
	if (gMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	gButtonMusicInfo = Mix_LoadWAV(
			"sounds\\Click On-SoundBible.com-1697535117.wav");
	if (gButtonMusicInfo == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	gButtonDraw = Mix_LoadWAV("sounds\\jumping.wav");
	if (gButtonDraw == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	gMusicBtton = Mix_LoadWAV("sounds\\cardOpenPackage2.wav");
	if (gMusicBtton == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}
	gWinSound = Mix_LoadWAV("sounds\\winSound.wav");
	if (gMusicBtton == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}
	gLoseSound = Mix_LoadWAV("sounds\\loseSound.wav");
	if (gMusicBtton == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	// load textures
	if (!gButtonMusic.loadFromFile(gRenderer, "images\\MusicButton2.png"))
	{
		printf("Failed to load background' texture image!\n");
		success = false;
	}
	if (!gButtonMusicX.loadFromFile(gRenderer, "images\\MusicButton.png"))
	{
		printf("Failed to load background' texture image!\n");
		success = false;
	}
	if (!gButtonChunk.loadFromFile(gRenderer, "images\\musicNote.png"))
	{
		printf("Failed to load background' texture image!\n");
		success = false;
	}
	if (!gButtonChunkX.loadFromFile(gRenderer, "images\\musicNoteX.png"))
	{
		printf("Failed to load background' texture image!\n");
		success = false;
	}
	if (!gCursorDefault.loadFromFile(gRenderer, "Black&RedGlow.png"))
	{
		printf("Failed to load background' texture image!\n");
		success = false;
	}

	if (!gBackground.loadFromFile(gRenderer, "images\\backGround.png"))
	{
		printf("Failed to load background' texture image!\n");
		success = false;
	}
	if (!gJoker.loadFromFile(gRenderer, "images\\joker.png"))
	{
		printf("Failed to load background' texture image!\n");
		success = false;
	}
	if (!gEnterCredit.loadFromFile(gRenderer, "images\\enterCredits.png"))
	{
		printf("Failed to load background' texture image!\n");
		success = false;
	}

	if (!gCard.loadFromFile(gRenderer, "images\\Cards.png"))
	{
		printf("Failed to load Cards texture image!\n");
		success = false;
	}

	if (!gHelp.loadFromFile(gRenderer, "images\\info.PNG"))
	{
		printf("Failed to load info texture image!\n");
		success = false;
	}
	if (!gHelp2.loadFromFile(gRenderer, "images\\info2.PNG"))
	{
		printf("Failed to load info texture image!\n");
		success = false;
	}
	if (!gDeal.loadFromFile(gRenderer, "images\\deal.png"))
	{
		printf("Failed to load deal.png texture image!\n");
		success = false;
	}
	if (!gDeal2.loadFromFile(gRenderer, "images\\deal2.png"))
	{
		printf("Failed to load deal2 texture image!\n");
		success = false;
	}
	if (!gInfo.loadFromFile(gRenderer, "images\\i.png"))
	{
		printf("Failed to load i.png texture image!\n");
		success = false;
	}
	if (!gAutoHold.loadFromFile(gRenderer, "images\\hold.png"))
	{
		printf("Failed to load hold texture image!\n");
		success = false;
	}

	if (!gDraw.loadFromFile(gRenderer, "images\\draw.png"))
	{
		printf("Failed to load draw texture image!\n");
		success = false;
	}

	if (!gDraw2.loadFromFile(gRenderer, "images\\draw2.png"))
	{
		printf("Failed to load draw2 texture image!\n");
		success = false;
	}
	if (!gYouWin.loadFromFile(gRenderer, "images\\youWin.png"))
	{
		printf("Failed to load draw2 texture image!\n");
		success = false;
	}

	if (!gYouLose.loadFromFile(gRenderer, "images\\youLose.png"))
	{
		printf("Failed to load draw2 texture image!\n");
		success = false;
	}
	if (!gRectHand.loadFromFile(gRenderer, "images\\rectHand.png"))
	{
		printf("Failed to load draw2 texture image!\n");
		success = false;
	}
	if (!gDoubleBackground1.loadFromFile(gRenderer,
			"images\\backgroundDouble1.png"))
	{
		printf("Failed to load draw2 texture image!\n");
		success = false;
	}
	if (!gDouble.loadDoubleFromFile(gRenderer, "images\\doubleButton.png"))
	{
		printf("Failed to load draw2 texture image!\n");
		success = false;
	}
	if (!gCancel.loadDoubleFromFile(gRenderer, "images\\canselButton.png"))
	{
		printf("Failed to load draw2 texture image!\n");
		success = false;
	}
	if (!gDoubleBackground2.loadFromFile(gRenderer,
			"images\\backgroundDouble.png"))
	{
		printf("Failed to load draw2 texture image!\n");
		success = false;
	}
	if (!gRed.loadDoubleFromFile(gRenderer, "images\\red.png"))
	{
		printf("Failed to load draw2 texture image!\n");
		success = false;
	}
	if (!gBlack.loadDoubleFromFile(gRenderer, "images\\black.png"))
	{
		printf("Failed to load draw2 texture image!\n");
		success = false;
	}
	if (!gDoubleCard.loadDoubleFromFile(gRenderer, "images\\Cards.png"))
	{
		printf("Failed to load draw2 texture image!\n");
		success = false;
	}
	return success;
}

void drawStats()
{
	gStatTotalPlayed.render(gRenderer, 900, 60);
	gStatWinGames.render(gRenderer, 900, 105);
	gStatLoseGames.render(gRenderer, 900, 150);
	gStatTotalCreditIn.render(gRenderer, 900, 190);
	gStatTotalCreditsWon.render(gRenderer, 900, 231);
	gCredit.render(gRenderer, 270, 310);

}

void drawButtons()
{
	soundButton == 0 ?
			gButtonMusic.drawButton(gRenderer, 950, 620, 50, 50) :
			gButtonMusicX.drawButton(gRenderer, 950, 620, 50, 50);
	checkChunkButton == false ?
			gButtonChunk.drawButton(gRenderer, 942, 555, 60, 60) :
			gButtonChunkX.drawButton(gRenderer, 942, 555, 60, 60);

	gDeal.drawButton(gRenderer, 700, 620, 100, 50);
	gInfo.drawButton(gRenderer, 10, 620, 50, 50);
	gDraw.drawButton(gRenderer, 830, 620, 100, 50);

}

void playGame()

{
	gJoker.render(gRenderer, 375, 5);

	switch (countPressButton)
	{
	case 0:
		for (int i = 0; i < 5; i++)
		{

			gCard.drawCard(gRenderer, 158, 492, cardX, 400, width);
			cardX += 150;
		}
		cardX = 137;

		break;
	case 1:
		if (width > 0 && switchBackFace == false)
		{
			for (int i = 0; i < 5; i++)
			{
				gCard.drawCard(gRenderer, 158, 492, cardX, 400, width);
				cardX += 150;
			}

			width -= 10;
			cardX = 137;
		}
		else
		{
			switchBackFace = true;
			for (unsigned i = 0; i < game.hand.size(); i++)
			{

				int y = game.hand[i].getSuit() * 123;
				int x = game.hand[i].getFace() * 79;
				gCard.drawCard(gRenderer, x, y, cardX, 400, width);

				if (game.hand[i].isHold())
				{
					gAutoHold.drawButton(gRenderer, cardX + 30, 477, 90, 35);
				}
				cardX += 150;
			}
			if (width < 150)
			{
				width += 10;
			}
			cardX = 137;

		}
		gRectHand.render(gRenderer, 65, 625);
		gDeal2.drawButton(gRenderer, 700, 620, 100, 50);

		break;
	case 2:

		switchBackFace = false;

		for (unsigned i = 0; i < game.hand.size(); i++)
		{

			int y = game.hand[i].getSuit() * 123;
			int x = game.hand[i].getFace() * 79;
			gCard.drawCard(gRenderer, x, y, cardX, 400, width);

			cardX += 150;
		}
		cardX = 137;
		width = 150;
		gRectHand.render(gRenderer, 65, 625);
		gDeal2.drawButton(gRenderer, 700, 620, 100, 50);
		gDraw2.drawButton(gRenderer, 830, 620, 100, 50);
		gWins.render(gRenderer, 690, 310);
		gHand.render(gRenderer, 200, 635);

		drawStats();

		doubleGame();

		break;
	default:
		break;
	}
}
void doubleGame()
{

	if (game.getWinType() > 0)
	{
		if (checkDouble == false)
		{
			gYouWin.render(gRenderer, 140, 420);
			gDoubleBackground1.render(gRenderer, 10, 15);
			gDouble.drawDoubleButton(gRenderer, 90, 210, 100, 50);
			gCancel.drawDoubleButton(gRenderer, 290, 210, 100, 50);

		}
		else
		{
			gDoubleBackground2.render(gRenderer, 10, 15);
			gBlack.drawDoubleButton(gRenderer, 310, 70, 110, 70);
			gRed.drawDoubleButton(gRenderer, 310, 160, 110, 70);

			if (checkBorB == true)
			{

				gDoubleCard.drawDoubleCard(gRenderer, checkSuit, stat, credit,
						game, win);

				if (win == true)
				{
					Mix_PlayChannel(-1, gWinSound, 0);
					gYouWin.render(gRenderer, 140, 420);
				}
				else
				{
					gYouLose.render(gRenderer, 140, 420);
					Mix_PlayChannel(-1, gLoseSound, 0);
				}
				game.deleteRevocery();
				SDL_RenderPresent(gRenderer);
				SDL_Delay(3000);
				checkDouble = false;
				countPressButton = 0;
				checkBorB = false;
				checkSuit = 0;
			}
		}
	}
	else
	{

		gYouLose.render(gRenderer, 140, 420);
		SDL_RenderPresent(gRenderer);
		SDL_Delay(3000);
		countPressButton = 0;
	}
}
void checkButtons(int &x, int &y)
{

	if (countPressButton == 0 && gDeal.checkButton(x, y) && info == false)
	{
		game.dealCards();
		loadGameText(game, gFont);
		Mix_PlayChannel(-1, gMusicBtton, 0);
		game.autoHold();
		countPressButton = 1;
	}

	if (countPressButton == 1 && gCard.checkButton(x, y) && info == false)
	{
		game.hand[(x - 137) / 150].isHold() ?
				game.hand[(x - 137) / 150].Unhold() :
				game.hand[(x - 137) / 150].Hold();

	}

	if (countPressButton == 1 && gDraw.checkButton(x, y) && info == false)
	{
		game.secondDealCards();
		game.getWinType() > 0 ? win = true : win = false;
		win == true ?
				Mix_PlayChannel(-1, gWinSound, 0) :
				Mix_PlayChannel(-1, gLoseSound, 0);
		loadGameText(game, gFont);
		countPressButton = 2;
		Mix_PlayChannel(-1, gButtonDraw, 0);
	}

	if (countPressButton == 2 && gDouble.checkDoubleButton(x, y)
			&& info == false && checkDouble == false)
	{
		checkDouble = true;
	}

	if (checkDouble == true && gRed.checkDoubleButton(x, y) && info == false)
	{
		checkSuit = 1;
		checkBorB = true;
	}

	if (checkDouble == true && gBlack.checkDoubleButton(x, y) && info == false)
	{
		checkSuit = 2;
		checkBorB = true;
	}

	if (countPressButton == 2 && gCancel.checkDoubleButton(x, y)
			&& info == false && checkDouble == false)
	{

		checkSuit = -1;
		gCancel.drawDoubleCard(gRenderer, checkSuit, stat, credit, game, win);
		checkDouble = false;
		countPressButton = 0;
	}

	if (gInfo.checkButton(x, y))
	{
		Mix_PlayChannel(-1, gButtonMusicInfo, 0);
		info = !info;
	}

	if (info == true && x > 871 && x < 942 && y > 574 && y < 651)
	{
		infoPages = 2;
	}

	if (info == true && x > 61 && x < 132 && y > 574 && y < 651)
	{
		infoPages = 1;
	}

	if (gButtonMusic.checkButton(x, y))
	{
		soundButton == 1 ? Mix_ResumeMusic() : Mix_PauseMusic();

		if (soundButton == 1)
		{
			soundButton = 0;
		}
		else
		{
			soundButton = 1;
			gButtonMusic.drawButton(gRenderer, 950, 620, 50, 50);
		}

	}
	if (gButtonChunk.checkButton(x, y))
	{
		checkChunkButton = !checkChunkButton;
		checkChunkButton == false ? Mix_Volume(-1, 100) : Mix_Volume(-1, 0);
	}
}

void numberEvent(SDL_Event &e)
{
	switch (e.key.keysym.sym)
	{
	case SDLK_0:
		newCredits = (newCredits * 10) + 0;
		break;
	case SDLK_1:
		newCredits = (newCredits * 10) + 1;
		break;
	case SDLK_2:
		newCredits = (newCredits * 10) + 2;
		break;
	case SDLK_3:
		newCredits = (newCredits * 10) + 3;
		break;
	case SDLK_4:
		newCredits = (newCredits * 10) + 4;
		break;
	case SDLK_5:
		newCredits = (newCredits * 10) + 5;
		break;
	case SDLK_6:
		newCredits = (newCredits * 10) + 6;
		break;
	case SDLK_7:
		newCredits = (newCredits * 10) + 7;
		break;
	case SDLK_8:
		newCredits = (newCredits * 10) + 8;
		break;
	case SDLK_9:
		newCredits = (newCredits * 10) + 9;
		break;
	case SDLK_SPACE:
		checkEnter = true;
		break;
	default:
		break;
	}

}
void help()
{
	if (info == true && infoPages == 1)
	{
		gHelp.render(gRenderer, 15, 2);
		gInfo.drawButton(gRenderer, 10, 620, 50, 50);
	}
	else if (info == true && infoPages == 2)
	{
		gHelp2.render(gRenderer, 15, 2);
		gInfo.drawButton(gRenderer, 10, 620, 50, 50);
	}

}
void close()
{
	gBackground.free();
	gCard.free();
	gDeal.free();
	gButtonMusic.free();
	gButtonMusicX.free();
	gDeal2.free();
	gAutoHold.free();
	gDraw.free();
	gDraw2.free();
	gInfo.free();
	gHelp.free();

	gCursorDefault.free();
	gEnterCredit.free();
	gCredit.free();
	gReadCredit.free();
	gWins.free();
	gHand.free();
	gStatTotalPlayed.free();
	gStatWinGames.free();
	gStatLoseGames.free();
	gStatTotalCreditIn.free();
	gStatTotalCreditsWon.free();
	gYouWin.free();
	gYouLose.free();
	gRectHand.free();

	gJoker.free();

	gButtonDraw = NULL;
	gButtonMusicInfo = NULL;
	gMusicBtton = NULL;
	gMusic = NULL;
	gBeat = NULL;

	TTF_CloseFont(gFont);
	gFont = NULL;

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	Mix_Quit();
}

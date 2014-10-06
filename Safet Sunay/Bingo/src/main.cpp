#include "GlobalVariables.h"

//Global variables
SDL_Window *window = NULL;
SDL_Renderer *gRenderer = NULL;
TTF_Font *font = NULL;
TTF_Font *statis = NULL;
SDL_Surface *surface = NULL;
SDL_Texture *texture = NULL;

LTexture ticket1Nums;

LTexture buttonPlay;
LTexture buttonQuit;
LTexture buttonInfo;
LTexture buttonRules;
LTexture buttonNewGame;
LTexture buttonSound;
LTexture buttonMusic;
LTexture soundStop;
LTexture musicStop;
LTexture gMark;
LTexture stats;
LTexture gSpriteSheetTexture;

SDL_Rect gSpriteClips;

CheckForBingo check;

//tickets
BingoTicket playerTicket;
BingoTicket compTicket;

//Ball
Ball ball;
Game game;

ToFile file;

bool init();
bool loadMedia();
void close();

int main(int argc, char* args[])
{
	srand(time(0));

	Player player1;
	Uint32 frameStart, frameTime;

	game.playgameVars();
	file.readHsInput();
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Event handler
			SDL_Event event;

			game.setBallNum(ball.getBallNum());

//			------------ Main loop -------------
			while (!game.getQuit())
			{
				frameStart = SDL_GetTicks();

				//Handle events on queue
				while (SDL_PollEvent(&event) != 0)
				{
					if (event.type == SDL_QUIT)
					{
						file.writeHsOutput();
						game.setQuit(true);
					}
					game.buttonPress(event);
				}

				// Renders buttons(Mouse over effect(Glow))
				// Renders player and computer cards(TTF)
				// Updates screen
				// Clears Render
				// Renders background image
				// Renders credit
				game.renderScreen();

				// After clicking on PLAY button sets isPlay - true
				// Starts ball motion and ball number drawing
				if (game.isPlay())
				{
					// Renders player's bet on screen
					game.displayBet(10);

					check.setRowCol(game.getBallNum(), playerTicket.ticket);

					if (game.renderBall(frameStart))
					{
						game.setBallNum(ball.getBallNum());
					}
				}

				frameTime = SDL_GetTicks() - frameStart;
				if (frameTime < DELAY_TIME)
				{
					SDL_Delay((int) (DELAY_TIME - frameTime));
				}
			}
		}
	}

	//Free resources and close SDL
	close();
	return 0;
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO || SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		window = SDL_CreateWindow("B I N G O !", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n",
					SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(window, -1,
					SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n",
						SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf(
					"SDL_image could not initialize! SDL_image Error: %s\n",
					IMG_GetError());
					success = false;
				}
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n",
					TTF_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	if (!gMark.loadFromFile("Images/BingoMark.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	if (!gBackgroundTexture.loadFromFile("Images/Bingo.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	if (!gRulesTexture.loadFromFile("Images/RulesBackground.png"))
	{
		printf("Failed to load Rules texture image!\n");
		success = false;
	}
	if (!gHighScoreTexture.loadFromFile("Images/RulesBackground.png"))
	{
		printf("Failed to load High Score texture image!\n");
		success = false;
	}
	if (!buttonNewGame.loadFromFile("Images/NewGame.png"))
	{
		printf("Failed to load button texture image!\n");
		success = false;
	}
	if (!buttonInfo.loadFromFile("Images/Info.png"))
	{
		printf("Failed to load button texture image!\n");
		success = false;
	}
	if (!buttonRules.loadFromFile("Images/Rules.png"))
	{
		printf("Failed to load button texture image!\n");
		success = false;
	}
	if (!buttonQuit.loadFromFile("Images/Quit.png"))
	{
		printf("Failed to load button texture image!\n");
		success = false;
	}
	if (!buttonPlay.loadFromFile("Images/PLAY.png"))
	{
		printf("Failed to load button texture image!\n");
		success = false;
	}
	if (!buttonMusic.loadFromFile("Images/MusicButtonMouseOver.png"))
	{
		printf("Failed to load button texture image!\n");
		success = false;
	}
	if (!buttonSound.loadFromFile("Images/SoundButtonMouseOver.png"))
	{
		printf("Failed to load button texture image!\n");
		success = false;
	}
	if (!gSpriteSheetTexture.loadFromFile("Images/BingoBalls75.png"))
	{
		printf("Failed to load balls animation texture!\n");
		success = false;
	}
	if (!soundStop.loadFromFile("Images/SoundStop.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}
	if (!musicStop.loadFromFile("Images/MusicStop.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}
	else
	{
		gSpriteClips.x = 0;
		gSpriteClips.y = 0;
		gSpriteClips.w = 2000;
		gSpriteClips.h = 1600;
	}

	font = TTF_OpenFont("titania.ttf", 26);
	if (font == NULL)
	{
		printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}

	statis = TTF_OpenFont("titania.ttf", 24);
	if (statis == NULL)
	{
		printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	return success;
}

void close()
{
	//Free loaded images
	ticket1Nums.free();
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(window);
	window = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

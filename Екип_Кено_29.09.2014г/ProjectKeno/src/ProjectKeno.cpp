#include "Global.h"
#include "Numbers.h"
#include "Balance.h"
#include "PayTable.h"
#include "Statistics.h"
#include "Recovery.h"
#include "KTexture.h"
#include "FrequencyNumber.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string>
#include "Button.h"
#include <SDL2/SDL_ttf.h>
#include <string>
#include <sstream>

using namespace std;

const int SCREEN_WIDTH = 878;
const int SCREEN_HEIGHT = 640;

bool isWin(int, int);
template<typename T, typename S>
void saveDataInFile(T&, S &);
void getRecovery(fstream&, Recovery &);
void getDataFromFile(fstream&, Statistics &);
void printStatistic(ostream&, Statistics &, fstream &);
void quickPick(vector<int>);
void saveFrequencyInFile(fstream &, FrequencyNumber &);
void loadFrequencyFromFile(fstream &, FrequencyNumber &);
void loadSelectedNumbers();
void setInitialColor();
void loadTTF();

bool init();
bool loadMedia();
bool loadLights();
void close();

SDL_Texture* loadTexture(std::string path);
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* background = NULL;

const int LIGHTS_ANIMATION = 3;
SDL_Rect gLightsClips[LIGHTS_ANIMATION];
KTexture gLightsSheetTexture;

KTexture infoButton;
KTexture infoButton2;
KTexture playButton;
KTexture musicButton;
SDL_Rect pButton;
SDL_Rect iButton;
SDL_Rect iButton2;
SDL_Rect mButton;

const int SELECTED_NUMBERS_ROWS = 8;
const int SELECTED_NUMBERS_COLS = 10;
Button gButtons[SELECTED_NUMBERS_ROWS][SELECTED_NUMBERS_COLS];

Mix_Music *gMainMelody = NULL;
Mix_Chunk *gPlay = NULL;
Mix_Chunk *gQuickPick = NULL;
Mix_Chunk *gSelect = NULL;
Mix_Chunk *gClear = NULL;

TTF_Font *gFont = NULL;
KTexture gText;
SDL_Color textColor = {0, 0, 0};

int main(int args, char* argc[]) {

	vector<int> userSelects;

	srand(time(0));

	fstream Logs("Statistics.dat", ios::in | ios::out | ios::binary);

	if (!Logs) {
		cerr << "The file could not be opened !!!";
		exit(1);
	}

	fstream fileRecovery("Recovery.dat", ios::in | ios::out | ios::binary);

	if (!Logs) {
		cerr << "The file could not be opened !!!";
		exit(1);
	}

	fstream fileFrequency("Frequency.dat", ios::in | ios::out);

	if (!Logs) {
		cerr << "The file could not be opened !!!";
		exit(1);
	}

//	static char choice = 'y';

	Recovery recover;
//	getRecovery(fileRecovery, recover);

	Balance credits(recover.getRecoveryBalance());

	Statistics stats;

	FrequencyNumber freq;
	loadFrequencyFromFile(fileFrequency, freq);
//
	saveFrequencyInFile(fileFrequency, freq);
//	saveDataInFile(Logs,stats);

	getDataFromFile(Logs, stats);
	printStatistic(cout, stats, Logs);
//
//	while (choice == 'y') {

//		cout << "Enter numbers from 1 to 80 (press 0 to end input)" << endl;

//		int number;
//		cin >> number;
	unsigned pick = 10;
	bool play = false;
	bool clear = false;
	bool music = false;
	if (!init()) {
		printf("Failed to initialize!\n");
	} else {
		//Load media
		if (!loadMedia()) {
			printf("Failed to load media!\n");
		} else {

			loadLights();
			loadSelectedNumbers();
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;
			int x, y;
			//Current animation frame
			int frame = 0;
			bool help = false;
			bool help2 = false;

			//While application is running
			while (!quit) {

				//Handle events on queue
				while (SDL_PollEvent(&e) != 0) {
					//User requests quit

					switch (e.type) {
					case SDL_QUIT:
						quit = true;
						break;
//
					case SDL_MOUSEBUTTONDOWN: {
						SDL_GetMouseState(&x, &y);
//						cout << x << " " << y << endl;
//
//						//Numbers Field
						if (x >= 218 && x <= 218 + SELECTED_NUMBERS_COLS * Button::WIDTH && y >= 38 && y <= 38
							+ SELECTED_NUMBERS_ROWS	* Button::HEIGHT)
						{
							if (gButtons[(y - 38) / Button::HEIGHT][(x - 218)
									/ Button::WIDTH].Clicked)
							{
								gButtons[(y - 38) / Button::HEIGHT][(x - 218)
										/ Button::WIDTH].setInitialColor();

								Mix_PlayChannel(-1, gSelect, 0);

								int remove =
										gButtons[(y - 38) / Button::HEIGHT][(x
												- 218) / Button::WIDTH].getNumber();

								for (unsigned i = 0; i < userSelects.size();
										i++) {
									if (userSelects[i] == remove) {
										userSelects.erase(
												userSelects.begin() + i);
									}
								}
								pick = userSelects.size();
							} else {
								if (userSelects.size() < 10)
								{
									Mix_PlayChannel(-1, gSelect, 0);
									gButtons[(y - 38) / Button::HEIGHT][(x - 218)
											/ Button::WIDTH].setColor(255, 255,
											0, 128);
									if (gButtons[(y - 38) / Button::HEIGHT][(x
											- 218) / Button::WIDTH].getNumber()
											> 0
											&& gButtons[(y - 38)
													/ Button::HEIGHT][(x - 218)
													/ Button::WIDTH].getNumber()
													<= 80) {
										userSelects.push_back(
												gButtons[(y - 38)
														/ Button::HEIGHT][(x
														- 218) / Button::WIDTH].getNumber());
										pick = userSelects.size();
										clear = false;

									}
								}
								if (clear && userSelects.size() == 10)
								{
									Mix_PlayChannel(-1, gSelect, 0);
									setInitialColor();
									userSelects.clear();
									clear = false;

									gButtons[(y - 38) / Button::HEIGHT][(x - 218)
											/ Button::WIDTH].Clicked = true;

									gButtons[(y - 38) / Button::HEIGHT][(x - 218)
											/ Button::WIDTH].setColor(255, 255,
											0, 128);

									if (gButtons[(y - 38) / Button::HEIGHT][(x
											- 218) / Button::WIDTH].getNumber()
											> 0
											&& gButtons[(y - 38)
													/ Button::HEIGHT][(x - 218)
													/ Button::WIDTH].getNumber()
													<= 80) {
										userSelects.push_back(
												gButtons[(y - 38)
														/ Button::HEIGHT][(x
														- 218) / Button::WIDTH].getNumber());
										pick = userSelects.size();
									}
								}
							}

							gButtons[(y - 38) / Button::HEIGHT][(x - 218)
									/ Button::WIDTH].Clicked =
									!gButtons[(y - 38) / Button::HEIGHT][(x
											- 218) / Button::WIDTH].Clicked;

							//Update screen
							SDL_RenderPresent(gRenderer);
						}
//
						//Play button
						if (x >= 483 && x <= 569 && y >= 413 && y <= 502
								&& userSelects.size() >= 2)
						{
							play = true;
							Mix_PlayChannel(-1, gPlay, 0);
						}

						if (pick <= 1) {
							pick = 10;
						}

						//QuickPick
						if (x > 327 && x < 428 && y > 457 && y < 517) {

							userSelects.clear();
							setInitialColor();

							Mix_PlayChannel(-1, gQuickPick, 0);

							while (userSelects.size() != pick) {
								int push = 1 + rand() % 80;
								gButtons[push / 10][(push % 10) - 1].setColor(
										255, 255, 0, 128);
								gButtons[push / 10][(push % 10) - 1].Clicked =
										true;
								userSelects.push_back(push);
								sort(userSelects.begin(), userSelects.end());

								userSelects.erase(
										unique(userSelects.begin(),
												userSelects.end()),
										userSelects.end());
							}
						}

						//Clear
						if (x > 133 && x < 214 && y > 369 && y < 442)
						{
							Mix_PlayChannel(-1, gClear, 0);
							setInitialColor();
							userSelects.clear();
							pick = 10;
						}

						if (x > 663 && x < 748 && y > 380 && y < 449)
						{
							help = true;
						}
						if(x > 810 && x < 878 && y > 510 && y < 640 && help == true)
						{
							help2 = true;
						}
						if (x > 0 && x < 80 && y > 580 && y < 640)
						{
							help2 = false;
						}
						if (x > 700 && x < 852 && y > 15 && y < 84) {
							help = false;
						}

						if(x > 853 && x < 878 && y > 0 && y < 30)
						{

							if(music == false)
							{
								Mix_PauseMusic();
							}
							else
							{
								Mix_ResumeMusic();
							}
							music = !music;
						}
					}
						break;
					}
				}

				if (Mix_PlayingMusic() == 0) {
					Mix_PlayMusic(gMainMelody, -1);
				}

				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				SDL_RenderClear(gRenderer);

				SDL_RenderCopy(gRenderer, background, NULL, NULL);
				if (userSelects.size() >= 2) {
					playButton.button(gRenderer, 460, 385, 130, 132);
				}

				SDL_Rect* currentClip = &gLightsClips[frame / 1000];
				gLightsSheetTexture.render(gRenderer, 0, 496, currentClip);

				for (int rows = 0; rows < 8; rows++) {
					for (int cols = 0; cols < 10; cols++) {
						gButtons[rows][cols].draw(gRenderer);
					}
				}



//				gText.renderText(gRenderer, 100, 100);
//				gText.loadFromRenderedText(gRenderer, gFont, "asodkasd", textColor);
				loadTTF();

				if (help== true)
				{
					infoButton.help(gRenderer, 0, 0, 878, 640);
					if (help2)
					{
						infoButton2.help(gRenderer, 0, 0, 878, 640);
					}
				}

				if(music == true)
				{
					musicButton.button(gRenderer, 849, 0, 29, 31);
				}



				//Update screen
				SDL_RenderPresent(gRenderer);

				//Go to next frame
				++frame;

				//Cycle animation
				if (frame / 1000 >= LIGHTS_ANIMATION)
				{
					frame = 0;
				}

				if (play) {
					Numbers numb(userSelects);

					cout << "Your picks: ";
					numb.printSelects();

					cout << "\nPicked numbers: ";
					numb.printRandom();

					cout << "\n" << numb.getHits();
					cout << endl;

					PayTable b(userSelects.size());
					b.print();

					credits.setCredit();
					credits.calculateWin(userSelects.size(), numb.getHits(),
							coefficient);

					stats.setNumberOfGames(stats.getNumberOfGames() + 1);

					if (isWin(userSelects.size(), numb.getHits())) {
						stats.setWinningGames(stats.getWinningGames() + 1);
						stats.setMaxPayout(
								(10
										* (coefficient[userSelects.size()][numb.getHits()])));
					} else {
						stats.setLostGames(stats.getLostGames() + 1);
					}

					recover.setRecoveryBalance(credits.getCredit());

					saveDataInFile(Logs, stats);
					saveDataInFile(fileRecovery, recover);

					freq.setMap(numb.getRandoms());
					freq.printMap();

					numb.clearReset();

					cout << "\nYour Credits are: " << credits.getCredit()
							<< endl;
					cout << "For continue playing press \"Y\" " << endl;
					play = false;
					clear = true;

					for (unsigned i = 0; i < userSelects.size(); i++) {
						cout << userSelects[i] << " " << endl;
					}
				}
				saveFrequencyInFile(fileFrequency, freq);
			}
		}
	}

	close();

	return 0;
}

void saveFrequencyInFile(fstream &write, FrequencyNumber &freq) {
	map<int, int> temp2;
	map<int, int>::iterator it;
	int key, value;
	char ch;
	while (write >> key >> ch >> value) {
		temp2[key] = value;
	}
	map<int, int> temp = freq.getMap();
	temp.insert(temp2.begin(), temp2.end());
	write.clear();
	write.seekp(0);
	it = temp.begin();
	for (int i = 0; i < 80; i++) {
		if ((i + 1) == it->first) {
			write << it->first << "-" << it->second << endl;
			it++;
		} else {
			write << i + 1 << "-" << 0 << endl;
		}

	}
}

void loadFrequencyFromFile(fstream &read, FrequencyNumber &freq) {
	map<int, int> temp;
	int key, value;
	char ch;
	read.seekg(0);
	while (read >> key >> ch >> value) {
		temp[key] = value;
	}
	freq.setMapFromFile(temp);
}

void quickPick(vector<int> quick) {

	int size = quick.size();
	quick.clear();
	for (int i = 0; i < size; i++) {
		quick.push_back(1 + rand() % 80);
	}

}

bool isWin(int a, int b) {
	if (coefficient[a][b] > 0)
		return true;
	else
		return false;
}


template<typename T, typename S>
void saveDataInFile(T &insertInFile, S &stat) {

	insertInFile.seekp(0);
	insertInFile.write(reinterpret_cast<const char *>(&stat), sizeof(S));

}

void getRecovery(fstream &file, Recovery &recover) {
	file.seekg(0);
	file.read(reinterpret_cast<char *>(&recover), sizeof(Recovery));
	recover.setRecoveryBalance(recover.getRecoveryBalance());
}

void getDataFromFile(fstream &file, Statistics &stat) {
	file.seekg(0);
	file.read(reinterpret_cast<char *>(&stat), sizeof(Statistics));
	stat.setLostGames(stat.getLostGames());
	stat.setWinningGames(stat.getWinningGames());
	stat.setNumberOfGames(stat.getNumberOfGames());
	stat.setMaxPayout(stat.getMaxPayout());

}

void printStatistic(ostream &output, Statistics &stat, fstream &file) {
	file.seekg(0);
	file.read(reinterpret_cast<char *>(&stat), sizeof(Statistics));
	output << setw(5) << right << "Games" << setw(7) << right << "Wins"
			<< setw(8) << right << "Loses" << setw(13) << right << "Max Payout"
			<< endl;

	output << setw(5) << right << stat.getNumberOfGames() << setw(7) << right
			<< stat.getWinningGames() << setw(8) << right << stat.getLostGames()
			<< setw(13) << right << stat.getMaxPayout() << endl;
}

bool init() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	} else {
		//Set texture filtering to linear
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("ALIEN KENO", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			printf("Window could not be created! SDL Error: %s\n",
					SDL_GetError());
			success = false;
		} else {
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1,
					SDL_RENDERER_ACCELERATED);
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

				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
					printf(
							"SDL_mixer could not initialize! SDL_mixer Error: %s\n",
							Mix_GetError());
					success = false;
				}

				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
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

	//Load PNG texture
	background = loadTexture("Images/BaseBackground.png");
	if (background == NULL) {
		printf("Failed to load texture image!\n");
		success = false;
	}

	if (!musicButton.loadFromFile(gRenderer, "Images/MusicMute.png")) {
			printf("Failed to load background texture image!\n");
			success = false;
		} else {
			mButton.x = 849;
			mButton.y = 609;
			mButton.w = 29;
			mButton.h = 31;
		}

	if (!playButton.loadFromFile(gRenderer, "Images/playGlow.png")) {
		printf("Failed to load background texture image!\n");
		success = false;
	} else {
		pButton.x = 0;
		pButton.y = 0;
		pButton.w = 116;
		pButton.h = 108;
	}

	if (!infoButton.loadFromFile(gRenderer, "Images/HelpScreen.png")) {
		printf("Failed to load background texture image!\n");
		success = false;
	} else {
		iButton.x = 0;
		iButton.y = 0;
		iButton.w = 878;
		iButton.h = 640;
	}
	if (!infoButton2.loadFromFile(gRenderer, "Images/HelpScreen2.png")) {
		printf("Failed to load background texture image!\n");
		success = false;
	} else {
		iButton2.x = 0;
		iButton2.y = 0;
		iButton2.w = 878;
		iButton2.h = 640;
	}

	gMainMelody = Mix_LoadMUS("Sounds/Keno_melody.mp3");
	Mix_VolumeMusic(50);
	if (gMainMelody == NULL) {
		printf("Failed to load beat music! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	gPlay = Mix_LoadWAV("Sounds/Playbutton.wav");
	Mix_VolumeChunk(gPlay,128);
	if (gPlay == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	gQuickPick = Mix_LoadWAV("Sounds/QuickPick.wav");
	Mix_VolumeChunk(gQuickPick,128);
	if (gQuickPick == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	gSelect = Mix_LoadWAV("Sounds/Select.wav");
	Mix_VolumeChunk(gSelect,128);
	if (gSelect == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	gClear = Mix_LoadWAV("Sounds/ClearButton.wav");
	Mix_VolumeChunk(gClear,128);
	if (gClear == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	gFont = TTF_OpenFont("moonhouse.ttf", 18 );
	if( gFont == NULL )
	{
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
		//Render text
		SDL_Color textColor = { 0, 0, 0 };
		if( !gText.loadFromRenderedText(gRenderer, gFont, "The quick brown fox jumps over the lazy dog", textColor ) )
		{
			printf( "Failed to render text texture!\n" );
			success = false;
		}
	}

	return success;
}

void close() {
	//Free loaded image
	gLightsSheetTexture.free();
	SDL_DestroyTexture(background);
	background = NULL;

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	Mix_FreeMusic(gMainMelody);
	gMainMelody = NULL;

	//Quit SDL subsystems
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture(std::string path) {
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(),
		IMG_GetError());
	} else {
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n",
					path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

bool loadLights() {
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if (!gLightsSheetTexture.loadFromFile(gRenderer, "Images/LightsTest.png")) {
		printf("Failed to load walking animation texture!\n");
		success = false;
	} else {
		//Set sprite clips
		gLightsClips[0].x = 0;
		gLightsClips[0].y = 0;
		gLightsClips[0].w = 878;
		gLightsClips[0].h = 143;

		gLightsClips[1].x = 0;
		gLightsClips[1].y = 144;
		gLightsClips[1].w = 878;
		gLightsClips[1].h = 143;

		gLightsClips[2].x = 0;
		gLightsClips[2].y = 288;
		gLightsClips[2].w = 878;
		gLightsClips[2].h = 143;

	}

	return success;
}

void loadSelectedNumbers() {
	int x = 218;
	int y = 38;

	int count = 1;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 10; j++) {
			gButtons[i][j].setPosition(x, y);
			gButtons[i][j].setNumber(count);
			count++;
			x += Button::WIDTH;
		}
		y += Button::HEIGHT;
		x = 218;
	}
}

void loadTTF() {
	int x = 225;
	int y = 41;


	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 10; j++)
		{
			stringstream ss;
			ss<<gButtons[i][j].getNumber();

			gText.loadFromRenderedText(gRenderer, gFont,ss.str(), textColor);
			gText.renderText(gRenderer, x, y);

			x += Button::WIDTH;
			ss<<"";

		}
		x=225;
		y += Button::HEIGHT;

	}
}

void setInitialColor() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 10; j++) {
//				gButtons[i][j].setPosition(x, y);
			gButtons[i][j].setInitialColor();
			gButtons[i][j].Clicked = false;

//				x += Button::WIDTH;
		}
//			y += Button::HEIGHT;
//			x = 218;
	}
}


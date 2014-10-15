#include "Global.h"
#include "Numbers.h"
#include "Balance.h"
#include "Statistics.h"
#include "Recovery.h"
#include "KTexture.h"
#include "FrequencyNumber.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string>
#include "Button.h"
#include <SDL2/SDL_ttf.h>
#include <string>
#include <exception>
#include <stdexcept>
#include <sstream>

using namespace std;

bool isWin(int, int);
bool screen = false;

template<typename T, typename S>
void saveDataInFile(T&, S &);
void getRecovery(fstream&, Recovery &);
void getDataFromFile(fstream&, Statistics &);
void saveFrequencyInFile(fstream &, FrequencyNumber &);
void loadFrequencyFromFile(fstream &, FrequencyNumber &);
void loadSelectedNumbers();
void setInitialColor();
void loadTTFGameboard();
void payTable(int,int,int);
void displayBalance(Balance &);
void displayStatistics(FrequencyNumber &, Statistics &);
void alienAnimation();
void ballAnimationColor(int &,int &);
void calculationAndSaveData(int &, vector<int> &,vector<int> &, Balance &, Statistics &, FrequencyNumber &, Recovery &,fstream& , fstream&);

bool init();
bool loadMedia();
void close();
void ballsOrder(vector<int> &,int,vector<int> &);

SDL_Texture* loadTexture(std::string path);
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* background = NULL;

const int LIGHTS_ANIMATION = 3;
SDL_Rect gLightsClips[LIGHTS_ANIMATION];
KTexture gLightsSheetTexture;

const int RADAR_ANIMATION = 25;
SDL_Rect gRadarClips[RADAR_ANIMATION];
KTexture gRadarSheetTexture;

const int ALIEN_ANIMATION = 2;
SDL_Rect gAlienClips[ALIEN_ANIMATION];
KTexture gAlienSheetTexture;

const int INC_DEC_ANIMATION = 2;
SDL_Rect gIncDecClips[INC_DEC_ANIMATION];
KTexture gIncDecSheetTexture;

const int RADIO_ANIMATION = 50;
SDL_Rect gRadioClips[RADIO_ANIMATION];
KTexture gRadioSheetTexture;

const int LOGO_ANIMATION = 20;
SDL_Rect gLogoClips[LOGO_ANIMATION];
KTexture gLogoSheetTexture;


KTexture infoButton;
KTexture infoButton2;
KTexture playButton;
KTexture musicButton;
KTexture clearInactive;
KTexture quickPickInactive;
KTexture chunkButton;
KTexture chunkButtonMute;


SDL_Rect pButton;
SDL_Rect iButton;
SDL_Rect iButton2;
SDL_Rect mButton;
SDL_Rect chunkButtonRect;
SDL_Rect chunkButtonRectMute;
SDL_Rect clearButton;
SDL_Rect quickPickButton;

const int BALL_COLORS = 4;
SDL_Rect ballsClips[BALL_COLORS];
KTexture balls[20];

const int SELECTED_NUMBERS_ROWS = 8;
const int SELECTED_NUMBERS_COLS = 10;
Button gButtons[SELECTED_NUMBERS_ROWS][SELECTED_NUMBERS_COLS];

Mix_Music *gMainMelody = NULL;
Mix_Chunk *gPlay = NULL;
Mix_Chunk *gQuickPick = NULL;
Mix_Chunk *gSelect = NULL;
Mix_Chunk *gClear = NULL;
Mix_Chunk *gWin = NULL;
Mix_Chunk *gCoin = NULL;

TTF_Font *gameBoardFont = NULL;
TTF_Font *infoFont = NULL;
TTF_Font *balanceFont = NULL;
TTF_Font *ballsFont = NULL;

KTexture gText;
SDL_Color textColor = { 0, 0, 0 };
SDL_Color payTableColor = { 165, 225, 169 };
SDL_Color winningsPayTableColor = { 255, 255, 0 };
SDL_Color balanceColor = { 255, 242, 59 };



unsigned int index = 0;
int main(int args, char* argc[]){

	vector<int> userSelects;
	vector<int> randoms;
	vector<int> numboffhit;

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

	Recovery recover;
	getRecovery(fileRecovery, recover);

	Balance credits(recover.getRecoveryBalance());

	Statistics stats;

	FrequencyNumber freq;
	loadFrequencyFromFile(fileFrequency, freq);

	freq.printMap();

	saveFrequencyInFile(fileFrequency, freq);
//	saveDataInFile(Logs,stats);

	getDataFromFile(Logs, stats);

	unsigned pick = 10;
	bool play = false;
	bool clear = false;
	bool music = false;
	bool help = false;
	bool help2 = false;
	bool ball = false;

	if (!init()) {
		printf("Failed to initialize!\n");
	} else {
		//Load media
		if (!loadMedia()) {
			printf("Failed to load media!\n");
		} else {

			loadSelectedNumbers();

			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;
			int x, y;
			//Current animation frame
			int frame = 0;

			Uint32  frameStart, frameTime;

			//While application is running
			while (!quit) {
				frameStart = SDL_GetTicks();

				//Handle events on queue
				while (SDL_PollEvent(&e) != 0) {
					//User requests quit

					if (play) {
						Numbers numb(userSelects);
						numb.printRandom();

						hits = numb.getHits();
						numboffhit = numb.getNumbOfHit();

//						recover.setRecoveryBalance(credits.getCredit());

//						saveDataInFile(Logs, stats);
//						saveDataInFile(fileRecovery, recover);

						randoms = numb.getRandoms();
						numb.clearReset();
						play = false;
						clear = true;
						index = 0;
						range = 540;
					}

					switch (e.type) {
					case SDL_QUIT:
						quit = true;
						break;

					case SDL_MOUSEBUTTONDOWN: {
						SDL_GetMouseState(&x, &y);

//						//Numbers Field
						if (x >= 218 && x <= 218 + SELECTED_NUMBERS_COLS * Button::WIDTH && y >= 38 && y <= 38 + SELECTED_NUMBERS_ROWS * Button::HEIGHT && screen == false)
						{
							hits = 0;
							ball = false;
							index = 0;
							if (gButtons[(y - 38) / Button::HEIGHT][(x - 218) / Button::WIDTH].Clicked)
							{
								gButtons[(y - 38) / Button::HEIGHT][(x - 218) / Button::WIDTH].setInitialColor();
								Mix_PlayChannel(-1, gSelect, 0);

								int remove = gButtons[(y - 38) / Button::HEIGHT][(x - 218) / Button::WIDTH].getNumber();

								for (unsigned i = 0; i < userSelects.size(); i++) {
									if (userSelects[i] == remove) {
										userSelects.erase(userSelects.begin() + i);
									}
								}

								pick = userSelects.size();
							}
							else
							{
								ball = false;
								if(ball)
								{
									setInitialColor();
								}
								if (userSelects.size() < 10)
								{
									Mix_PlayChannel(-1, gSelect, 0);
									gButtons[(y - 38) / Button::HEIGHT][(x - 218) / Button::WIDTH].setColor(255, 255, 0, 128);

									if (gButtons[(y - 38) / Button::HEIGHT][(x - 218) / Button::WIDTH].getNumber() > 0 && gButtons[(y - 38)
									    / Button::HEIGHT][(x - 218) / Button::WIDTH].getNumber() <= 80)
									{
										userSelects.push_back(gButtons[(y - 38) / Button::HEIGHT][(x - 218) / Button::WIDTH].getNumber());
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

									gButtons[(y - 38) / Button::HEIGHT][(x - 218) / Button::WIDTH].Clicked = true;

									gButtons[(y - 38) / Button::HEIGHT][(x - 218) / Button::WIDTH].setColor(255, 255, 0, 128);

									if (gButtons[(y - 38) / Button::HEIGHT][(x - 218) / Button::WIDTH].getNumber() > 0 && gButtons[(y - 38)
										/ Button::HEIGHT][(x - 218) / Button::WIDTH].getNumber() <= 80)
									{
										userSelects.push_back(gButtons[(y - 38) / Button::HEIGHT][(x - 218) / Button::WIDTH].getNumber());
										pick = userSelects.size();
									}
								}
							}

							gButtons[(y - 38) / Button::HEIGHT][(x - 218) / Button::WIDTH].Clicked = !gButtons[(y - 38) / Button::HEIGHT][(x - 218) / Button::WIDTH].Clicked;

							//Update screen
							SDL_RenderPresent(gRenderer);
						}
//
						//Play button
						if (x >= 483 && x <= 569 && y >= 413 && y <= 502 && userSelects.size() >= 2 && screen == false && credits.getCredit() > 0)
						{
							for(unsigned i = 0; i < userSelects.size();i++)
							{
								gButtons[userSelects[i]/10][(userSelects[i]%10)-1].setColor(255, 255, 0, 128);
							}

							play = true;
							Mix_PlayChannel(-1, gPlay, 0);
							ballY = 640;
							index = 0;
							randoms.clear();
							ballX = 170;
							ballY = 640;
							ball = true;
							hits = 0;
							balanceCount = 0;
							credits.setCredit();
						}

						if (pick <= 1) {
							pick = 10;
						}

						//QuickPick
						if (x > 327 && x < 428 && y > 457 && y < 517 && screen == false)
						{
							index = 0;
							userSelects.clear();
							setInitialColor();
							ball = false;
							Mix_PlayChannel(-1, gQuickPick, 0);
							hits =0;

							while (userSelects.size() != pick)
							{
								int push = 1 + rand() % 80;
								gButtons[push / 10][(push % 10) - 1].setColor(255, 255, 0, 128);
								gButtons[push / 10][(push % 10) - 1].Clicked = true;
								userSelects.push_back(push);
								sort(userSelects.begin(), userSelects.end());
								userSelects.erase(unique(userSelects.begin(), userSelects.end()), userSelects.end());
							}
						}

						//Clear
						if (x > 133 && x < 214 && y > 369 && y < 442 && screen == false && userSelects.size() != 0)
						{
							Mix_PlayChannel(-1, gClear, 0);
							setInitialColor();
							userSelects.clear();
							pick = 10;
							ball = false;
							index =0;
							hits = 0;
						}

						//Help screens
						if (x > 663 && x < 721 && y > 380 && y < 435) {
							help = true;
							screen = true;
						}
						if (x > 810 && x < 878 && y > 510 && y < 640 && help == true) {
							help2 = true;
						}
						if (x > 0 && x < 80 && y > 580 && y < 640) {
							help2 = false;
						}
						if (x > 700 && x < 852 && y > 15 && y < 84 && help2 == false) {
							help = false;
							screen = false;
						}

						//playMusic
						if (x > 853 && x < 878 && y > 0 && y < 30 && help == false)
						{
							if (music == false) {
								Mix_PauseMusic();
							} else {
								Mix_ResumeMusic();
							}
							music = !music;
						}
						//playChunk
						if (x > 853 && x < 878 && y > 31 && y < 60)
						{
							if(chunk)
							{
								Mix_VolumeChunk(gPlay,0);
								Mix_VolumeChunk(gQuickPick,0);
								Mix_VolumeChunk(gSelect,0);
								Mix_VolumeChunk(gClear,0);
								Mix_VolumeChunk(gWin,0);
								Mix_VolumeChunk(gCoin,0);
							}
							else
							{
								Mix_VolumeChunk(gPlay,128);
								Mix_VolumeChunk(gQuickPick,128);
								Mix_VolumeChunk(gSelect,128);
								Mix_VolumeChunk(gClear,128);
								Mix_VolumeChunk(gWin,128);
								Mix_VolumeChunk(gCoin,128);
							}
							chunk = !chunk;
						}
						if (x > 565 && x < 591 && y > 237 && y < 264 && screen == false && credits.getBet() < credits.getCredit())
						{
							if(credits.getCredit() >= (credits.getBet() + 10) )
							{
							credits.setBet(credits.getBet() + 10);
							}
							incDecCount = 0;
							Mix_PlayChannel(-1, gCoin, 0);
						}
						if (x > 593 && x < 619 && y > 237 && y < 264 && screen == false && credits.getBet() > 10 )
						{
							if(credits.getBet() > 10)
							{
							credits.setBet(credits.getBet() - 10);
							}
							incDecCount = 0;
							Mix_PlayChannel(-1, gCoin, 0);
						}
					}break;
				}
			}

				if (Mix_PlayingMusic() == 0) {
					Mix_PlayMusic(gMainMelody, -1);
				}

				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				SDL_RenderClear(gRenderer);

				SDL_RenderCopy(gRenderer, background, NULL, NULL);

				if (userSelects.size() >= 2 && screen == false)
				{
					playButton.render(gRenderer, 458, 384, &pButton);
				}

				SDL_Rect* currentClip = &gLightsClips[frame / 30];
				gLightsSheetTexture.render(gRenderer, 0, 496, currentClip);

				SDL_Rect* RadarClip = &gRadarClips[radarFrame / 2];
				gRadarSheetTexture.render(gRenderer, 733, 337, RadarClip);

				SDL_Rect* RadioClip = &gRadioClips[radioFrame / 1];
				gRadioSheetTexture.render(gRenderer, 691, 470, RadioClip);

				SDL_Rect* LogoClip = &gLogoClips[logoFrame / 8];
				gLogoSheetTexture.render(gRenderer, 59, 443, LogoClip);

				for (int rows = 0; rows < 8; rows++) {
					for (int cols = 0; cols < 10; cols++) {
						gButtons[rows][cols].draw(gRenderer);
					}
				}

				if (help == false) {
					loadTTFGameboard();
				}
				if (help == true) {
					infoButton.render(gRenderer, 0, 0, &iButton );

					if (help2)
					{
						infoButton2.render(gRenderer, 0, 0, &iButton2);
					}
				}

				if (music == true && help == false) {
					musicButton.render(gRenderer, 849, 0, &mButton);
				}
				if(chunk && help == false)
				{
					chunkButton.render(gRenderer, 849, 32, &chunkButtonRect);
				}
				else if(!chunk && help == false)
				{
					chunkButtonMute.render(gRenderer, 849, 32, &chunkButtonRectMute);
				}

				if (help == false) {

					if (userSelects.size() > 1)
					{
						payTable(userSelects.size(),hits,index);
					}

					displayBalance(credits);
					freq.printMap();
					displayStatistics(freq, stats);
					freq.clear();
				}

				ballX2 = 170;
				ballY2 = 540;
				moveX = 11;
				moveY = 13;
				ballAnimationColor(counter, color);
				if(ball && randoms.size() > 0 && help == false){
					ballsOrder(randoms,color,numboffhit);
				}


				if((userSelects.size() == 0 || screen == true) && help == false){
				clearInactive.render(gRenderer,142,368,&clearButton);
				}

				if (x > 565 && x < 591 && y > 237 && y < 264 && screen == false && help == false && credits.getBet() < credits.getCredit() )
				{
					SDL_Rect* incDecClip = &gIncDecClips[0];
					gIncDecSheetTexture.render(gRenderer, 563, 233, incDecClip);

					if (incDecCount == 10)
					{
						x=0;
						y=0;
					}
					if(incDecCount < 11)
					{
						incDecCount++;
					}
				}

				if (x > 593 && x < 619 && y > 237 && y < 264 && screen == false && help == false && credits.getBet() > 10)
				{
					SDL_Rect* incDecClip = &gIncDecClips[1];
					gIncDecSheetTexture.render(gRenderer, 589, 233, incDecClip);
					if (incDecCount == 10)
					{
						x=0;
						y=0;
					}
					if(incDecCount < 11)
					{
						incDecCount++;
					}
				}

				if (index == 20 && balanceCount == 0)
				{
					calculationAndSaveData(balanceCount,userSelects,randoms,credits,stats,freq,recover,Logs,fileRecovery);
				}


				if (help == false && coefficient[userSelects.size()][hits] > 0 && index == 20 && counter > 0)
				{
					gText.loadFromRenderedText(gRenderer, balanceFont, "W I N:", balanceColor);
					gText.renderText(gRenderer, 385, 355);

					stringstream ss;
					ss<<coefficient[userSelects.size()][hits] * credits.getBet();

					gText.loadFromRenderedText(gRenderer, balanceFont, ss.str(), balanceColor);
					gText.renderText(gRenderer, 455, 355);

					ss<<"";
					ss.clear();
				}

				if (help == false && screen == true){
					quickPickInactive.render(gRenderer,331,457,&quickPickButton);
				}

				if (coefficient[userSelects.size()][hits] == 0 && index == 20 && help == false)
				{
					alienAnimation();
				}
				//Update screen
				SDL_RenderPresent(gRenderer);

				//Go to next frame
				++frame;

				//Cycle animation
				if (frame / 30 >= LIGHTS_ANIMATION) {
					frame = 0;
				}

				//Go to next frame
				++radarFrame;

				//Radar animation
				if (radarFrame / 2 >= RADAR_ANIMATION) {
					radarFrame = 0;
				}

				++radioFrame;

				//Radio animation
				if (radioFrame / 1 >= RADIO_ANIMATION) {
					radioFrame = 0;
				}

				++logoFrame;

				//Logo animation
				if (logoFrame / 8 >= LOGO_ANIMATION) {
					logoFrame = 0;
				}

				saveFrequencyInFile(fileFrequency, freq);

				frameTime = SDL_GetTicks() - frameStart;
				if(frameTime < DELAY_TIME){
					SDL_Delay((int)(DELAY_TIME - frameTime));
				}
			}
		}
	}

	close();

	return 0;
}

//Synchronize and saves map with frequency numbers in file
void saveFrequencyInFile(fstream &write, FrequencyNumber &freq) {

	map<int, int> temp2;
	map<int, int>::iterator it;

	int key, value;
	char ch;

	while (write >> key >> ch >> value)
	{
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
		}
		else
		{
			write << i + 1 << "-" << 0 << endl;
		}

	}
}

//Load information from file and set temporary map in main map in FrequencyNumber class
void loadFrequencyFromFile(fstream &read, FrequencyNumber &freq) {
	map<int, int> temp;

	int key, value;
	char ch;

	read.seekg(0);

	while (read >> key >> ch >> value)
	{
		temp[key] = value;
	}
	freq.setMapFromFile(temp);
}


//Check if current game have win
bool isWin(int numbers, int hits)
{
	if (coefficient[numbers][hits] > 0)
		return true;
	else
		return false;
}


//Save Recovery and Statistics information in file
template<typename T, typename S>
void saveDataInFile(T &insertInFile, S &stat) {

	insertInFile.seekp(0);
	insertInFile.write(reinterpret_cast<const char *>(&stat), sizeof(S));
}

//Read and set recovery from file and set in Recovery class
void getRecovery(fstream &file, Recovery &recover) {
	file.seekg(0);
	file.read(reinterpret_cast<char *>(&recover), sizeof(Recovery));
	recover.setRecoveryBalance(recover.getRecoveryBalance());
}

//Read and set statistic infomation from file and set it to the Statistic class
void getDataFromFile(fstream &file, Statistics &stat) {
	file.seekg(0);
	file.read(reinterpret_cast<char *>(&stat), sizeof(Statistics));
	stat.setLostGames(stat.getLostGames());
	stat.setWinningGames(stat.getWinningGames());
	stat.setNumberOfGames(stat.getNumberOfGames());
	stat.setMaxPayout(stat.getMaxPayout());
}

//initilizaton of sdl window
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
		gWindow = SDL_CreateWindow("TEAM KENO", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			printf("Window could not be created! SDL Error: %s\n",SDL_GetError());
			success = false;
		} else {
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC);
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
					printf("SDL_image could not initialize! SDL_image Error: %s\n",IMG_GetError());
					success = false;
				}

				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n",Mix_GetError());
					success = false;
				}

				if (TTF_Init() == -1) {
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n",
					TTF_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

//Load all images, sounds and, fonts
bool loadMedia() {
	//Loading success flag
	bool success = true;

	//Load PNG background texture
	background = loadTexture("Images/Background.png");
	if (background == NULL) {
		printf("Failed to load background texture image!\n");
		success = false;
	}

	if (!musicButton.loadFromFile(gRenderer, "Images/MusicMute.png")) {
		printf("Failed to load MusicMute texture image!\n");
		success = false;
	} else {
		mButton.x = 0;
		mButton.y = 0;
		mButton.w = musicButton.getWidth();
		mButton.h = musicButton.getHeight();
	}

	if (!chunkButton.loadFromFile(gRenderer, "Images/sound2.png")) {
			printf("Failed to load MusicMute texture image!\n");
			success = false;
		} else {
			chunkButtonRect.x = 0;
			chunkButtonRect.y = 0;
			chunkButtonRect.w = chunkButton.getWidth();
			chunkButtonRect.h = chunkButton.getHeight();
		}

	if (!chunkButtonMute.loadFromFile(gRenderer, "Images/soundmute2.png")) {
			printf("Failed to load MusicMute texture image!\n");
			success = false;
		} else {
			chunkButtonRectMute.x = 0;
			chunkButtonRectMute.y = 0;
			chunkButtonRectMute.w = chunkButtonMute.getWidth();
			chunkButtonRectMute.h = chunkButtonMute.getHeight();
		}

	if (!playButton.loadFromFile(gRenderer, "Images/playGlow.png")) {
		printf("Failed to load playGlow texture image!\n");
		success = false;
	} else {
		pButton.x = 0;
		pButton.y = 0;
		pButton.w = playButton.getWidth()+1;
		pButton.h = playButton.getHeight()+1;
	}

	if (!clearInactive.loadFromFile(gRenderer, "Images/ClearInactive.png")) {
		printf("Failed to load ClearInactive button texture image!\n");
		success = false;
	} else {
		clearButton.x = 0;
		clearButton.y = 0;
		clearButton.w = clearInactive.getWidth();
		clearButton.h = clearInactive.getHeight();
	}

	if (!quickPickInactive.loadFromFile(gRenderer, "Images/quickPickInactive.png")) {
		printf("Failed to load quickPickInactive button texture image!\n");
		success = false;
	} else {
		quickPickButton.x = 0;
		quickPickButton.y = 0;
		quickPickButton.w = quickPickInactive.getWidth();
		quickPickButton.h = quickPickInactive.getHeight();
	}

	for(int i = 0; i < 20; i++)
	{
		if (!balls[i].loadFromFile(gRenderer, "Images/Balls.png")) {
		printf("Failed to load Balls texture image!\n");
		success = false;
	} else {

		ballsClips[0].x = 0;
		ballsClips[0].y = 0;
		ballsClips[0].w = 45;
		ballsClips[0].h = 45;

		ballsClips[1].x = 45;
		ballsClips[1].y = 0;
		ballsClips[1].w = 45;
		ballsClips[1].h = 45;

		ballsClips[2].x = 90;
		ballsClips[2].y = 0;
		ballsClips[2].w = 45;
		ballsClips[2].h = 45;

		ballsClips[3].x = 135;
		ballsClips[3].y = 0;
		ballsClips[3].w = 45;
		ballsClips[3].h = 45;
	}
	}


	if (!infoButton.loadFromFile(gRenderer, "Images/HelpScreen.png")) {
		printf("Failed to load HelpScreen texture image!\n");
		success = false;
	} else {
		iButton.x = 0;
		iButton.y = 0;
		iButton.w = infoButton.getWidth();
		iButton.h = infoButton.getHeight();
	}
	if (!infoButton2.loadFromFile(gRenderer, "Images/HelpScreen2.png")) {
		printf("Failed to load HelpScreen2 texture image!\n");
		success = false;
	} else {
		iButton2.x = 0;
		iButton2.y = 0;
		iButton2.w = infoButton2.getWidth();
		iButton2.h = infoButton2.getHeight();
	}

	if (!gLightsSheetTexture.loadFromFile(gRenderer, "Images/Lights.png")) {
		printf("Failed to load Lights animation texture!\n");
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

	if (!gRadarSheetTexture.loadFromFile(gRenderer, "Images/Radar.png")) {
		printf("Failed to load Radar animation texture!\n");
		success = false;
	} else {
		//Set sprite clips
		int radarX = 0;
		int radarY = 0;
		for (int i = 1; i < 26; i++)
		{
			gRadarClips[i-1].x = radarX;
			gRadarClips[i-1].y = radarY;
			gRadarClips[i-1].w = 136;
			gRadarClips[i-1].h = 107;
			radarX += 136;
			if (i % 5 == 0 )
			{
				radarX = 0;
				radarY += 107;
			}
		}
	}

	if (!gRadioSheetTexture.loadFromFile(gRenderer, "Images/RadioWaves.png")) {
		printf("Failed to load Radio animation texture!\n");
		success = false;
	} else {
		int radioX = 0;
		int radioY = 0;
		for (int i = 1; i < 51; i++)
			{
				gRadioClips[i-1].x = radioX;
				gRadioClips[i-1].y = radioY;
				gRadioClips[i-1].w = 107;
				gRadioClips[i-1].h = 73;
				radioX += 107;
				if (i % 5 == 0 )
				{
					radioX = 0;
					radioY += 73;
				}
			}
	}

	if (!gLogoSheetTexture.loadFromFile(gRenderer, "Images/Logo.png")) {
		printf("Failed to load Logo animation texture!\n");
		success = false;
	} else {
		int logoX = 0;
		int logoY = 0;
		for (int i = 1; i < 21; i++)
			{
				gLogoClips[i-1].x = logoX;
				gLogoClips[i-1].y = logoY;
				gLogoClips[i-1].w = 135;
				gLogoClips[i-1].h = 108;
				logoX += 135;
				if (i % 5 == 0 )
				{
					logoX = 0;
					logoY += 108;
				}
			}
	}

	if (!gAlienSheetTexture.loadFromFile(gRenderer, "Images/AliensPNG.png")) {
		printf("Failed to load Lights animation texture!\n");
		success = false;
	} else {
		//Set sprite clips
		gAlienClips[0].x = 24;
		gAlienClips[0].y = 0;
		gAlienClips[0].w = 73;
		gAlienClips[0].h = 76;

		gAlienClips[1].x =120;
		gAlienClips[1].y = 65;
		gAlienClips[1].w = 73;
		gAlienClips[1].h = 76;
	}

	if (!gIncDecSheetTexture.loadFromFile(gRenderer, "Images/PlusMinus.png")) {
		printf("Failed to load Increase/Decrease animation texture!\n");
		success = false;
	} else {
		//Set sprite clips
		gIncDecClips[0].x = 0;
		gIncDecClips[0].y = 0;
		gIncDecClips[0].w = 26;
		gIncDecClips[0].h = 32;

		gIncDecClips[1].x =26;
		gIncDecClips[1].y = 0;
		gIncDecClips[1].w = 26;
		gIncDecClips[1].h = 32;
	}

	gMainMelody = Mix_LoadMUS("Sounds/Keno_melody.mp3");
	Mix_VolumeMusic(50);
	if (gMainMelody == NULL) {
		printf("Failed to load Keno_melody! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	gPlay = Mix_LoadWAV("Sounds/playButton.wav");
	Mix_VolumeChunk(gPlay, 128);
	if (gPlay == NULL) {
		printf("Failed to load playButton Chunk! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	gQuickPick = Mix_LoadWAV("Sounds/QuickPick.wav");
	Mix_VolumeChunk(gQuickPick, 128);
	if (gQuickPick == NULL) {
		printf("Failed to load QuickPick Chunk! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	gSelect = Mix_LoadWAV("Sounds/Select.wav");
	Mix_VolumeChunk(gSelect, 128);
	if (gSelect == NULL) {
		printf("Failed to load Select Chunk! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	gWin = Mix_LoadWAV("Sounds/Winning.wav");
	Mix_VolumeChunk(gWin, 128);
	if (gWin == NULL) {
		printf("Failed to load Winning Chunk! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	gClear = Mix_LoadWAV("Sounds/ClearButton.wav");
	Mix_VolumeChunk(gClear, 128);
	if (gClear == NULL) {
		printf("Failed to load ClearButton Chunk! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	gCoin = Mix_LoadWAV("Sounds/coin2.wav");
	Mix_VolumeChunk(gClear, 128);
	if (gCoin == NULL) {
		printf("Failed to load Coin Chunk! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	gameBoardFont = TTF_OpenFont("Fonts/moonhouse.ttf", 18);
	TTF_SetFontStyle(gameBoardFont, TTF_STYLE_BOLD);
	if (gameBoardFont == NULL) {
		printf("Failed to load moonhouse font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	} else {
		//Render text
		SDL_Color textColor = { 0, 0, 0 };
		if (!gText.loadFromRenderedText(gRenderer, gameBoardFont,
				"The quick brown fox jumps over the lazy dog", textColor)) {
			printf("Failed to render text texture!\n");
			success = false;
		}
	}

	infoFont = TTF_OpenFont("Fonts/Days.otf", 15);
	if (infoFont == NULL) {
		printf("Failed to load Days font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	} else {
		//Render text
		SDL_Color textColor = { 0, 0, 0 };
		if (!gText.loadFromRenderedText(gRenderer, infoFont,
				"The quick brown fox jumps over the lazy dog", textColor)) {
			printf("Failed to render text texture!\n");
			success = false;
		}
	}

	balanceFont = TTF_OpenFont("Fonts/Balance.ttf", 14);
	TTF_SetFontStyle(balanceFont, TTF_STYLE_BOLD);
	if (balanceFont == NULL) {
		printf("Failed to load Balance font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	} else {
		//Render text
		SDL_Color textColor = { 0, 0, 0 };
		if (!gText.loadFromRenderedText(gRenderer, balanceFont,
				"The quick brown fox jumps over the lazy dog", textColor)) {
			printf("Failed to render text texture!\n");
			success = false;
		}
	}

	ballsFont = TTF_OpenFont("Fonts/Evogria.ttf", 16);
	if (balanceFont == NULL) {
		printf("Failed to load Evogria font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	} else {
		//Render text
		SDL_Color textColor = { 0, 0, 0 };
		if (!gText.loadFromRenderedText(gRenderer, ballsFont,
				"The quick brown fox jumps over the lazy dog", textColor)) {
			printf("Failed to render text texture!\n");
			success = false;
		}
	}

	return success;
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

void loadTTFGameboard() {
	int x = 233;
	int y = 41;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 10; j++)
		{
			if (i > 0 && j == 0) {
				x += 6;
			}
			if (i == 1) {
				x += 6;
			}
			if (i == 1 && j == 9) {
				x -= 5;
			}
			stringstream ss;
			ss << gButtons[i][j].getNumber();
			gText.loadFromRenderedText(gRenderer, gameBoardFont, ss.str(),
					textColor);
			gText.renderText(gRenderer, x, y);
			x += Button::WIDTH;
			if (i > 0 && j == 0) {
				x -= 6;
			}
			if (i == 1) {
				x -= 6;
			}
			if (i == 1 && j == 9) {
				x += 5;
			}
			ss << "";

		}
		x = 224;
		y += Button::HEIGHT;

	}
}

void setInitialColor() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 10; j++) {
			gButtons[i][j].setInitialColor();
			gButtons[i][j].Clicked = false;
		}
	}
}

void payTable(int numbers,int hits, int index) {
	int y = 80;
	gText.loadFromRenderedText(gRenderer, infoFont, "Hits", payTableColor);
	gText.renderText(gRenderer, 40, 60);
	gText.loadFromRenderedText(gRenderer, infoFont, "Payout", payTableColor);
	gText.renderText(gRenderer, 93, 60);

	for (int j = numbers; j > 0; j--) {
		int x = 41;
		stringstream ss;
		stringstream ss2;
		if (hits > 0 && hits == j && index == 20)
		{
			ss << j;
			ss<<"*";
			gText.loadFromRenderedText(gRenderer, infoFont, ss.str(), winningsPayTableColor);
			gText.renderText(gRenderer, x, y);
			ss << "";
			ss.clear();
			ss2 << coefficient[numbers][j];
			x = 93;
			gText.loadFromRenderedText(gRenderer, infoFont, ss2.str(),winningsPayTableColor);
			gText.renderText(gRenderer, x, y);

			y += 20;
			ss2 << "";
			ss2.clear();
		}
		else{
		ss << j;
		gText.loadFromRenderedText(gRenderer, infoFont, ss.str(),payTableColor);
		gText.renderText(gRenderer, x, y);
		ss << "";
		ss.clear();
		ss2 << coefficient[numbers][j];
		x = 93;
		gText.loadFromRenderedText(gRenderer, infoFont, ss2.str(),payTableColor);
		gText.renderText(gRenderer, x, y);

		y += 20;
		ss2 << "";
		ss2.clear();
		}
	}
}

void displayBalance(Balance &credits) {
	int x = 390;
	int y = 239;

	gText.loadFromRenderedText(gRenderer, balanceFont, "CREDIT:", balanceColor);
	gText.renderText(gRenderer, 326, y);
	stringstream ss;
	ss << credits.getCredit();
	gText.loadFromRenderedText(gRenderer, balanceFont, ss.str(), balanceColor);
	gText.renderText(gRenderer, x, y);
	ss << "";
	ss.clear();
	stringstream ss2;
	ss2<<"BET ";
	ss2<<credits.getBet();
	gText.loadFromRenderedText(gRenderer, balanceFont,ss2.str(), balanceColor);
	gText.renderText(gRenderer, 475, y);
	ss2 << "";
	ss2.clear();
}

void displayStatistics(FrequencyNumber &freq, Statistics &stat) {
	int y = 75;
	gText.loadFromRenderedText(gRenderer, infoFont, "Num", payTableColor);
	gText.renderText(gRenderer, 719, 55);
	gText.loadFromRenderedText(gRenderer, infoFont, "Freq", payTableColor);
	gText.renderText(gRenderer, 794, 55);

	for (unsigned i = 0; i < freq.getNumb().size(); i++) {
		stringstream ss;
		ss << freq.getNumb()[i];
		gText.loadFromRenderedText(gRenderer, infoFont, ss.str(),payTableColor);
		gText.renderText(gRenderer, 719, y);
		ss << "";
		ss.clear();
		stringstream ss2;
		ss2 << freq.getFreq()[i];
		gText.loadFromRenderedText(gRenderer, infoFont, ss2.str(),
				payTableColor);
		gText.renderText(gRenderer, 794, y);
		ss2 << "";
		ss2.clear();
		y += 20;
	}

	gText.loadFromRenderedText(gRenderer, infoFont, "Games", payTableColor);
	gText.renderText(gRenderer, 719, 180);
	stringstream games;
	games << stat.getNumberOfGames();
	gText.loadFromRenderedText(gRenderer, infoFont, games.str(), payTableColor);
	gText.renderText(gRenderer, 794, 180);
	games << "";

	gText.loadFromRenderedText(gRenderer, infoFont, "Won", payTableColor);
	gText.renderText(gRenderer, 719, 200);
	stringstream won;
	won << stat.getWinningGames();
	gText.loadFromRenderedText(gRenderer, infoFont, won.str(), payTableColor);
	gText.renderText(gRenderer, 794, 200);
	won << "";

	gText.loadFromRenderedText(gRenderer, infoFont, "Lost", payTableColor);
	gText.renderText(gRenderer, 719, 220);
	stringstream lost;
	lost << stat.getLostGames();
	gText.loadFromRenderedText(gRenderer, infoFont, lost.str(), payTableColor);
	gText.renderText(gRenderer, 794, 220);
	lost << "";

	gText.loadFromRenderedText(gRenderer, infoFont, "Max   Payout",payTableColor);
	gText.renderText(gRenderer, 719, 245);
	stringstream pay;
	pay << stat.getMaxPayout();
	gText.loadFromRenderedText(gRenderer, infoFont, pay.str(), payTableColor);
	gText.renderText(gRenderer, 754, 265);
	pay << "";
}

void ballsOrder(vector<int> &randoms,int col,vector<int> &v)
{
	ballY-=2;
	if (randoms[index] < 10)
	{
		moveX = 16;
	}

	if(ballY > range)
	{
		screen = true;
		if(index < randoms.size())
		{
		balls[index].ballRender(gRenderer, ballX, ballY, &ballsClips[0]);
		stringstream ss;
		ss<<randoms[index];
		gText.loadFromRenderedText(gRenderer,ballsFont,ss.str(),payTableColor);
		gText.renderText(gRenderer,ballX+moveX,ballY+moveY);
		ss<<"";
		ss.clear();
		}
		if (ballY == range + 2 && index < randoms.size())
		{
			if(index == 9)
			{
				range = 590;
				ballX = 170 - 55;
			}

			index++;
			ballY = 640;
			ballX += 55;
		}
	}
	else
	{
		screen = false;
	}

	for ( unsigned i = 0; i < index; i++)
		{
			int x = randoms[i];
			moveX = 11;
			moveY = 13;
			if (i == 10)
			{
				ballX2= 170;
				ballY2 = 590;
			}
			if(binary_search(v.begin(),v.end(),x))
			{
				if (randoms[i] < 10)
				{
					moveX = 16;
				}
				if(((index < randoms.size() && (index-1) == i) || i == 19) && ballY == 638 ){
				Mix_PlayChannel(-1, gWin, 0);
				}

				gButtons[randoms[i]/10][(randoms[i]%10)-1].setColor(0,255,0,0);
				balls[i].ballRender(gRenderer, ballX2, ballY2, &ballsClips[col]);
				stringstream ss;
				ss<<randoms[i];
				gText.loadFromRenderedText(gRenderer,ballsFont,ss.str(),payTableColor);
				gText.renderText(gRenderer,ballX2+moveX,ballY2+moveY);
				ss<<"";
				ss.clear();
				ballX2 += 55;
			}
			else
			{
				if (randoms[i] < 10)
				{
					moveX = 16;
				}
				balls[i].ballRender(gRenderer, ballX2, ballY2, &ballsClips[0]);
				stringstream ss;
				ss<<randoms[i];
				gText.loadFromRenderedText(gRenderer,ballsFont,ss.str(),payTableColor);
				gText.renderText(gRenderer,ballX2+moveX,ballY2+moveY);
				ss<<"";
				ss.clear();
				ballX2 +=55;
			}
		}
}

void close()
{
	//Free loaded image
	gLightsSheetTexture.free();
	infoButton.free();
	infoButton2.free();
	playButton.free();
	musicButton.free();
	chunkButton.free();
	chunkButtonMute.free();
	clearInactive.free();
	quickPickInactive.free();
	gText.free();
	for (int i = 0; i < 20; i++)
	{
		balls[i].free();
	}
	gRadarSheetTexture.free();
	gRadioSheetTexture.free();
	gIncDecSheetTexture.free();
	gAlienSheetTexture.free();
	SDL_DestroyTexture(background);
	background = NULL;

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	Mix_FreeMusic(gMainMelody);
	gMainMelody = NULL;
	Mix_FreeChunk(gPlay);
	gPlay = NULL;
	Mix_FreeChunk(gQuickPick);
	gQuickPick = NULL;
	Mix_FreeChunk(gSelect);
	gSelect = NULL;
	Mix_FreeChunk(gClear);
	gClear = NULL;
	Mix_FreeChunk(gWin);
	gWin = NULL;

	//Quit SDL subsystems
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

void alienAnimation()
{
	if (alienCount < 10) {
		SDL_Rect* currentClip2 = &gAlienClips[0];
		gAlienSheetTexture.render(gRenderer, 612, 266, currentClip2);
		alienCount++;
	}
	if (alienCount >= 10 && alienCount < 20) {
		SDL_Rect* currentClip3 = &gAlienClips[1];
		gAlienSheetTexture.render(gRenderer, 615, 267, currentClip3);
		alienCount++;
	}
	if (alienCount == 20) {
		alienCount = 0;
	}

}

void ballAnimationColor(int &counter,int &color)
{
	if(counter < 3){
		color = 1;
		counter++;
	}
	if(counter >=3 && counter < 6){
		color =2;
		counter++;
	}
	if(counter >=6 && counter <= 9){
		color =3;
		counter++;
	}
	if(counter == 10){
		counter = 0;
	}
}
void calculationAndSaveData(int &balanceCount, vector<int> &userSelects,vector<int> &randoms, Balance &credits, Statistics &stats, FrequencyNumber &freq, Recovery &recover, fstream &Logs, fstream &fileRecovery)
{
	credits.calculateWin(userSelects.size(), hits, coefficient);
	balanceCount++;
	recover.setRecoveryBalance(credits.getCredit());
	saveDataInFile(fileRecovery, recover);

	stats.setNumberOfGames(stats.getNumberOfGames() + 1);
	if (isWin(userSelects.size(), hits)) {
		stats.setWinningGames(stats.getWinningGames() + 1);
		stats.setMaxPayout((credits.getBet() * (coefficient[userSelects.size()][hits])));
	} else {
		stats.setLostGames(stats.getLostGames() + 1);
	}
	freq.setMap(randoms);
	saveDataInFile(Logs, stats);
	if(credits.getCredit() < credits.getBet())
	{
		credits.setBet(credits.getCredit());
	}
}

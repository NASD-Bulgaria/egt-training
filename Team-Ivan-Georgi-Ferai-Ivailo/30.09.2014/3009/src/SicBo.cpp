//============================================================================
// Name        : SicBo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "Button.h"
#include "RollDice.h"
#include "Player.h"
#include "File.h"


using namespace std;
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 701;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* backGround = NULL;
TTF_Font* gFont = NULL;


//TTF surface

SDL_Surface *topInfo = NULL;

SDL_Surface *eachDiceInfo = NULL;
SDL_Surface* creditButton = NULL;
SDL_Surface* bet = NULL;

SDL_Surface *rollDiceOne = NULL;
SDL_Surface *rollDiceTwo = NULL;
SDL_Surface *rollDiceThree = NULL;
SDL_Surface *rollDiceFour = NULL;
SDL_Surface *rollDiceFive = NULL;
SDL_Surface *rollDiceSix = NULL;
SDL_Surface *firstDiceRoll = NULL;
SDL_Surface *secondDiceRoll = NULL;
SDL_Surface *thirdDiceRoll = NULL;

SDL_Surface* newGame = NULL;
SDL_Surface* newGameOn = NULL;
SDL_Surface* highScore = NULL;
SDL_Surface* help = NULL;
//SDL_Surface* helpOn = NULL;
SDL_Surface* helpImage = NULL;
SDL_Surface* clear = NULL;
SDL_Surface* roll = NULL;
SDL_Surface* rollOn = NULL;
SDL_Surface* backToGame = NULL;

SDL_Surface* small = NULL;
SDL_Surface* big = NULL;

SDL_Surface* doubleOne = NULL;
SDL_Surface* doubleTwo = NULL;
SDL_Surface* doubleThree = NULL;
SDL_Surface* doubleFour = NULL;
SDL_Surface* doubleFive = NULL;
SDL_Surface* doubleSix = NULL;

SDL_Surface* tripleOne = NULL;
SDL_Surface* tripleTwo = NULL;
SDL_Surface* tripleThree = NULL;
SDL_Surface* tripleFour = NULL;
SDL_Surface* tripleFive = NULL;
SDL_Surface* tripleSix = NULL;
SDL_Surface* anyTriple = NULL;

SDL_Surface* sumFour = NULL;
SDL_Surface* sumFive = NULL;
SDL_Surface* sumSix = NULL;
SDL_Surface* sumSeven = NULL;
SDL_Surface* sumEight = NULL;
SDL_Surface* sumNine = NULL;
SDL_Surface* sumTen = NULL;
SDL_Surface* sumEleven = NULL;
SDL_Surface* sumTwelve = NULL;
SDL_Surface* sumThirteen = NULL;
SDL_Surface* sumFourteen = NULL;
SDL_Surface* sumFifteen = NULL;
SDL_Surface* sumSixteen = NULL;
SDL_Surface* sumSeventeen = NULL;

SDL_Surface* pairInfo = NULL;
SDL_Surface* pairOneTwo = NULL;
SDL_Surface* pairOneThree = NULL;
SDL_Surface* pairOneFour = NULL;
SDL_Surface* pairOneFive = NULL;
SDL_Surface* pairOneSix = NULL;
SDL_Surface* pairTwoThree = NULL;
SDL_Surface* pairTwoFour = NULL;
SDL_Surface* pairTwoFive = NULL;
SDL_Surface* pairTwoSix = NULL;
SDL_Surface* pairThreeFour = NULL;
SDL_Surface* pairThreeFive = NULL;
SDL_Surface* pairThreeSix = NULL;
SDL_Surface* pairFourFive = NULL;
SDL_Surface* pairFourSix = NULL;
SDL_Surface* pairFiveSix = NULL;

SDL_Surface* anyStraight = NULL;
SDL_Surface* oneTwoThree = NULL;
SDL_Surface* TwoThreeFour = NULL;
SDL_Surface* ThreeFourFive = NULL;
SDL_Surface* FourFiveSix = NULL;

SDL_Surface* one = NULL;
SDL_Surface* two = NULL;
SDL_Surface* three = NULL;
SDL_Surface* four = NULL;
SDL_Surface* five = NULL;
SDL_Surface* six = NULL;

//The music that will be played
Mix_Music *music = NULL;

//The sound effects that will be used
Mix_Chunk *rollDice = NULL;
Mix_Chunk *win = NULL;
Mix_Chunk *chips = NULL;

//sound and music
SDL_Surface* sound = NULL;
SDL_Surface* soundOff = NULL;
SDL_Surface* playMusic = NULL;
SDL_Surface* playMusicOff = NULL;

bool init();
bool loadMedia();
bool loadMusic();
void close();
void cleanUp();
void drawTable();
void updateTable();
void clearBetAndWin();
void dicesVisual();
int checkHighScore();
void doEvents();
void helpWindow();
void rollButtonOn();
void newGameButtonOn();

TTF_Font* loadfont(string file, int ptsize);
SDL_Surface *drawtext(TTF_Font *fonttodraw,string text);
SDL_Surface* loadSurface(std::string path);

void onScreenCredit(Player &);
void onScreenWin(Player &);
void onScreenBet(vector <Button> &);
void onHighScore(File &);

File inFile;
Player player(1000,0,0);
RollDice rolldice;
vector<Button> mainVec;
vector<Button> menuButtons;
int currentMaxWin = 0;
int check = 0;
bool quit = false;
bool helpQuit = true;
bool playMus = true;
bool playSound = true;

int main(int argc, char* args[])
{
	const int FPS = 30;
	Uint32 start;
	srand(time(NULL));
	int recovery = inFile.recovery();
	player.setCredit(recovery);

	if ((!init()) || (!loadMedia()) || (!loadMusic())) {
		printf("Failed to initialize!\n");
	}
	else
	{
		Mix_PlayMusic( music, -1 );
		drawTable();
		while (!quit)
		{
			if(helpQuit) {
				updateTable();
				doEvents();
				start = SDL_GetTicks();
			}
			else {
				helpWindow();
				doEvents();
			}
			if (1000 / FPS > SDL_GetTicks() - start) {
				SDL_Delay(1000 / FPS - (SDL_GetTicks() - start));
			}

		}//end while(quit)
		cout << "You click the quit button !";

	}
	cleanUp();
	close();
	return 0;
}

bool init() {
//Initialization flag
	bool success = true;

//Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	} else {
		//Create window
		window = SDL_CreateWindow("Sic Bo 0.9b", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n",
					SDL_GetError());
			success = false;
		}
		else {
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				} else {

					//Get window surface
					screenSurface = SDL_GetWindowSurface(window);
				}
		}
		if (TTF_Init() == -1)
		{
			printf("Unable to initialize SDL_ttf: %s \n", TTF_GetError());
			exit(1);
		}
		if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
		{
			printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
			success = false;
		}
	}
	return success;
}

SDL_Surface *drawtext(TTF_Font *fonttodraw,string text)
{
	SDL_Color green = {0,255,0};
	SDL_Color black = {0,0,0};
	SDL_Surface *resulting_text = NULL;
	resulting_text = TTF_RenderText_Shaded(fonttodraw, text.c_str(), green,black);
	return resulting_text;
}

TTF_Font* loadfont(string file, int ptsize)
 {
   TTF_Font* tmpfont;
   tmpfont = TTF_OpenFont(file.c_str(), ptsize);
   if (tmpfont == NULL)
   {
     printf("Unable to load font: %s %s \n", file.c_str(), TTF_GetError());
   }
   return tmpfont;
 }
SDL_Surface* loadSurface( std::string path ) {
	SDL_Surface* optimizedSurface = NULL;
		//Load image at specified path
		SDL_Surface* myImage = IMG_Load( path.c_str() );

		if( myImage == NULL ){

			printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
			exit(1);
		}
		else {
			//Convert surface to screen format
			optimizedSurface = SDL_ConvertSurface(myImage, screenSurface->format, 0);
			if(optimizedSurface == NULL) {
				printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
				exit(1);
			}
			//Get rid of old loaded surface
			SDL_FreeSurface( myImage );
		}
		return optimizedSurface;
}

void onHighScore(File &high) {
	SDL_Surface* highS = NULL;
	int maxWin = high.highScore();
	string highScore = static_cast<ostringstream*>(&(ostringstream() << maxWin)) -> str();
	highS = drawtext(gFont, highScore);
	SDL_Rect highRect = {440, 580, 535, 620};
	SDL_BlitSurface(highS, NULL, screenSurface, &highRect);
}
void onScreenCredit(Player &ob)
{

	int creditNum = ob.showCredit();
	SDL_Surface* creditSurface = NULL;
	string creditStr = static_cast<ostringstream*>( &(ostringstream() << creditNum) )->str();
	creditSurface = drawtext(gFont,creditStr);
	SDL_Rect credit_rect = {80, 586, 100, 50};
	SDL_BlitSurface(creditSurface, NULL, screenSurface, &credit_rect);
}
void onScreenWin(Player &ob)
{
	int winNum = ob.getShowWin();

	SDL_Surface* winSurface = NULL;
	string winStr = static_cast<ostringstream*>( &(ostringstream() << winNum) )->str();
	winSurface = drawtext(gFont,winStr);
	SDL_Rect win_rect = {255, 590, 100, 50};
	SDL_BlitSurface(winSurface, NULL, screenSurface, &win_rect);
}
void onScreenBet(vector<Button> &ob)
{
	SDL_Surface* winSurface = NULL;
	int betNum = 0;
	for(size_t i = 0; i < ob.size();i++)
	{
		betNum += ob[i].getBet();
	}
	string betStr = static_cast<ostringstream*>( &(ostringstream() << betNum) )->str();
	winSurface = drawtext(gFont,betStr);
	SDL_Rect bet_rect = {255, 562, 100, 50};
	SDL_BlitSurface(winSurface, NULL, screenSurface, &bet_rect);
}

bool loadMusic() {
	bool success = true;
	music = Mix_LoadMUS( "resources//sound//casino.wav" );
	//Load sound effects
	chips = Mix_LoadWAV( "resources//sound//chip.wav" );
	rollDice = Mix_LoadWAV( "resources//sound//Shake And Roll Dice.wav" );
	win = Mix_LoadWAV( "resources//sound//win.wav" );
	if( chips == NULL || rollDice == NULL || win == NULL ||  music == NULL )
	{
		printf( "Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
	return success;
}

bool loadMedia() {

	bool success = true;
	helpImage = loadSurface("resources//images//help//helpScreen.png");

//sound images
	sound = loadSurface("resources//images//other//sound.png");
	soundOff = loadSurface("resources//images//other//sound off.png");
	playMusic = loadSurface("resources//images//other//unmute.png");
	playMusicOff = loadSurface("resources//images//other//mute.png");
//TTF load
	gFont = loadfont("Chinese Takeaway.ttf", 25);
//background image
	backGround = loadSurface("resources//images//background//background.png");

//play buttons
	newGame = loadSurface("resources//images//other//newgame.png");
	newGameOn = loadSurface("resources//images//other//newgameb.png");
	highScore = loadSurface("resources//images//other//highscore.png");
	clear = loadSurface("resources//images//other//clear.png");
	roll = loadSurface("resources//images//roll//roll.png");
	rollOn = loadSurface("resources//images//roll//rollb.png");
	help = loadSurface("resources//images//help//help.png");
	//six dices images
	rollDiceOne = loadSurface("resources//images//six dices//one.png");
	rollDiceTwo = loadSurface("resources//images//six dices//two.png");
	rollDiceThree = loadSurface("resources//images//six dices//three.png");
	rollDiceFour = loadSurface("resources//images//six dices//four.png");
	rollDiceFive = loadSurface("resources//images//six dices//five.png");
	rollDiceSix = loadSurface("resources//images//six dices//six.png");

//bet info area for any triple
	topInfo = loadSurface("resources//images//betinfo//topInfob.png");
//bet info area for each dice
	eachDiceInfo = loadSurface("resources//images//betinfo//eachdiceb.png");
//credit info image
	creditButton = loadSurface("resources//images//other//credits2.png");
	bet = loadSurface("resources//images//other//betWinArea2.png");

//smallBet image
	small = loadSurface("resources//images//small//smallb.png");
//bigBet image
	big = loadSurface("resources//images//big//bigb.png");

// any double images
	doubleOne = loadSurface("resources//images//double//doubleOneb.png");
	doubleTwo = loadSurface("resources//images//double//doubleTwob.png");
	doubleThree = loadSurface("resources//images//double//doubleThreeb.png");
	doubleFour = loadSurface("resources//images//double//doubleFour2b.png");
	doubleFive = loadSurface("resources//images//double//doubleFiveb.png");
	doubleSix = loadSurface("resources//images//double//doubleSixb.png");

// each triple impages
	tripleOne = loadSurface("resources//images//triple//tripleOneb.png");
	tripleTwo = loadSurface("resources//images//triple//tripleTwob.png");
	tripleThree = loadSurface("resources//images//triple//tripleThreeb.png");
	tripleFour = loadSurface("resources//images//triple//tripleFourb.png");
	tripleFive = loadSurface("resources//images//triple//tripleFiveb.png");
	tripleSix = loadSurface("resources//images//triple//tripleSixb.png");
	anyTriple = loadSurface("resources//images//triple//anyTriple2b.png");

// total sum images
	sumFour = loadSurface("resources//images//sum//fourb.png");
	sumFive = loadSurface("resources//images//sum//fiveb.png");
	sumSix = loadSurface("resources//images//sum//sixb.png");
	sumSeven = loadSurface("resources//images//sum//sevenb.png");
	sumEight = loadSurface("resources//images//sum//eightb.png");
	sumNine = loadSurface("resources//images//sum//nineb.png");
	sumTen = loadSurface("resources//images//sum//tenb.png");
	sumEleven = loadSurface("resources//images//sum//elevenb.png");
	sumTwelve = loadSurface("resources//images//sum//twelveb.png");
	sumThirteen = loadSurface("resources//images//sum//thirteenb.png");
	sumFourteen = loadSurface("resources//images//sum//fourteenb.png");
	sumFifteen = loadSurface("resources//images//sum//fifteenb.png");
	sumSixteen = loadSurface("resources//images//sum//sixteenb.png");
	sumSeventeen = loadSurface("resources//images//sum//seventeenb.png");

// load pair dice images
	pairInfo = loadSurface("resources//images//pair//pairInfo.png");
	pairOneTwo = loadSurface("resources//images//pair//oneToTwob.png");
	pairOneThree = loadSurface("resources//images//pair//oneToThreeb.png");
	pairOneFour = loadSurface("resources//images//pair//oneToFourb.png");
	pairOneFive = loadSurface("resources//images//pair//oneToFiveb.png");
	pairOneSix = loadSurface("resources//images//pair//oneToSixb.png");
	pairTwoThree = loadSurface("resources//images//pair//twoToThreeb.png");
	pairTwoFour = loadSurface("resources//images//pair//twoToFourb.png");
	pairTwoFive = loadSurface("resources//images//pair//twoToFiveb.png");
	pairTwoSix = loadSurface("resources//images//pair//twoToSixb.png");
	pairThreeFour = loadSurface("resources//images//pair//threeToFourb.png");
	pairThreeFive = loadSurface("resources//images//pair//threeToFiveb.png");
	pairThreeSix = loadSurface("resources//images//pair//threeToSixb.png");
	pairFourFive = loadSurface("resources//images//pair//fourToFiveb.png");
	pairFourSix = loadSurface("resources//images//pair//fourToSixb.png");
	pairFiveSix = loadSurface("resources//images//pair//fiveToSixb.png");

//images for straights
	anyStraight = loadSurface("resources//images//straight//anyStraightb.png");
	oneTwoThree = loadSurface("resources//images//straight//oneTwoThreeb.png");
	TwoThreeFour = loadSurface("resources//images//straight//TwoThreeFourb.png");
	ThreeFourFive = loadSurface("resources//images//straight//ThreeFourFiveb.png");
	FourFiveSix = loadSurface("resources//images//straight//FourFiveSixb.png");

//images for one dice
	one = loadSurface("resources//images//dice//oneb.png");
	two = loadSurface("resources//images//dice//twob.png");
	three = loadSurface("resources//images//dice//threeb.png");
	four = loadSurface("resources//images//dice//fourb.png");
	five = loadSurface("resources//images//dice//fiveb.png");
	six = loadSurface("resources//images//dice//sixb.png");

	return success;

} //end of function loadMedia().
void close() {

//table buttons
	SDL_FreeSurface(newGame);
	newGame = NULL;
	SDL_FreeSurface(newGameOn);
	newGameOn = NULL;
	SDL_FreeSurface(highScore);
	highScore = NULL;
	SDL_FreeSurface(creditButton);
	creditButton = NULL;
	SDL_FreeSurface(help);
	help = NULL;
//	SDL_FreeSurface(helpOn);
//	helpOn = NULL;
	SDL_FreeSurface(clear);
	clear = NULL;
	SDL_FreeSurface(roll);
	roll = NULL;
	SDL_FreeSurface(rollOn);
	rollOn = NULL;
	SDL_FreeSurface(bet);
	bet = NULL;
	SDL_FreeSurface(backToGame);
	backToGame = NULL;
//top info
	SDL_FreeSurface(topInfo);
	topInfo = NULL;
//each dice bet info area
	SDL_FreeSurface(eachDiceInfo);
	eachDiceInfo = NULL;

// small image
	SDL_FreeSurface(small);
	small = NULL;
// big image
	SDL_FreeSurface(big);
	big = NULL;

// any double image
	SDL_FreeSurface(doubleOne);
	doubleOne = NULL;
	SDL_FreeSurface(doubleTwo);
	doubleTwo = NULL;
	SDL_FreeSurface(doubleThree);
	doubleThree = NULL;
	SDL_FreeSurface(doubleFour);
	doubleFour = NULL;
	SDL_FreeSurface(doubleFive);
	doubleFive = NULL;
	SDL_FreeSurface(doubleSix);
	doubleSix = NULL;

// each triple image
	SDL_FreeSurface(tripleOne);
	tripleOne = NULL;
	SDL_FreeSurface(tripleTwo);
	tripleTwo = NULL;
	SDL_FreeSurface(tripleThree);
	tripleThree = NULL;
	SDL_FreeSurface(tripleFour);
	tripleFour = NULL;
	SDL_FreeSurface(tripleFive);
	tripleFive = NULL;
	SDL_FreeSurface(tripleSix);
	tripleSix = NULL;
//any triple
	SDL_FreeSurface(anyTriple);
	anyTriple = NULL;

//total sum
	SDL_FreeSurface(sumFour);
	sumFour = NULL;
	SDL_FreeSurface(sumFive);
	sumFive = NULL;
	SDL_FreeSurface(sumSix);
	sumSix = NULL;
	SDL_FreeSurface(sumSeven);
	sumSeven = NULL;
	SDL_FreeSurface(sumEight);
	sumEight = NULL;
	SDL_FreeSurface(sumNine);
	sumNine = NULL;
	SDL_FreeSurface(sumTen);
	sumTen = NULL;
	SDL_FreeSurface(sumEleven);
	sumEleven = NULL;
	SDL_FreeSurface(sumTwelve);
	sumTwelve = NULL;
	SDL_FreeSurface(sumThirteen);
	sumThirteen = NULL;
	SDL_FreeSurface(sumFourteen);
	sumFourteen = NULL;
	SDL_FreeSurface(sumFifteen);
	sumFifteen = NULL;
	SDL_FreeSurface(sumSixteen);
	sumSixteen = NULL;
	SDL_FreeSurface(sumSeventeen);
	sumSeventeen = NULL;

//pair dices
	SDL_FreeSurface(pairOneTwo);
	pairOneTwo = NULL;
	SDL_FreeSurface(pairOneThree);
	pairOneThree = NULL;
	SDL_FreeSurface(pairOneFour);
	pairOneFour = NULL;
	SDL_FreeSurface(pairOneFive);
	pairOneFive = NULL;
	SDL_FreeSurface(pairOneSix);
	pairOneSix = NULL;
	SDL_FreeSurface(pairTwoThree);
	pairTwoThree = NULL;
	SDL_FreeSurface(pairTwoFour);
	pairTwoFour = NULL;
	SDL_FreeSurface(pairTwoFive);
	pairTwoFive = NULL;
	SDL_FreeSurface(pairTwoSix);
	pairTwoSix = NULL;
	SDL_FreeSurface(pairThreeFour);
	pairThreeFour = NULL;
	SDL_FreeSurface(pairThreeFive);
	pairThreeFive = NULL;
	SDL_FreeSurface(pairThreeSix);
	pairThreeSix = NULL;
	SDL_FreeSurface(pairFourFive);
	pairFourFive = NULL;
	SDL_FreeSurface(pairFourSix);
	pairFourSix = NULL;
	SDL_FreeSurface(pairFiveSix);
	pairFiveSix = NULL;

//straights
	SDL_FreeSurface(anyStraight);
	anyStraight = NULL;
	SDL_FreeSurface(oneTwoThree);
	oneTwoThree = NULL;
	SDL_FreeSurface(TwoThreeFour);
	TwoThreeFour = NULL;
	SDL_FreeSurface(ThreeFourFive);
	ThreeFourFive = NULL;
	SDL_FreeSurface(FourFiveSix);
	FourFiveSix = NULL;

//each dice
	SDL_FreeSurface(one);
	one = NULL;
	SDL_FreeSurface(two);
	two = NULL;
	SDL_FreeSurface(three);
	three = NULL;
	SDL_FreeSurface(four);
	four = NULL;
	SDL_FreeSurface(five);
	five = NULL;
	SDL_FreeSurface(six);
	six = NULL;

	//six dices roll
	SDL_FreeSurface(pairInfo);
	pairInfo = NULL;
	SDL_FreeSurface(rollDiceOne);
	rollDiceOne = NULL;
	SDL_FreeSurface(rollDiceTwo);
	rollDiceTwo = NULL;
	SDL_FreeSurface(rollDiceThree);
	rollDiceThree = NULL;
	SDL_FreeSurface(rollDiceFour);
	rollDiceFour = NULL;
	SDL_FreeSurface(rollDiceFive);
	rollDiceFive = NULL;
	SDL_FreeSurface(rollDiceSix);
	rollDiceSix = NULL;
	SDL_FreeSurface(firstDiceRoll);
	firstDiceRoll = NULL;
	SDL_FreeSurface(secondDiceRoll);
	secondDiceRoll = NULL;
	SDL_FreeSurface(thirdDiceRoll);
	thirdDiceRoll = NULL;
	TTF_CloseFont(gFont);
	gFont = NULL;

	SDL_FreeSurface(backGround);
	backGround = NULL;
	SDL_FreeSurface(screenSurface);
	screenSurface = NULL;
//Destroy window
	SDL_DestroyWindow(window);
	window = NULL;


	IMG_Quit();
	TTF_Quit();
	SDL_Quit();

} //end of function close().
void cleanUp() {
	//free the sound
	SDL_FreeSurface(backGround);
	backGround = NULL;

	Mix_FreeChunk( chips );
	chips = NULL;
	Mix_FreeChunk( win );
	win = NULL;
	Mix_FreeChunk( rollDice );
	rollDice = NULL;

	//Free the music
	Mix_FreeMusic( music );
	music = NULL;

	Mix_CloseAudio();

}

void drawTable() {
//Apply background on the window.
	SDL_BlitSurface(backGround, NULL, screenSurface, NULL);

//Apply bet info images on the screen
//creditButton info
	SDL_Rect creditInfo = { 25, 560, 0, 0 };
	SDL_BlitSurface(creditButton, NULL, screenSurface, &creditInfo);
	SDL_Rect betInfo = { 190, 560, 0, 0 };
	SDL_BlitSurface(bet, NULL, screenSurface, &betInfo);

// top info
	SDL_Rect topBetInfo = { 158, 60, 0, 0 };
	SDL_BlitSurface(topInfo, NULL, screenSurface, &topBetInfo);
//each dice
	SDL_Rect eachDiceBottom = { 25, 520, 0, 0 };
	SDL_BlitSurface(eachDiceInfo, NULL, screenSurface, &eachDiceBottom);

//BUTTONS

//table buttons


	Button rollButton(700, 560, 860, 620, roll, screenSurface);
	rollButton.drawToScreen(0);
	mainVec.push_back(rollButton);

// button for small position
	Button smallButton(25, 60, 155, 190, small, screenSurface);
	smallButton.drawToScreen(1);
	mainVec.push_back(smallButton);

//button for big position
	Button bigButton(869, 60, 1003, 190, big, screenSurface);
	bigButton.drawToScreen(15);
	mainVec.push_back(bigButton);

// buttons for any double position
// double one button
	Button doubleOneButton(158, 80, 223, 190, doubleOne, screenSurface);
	doubleOneButton.drawToScreen(2);
	mainVec.push_back(doubleOneButton);
//double two button
	Button doubleTwoButton(225, 80, 290, 190, doubleTwo, screenSurface);
	doubleTwoButton.drawToScreen(3);
	mainVec.push_back(doubleTwoButton);
//double three button
	Button doubleThreeButton(292, 80, 357, 190, doubleThree, screenSurface);
	doubleThreeButton.drawToScreen(4);
	mainVec.push_back(doubleThreeButton);
//double four button
	Button doubleFourButton(667, 80, 732, 190, doubleFour, screenSurface);
	doubleFourButton.drawToScreen(5);
	mainVec.push_back(doubleFourButton);
// double five button
	Button doubleFiveButton(734, 80, 799, 190, doubleFive, screenSurface);
	doubleFiveButton.drawToScreen(6);
	mainVec.push_back(doubleFiveButton);
// double six button
	Button doubleSixButton(801, 80, 866, 190, doubleSix, screenSurface);
	doubleSixButton.drawToScreen(7);
	mainVec.push_back(doubleSixButton);

// buttons for each triple position
// triple one button
	Button tripleOneButton(360, 80, 465, 114, tripleOne, screenSurface);
	tripleOneButton.drawToScreen(8);
	mainVec.push_back(tripleOneButton);
//triple two button
	Button tripleTwoButton(360, 118, 465, 152, tripleTwo, screenSurface);
	tripleTwoButton.drawToScreen(9);
	mainVec.push_back(tripleTwoButton);
//triple three button
	Button tripleThreeButton(360, 156, 465, 190, tripleThree, screenSurface);
	tripleThreeButton.drawToScreen(10);
	mainVec.push_back(tripleThreeButton);
//triple four button
	Button tripleFourButton(559, 80, 664, 114, tripleFour, screenSurface);
	tripleFourButton.drawToScreen(11);
	mainVec.push_back(tripleFourButton);
// triple five button
	Button tripleFiveButton(559, 118, 664, 152, tripleFive, screenSurface);
	tripleFiveButton.drawToScreen(12);
	mainVec.push_back(tripleFiveButton);
// triple six button
	Button tripleSixButton(559, 156, 664, 190, tripleSix, screenSurface);
	tripleSixButton.drawToScreen(13);
	mainVec.push_back(tripleSixButton);
// any triple button
	Button anyTripleButton(468, 80, 556, 190, anyTriple, screenSurface);
	anyTripleButton.drawToScreen(14);
	mainVec.push_back(anyTripleButton);

// total sum buttons
	Button sumFourButton(25, 192, 93, 302, sumFour, screenSurface);
	sumFourButton.drawToScreen(16);
	mainVec.push_back(sumFourButton);
	Button sumFiveButton(95, 192, 163, 303, sumFive, screenSurface);
	sumFiveButton.drawToScreen(17);
	mainVec.push_back(sumFiveButton);
	Button sumSixButton(165, 192, 233, 302, sumSix, screenSurface);
	sumSixButton.drawToScreen(18);
	mainVec.push_back(sumSixButton);
	Button sumSevenButton(235, 192, 303, 302, sumSeven, screenSurface);
	sumSevenButton.drawToScreen(19);
	mainVec.push_back(sumSevenButton);
	Button sumEightButton(305, 192, 373, 302, sumEight, screenSurface);
	sumEightButton.drawToScreen(20);
	mainVec.push_back(sumEightButton);
	Button sumNineButton(375, 192, 443, 302, sumNine, screenSurface);
	sumNineButton.drawToScreen(21);
	mainVec.push_back(sumNineButton);
	Button sumTenButton(445, 192, 513, 302, sumTen, screenSurface);
	sumTenButton.drawToScreen(22);
	mainVec.push_back(sumTenButton);
	Button sumElevenButton(515, 192, 583, 302, sumEleven, screenSurface);
	sumElevenButton.drawToScreen(23);
	mainVec.push_back(sumElevenButton);
	Button sumTwelveButton(585, 192, 653, 302, sumTwelve, screenSurface);
	sumTwelveButton.drawToScreen(24);
	mainVec.push_back(sumTwelveButton);
	Button sumThirteenButton(655, 192, 723, 302, sumThirteen, screenSurface);
	sumThirteenButton.drawToScreen(25);
	mainVec.push_back(sumThirteenButton);
	Button sumFourteenButton(725, 192, 793, 302, sumFourteen, screenSurface);
	sumFourteenButton.drawToScreen(26);
	mainVec.push_back(sumFourteenButton);
	Button sumFifteenButton(795, 192, 863, 302, sumFifteen, screenSurface);
	sumFifteenButton.drawToScreen(27);
	mainVec.push_back(sumFifteenButton);
	Button sumSixteenButton(865, 192, 933, 302, sumSixteen, screenSurface);
	sumSixteenButton.drawToScreen(28);
	mainVec.push_back(sumSixteenButton);
	Button sumSeventeenButton(935, 192, 1003, 302, sumSeventeen, screenSurface);
	sumSeventeenButton.drawToScreen(29);
	mainVec.push_back(sumSeventeenButton);

//pair dice buttons
	Button pairOneToTwoButton(105, 304, 163, 414, pairOneTwo, screenSurface);
	pairOneToTwoButton.drawToScreen(30);
	mainVec.push_back(pairOneToTwoButton);
	Button pairOneToThreeButton(165, 304, 223, 414, pairOneThree, screenSurface);
	pairOneToThreeButton.drawToScreen(31);
	mainVec.push_back(pairOneToThreeButton);
	Button pairOneToFourButton(225, 304, 283, 414, pairOneFour, screenSurface);
	pairOneToFourButton.drawToScreen(32);
	mainVec.push_back(pairOneToFourButton);
	Button pairOneToFiveButton(285, 304, 343, 414, pairOneFive, screenSurface);
	pairOneToFiveButton.drawToScreen(33);
	mainVec.push_back(pairOneToFiveButton);
	Button pairOneToSixButton(345, 304, 403, 414, pairOneSix, screenSurface);
	pairOneToSixButton.drawToScreen(34);
	mainVec.push_back(pairOneToSixButton);
	Button pairTwoToThreeButton(405, 304, 463, 414, pairTwoThree, screenSurface);
	pairTwoToThreeButton.drawToScreen(35);
	mainVec.push_back(pairTwoToThreeButton);
	Button pairTwoToFourButton(465, 304, 523, 414, pairTwoFour, screenSurface);
	pairTwoToFourButton.drawToScreen(36);
	mainVec.push_back(pairTwoToFourButton);
	Button pairTwoToFiveButton(525, 304, 583, 414, pairTwoFive, screenSurface);
	pairTwoToFiveButton.drawToScreen(37);
	mainVec.push_back(pairTwoToFiveButton);
	Button pairTwoToSixButton(585, 304, 643, 414, pairTwoSix, screenSurface);
	pairTwoToSixButton.drawToScreen(38);
	mainVec.push_back(pairTwoToSixButton);
	Button pairThreeToFourButton(645, 304, 703, 414, pairThreeFour, screenSurface);
	pairThreeToFourButton.drawToScreen(39);
	mainVec.push_back(pairThreeToFourButton);
	Button pairThreeToFiveButton(705, 304, 763, 414, pairThreeFive, screenSurface);
	pairThreeToFiveButton.drawToScreen(40);
	mainVec.push_back(pairThreeToFiveButton);
	Button pairThreeToSixButton(765, 304, 823, 414, pairThreeSix, screenSurface);
	pairThreeToSixButton.drawToScreen(41);
	mainVec.push_back(pairThreeToSixButton);
	Button pairFourToFiveButton(825, 304, 883, 414, pairFourFive, screenSurface);
	pairFourToFiveButton.drawToScreen(42);
	mainVec.push_back(pairFourToFiveButton);
	Button pairFourToSixButton(885, 304, 943, 414, pairFourSix, screenSurface);
	pairFourToSixButton.drawToScreen(43);
	mainVec.push_back(pairFourToSixButton);
	Button pairFiveToSixButton(945, 304, 1003, 414, pairFiveSix, screenSurface);
	pairFiveToSixButton.drawToScreen(44);
	mainVec.push_back(pairFiveToSixButton);

//each dice buttons
	Button oneButton(25, 458, 186, 518, one, screenSurface);
	oneButton.drawToScreen(45);
	mainVec.push_back(oneButton);
	Button twoButton(188, 458, 349, 518, two, screenSurface);
	twoButton.drawToScreen(46);
	mainVec.push_back(twoButton);
	Button threeButton(351, 458, 512, 518, three, screenSurface);
	threeButton.drawToScreen(47);
	mainVec.push_back(threeButton);
	Button fourButton(514, 458, 675, 518, four, screenSurface);
	fourButton.drawToScreen(48);
	mainVec.push_back(fourButton);
	Button fiveButton(677, 458, 838, 518, five, screenSurface);
	fiveButton.drawToScreen(49);
	mainVec.push_back(fiveButton);
	Button sixButton(840, 458, 1001, 518, six, screenSurface);
	sixButton.drawToScreen(50);
	mainVec.push_back(sixButton);

//straights buttons
	Button anyStraightButton(25, 416, 219, 456, anyStraight, screenSurface);
	anyStraightButton.drawToScreen(51);
	mainVec.push_back(anyStraightButton);
	Button oneTwoThreeButton(221, 416, 415, 456, oneTwoThree, screenSurface);
	oneTwoThreeButton.drawToScreen(52);
	mainVec.push_back(oneTwoThreeButton);
	Button TwoThreeFourButton(417, 416, 611, 456, TwoThreeFour, screenSurface);
	TwoThreeFourButton.drawToScreen(53);
	mainVec.push_back(TwoThreeFourButton);
	Button ThreeFourFiveButton(613, 416, 807, 456, ThreeFourFive, screenSurface);
	ThreeFourFiveButton.drawToScreen(54);
	mainVec.push_back(ThreeFourFiveButton);
	Button FourFiveSixButton(809, 416, 1003, 456, FourFiveSix, screenSurface);
	FourFiveSixButton.drawToScreen(55);
	mainVec.push_back(FourFiveSixButton);

//tableButtons
	Button newGameButton(25, 20, 155, 50, newGame, screenSurface);
	newGameButton.drawToScreen(56);
	menuButtons.push_back(newGameButton);
	Button highScoreButton(405, 560, 535, 620, highScore, screenSurface);
	highScoreButton.drawToScreen(57);
	menuButtons.push_back(highScoreButton);
	Button helpButton(215, 20, 345, 50, help, screenSurface);
	helpButton.drawToScreen(58);
	menuButtons.push_back(helpButton);
	Button clearButton(600, 560, 670, 590, clear, screenSurface);
	clearButton.drawToScreen(59);
	menuButtons.push_back(clearButton);

	Button backToGameBut(856, 638, 1006, 688, backToGame, screenSurface);
	menuButtons.push_back(backToGameBut);

//sound Botton
	Button soundButton(550, 10, 590, 50, sound, screenSurface);
	soundButton.drawToScreen(60);
	menuButtons.push_back(soundButton);
	Button musicButton(600, 10, 640, 50, playMusic, screenSurface);
	musicButton.drawToScreen(61);
	menuButtons.push_back(musicButton);

	SDL_UpdateWindowSurface(window);

}
void updateTable() {
//Apply background on the window.
	SDL_BlitSurface(backGround, NULL, screenSurface, NULL);

//Apply bet info images on the screen
//credit info
	SDL_Rect creditInfo = { 25, 560, 0, 0 };
	SDL_BlitSurface(creditButton, NULL, screenSurface, &creditInfo);
	SDL_Rect betInfo = { 190, 560, 0, 0 };
	SDL_BlitSurface(bet, NULL, screenSurface, &betInfo);

// top Info
	SDL_Rect topBetInfo = { 158, 60, 0, 0 };
	SDL_BlitSurface(topInfo, NULL, screenSurface, &topBetInfo);
//each dice
	SDL_Rect eachDiceBottom = { 25, 520, 0, 0 };
	SDL_BlitSurface(eachDiceInfo, NULL, screenSurface, &eachDiceBottom);

//pair info image
	SDL_Rect pairsInfo = { 25, 304, 0, 0 };
	SDL_BlitSurface(pairInfo, NULL, screenSurface, &pairsInfo);

	//sound image
		SDL_Rect soundRec = { 550, 10, 0, 0 };
		SDL_BlitSurface(sound, NULL, screenSurface, &soundRec);
		SDL_Rect soundRecOff = { 550, 10, 0, 0 };
		SDL_BlitSurface(soundOff, NULL, screenSurface, &soundRecOff);

		SDL_Rect playMusicOn = { 600, 10, 0, 0 };
		SDL_BlitSurface(playMusic, NULL, screenSurface, &playMusicOn);

		SDL_Rect playMusicOFF = { 600, 10, 0, 0 };
		SDL_BlitSurface(playMusicOff, NULL, screenSurface, &playMusicOFF);

//BUTTONS

//table buttons

//	Button rollButton(700, 560, 860, 620, roll, screenSurface);
	mainVec[0].drawToScreen(0);

// button for small position
	Button smallButton(25, 60, 155, 190, small, screenSurface);
	smallButton.drawToScreen(1);

//button for big position
	Button bigButton(869, 60, 1003, 190, big, screenSurface);
	bigButton.drawToScreen(15);

// buttons for any double position
// double one button
	Button doubleOneButton(158, 80, 223, 190, doubleOne, screenSurface);
	doubleOneButton.drawToScreen(2);
//double two button
	Button doubleTwoButton(225, 80, 290, 190, doubleTwo, screenSurface);
	doubleTwoButton.drawToScreen(3);
//double three button
	Button doubleThreeButton(292, 80, 357, 190, doubleThree, screenSurface);
	doubleThreeButton.drawToScreen(4);
//double four button
	Button doubleFourButton(667, 80, 732, 190, doubleFour, screenSurface);
	doubleFourButton.drawToScreen(5);
// double five button
	Button doubleFiveButton(734, 80, 799, 190, doubleFive, screenSurface);
	doubleFiveButton.drawToScreen(6);
// double six button
	Button doubleSixButton(801, 80, 866, 190, doubleSix, screenSurface);
	doubleSixButton.drawToScreen(7);

// buttons for each triple position
// triple one button
	Button tripleOneButton(360, 80, 465, 114, tripleOne, screenSurface);
	tripleOneButton.drawToScreen(8);
//triple two button
	Button tripleTwoButton(360, 118, 465, 152, tripleTwo, screenSurface);
	tripleTwoButton.drawToScreen(9);
//triple three button
	Button tripleThreeButton(360, 156, 465, 190, tripleThree, screenSurface);
	tripleThreeButton.drawToScreen(10);
//triple four button
	Button tripleFourButton(559, 80, 664, 114, tripleFour, screenSurface);
	tripleFourButton.drawToScreen(11);
// triple five button
	Button tripleFiveButton(559, 118, 664, 152, tripleFive, screenSurface);
	tripleFiveButton.drawToScreen(12);
// triple six button
	Button tripleSixButton(559, 156, 664, 190, tripleSix, screenSurface);
	tripleSixButton.drawToScreen(13);
// any triple button
	Button anyTripleButton(468, 80, 556, 190, anyTriple, screenSurface);
	anyTripleButton.drawToScreen(14);

// total sum buttons
	Button sumFourButton(25, 192, 93, 302, sumFour, screenSurface);
	sumFourButton.drawToScreen(16);
	Button sumFiveButton(95, 192, 163, 303, sumFive, screenSurface);
	sumFiveButton.drawToScreen(17);
	Button sumSixButton(165, 192, 233, 302, sumSix, screenSurface);
	sumSixButton.drawToScreen(18);
	Button sumSevenButton(235, 192, 303, 302, sumSeven, screenSurface);
	sumSevenButton.drawToScreen(19);
	Button sumEightButton(305, 192, 373, 302, sumEight, screenSurface);
	sumEightButton.drawToScreen(20);
	Button sumNineButton(375, 192, 443, 302, sumNine, screenSurface);
	sumNineButton.drawToScreen(21);
	Button sumTenButton(445, 192, 513, 302, sumTen, screenSurface);
	sumTenButton.drawToScreen(22);
	Button sumElevenButton(515, 192, 583, 302, sumEleven, screenSurface);
	sumElevenButton.drawToScreen(23);
	Button sumTwelveButton(585, 192, 653, 302, sumTwelve, screenSurface);
	sumTwelveButton.drawToScreen(24);
	Button sumThirteenButton(655, 192, 723, 302, sumThirteen, screenSurface);
	sumThirteenButton.drawToScreen(25);
	Button sumFourteenButton(725, 192, 793, 302, sumFourteen, screenSurface);
	sumFourteenButton.drawToScreen(26);
	Button sumFifteenButton(795, 192, 863, 302, sumFifteen, screenSurface);
	sumFifteenButton.drawToScreen(27);
	Button sumSixteenButton(865, 192, 933, 302, sumSixteen, screenSurface);
	sumSixteenButton.drawToScreen(28);
	Button sumSeventeenButton(935, 192, 1003, 302, sumSeventeen, screenSurface);
	sumSeventeenButton.drawToScreen(29);

//pair dice buttons
	Button pairOneToTwoButton(105, 304, 163, 414, pairOneTwo, screenSurface);
	pairOneToTwoButton.drawToScreen(30);
	Button pairOneToThreeButton(165, 304, 223, 414, pairOneThree, screenSurface);
	pairOneToThreeButton.drawToScreen(31);
	Button pairOneToFourButton(225, 304, 283, 414, pairOneFour, screenSurface);
	pairOneToFourButton.drawToScreen(32);
	Button pairOneToFiveButton(285, 304, 343, 414, pairOneFive, screenSurface);
	pairOneToFiveButton.drawToScreen(33);
	Button pairOneToSixButton(345, 304, 403, 414, pairOneSix, screenSurface);
	pairOneToSixButton.drawToScreen(34);
	Button pairTwoToThreeButton(405, 304, 463, 414, pairTwoThree, screenSurface);
	pairTwoToThreeButton.drawToScreen(35);
	Button pairTwoToFourButton(465, 304, 523, 414, pairTwoFour, screenSurface);
	pairTwoToFourButton.drawToScreen(36);
	Button pairTwoToFiveButton(525, 304, 583, 414, pairTwoFive, screenSurface);
	pairTwoToFiveButton.drawToScreen(37);
	Button pairTwoToSixButton(585, 304, 643, 414, pairTwoSix, screenSurface);
	pairTwoToSixButton.drawToScreen(38);
	Button pairThreeToFourButton(645, 304, 703, 414, pairThreeFour, screenSurface);
	pairThreeToFourButton.drawToScreen(39);
	Button pairThreeToFiveButton(705, 304, 763, 414, pairThreeFive, screenSurface);
	pairThreeToFiveButton.drawToScreen(40);
	Button pairThreeToSixButton(765, 304, 823, 414, pairThreeSix, screenSurface);
	pairThreeToSixButton.drawToScreen(41);
	Button pairFourToFiveButton(825, 304, 883, 414, pairFourFive, screenSurface);
	pairFourToFiveButton.drawToScreen(42);
	Button pairFourToSixButton(885, 304, 943, 414, pairFourSix, screenSurface);
	pairFourToSixButton.drawToScreen(43);
	Button pairFiveToSixButton(945, 304, 1003, 414, pairFiveSix, screenSurface);
	pairFiveToSixButton.drawToScreen(44);

//each dice buttons
	Button oneButton(25, 458, 186, 518, one, screenSurface);
	oneButton.drawToScreen(45);
	Button twoButton(188, 458, 349, 518, two, screenSurface);
	twoButton.drawToScreen(46);
	Button threeButton(351, 458, 512, 518, three, screenSurface);
	threeButton.drawToScreen(47);
	Button fourButton(514, 458, 675, 518, four, screenSurface);
	fourButton.drawToScreen(48);
	Button fiveButton(677, 458, 838, 518, five, screenSurface);
	fiveButton.drawToScreen(49);
	Button sixButton(840, 458, 1001, 518, six, screenSurface);
	sixButton.drawToScreen(50);

//straights buttons
	Button anyStraightButton(25, 416, 219, 456, anyStraight, screenSurface);
	anyStraightButton.drawToScreen(51);
	Button oneTwoThreeButton(221, 416, 415, 456, oneTwoThree, screenSurface);
	oneTwoThreeButton.drawToScreen(52);
	Button TwoThreeFourButton(417, 416, 611, 456, TwoThreeFour, screenSurface);
	TwoThreeFourButton.drawToScreen(53);
	Button ThreeFourFiveButton(613, 416, 807, 456, ThreeFourFive, screenSurface);
	ThreeFourFiveButton.drawToScreen(54);

	Button FourFiveSixButton(809, 416, 1003, 456, FourFiveSix, screenSurface);
	FourFiveSixButton.drawToScreen(55);

//tableButtons
	Button newGameButton(25, 20, 155, 50, newGame, screenSurface);
	newGameButton.drawToScreen(56);
	Button highScoreButton(405, 560, 535, 620, highScore, screenSurface);
	highScoreButton.drawToScreen(57);
	Button helpButton(215, 20, 345, 50, help, screenSurface);
	helpButton.drawToScreen(58);
	Button clearButton(600, 560, 670, 590, clear, screenSurface);
	clearButton.drawToScreen(59);

//sound Buttons
	if(playSound)
	{
		Button soundButton(550, 10, 590, 50, sound, screenSurface);
		soundButton.drawToScreen(60);
	}
	if(playMus)
	{
		Button musicButton(600, 10, 640, 50, playMusic, screenSurface);
		musicButton.drawToScreen(61);
	}

	onHighScore(inFile);
	onScreenCredit(player);
	onScreenBet(mainVec);
	onScreenWin(player);
	dicesVisual();
	SDL_UpdateWindowSurface(window);
}
void clearBetAndWin()
{
	for (size_t i = 1; i < mainVec.size(); i++) {
		mainVec[i].nullBetAndWin();
		player.nullBet();
		player.nullWin();
	}
}
void dicesVisual() {
	//3 dices visual
	SDL_Surface* dices[6];

	SDL_Rect firstDice = { 760, 0, 0, 0 };
	SDL_Rect secondDice = { 820, 0, 0, 0 };
	SDL_Rect thirdDice = { 880, 0, 0, 0 };

	dices[0] = rollDiceOne;
	dices[1] = rollDiceTwo;
	dices[2] = rollDiceThree;
	dices[3] = rollDiceFour;
	dices[4] = rollDiceFive;
	dices[5] = rollDiceSix;
	firstDiceRoll = dices[rolldice.getFirstDice() - 1];
	secondDiceRoll = dices[rolldice.getSecondDice() - 1];
	thirdDiceRoll = dices[rolldice.getThirdDice() - 1];
	SDL_BlitSurface(firstDiceRoll, NULL, screenSurface, &firstDice);
	SDL_BlitSurface(secondDiceRoll, NULL, screenSurface, &secondDice);
	SDL_BlitSurface(thirdDiceRoll, NULL, screenSurface, &thirdDice);
}
int checkHighScore() {
	if (player.getWin() > currentMaxWin) {
		currentMaxWin = player.getWin();
	}
	return currentMaxWin;
}

void doEvents() {
	SDL_Event ev;
	while (SDL_PollEvent(&ev) != 0)
		{

			if (ev.type == SDL_QUIT)
			{
				quit = true;
			}
			if (ev.type == SDL_MOUSEBUTTONDOWN)
			{

				if (ev.button.button == SDL_BUTTON_LEFT)
				{
					for (size_t i = 1; i < mainVec.size(); i++)
					{
						mainVec[i].clearButtons();
					}


					if (mainVec[0].checkEvents(&ev))
					{
						Mix_PlayChannel( -1, rollDice, 0 );
						rolldice.rollAllDices();
						int a = rolldice.getFirstDice();
						int b = rolldice.getSecondDice();
						int c = rolldice.getThirdDice();

						for (size_t i = 1; i < mainVec.size(); i++)
						{
							mainVec[i].checkAllButton(a, b, c);
							player.setBet(mainVec[i].getBet());
							player.setWin(mainVec[i].getWin());
							check = checkHighScore();
						}
						for (size_t i = 1; i < mainVec.size(); i++)
						{
							mainVec[i].nullBetAndWin();
						}
						player.setShowWin(player.getWin());
						if (player.getWin() > 0)
						{
							Mix_PlayChannel( -1, win, 0 );

						}
						player.getCredit();
						rollButtonOn();
						clearBetAndWin();
					}
					else {
						for (size_t i = 1; i < 56; i++)
						{
							if (mainVec[i].checkEvents(&ev))
							{
								Mix_PlayChannel( -1, chips, 0 );
								mainVec[i].setBet(10);
							}
						}
					}
					if (menuButtons[0].checkEvents(&ev))
					{
						player.setCredit(1000);
						newGameButtonOn();
					}
					if (menuButtons[3].checkEvents(&ev))
					{
						player.nullBet();
						for (size_t i = 1; i < mainVec.size(); i++)
						{
							mainVec[i].nullBetAndWin();
						}
					}
					if(menuButtons[2].checkEvents(&ev)){
						helpQuit = false;
					}
					if(menuButtons[4].checkEvents(&ev)) {
						helpQuit = true;
					}
					if (menuButtons[5].checkEvents(&ev))
					{
						if (playSound){
							playSound = false;
						}
						else{
							playSound = true;
						}
					}
					if (menuButtons[6].checkEvents(&ev))
					{
						if( Mix_PlayingMusic() == 0 )
						{
							playMus = true;
							Mix_PlayMusic( music, -1 );
						}
						else
						{
							playMus = false;
							Mix_HaltMusic();
						}
					}
				}
			}
		inFile.recordHighScore(check);
		inFile.recordCredit(player.getCredit());
		}//exit from event
}

void helpWindow() {
	SDL_BlitSurface(helpImage, NULL, screenSurface, NULL);
	SDL_UpdateWindowSurface(window);
}

void rollButtonOn() {

	SDL_Rect rollButtOn = {700, 560, 860, 620 };
	SDL_BlitSurface(rollOn, NULL, screenSurface, &rollButtOn);
	SDL_UpdateWindowSurface(window);
}

void newGameButtonOn() {

	SDL_Rect newGameButtOn =  {25, 20, 155, 50};
	SDL_BlitSurface(newGameOn, NULL, screenSurface, &newGameButtOn);
	SDL_UpdateWindowSurface(window);
}

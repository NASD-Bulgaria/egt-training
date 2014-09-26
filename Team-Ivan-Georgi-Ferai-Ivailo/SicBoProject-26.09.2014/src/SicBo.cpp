//============================================================================
// Name        : SicBo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
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

// bet info images.
//any double
SDL_Surface *eachDoubleBetLeftInfo = NULL;
SDL_Surface *eachDoubleBetRightInfo = NULL;
//each triple
SDL_Surface *eachTripleBetLeftInfo = NULL;
SDL_Surface *eachTripleBetRightInfo = NULL;
//any triple
SDL_Surface *anyTripleBetInfo = NULL;
//each dice info
SDL_Surface *eachDiceInfo = NULL;

//credit and bet info
SDL_Surface* credit = NULL;
SDL_Surface* bet = NULL;

//dice info
//6 dices images
SDL_Surface *rollDiceOne = NULL;
SDL_Surface *rollDiceTwo = NULL;
SDL_Surface *rollDiceThree = NULL;
SDL_Surface *rollDiceFour = NULL;
SDL_Surface *rollDiceFive = NULL;
SDL_Surface *rollDiceSix = NULL;
SDL_Surface *firstDiceRoll = NULL;
SDL_Surface *secondDiceRoll = NULL;
SDL_Surface *thirdDiceRoll = NULL;

// Buttons
//play buttons
SDL_Surface* newGame = NULL;
SDL_Surface* highScore = NULL;
SDL_Surface* help = NULL;
SDL_Surface* clear = NULL;
SDL_Surface* roll = NULL;

// Buttons for small and big.
SDL_Surface* small = NULL;
SDL_Surface* big = NULL;

// Buttons for any double
SDL_Surface* doubleOne = NULL;
SDL_Surface* doubleTwo = NULL;
SDL_Surface* doubleThree = NULL;
SDL_Surface* doubleFour = NULL;
SDL_Surface* doubleFive = NULL;
SDL_Surface* doubleSix = NULL;

// Buttons for each triple
SDL_Surface* tripleOne = NULL;
SDL_Surface* tripleTwo = NULL;
SDL_Surface* tripleThree = NULL;
SDL_Surface* tripleFour = NULL;
SDL_Surface* tripleFive = NULL;
SDL_Surface* tripleSix = NULL;

// for any triple
SDL_Surface* anyTriple = NULL;

//Buttons for dice sum
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

//Buttons for dice pair
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

//Buttons for straight
SDL_Surface* anyStraight = NULL;
SDL_Surface* oneTwoThree = NULL;
SDL_Surface* TwoThreeFour = NULL;
SDL_Surface* ThreeFourFive = NULL;
SDL_Surface* FourFiveSix = NULL;

//Buttons for each dice
SDL_Surface* one = NULL;
SDL_Surface* two = NULL;
SDL_Surface* three = NULL;
SDL_Surface* four = NULL;
SDL_Surface* five = NULL;
SDL_Surface* six = NULL;

bool init();
bool initHelp();
bool checkMedia(SDL_Surface*);
bool loadMedia();
void close();
void closeHelp();
void drawTable();
void updateTable();
void clearBetAndWin();
void dicesVisual();
int checkHighScore();
void helpWindows();
SDL_Surface* loadSurface( std::string path );

File inFile;
Player player(1000, 0, 0);
RollDice rolldice;
//const int buttonSize = 56;
vector<Button> mainVec;
vector<Button> menuButtons;

int currentMaxWin = 0;

int main(int argc, char* args[]) {
	int check = 0;

	const int FPS = 30;
	Uint32 start;
	bool quit = false;
	srand(time(NULL));
	SDL_Event ev;

		if ((!init()) || (!loadMedia())) {
			printf("Failed to initialize!\n");
		}
		else {
			drawTable();
			int recovery = inFile.recovery();
			player.setCredit(recovery);
			while (!quit) {
				updateTable();
				start = SDL_GetTicks();
				while (SDL_PollEvent(&ev) != 0) {
					if (ev.type == SDL_QUIT) {
						quit = true;
					}
					if (ev.type == SDL_MOUSEBUTTONDOWN) {
						if (ev.button.button == SDL_BUTTON_LEFT) {
							for (size_t i = 1; i < mainVec.size(); i++) {
								mainVec[i].clearButtons();
							}

							if (mainVec[0].checkEvents(&ev)) {
								rolldice.rollAllDices();
								int a = rolldice.getFirstDice();
								int b = rolldice.getSecondDice();
								int c = rolldice.getThirdDice();
								cout << a << " " << b << " " << c << endl;

								for (size_t i = 1; i < mainVec.size(); i++) {
									mainVec[i].checkAllButton(a, b, c);
									player.setBet(mainVec[i].getBet());
									player.setWin(mainVec[i].getWin());
									check = checkHighScore();
								}
								cout << "High win: " << check << endl;
								cout << player.getCredit() << endl;
								clearBetAndWin();
							}
							else {
								for (size_t i = 1; i < 56; i++) {
									if (mainVec[i].checkEvents(&ev)) {
										mainVec[i].setBet(5);
									cout << "getBet " << mainVec[i].getBet()<< endl;
									}
								}
							}
							if (menuButtons[0].checkEvents(&ev)) {
								player.setCredit(1000);
							}
							if (menuButtons[3].checkEvents(&ev)) {
							player.nullBetAndWin();
								for (size_t i = 1; i < mainVec.size(); i++) {
									mainVec[i].nullBetAndWin();
								}
							}
						}
					}
				inFile.recordHighScore(check);
				inFile.recordCredit(player.getCredit());
				}//exit from event
			if (1000 / FPS > SDL_GetTicks() - start) {
				SDL_Delay(1000 / FPS - (SDL_GetTicks() - start));
			}
		} //end While(!quit)
		cout << "You click the quit button !";
	}
	return 0;
}

bool init() {
//Initialization flag
	bool success = true;

//Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	} else {
		//Create window
		window = SDL_CreateWindow("Sic Bo 0.01a", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n",
					SDL_GetError());
			success = false;
		} else {
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);
		}
	}

	return success;
}

SDL_Surface* loadSurface( std::string path ) {
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );

	if( loadedSurface == NULL ){

		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );

	}
	else {
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, 0);
		if(optimizedSurface == NULL) {
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;

}

bool loadMedia() {

	bool success = true;

//background image
	backGround = loadSurface("resources//images//background//background.bmp");

//play buttons
	newGame = loadSurface("resources//images//other//newgame.bmp");
	highScore = loadSurface("resources//images//other//highscore.bmp");
	help = loadSurface("resources//images//other//help.bmp");
	clear = loadSurface("resources//images//other//clear.bmp");
	roll = loadSurface("resources//images//other//roll.bmp");

	//six dices images
	rollDiceOne = loadSurface("resources//images//six dices//one.bmp");
	rollDiceTwo = loadSurface("resources//images//six dices//two.bmp");
	rollDiceThree = loadSurface("resources//images//six dices//three.bmp");
	rollDiceFour = loadSurface("resources//images//six dices//four.bmp");
	rollDiceFive = loadSurface("resources//images//six dices//five.bmp");
	rollDiceSix = loadSurface("resources//images//six dices//six.bmp");

// bet info images
// bet info area for each double left and right
	eachDoubleBetLeftInfo = loadSurface(
			"resources//images//betinfo//eachDouble3.bmp");
	eachDoubleBetRightInfo = loadSurface(
			"resources//images//betinfo//eachDouble3.bmp");
//bet info area for each triple left and right
	eachTripleBetLeftInfo = loadSurface(
			"resources//images//betinfo//eachTriple.bmp");
	eachTripleBetRightInfo = loadSurface(
			"resources//images//betinfo//eachTriple.bmp");
//bet info area for any triple
	anyTripleBetInfo = loadSurface("resources//images//betinfo//anyTriple.bmp");
//bet info area for each dice
	eachDiceInfo = loadSurface("resources//images//betinfo//eachdice.bmp");
//credit info image
	credit = loadSurface("resources//images//other//credit.bmp");
	bet = loadSurface("resources//images//other//betWinArea.bmp");

//smallBet image
	small = loadSurface("resources//images//small//small.bmp");
//bigBet image
	big = loadSurface("resources//images//big//big.bmp");

// any double images
	doubleOne = loadSurface("resources//images//double//doubleOne.bmp");
	doubleTwo = loadSurface("resources//images//double//doubleTwo.bmp");
	doubleThree = loadSurface("resources//images//double//doubleThree.bmp");
	doubleFour = loadSurface("resources//images//double//doubleFour.bmp");
	doubleFive = SDL_LoadBMP("resources//images//double//doubleFive.bmp");
	doubleSix = loadSurface("resources//images//double//doubleSix.bmp");

// each triple impages
	tripleOne = loadSurface("resources//images//triple//tripleOne.bmp");
	tripleTwo = loadSurface("resources//images//triple//tripleTwo.bmp");
	tripleThree = loadSurface("resources//images//triple//tripleThree.bmp");
	tripleFour = loadSurface("resources//images//triple//tripleFour.bmp");
	tripleFive = loadSurface("resources//images//triple//tripleFive.bmp");
	tripleSix = loadSurface("resources//images//triple//tripleSix.bmp");
	anyTriple = loadSurface("resources//images//triple//anyTriple2.bmp");

// total sum images
	sumFour = loadSurface("resources//images//sum//four.bmp");
	sumFive = loadSurface("resources//images//sum//five.bmp");
	sumSix = loadSurface("resources//images//sum//six.bmp");
	sumSeven = loadSurface("resources//images//sum//seven.bmp");
	sumEight = loadSurface("resources//images//sum//eight.bmp");
	sumNine = loadSurface("resources//images//sum//nine.bmp");
	sumTen = loadSurface("resources//images//sum//ten.bmp");
	sumEleven = loadSurface("resources//images//sum//eleven.bmp");
	sumTwelve = loadSurface("resources//images//sum//twelve.bmp");
	sumThirteen = loadSurface("resources//images//sum//thirteen.bmp");
	sumFourteen = loadSurface("resources//images//sum//fourteen.bmp");
	sumFifteen = loadSurface("resources//images//sum//fifteen.bmp");
	sumSixteen = loadSurface("resources//images//sum//sixteen.bmp");
	sumSeventeen = loadSurface("resources//images//sum//seventeen.bmp");

// load pair dice images
	pairInfo = loadSurface("resources//images//pair//pairInfo.bmp");
	pairOneTwo = loadSurface("resources//images//pair//oneToTwo.bmp");
	pairOneThree = loadSurface("resources//images//pair//oneToThree.bmp");
	pairOneFour = loadSurface("resources//images//pair//oneToFour.bmp");
	pairOneFive = loadSurface("resources//images//pair//oneToFive.bmp");
	pairOneSix = loadSurface("resources//images//pair//oneToSix.bmp");
	pairTwoThree = loadSurface("resources//images//pair//twoToThree.bmp");
	pairTwoFour = loadSurface("resources//images//pair//twoToFour.bmp");
	pairTwoFive = loadSurface("resources//images//pair//twoToFive.bmp");
	pairTwoSix = loadSurface("resources//images//pair//twoToSix.bmp");
	pairThreeFour = loadSurface("resources//images//pair//threeToFour.bmp");
	pairThreeFive = loadSurface("resources//images//pair//threeToFive.bmp");
	pairThreeSix = loadSurface("resources//images//pair//threeToSix.bmp");
	pairFourFive = loadSurface("resources//images//pair//fourToFive.bmp");
	pairFourSix = loadSurface("resources//images//pair//fourToSix.bmp");
	pairFiveSix = loadSurface("resources//images//pair//fiveToSix.bmp");

//images for straights
	anyStraight = loadSurface("resources//images//straight//anyStraight.bmp");
	oneTwoThree = loadSurface("resources//images//straight//oneTwoThree.bmp");
	TwoThreeFour = loadSurface("resources//images//straight//TwoThreeFour.bmp");
	ThreeFourFive = loadSurface(
			"resources//images//straight//ThreeFourFive.bmp");
	FourFiveSix = loadSurface("resources//images//straight//FourFiveSix.bmp");

//images for one dice
	one = loadSurface("resources//images//dice//one.bmp");
	two = loadSurface("resources//images//dice//two.bmp");
	three = loadSurface("resources//images//dice//three.bmp");
	four = loadSurface("resources//images//dice//four.bmp");
	five = loadSurface("resources//images//dice//five.bmp");
	six = loadSurface("resources//images//dice//six.bmp");

	return success;

} //end of function loadMedia().

void close() {
//Deallocate surface
//background image
	SDL_FreeSurface(backGround);
	backGround = NULL;

//table buttons
	SDL_FreeSurface(newGame);
	newGame = NULL;
	SDL_FreeSurface(highScore);
	highScore = NULL;
	SDL_FreeSurface(credit);
	credit = NULL;
	SDL_FreeSurface(help);
	help = NULL;
	SDL_FreeSurface(clear);
	clear = NULL;
	SDL_FreeSurface(roll);
	roll = NULL;
	SDL_FreeSurface(bet);
	bet = NULL;

// bet info images
// each double info images
	SDL_FreeSurface(eachDoubleBetLeftInfo);
	eachDoubleBetLeftInfo = NULL;
	SDL_FreeSurface(eachDoubleBetRightInfo);
	eachDoubleBetRightInfo = NULL;
//each triple info images
	SDL_FreeSurface(eachTripleBetLeftInfo);
	eachTripleBetLeftInfo = NULL;
	SDL_FreeSurface(eachTripleBetRightInfo);
	eachTripleBetRightInfo = NULL;
//any triple bet info area
	SDL_FreeSurface(anyTripleBetInfo);
	anyTripleBetInfo = NULL;
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
	SDL_FreeSurface(sumFour);
	sumFour = NULL;

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

//Destroy window
	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();

} //end of function close().

void drawTable() {
//Apply background on the window.
	SDL_BlitSurface(backGround, NULL, screenSurface, NULL);

//Apply bet info images on the screen
//credit info
	SDL_Rect creditInfo = { 50, 560, 0, 0 };
	SDL_BlitSurface(credit, NULL, screenSurface, &creditInfo);
	SDL_Rect betInfo = { 215, 560, 0, 0 };
	SDL_BlitSurface(bet, NULL, screenSurface, &betInfo);

//each double
	SDL_Rect eachDoubleLeft = { 158, 60, 0, 0 };
	SDL_BlitSurface(eachDoubleBetLeftInfo, NULL, screenSurface,
			&eachDoubleLeft);
	SDL_Rect eachDoubleRight = { 667, 60, 0, 0 };
	SDL_BlitSurface(eachDoubleBetRightInfo, NULL, screenSurface,
			&eachDoubleRight);
// each triple
	SDL_Rect eachTripleLeft = { 360, 60, 0, 0 };
	SDL_BlitSurface(eachTripleBetLeftInfo, NULL, screenSurface,
			&eachTripleLeft);
	SDL_Rect eachTripleRight = { 559, 60, 0, 0 };
	SDL_BlitSurface(eachTripleBetRightInfo, NULL, screenSurface,
			&eachTripleRight);
//any triple
	SDL_Rect anyTripleCenter = { 468, 60, 0, 0 };
	SDL_BlitSurface(anyTripleBetInfo, NULL, screenSurface, &anyTripleCenter);
//each dice
	SDL_Rect eachDiceBottom = { 25, 520, 0, 0 };
	SDL_BlitSurface(eachDiceInfo, NULL, screenSurface, &eachDiceBottom);

//BUTTONS

//table buttons

	Button rollButton(700, 560, 770, 590, roll, screenSurface);
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
	Button pairOneToThreeButton(165, 304, 223, 414, pairOneThree,
			screenSurface);
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
	Button pairTwoToThreeButton(405, 304, 463, 414, pairTwoThree,
			screenSurface);
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
	Button pairThreeToFourButton(645, 304, 703, 414, pairThreeFour,
			screenSurface);
	pairThreeToFourButton.drawToScreen(39);
	mainVec.push_back(pairThreeToFourButton);
	Button pairThreeToFiveButton(705, 304, 763, 414, pairThreeFive,
			screenSurface);
	pairThreeToFiveButton.drawToScreen(40);
	mainVec.push_back(pairThreeToFiveButton);
	Button pairThreeToSixButton(765, 304, 823, 414, pairThreeSix,
			screenSurface);
	pairThreeToSixButton.drawToScreen(41);
	mainVec.push_back(pairThreeToSixButton);
	Button pairFourToFiveButton(825, 304, 883, 414, pairFourFive,
			screenSurface);
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
	Button ThreeFourFiveButton(613, 416, 807, 456, ThreeFourFive,
			screenSurface);
	ThreeFourFiveButton.drawToScreen(54);
	mainVec.push_back(ThreeFourFiveButton);
	Button FourFiveSixButton(809, 416, 1003, 456, FourFiveSix, screenSurface);
	FourFiveSixButton.drawToScreen(55);
	mainVec.push_back(FourFiveSixButton);

//tableButtons
	Button newGameButton(25, 20, 155, 50, newGame, screenSurface);
	newGameButton.drawToScreen(56);
	menuButtons.push_back(newGameButton);
	Button highScoreButton(215, 20, 345, 50, highScore, screenSurface);
	highScoreButton.drawToScreen(57);
	menuButtons.push_back(highScoreButton);
	Button helpButton(405, 20, 535, 50, help, screenSurface);
	helpButton.drawToScreen(58);
	menuButtons.push_back(helpButton);
	Button clearButton(600, 560, 670, 590, clear, screenSurface);
	clearButton.drawToScreen(59);
	menuButtons.push_back(clearButton);
	SDL_UpdateWindowSurface(window);

}

void updateTable() {
//Apply background on the window.
	SDL_BlitSurface(backGround, NULL, screenSurface, NULL);

//Apply bet info images on the screen
//credit info
	SDL_Rect creditInfo = { 50, 560, 0, 0 };
	SDL_BlitSurface(credit, NULL, screenSurface, &creditInfo);
	SDL_Rect betInfo = { 215, 560, 0, 0 };
	SDL_BlitSurface(bet, NULL, screenSurface, &betInfo);

//each double
	SDL_Rect eachDoubleLeft = { 158, 60, 0, 0 };
	SDL_BlitSurface(eachDoubleBetLeftInfo, NULL, screenSurface,
			&eachDoubleLeft);
	SDL_Rect eachDoubleRight = { 667, 60, 0, 0 };
	SDL_BlitSurface(eachDoubleBetRightInfo, NULL, screenSurface,
			&eachDoubleRight);
// each triple
	SDL_Rect eachTripleLeft = { 360, 60, 0, 0 };
	SDL_BlitSurface(eachTripleBetLeftInfo, NULL, screenSurface,
			&eachTripleLeft);
	SDL_Rect eachTripleRight = { 559, 60, 0, 0 };
	SDL_BlitSurface(eachTripleBetRightInfo, NULL, screenSurface,
			&eachTripleRight);
//any triple
	SDL_Rect anyTripleCenter = { 468, 60, 0, 0 };
	SDL_BlitSurface(anyTripleBetInfo, NULL, screenSurface, &anyTripleCenter);
//each dice
	SDL_Rect eachDiceBottom = { 25, 520, 0, 0 };
	SDL_BlitSurface(eachDiceInfo, NULL, screenSurface, &eachDiceBottom);

//pair info image
	SDL_Rect pairsInfo = { 25, 304, 0, 0 };
	SDL_BlitSurface(pairInfo, NULL, screenSurface, &pairsInfo);

//BUTTONS

//table buttons

	Button rollButton(700, 560, 770, 590, roll, screenSurface);
	rollButton.drawToScreen(0);

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
	Button pairOneToThreeButton(165, 304, 223, 414, pairOneThree,
			screenSurface);
	pairOneToThreeButton.drawToScreen(31);
	Button pairOneToFourButton(225, 304, 283, 414, pairOneFour, screenSurface);
	pairOneToFourButton.drawToScreen(32);
	Button pairOneToFiveButton(285, 304, 343, 414, pairOneFive, screenSurface);
	pairOneToFiveButton.drawToScreen(33);
	Button pairOneToSixButton(345, 304, 403, 414, pairOneSix, screenSurface);
	pairOneToSixButton.drawToScreen(34);
	Button pairTwoToThreeButton(405, 304, 463, 414, pairTwoThree,
			screenSurface);
	pairTwoToThreeButton.drawToScreen(35);
	Button pairTwoToFourButton(465, 304, 523, 414, pairTwoFour, screenSurface);
	pairTwoToFourButton.drawToScreen(36);
	Button pairTwoToFiveButton(525, 304, 583, 414, pairTwoFive, screenSurface);
	pairTwoToFiveButton.drawToScreen(37);
	Button pairTwoToSixButton(585, 304, 643, 414, pairTwoSix, screenSurface);
	pairTwoToSixButton.drawToScreen(38);
	Button pairThreeToFourButton(645, 304, 703, 414, pairThreeFour,
			screenSurface);
	pairThreeToFourButton.drawToScreen(39);
	Button pairThreeToFiveButton(705, 304, 763, 414, pairThreeFive,
			screenSurface);
	pairThreeToFiveButton.drawToScreen(40);
	Button pairThreeToSixButton(765, 304, 823, 414, pairThreeSix,
			screenSurface);
	pairThreeToSixButton.drawToScreen(41);
	Button pairFourToFiveButton(825, 304, 883, 414, pairFourFive,
			screenSurface);
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

	Button ThreeFourFiveButton(613, 416, 807, 456, ThreeFourFive,
			screenSurface);
	ThreeFourFiveButton.drawToScreen(54);

	Button FourFiveSixButton(809, 416, 1003, 456, FourFiveSix, screenSurface);
	FourFiveSixButton.drawToScreen(55);

//tableButtons
	Button newGameButton(25, 20, 155, 50, newGame, screenSurface);
	newGameButton.drawToScreen(56);
	menuButtons.push_back(newGameButton);
	Button highScoreButton(215, 20, 345, 50, highScore, screenSurface);
	highScoreButton.drawToScreen(57);
	menuButtons.push_back(highScoreButton);
	Button helpButton(405, 20, 535, 50, help, screenSurface);
	helpButton.drawToScreen(58);
	menuButtons.push_back(helpButton);
	Button clearButton(600, 560, 670, 590, clear, screenSurface);
	clearButton.drawToScreen(59);
	menuButtons.push_back(clearButton);
	dicesVisual();

}
void clearBetAndWin() {
	for (size_t i = 1; i < mainVec.size(); i++) {
		mainVec[i].nullBetAndWin();
		player.nullBetAndWin();
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
	SDL_UpdateWindowSurface(window);
}

int checkHighScore() {
	if (player.getWin() > currentMaxWin) {
		currentMaxWin = player.getWin();
	}
	return currentMaxWin;
}



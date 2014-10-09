/*
 * Draw.cpp
 *
 *  Created on: 1.10.2014 �.
 *      Author: msi
 */

#include "Draw.h"

Draw::Draw()
{
	window = NULL;
	image = NULL;
	surface = NULL;
	bet = 0;
	win = 0;
	totalPlayerBet = 0;
	ID = 0;
}
Draw::~Draw(){}


//DRAW FUNCTION
bool Draw::loadMediaImages()
{
	//This function is for loading all images for Sic Bo game.
	bool success = true;

	//CHIPCS
	blueChip = loadSurface("resources//images//Chip//blueChip2.png");
	redChip = loadSurface("resources//images//Chip//RedChip2.png");
	yellowChip = loadSurface("resources//images//Chip//YellowChip2.png");

	//background image
	backGround = loadSurface("resources//images//background//background.png");
	//play buttons
	newGame = loadSurface("resources//images//other//newgame2.png");
	newGameOn = loadSurface("resources//images//other//newgame2b.png");
	help = loadSurface("resources//images//help//help2.png");
	next = loadSurface("resources//images//other//next.png");
	prev = loadSurface("resources//images//other//prev.png");
	highScore = loadSurface("resources//images//other//highscore2.png");
	clear = loadSurface("resources//images//other//clear2.png");
	clearOn = loadSurface("resources//images//other//clear2b.png");
	roll = loadSurface("resources//images//roll//roll2.png");
	rollOn = loadSurface("resources//images//roll//roll2b.png");
	backToGame = loadSurface("resources//images//help//backToGame.png");
	statsButton = loadSurface("resources//images//help/statistic.png");
		//six dices images
	rollDiceOne = loadSurface("resources//images//six dices//one.png");
	rollDiceTwo = loadSurface("resources//images//six dices//two.png");
	rollDiceThree = loadSurface("resources//images//six dices//three.png");
	rollDiceFour = loadSurface("resources//images//six dices//four.png");
	rollDiceFive = loadSurface("resources//images//six dices//five.png");
	rollDiceSix = loadSurface("resources//images//six dices//six.png");

//	//betButton info area for any triple
	    topInfo = loadSurface("resources//images//betinfo//topInfob.png");
//	//bet info area for each dice
		eachDiceInfo = loadSurface("resources//images//betinfo//eachdice.png");
//	//credit info image
		creditButton = loadSurface("resources//images//other//credits.png");
		betButton = loadSurface("resources//images//other//betAndWin.png");
		pairInfo = loadSurface("resources//images//pair//pairInfo.png");
	// smallBet image
		small = loadSurface("resources//images//small//small.png");
	//bigBet image
		big = loadSurface("resources//images//big//big.png");
		chipInfo = loadSurface("resources//images//other//chipInfo.png");
	//
	// any double images
		doubleOne = loadSurface("resources//images//double//doubleOne.png");
		doubleTwo = loadSurface("resources//images//double//doubleTwo.png");
		doubleThree = loadSurface("resources//images//double//doubleThree.png");
		doubleFour = loadSurface("resources//images//double//doubleFour.png");
		doubleFive = loadSurface("resources//images//double//doubleFive.png");
		doubleSix = loadSurface("resources//images//double//doubleSix.png");

	// each triple impages
		anyTriple = loadSurface("resources//images//triple//anyTriple.png");
		tripleOne = loadSurface("resources//images//triple//tripleOne.png");
		tripleTwo = loadSurface("resources//images//triple//tripleTwo.png");
		tripleThree = loadSurface("resources//images//triple//tripleThree.png");
		tripleFour = loadSurface("resources//images//triple//tripleFour.png");
		tripleFive = loadSurface("resources//images//triple//tripleFive.png");
		tripleSix = loadSurface("resources//images//triple//tripleSix.png");


	//// total sum images
		sumFour = loadSurface("resources//images//sum//four.png");
		sumFive = loadSurface("resources//images//sum//five.png");
		sumSix = loadSurface("resources//images//sum//six.png");
		sumSeven = loadSurface("resources//images//sum//seven.png");
		sumEight = loadSurface("resources//images//sum//eight.png");
		sumNine = loadSurface("resources//images//sum//nine.png");
		sumTen = loadSurface("resources//images//sum//ten.png");
		sumEleven = loadSurface("resources//images//sum//eleven.png");
		sumTwelve = loadSurface("resources//images//sum//twelve.png");
		sumThirteen = loadSurface("resources//images//sum//thirteen.png");
		sumFourteen = loadSurface("resources//images//sum//fourteen.png");
		sumFifteen = loadSurface("resources//images//sum//fifteen.png");
		sumSixteen = loadSurface("resources//images//sum//sixteen.png");
		sumSeventeen = loadSurface("resources//images//sum//seventeen.png");

	// load pair dice images
	//	pairInfo = loadSurface("resources//images//pair//pairInfo.png");
		pairOneTwo = loadSurface("resources//images//pair//oneToTwo.png");
		pairOneThree = loadSurface("resources//images//pair//oneToThree.png");
		pairOneFour = loadSurface("resources//images//pair//oneToFour.png");
		pairOneFive = loadSurface("resources//images//pair//oneToFive.png");
		pairOneSix = loadSurface("resources//images//pair//oneToSix.png");
		pairTwoThree = loadSurface("resources//images//pair//twoToThree.png");
		pairTwoFour = loadSurface("resources//images//pair//twoToFour.png");
		pairTwoFive = loadSurface("resources//images//pair//twoToFive.png");
		pairTwoSix = loadSurface("resources//images//pair//twoToSix.png");
		pairThreeFour = loadSurface("resources//images//pair//threeToFour.png");
		pairThreeFive = loadSurface("resources//images//pair//threeToFive.png");
		pairThreeSix = loadSurface("resources//images//pair//threeToSix.png");
		pairFourFive = loadSurface("resources//images//pair//fourToFive.png");
		pairFourSix = loadSurface("resources//images//pair//fourToSix.png");
		pairFiveSix = loadSurface("resources//images//pair//fiveToSix.png");

	//images for straights
		anyStraight = loadSurface("resources//images//straight//anyStraight.png");
		oneTwoThree = loadSurface("resources//images//straight//oneTwoThree.png");
		TwoThreeFour = loadSurface("resources//images//straight//TwoThreeFour.png");
		ThreeFourFive = loadSurface("resources//images//straight//ThreeFourFive.png");
		FourFiveSix = loadSurface("resources//images//straight//FourFiveSix.png");

	//images for one dice
		one = loadSurface("resources//images//dice//one.png");
		two = loadSurface("resources//images//dice//two.png");
		three = loadSurface("resources//images//dice//three.png");
		four = loadSurface("resources//images//dice//four.png");
		five = loadSurface("resources//images//dice//five.png");
		six = loadSurface("resources//images//dice//six.png");

	//sound and music images
		musicOn = loadSurface("resources//images//sound//musicOn.png");
		musicOff = loadSurface("resources//images//sound//musicOff.png");
		soundOn = loadSurface("resources//images//sound//soundOn.png");
		soundOff = loadSurface("resources//images//sound//soundOff.png");

	return success;
}
SDL_Surface* Draw::loadSurface(std::string path)
{
	//loadSurface - check if the images is loaded successful

	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* myImage = IMG_Load(path.c_str());
	if (myImage == NULL)
	{
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		exit(1);
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface(myImage, surface->format,0);
		if (optimizedSurface == NULL)
		{
			exit(1);
		}
		SDL_FreeSurface(myImage);
	}
	return optimizedSurface;
}

void Draw::CreateObjects()
{
	//CreateObjects - this is function to create unique objects with their parameters
//Small And big
	objectFiller(0, 25,  80, small, surface);
	objectFiller(1, 869, 80, big, surface);
//Double
	objectFiller(2, 158, 100, doubleOne, surface);
	objectFiller(3, 225, 100, doubleTwo, surface);
	objectFiller(4, 292, 100, doubleThree, surface);
	objectFiller(5, 667, 100, doubleFour, surface);
	objectFiller(6, 734, 100, doubleFive, surface);
	objectFiller(7, 801, 100, doubleSix, surface);
//Triple
	objectFiller(8,  468, 100, anyTriple, surface);
	objectFiller(9,  360, 100, tripleOne, surface);
	objectFiller(10, 360, 138, tripleTwo, surface);
	objectFiller(11, 360, 176, tripleThree, surface);
	objectFiller(12, 559, 100, tripleFour, surface);
	objectFiller(13, 559, 138, tripleFive, surface);
	objectFiller(14, 559, 176, tripleSix, surface);

//Total sum
	objectFiller(15, 25, 212, sumFour, surface);
	objectFiller(16, 95, 212, sumFive, surface);
	objectFiller(17, 165, 212, sumSix, surface);
	objectFiller(18, 235, 212, sumSeven, surface);
	objectFiller(19, 305, 212, sumEight, surface);
	objectFiller(20, 375, 212, sumNine, surface);
	objectFiller(21, 445, 212, sumTen, surface);
	objectFiller(22, 515, 212, sumEleven, surface);
	objectFiller(23, 585, 212, sumTwelve, surface);
	objectFiller(24, 655, 212, sumThirteen, surface);
	objectFiller(25, 725, 212, sumFourteen, surface);
	objectFiller(26, 795, 212, sumFifteen, surface);
	objectFiller(27, 865, 212, sumSixteen, surface);
	objectFiller(28, 935, 212, sumSeventeen, surface);

//Pair images
	objectFiller(29, 105, 324, pairOneTwo, surface);
	objectFiller(30, 165, 324, pairOneThree, surface);
	objectFiller(31, 225, 324, pairOneFour, surface);
	objectFiller(32, 285, 324, pairOneFive, surface);
	objectFiller(33, 345, 324, pairOneSix, surface);
	objectFiller(34, 405, 324, pairTwoThree, surface);
	objectFiller(35, 465, 324, pairTwoFour, surface);
	objectFiller(36, 525, 324, pairTwoFive, surface);
	objectFiller(37, 585, 324, pairTwoSix, surface);
	objectFiller(38, 645, 324, pairThreeFour, surface);
	objectFiller(39, 705, 324, pairThreeFive, surface);
	objectFiller(40, 765, 324, pairThreeSix, surface);
	objectFiller(41, 825, 324, pairFourFive, surface);
	objectFiller(42, 885, 324, pairFourSix, surface);
	objectFiller(43, 945, 324, pairFiveSix, surface);

//Straight images
	objectFiller(44, 25,  436, anyStraight, surface);
	objectFiller(45, 221, 436, oneTwoThree, surface);
	objectFiller(46, 417, 436, TwoThreeFour, surface);
	objectFiller(47, 613, 436, ThreeFourFive, surface);
	objectFiller(48, 809, 436, FourFiveSix, surface);

//Each Dice image
	objectFiller(49, 25,  478, one, surface);
	objectFiller(50, 188, 478, two, surface);
	objectFiller(51, 351, 478, three, surface);
	objectFiller(52, 514, 478, four, surface);
	objectFiller(53, 677, 478, five, surface);
	objectFiller(54, 840, 478, six, surface);


	menuFiller(0, 720, 600, roll, surface);
	menuFiller(1, 25, 5, newGame, surface);
	menuFiller(2, 175, 5, help, surface);
	menuFiller(3, 570, 600, clear, surface);
	menuFiller(4, 963, 11, musicOn, surface);
	menuFiller(5, 921, 11, soundOn, surface);
	menuFiller(6, 325,  5,statsButton,surface);
	menuFiller(7, 856, 650, backToGame, surface);
	menuFiller(8, 770, 650, next, surface);
	menuFiller(9, 690, 650, prev, surface);
}

void Draw::addButtonInformation(int idbutton,int x,int y, SDL_Surface* image_name,SDL_Surface* screen)
{
	//addButtonInformation this is function to set all important information for the object
	// @param idbutton - unique number for any button
	// @param x,y,w,h - coordinates of object (SDL_Rect)
	// @param SDL_Surface* image - use image for button
	// @param SDL_Surface* screen - use background surface for all buttons
	ID = idbutton;
	image_rect.x = x;
	image_rect.y = y;
	image_rect.w = 0;
	image_rect.h = 0;
	image = image_name;
	surface = screen;
}
void Draw::objectFiller(int idbutton,int x,int y, SDL_Surface* image,SDL_Surface* screen)
{
	//objectFiller this is function to create new objects and put them into vector
	// @param idbutton - unique number for any button
	// @param x,y,w,h - coordinates of object (SDL_Rect)
	// @param SDL_Surface* image - use image for button
	// @param SDL_Surface* screen - use background surface for all buttons
	Draw* tempObject;
	tempObject = new Draw;
	tempObject->addButtonInformation(idbutton,x,y,image,screen);
	buttonImages.push_back(*tempObject);
	delete tempObject;
}
void Draw::menuFiller(int idbutton,int x,int y, SDL_Surface* image,SDL_Surface* screen) {
	//menuObjects this is function to create our menu buttons and put them in the vector.
	// @param idbutton - id of the button.
	// @param x,y - beginning of the button top x and y position.
	// @param SDL_Surface* -
	Draw* menuObjects;
	menuObjects = new Draw;
	menuObjects->addButtonInformation(idbutton, x, y, image, screen);
	menuButtons.push_back(*menuObjects);
	delete menuObjects;
}

SDL_Rect Draw::getButtonRect()
{
	return image_rect;
}
SDL_Surface* Draw::getSurface()
{
	return surface;
}
void Draw::draw()
{
	//Draw image on the surface with image_rect parameters
	SDL_BlitSurface(image,NULL,surface,&image_rect);
}
void Draw::freeSurface(SDL_Surface* image_name)
{
	//close and free surface for specific object image
	SDL_FreeSurface(image_name);
	image_name = NULL;
}
void Draw::mouseCursor()
{
	int x,y;
	SDL_GetMouseState(&x, &y);
	if ((x > 0 && x < 1024) && (y > 0 && y < 701))
	{
		SDL_Surface *cursor;
		cursor = loadSurface("resources//images//other//cursor.png");
		SDL_Rect cursorRect = {x, y, x+20, y+20};
		SDL_SetColorKey(cursor, SDL_TRUE, SDL_MapRGB(cursor->format, 255, 255, 255));
		SDL_BlitSurface(cursor, NULL, surface, &cursorRect);
		SDL_FreeSurface(cursor);
		cursor = NULL;
	}
}

bool Draw::checkEvents(SDL_Event *e)
{
	bool result = false;
	if( e->type == SDL_MOUSEBUTTONDOWN)
	{
		int xCord, yCord;
		SDL_GetMouseState( &xCord, &yCord );
		bool inside = true;

		//Mouse is left of the button
		if( xCord < Draw::image_rect.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( xCord > Draw::image_rect.x + Draw::image_rect.w )
		{
			inside = false;
		}
		//Mouse above the button
		else if( yCord < Draw::image_rect.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( yCord > Draw::image_rect.y + Draw::image_rect.h )
		{
			inside = false;
		}
		if(inside == true)
		{
			result = true;
		}
	}
	return result;
}

int Draw::getID()
{
	return ID;
}
void Draw::drawImages() {
	SDL_BlitSurface(backGround, NULL, surface, NULL);
	SDL_Rect betTopInfo = {158, 80, 0, 0};
	SDL_BlitSurface(topInfo, NULL, surface, &betTopInfo);
	SDL_Rect betEachDice = {25, 540, 0, 0};
	SDL_BlitSurface(eachDiceInfo, NULL, surface, &betEachDice);
	SDL_Rect creditInfo = {25, 600, 0, 0};
	SDL_BlitSurface(creditButton, NULL, surface, &creditInfo);
	SDL_Rect betArea = {190, 600, 0, 0};
	SDL_BlitSurface(betButton, NULL, surface, &betArea);
	SDL_Rect highScoreInfo = {405, 600, 0, 0};
	SDL_BlitSurface(highScore, NULL, surface, &highScoreInfo);
	SDL_Rect pairInfoIm = {25, 324, 0, 0};
	SDL_BlitSurface(pairInfo, NULL, surface, &pairInfoIm);
	SDL_Rect chipInfoRect = {490, 10, 0, 0};
	SDL_BlitSurface(chipInfo, NULL, surface, &chipInfoRect);
	SDL_SetColorKey(chipInfo, SDL_TRUE, SDL_MapRGB(chipInfo->format, 192, 192, 192));
}

void Draw::soundImageOffOn( bool sound )
{
	SDL_Rect soundImOffon = {921, 11, 0, 0};

	if ( sound )
	{
		SDL_BlitSurface(soundOn, NULL, surface, &soundImOffon);
	}
	else{
		SDL_BlitSurface(soundOff, NULL, surface, &soundImOffon);
	}
}

void Draw::musicImageOffOn()
{
	SDL_Rect musicImOffOn = {963, 11, 0, 0};
	if (Mix_PlayingMusic() == 0)
	{
		SDL_BlitSurface(musicOff, NULL, surface, &musicImOffOn);
	}
	else{
		SDL_BlitSurface(musicOn, NULL, surface, &musicImOffOn);
	}
}

void Draw::rollButtonOn()
{
	SDL_Rect rollButtOn = {720, 600, 0, 0};
	SDL_BlitSurface(rollOn, NULL, surface, &rollButtOn);
	SDL_UpdateWindowSurface(window);
}
void Draw::newGameButtonOn() {
	SDL_Rect newGameButtOn = {25, 5, 0, 0};
	SDL_BlitSurface(newGameOn, NULL, surface, &newGameButtOn);
	SDL_UpdateWindowSurface(window);
}
void Draw::clearButtonOn() {
	SDL_Rect clearButtOn = {570, 600, 0, 0};
	SDL_BlitSurface(clearOn, NULL, surface, &clearButtOn);
	SDL_UpdateWindowSurface(window);
}
SDL_Surface* Draw::getImage()
{
	return image;
}
void Draw::freeImages()
{
	freeSurface(topInfo);
	freeSurface(eachDiceInfo);
	freeSurface(creditButton);
	freeSurface(betButton);
	freeSurface(backGround);
	freeSurface(rollOn);
	freeSurface(newGameOn);
	freeSurface(clearOn);
	freeSurface(blueChip);
	freeSurface(yellowChip);
	freeSurface(redChip);

	freeSurface(rollDiceOne);
	freeSurface(rollDiceTwo);
	freeSurface(rollDiceThree);
	freeSurface(rollDiceFour);
	freeSurface(rollDiceFive);
	freeSurface(rollDiceSix);

	freeSurface(musicOff);
	freeSurface(soundOff);

}

//MATH FUNCTION

void Draw::checkWinner(int ID,int a,int b,int c)
{
	switch(ID)
	{
		case  SMALL: checkSmall(1,a,b,c); break;
		case  BIG: checkBig(2,a,b,c); break;
		case  DOUBLE_1: calculateDouble(1,a,b,c); break;
		case  DOUBLE_2: calculateDouble(2,a,b,c); break;
		case  DOUBLE_3: calculateDouble(3,a,b,c); break;
		case  DOUBLE_4: calculateDouble(4,a,b,c); break;
		case  DOUBLE_5: calculateDouble(5,a,b,c); break;
		case  DOUBLE_6: calculateDouble(6,a,b,c); break;
		case  ANY_TRIPLE: calculateAnyTriple(a,b,c); break;
		case  TRIPLE_1:	calculateTriple(1,a,b,c); break;
		case  TRIPLE_2: calculateTriple(2,a,b,c); break;
		case  TRIPLE_3: calculateTriple(3,a,b,c); break;
		case  TRIPLE_4: calculateTriple(4,a,b,c); break;
		case  TRIPLE_5: calculateTriple(5,a,b,c); break;
		case  TRIPLE_6: calculateTriple(6,a,b,c); break;
		case  SUM_4:  calculateSum(4,a,b,c); break;
		case  SUM_5:  calculateSum(5,a,b,c); break;
		case  SUM_6:  calculateSum(6,a,b,c); break;
		case  SUM_7:  calculateSum(7,a,b,c); break;
		case  SUM_8:  calculateSum(8,a,b,c); break;
		case  SUM_9:  calculateSum(9,a,b,c); break;
		case  SUM_10: calculateSum(10,a,b,c); break;
		case  SUM_11: calculateSum(11,a,b,c); break;
		case  SUM_12: calculateSum(12,a,b,c); break;
		case  SUM_13: calculateSum(13,a,b,c); break;
		case  SUM_14: calculateSum(14,a,b,c); break;
		case  SUM_15: calculateSum(15,a,b,c); break;
		case  SUM_16: calculateSum(16,a,b,c); break;
		case  SUM_17: calculateSum(17,a,b,c); break;
		case  PAIR_1_2: calculateTwo_pair(1,2,a,b,c); break;
		case  PAIR_1_3: calculateTwo_pair(1,3,a,b,c); break;
		case  PAIR_1_4: calculateTwo_pair(1,4,a,b,c); break;
		case  PAIR_1_5: calculateTwo_pair(1,5,a,b,c); break;
		case  PAIR_1_6: calculateTwo_pair(1,6,a,b,c); break;
		case  PAIR_2_3: calculateTwo_pair(2,3,a,b,c); break;
		case  PAIR_2_4: calculateTwo_pair(2,4,a,b,c); break;
		case  PAIR_2_5: calculateTwo_pair(2,5,a,b,c); break;
		case  PAIR_2_6: calculateTwo_pair(2,6,a,b,c); break;
		case  PAIR_3_4: calculateTwo_pair(3,4,a,b,c); break;
		case  PAIR_3_5: calculateTwo_pair(3,5,a,b,c); break;
		case  PAIR_3_6: calculateTwo_pair(3,6,a,b,c); break;
		case  PAIR_4_5: calculateTwo_pair(4,5,a,b,c); break;
		case  PAIR_4_6: calculateTwo_pair(4,6,a,b,c); break;
		case  PAIR_5_6: calculateTwo_pair(5,6,a,b,c); break;
		case  ANYSTRAIGHT: calculateAnyStraigth(a,b,c); break;
		case  STR_1_2_3: calculateStraigth(1,a,b,c); break;
		case  STR_2_3_4: calculateStraigth(2,a,b,c); break;
		case  STR_3_4_5: calculateStraigth(3,a,b,c); break;
		case  STR_4_5_6: calculateStraigth(4,a,b,c); break;
		case  ONE:	 calculateOne_pair(1,a,b,c); break;
		case  TWO:	 calculateOne_pair(2,a,b,c); break;
		case  THREE: calculateOne_pair(3,a,b,c); break;
		case  FOUR: calculateOne_pair(4,a,b,c); break;
		case  FIVE: calculateOne_pair(5,a,b,c); break;
		case  SIX:   calculateOne_pair(6,a,b,c); break;
		default: break;
	}
}
void Draw::checkSmall(int unique,int a,int b,int c)
{
	int sum = a + b + c;
	bool checkTriple = (a != b || a != c);
	if(unique == 1) // Check for small
	{
		if((sum >= 4 && sum <= 10) && (checkTriple))
		{
			win = bet + bet;
			SDL_SetSurfaceBlendMode(getImage(),SDL_BLENDMODE_ADD);
		}
	}
}
void Draw::checkBig(int unique,int a,int b,int c)
{
	int sum = a + b + c;
	bool checkTriple = (a != b || a != c);
	if(unique == 2) // Check for big
	{
		if((sum >= 11 && sum <= 17) && (checkTriple))
		{
			win = bet + bet;
			SDL_SetSurfaceBlendMode(getImage(),SDL_BLENDMODE_ADD);
		}
	}
}
void Draw::calculateDouble(int unique,int a,int b,int c)
{
	bool double_result = ((a == b && a != c) || (a != b && b == c));
	if((b == unique) && (double_result))
	{
		win = bet + (bet*11);
		SDL_SetSurfaceBlendMode(getImage(),SDL_BLENDMODE_ADD);
	}
}
void Draw::calculateTriple(int unique,int a,int b, int c)
{
	bool triple_result = (a == b && a == c);
	if((a == unique) && (triple_result))
	{
		win = bet + (bet*180);
		SDL_SetSurfaceBlendMode(getImage(),SDL_BLENDMODE_ADD);
	}
}

void Draw::calculateAnyTriple(int a,int b,int c)
{
	if(a == b && b == c)
	{
		win = bet + (bet*30);
		SDL_SetSurfaceBlendMode(getImage(),SDL_BLENDMODE_ADD);
	}
}

void Draw::calculateSum(int unique,int a,int b,int c)
{
	if(a+b+c == unique)
	{
		coeff_4_17(unique);
		coeff_5_16(unique);
		coeff_6_15(unique);
		coeff_7_14(unique);
		coeff_8_13(unique);
		coeff_9_12(unique);
		coeff_10_11(unique);
		SDL_SetSurfaceBlendMode(getImage(),SDL_BLENDMODE_ADD);
	}
}
void Draw::coeff_4_17(int unique)
{
	if( unique == 4 || unique == 17 )
		{
			win = bet + (bet*62);
		}
}
void Draw::coeff_5_16(int unique)
{
	if( unique == 5 || unique == 16 )
		{
			win = bet + (bet*31);
		}
}
void Draw::coeff_6_15(int unique)
{
	if( unique == 6 || unique == 15 )
		{
			win = bet + (bet*18);
		}
}
void Draw::coeff_7_14(int unique)
{
	if( unique == 7 || unique == 14 )
		{
			win = bet + (bet*12);
		}
}
void Draw::coeff_8_13(int unique)
{
	if( unique == 8 || unique == 13 )
		{
			win = bet + (bet*8);
		}
}
void Draw::coeff_9_12(int unique)
{
	if( unique == 9 || unique == 12 )
		{
			win = bet + (bet*7);
		}
}
void Draw::coeff_10_11(int unique)
{
	if( unique == 10 || unique == 11 )
		{
			win = bet + (bet*6);
		}
}

void Draw::calculateStraigth(int unique,int a,int b, int c)
{
	bool straigth_result = (a == (b-1)) && (b == (c-1));
	if((unique == a) && straigth_result)
	{
		win = bet + (bet*30);
		SDL_SetSurfaceBlendMode(getImage(),SDL_BLENDMODE_ADD);
	}
}

void Draw::calculateAnyStraigth(int a,int b, int c)
{
	bool anyStr = ((a+1 == b) && (b+1 == c));
	if(anyStr)
	{
		win = bet + (bet*8);
		SDL_SetSurfaceBlendMode(getImage(),SDL_BLENDMODE_ADD);	}
}

void Draw::calculateTwo_pair(int first,int second,int a,int b, int c)
{
	bool twoPair_1 = (a == first && b == second);
	bool twoPair_2 = (a == first && c == second);
	bool twoPair_3 = (b == first && c == second);

	if((twoPair_1 || twoPair_2) || twoPair_3)
	{
		win = bet + (bet*6);
		SDL_SetSurfaceBlendMode(getImage(),SDL_BLENDMODE_ADD);
	}
}

void Draw::calculateOne_pair(int U,int a,int b,int c)
{
	bool one_pair = ((a == U && b != U && c != U) ||
					((b == U && a != U && c != U) ||
					(c == U && a != U && b != U)));

	bool two_pair = ((a == U && b == U && c != U) ||
					((a == U && c == U && b != U) ||
					(b == U && c == U && a != U)));

	bool three_pair = (a == U && b == U && c == U);

	if(one_pair)
	{
		win = bet + bet;
		SDL_SetSurfaceBlendMode(getImage(),SDL_BLENDMODE_ADD);
	}
	else if(two_pair)
	{
		win = bet + (bet*2);
		SDL_SetSurfaceBlendMode(getImage(),SDL_BLENDMODE_ADD);
	}
	else if(three_pair)
	{
		win = bet + (bet*12);
		SDL_SetSurfaceBlendMode(getImage(),SDL_BLENDMODE_ADD);
	}
}


// PLAYER FUNCTION
void Draw::setBet(int bet)
{
	this->bet += bet;
	check1000();
	check200();
	check175();
	check125();
	check100();
	check60();
	check50();
	check25();
	check10();
}
int Draw::getBet()
{
	return bet;
}
int Draw::getWin()
{
	return win;
}

void Draw::check1000()
{
	if(( ID == SMALL || ID == BIG ) || ( ID >= ONE && ID <= SIX))
	{
		if (bet >= 1000)
		{
			bet = 1000;
		}
	}
}

void Draw::check200()
{
	bool maxBet200 = (ID == SUM_10 || ID == SUM_11) || (ID >= PAIR_1_2 && ID <= PAIR_5_6);
	if (maxBet200)
	{
		if (bet >= 200)
		{
			bet = 200;
		}
	}
}

void Draw::check175()
{
	if (ID == SUM_9 || ID == SUM_12)
	{
		if (bet >= 175)
			bet = 175;
	}

}

void Draw::check125()
{
	if ((ID == SUM_8 || ID == SUM_13) || ID == ANYSTRAIGHT)
	{
		if (bet >= 125)
			bet = 125;
	}
}

void Draw::check100()
{
	if ((ID == SUM_7 || ID == SUM_14) || (ID >= DOUBLE_1 && ID <= DOUBLE_6))
	{
		if (bet >= 100)
			bet = 100;
	}
}

void Draw::check60()
{
	if (ID == SUM_6 || ID == SUM_15)
	{
		if (bet > 60)
			bet = 60;
	}
}

void Draw::check50()
{
	if (((ID == ANY_TRIPLE || ID == SUM_5) || ID == SUM_16) || (ID >= STR_1_2_3 && ID <= STR_4_5_6))
	{
		if (bet > 50)
			bet = 50;
	}
}

void Draw::check25()
{
	if (ID == SUM_4 || ID == SUM_17)
	{
		if (bet >= 25)
			bet = 25;
	}

}

void Draw::check10()
{
	if (ID >= TRIPLE_1 && ID <= TRIPLE_6)
	{
		if (bet >= 10)
			bet = 10;
	}
}

void Draw::nullBetAndWin()
{
	for(size_t i = 0;i<buttonImages.size();++i)
	{
		buttonImages[i].win = 0;
		buttonImages[i].bet = 0;
	}
	totalPlayerBet = 0;
}

void Draw::clearButtonsMODE()
{
	for(size_t i = 0;i<buttonImages.size();++i)
	{
		SDL_SetSurfaceBlendMode(buttonImages[i].getImage(),SDL_BLENDMODE_NONE);
	}
}



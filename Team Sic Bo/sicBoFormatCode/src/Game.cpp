/*
 * Game.cpp
 *
 *  Created on: 1.10.2014 �.
 *      Author: msi
 */

#include "Game.h"

Game::Game()
{
	window = NULL;
	running = true;
	soundOffOn = true;
	switchScreen=1;
}

Game::~Game()
{
	free();
}

bool Game::init(string title,int x,int y,int w,int h)
{
	if(SDL_INIT_VIDEO == 0)
	{
		return false;
	}
	else
	{
		window = SDL_CreateWindow(title.c_str(), x, y,w, h, 0);
		if(window == NULL)
		{
			return false;
		}
		else
		{
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				return false;
			}
			else
			{
				surface = SDL_GetWindowSurface(window);
				loadMedia();

				Draw::CreateObjects();
				nullBetAndWin();
				player.setCredit(record.recoveryCredits());
				testDice.nullAllDices();
				printStatistic.fillListFromFile();
			}
		}
	}
	running = true;
	return true;
}

bool Game::loadMedia()
{
	Draw::loadMediaImages();
	TrueTypeFont::load();
	Music::loadMusic();
	return true;
}

void Game::drawTable()
{
	Draw::drawImages();
	for(size_t i = 0;i<buttonImages.size();i++)
	{
		buttonImages[i].draw();
	}
	for(size_t i = 0;i<menuButtons.size()-3;i++)
	{
		menuButtons[i].draw();
	}
	drawAllTTF();
	musicImageOffOn();
	soundImageOffOn(soundOffOn);
	dicesVisual();
	mouseCursor();
	SDL_UpdateWindowSurface(window);
}

void Game::handleEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event) != 0)
	{
		if(event.type == SDL_QUIT)
		{
			running = false;
		}
		if((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT))
		{
			clearButtonsMODE();
			handleRollButton(event);
			handleClearButton(event);
			handleNewGameButton(event);
			handleSoundsButtons(event);
			handleHelpButton(event);
			handleBackToGameButton(event);
			handleStatsMenuButton(event);
			for (size_t i = 0; i < buttonImages.size(); ++i)
			{
				if (buttonImages[i].checkEvents(&event))
				{
					totalPlayerBet += 5;
					if(totalPlayerBet <= player.showCredit())
					{
						Music::playSetChipSound();
						buttonImages[i].setBet(5);
					}

				}
			}
		}
	}
	record.recordCredit(player.showCredit());
}

void Game::handleRollButton(SDL_Event &event)
{
	if(menuButtons[0].checkEvents(&event) && (totalPlayerBet > 0))
	{
		Music::playRollSound();
		player.nullPlayerStatistic();
		rollButtonOn();
		fakeDiceRoll();
		testDice.rollAllDices();
		int a = testDice.getFirstDice();
		int b = testDice.getSecondDice();
		int c = testDice.getThirdDice();
		for (size_t i = 0; i < buttonImages.size(); i++)
		{
			buttonImages[i].checkWinner(buttonImages[i].getID(),a,b,c);

			player.setBet(buttonImages[i].getBet());
			player.setWin(buttonImages[i].getWin());
		}
		int playerBet = player.getBet();
		int playerWin = player.getWin();

		printStatistic.setGameStatistic(playerBet,playerWin,a,b,c);
		printStatistic.calculateMainStatistic();
		printStatistic.saveStatisticsToFile();

		player.setShowWin(player.getWin());
		player.getCredit();

		if (player.getWin() > 0)
		{
			Music::playWinSound();
		}
		nullBetAndWin();
	}
}
void Game::handleClearButton(SDL_Event &event) {
	if(menuButtons[3].checkEvents(&event)) {
		clearButtonOn();
		nullBetAndWin();
	}
}

void Game::handleNewGameButton(SDL_Event &event) {
	if(menuButtons[1].checkEvents(&event)) {
		newGameButtonOn();
		player.setCredit(1000);
	}
}

void Game::handleHelpButton(SDL_Event &event)
{
	if(menuButtons[2].checkEvents(&event)){
		switchScreen=2;
	}
}

void Game::handleNextFirstButton(SDL_Event &event) {
	if(menuButtons[8].checkEvents(&event) && (switchScreen == 2)) {
		switchScreen = 3;
	}
	else if(menuButtons[8].checkEvents(&event) && (switchScreen == 3)) {
		switchScreen = 4;
	}
}

void Game::handlePrevButton(SDL_Event &event) {
	if(menuButtons[9].checkEvents(&event) && (switchScreen == 3)) {
		switchScreen = 2;
	}
	else if(menuButtons[9].checkEvents(&event) && (switchScreen == 4)) {
		switchScreen = 3;
	}
}

void Game::handleSoundsButtons(SDL_Event &event)
{
	if( menuButtons[5].checkEvents(&event))
	{
		if( soundOffOn == true )
		{
			Music::stopSound();
			soundOffOn = false;
		}
		else
		{
			Music::playSound();
			soundOffOn = true;
		}

	}
	if (menuButtons[4].checkEvents(&event))
	{
		Music::playStopMusic();
	}
}

void Game::helpWindowScreen()
{
	SDL_Surface* helpImage = NULL;
	helpImage = loadSurface("resources//images//help//helpFirst.png");
	SDL_BlitSurface(helpImage,NULL,getSurface(),NULL);
	menuButtons[7].draw();
	menuButtons[8].draw();
	mouseCursor();
	SDL_UpdateWindowSurface(window);
	SDL_FreeSurface(helpImage);
	helpImage = NULL;
}
void Game::helpSecondScreen() {
	SDL_Surface* helpSecond = NULL;
	helpSecond = loadSurface("resources//images//help//helpSecond.png");
	SDL_BlitSurface(helpSecond,NULL,getSurface(),NULL);
	menuButtons[7].draw();
	menuButtons[8].draw();
	menuButtons[9].draw();
	mouseCursor();
	SDL_UpdateWindowSurface(window);
	SDL_FreeSurface(helpSecond);
	helpSecond = NULL;
}
void Game::helpThirdScreen() {
	SDL_Surface* helpThird = NULL;
	helpThird = loadSurface("resources//images//help//helpThird.png");
	SDL_BlitSurface(helpThird,NULL,getSurface(),NULL);
	menuButtons[7].draw();
	menuButtons[9].draw();
	mouseCursor();
	SDL_UpdateWindowSurface(window);
	SDL_FreeSurface(helpThird);
	helpThird = NULL;
}
void Game::handleBackToGameButton(SDL_Event &event)
{
	if(menuButtons[7].checkEvents(&event))
	{
		switchScreen=1;
	}
}
void Game::handleHelpEvent()
{
	SDL_Event helpEvent;
		while(SDL_PollEvent(&helpEvent) != 0)
		{
			if(helpEvent.type == SDL_QUIT)
			{
				running = false;
			}
			if((helpEvent.type == SDL_MOUSEBUTTONDOWN) && (helpEvent.button.button == SDL_BUTTON_LEFT))
			{
				handleBackToGameButton(helpEvent);
			}
		}
}
void Game::handleHelpFirst()
{
	SDL_Event helpEvent;
		while(SDL_PollEvent(&helpEvent) != 0)
		{
			if(helpEvent.type == SDL_QUIT)
			{
				running = false;
			}
			if((helpEvent.type == SDL_MOUSEBUTTONDOWN) && (helpEvent.button.button == SDL_BUTTON_LEFT))
			{
				handleBackToGameButton(helpEvent);
				handleNextFirstButton(helpEvent);
				handlePrevButton(helpEvent);
			}
		}

}
void Game::handleStatsMenuButton(SDL_Event &event)
{
	if(menuButtons[6].checkEvents(&event))
		switchScreen=5;
}

void Game::statsWindowScreen()
{
	SDL_Surface* statsScreen = NULL;
	statsScreen = loadSurface("resources//images//background//background2.png");
	SDL_BlitSurface(statsScreen,NULL,getSurface(),NULL);
	printStatisticData();
	menuButtons[7].draw();
	mouseCursor();
	SDL_UpdateWindowSurface(window);
	SDL_FreeSurface(statsScreen);
	statsScreen = NULL;
}

void Game::handleGameEvents()
{
	SDL_ShowCursor( SDL_DISABLE);
	switch(switchScreen)
	{
	case GAMETABLE:
		reduceFPS();
		drawTable();
		handleEvents();
		break;
	case HELPFIRST:
		helpWindowScreen();
		reduceFPS();
		handleHelpFirst();
		break;
	case HELPSECOND:
		helpSecondScreen();
		reduceFPS();
		handleHelpFirst();
		break;
	case HELPTHIRD:
		helpThirdScreen();
		reduceFPS();
		handleHelpFirst();
		break;

	case STATSMENU:
		statsWindowScreen();
		reduceFPS();
		handleHelpEvent();
		break;
	}
}
void Game::reduceFPS()
{
	const int FPS = 100;
	Uint32 start;
	start = SDL_GetTicks();
	if (1000 / FPS > SDL_GetTicks() - start)
	{
		SDL_Delay(1000 / FPS - (SDL_GetTicks() - start));
	}
}

void Game::free()
{
	freeImages();
	for(size_t i = 0;i < buttonImages.size(); ++i)
	{
		buttonImages[i].Draw::freeSurface(buttonImages[i].Draw::getImage());
	}
	for(size_t i = 0;i < menuButtons.size(); ++i)
	{
		menuButtons[i].Draw::freeSurface(menuButtons[i].Draw::getImage());
	}

	SDL_FreeSurface(surface);
	surface = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	IMG_Quit();
	SDL_Quit();
}

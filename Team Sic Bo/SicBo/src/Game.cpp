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
	soundoffon = false;
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
	for(size_t i = 0;i<menuButtons.size()-1;i++)
	{
		menuButtons[i].draw();
	}
	drawAllTTF();
	Draw::musicImageOffOn();
	Draw::soundImageOffOn(soundoffon);
	dicesVisual();
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
	if(menuButtons[0].checkEvents(&event))
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
	if(menuButtons[2].checkEvents(&event))
		helpWindow=false;
}

void Game::handleSoundsButtons(SDL_Event &event)
{
	if( menuButtons[5].checkEvents(&event))
	{
		if( soundoffon == false )
		{
			Music::stopSound();
			soundoffon = true;
		}
		else
		{
			Music::playSound();
			soundoffon = false;
		}

	}
	if (menuButtons[4].checkEvents(&event))
	{
		Music::playStopMusic();
	}
}

void Game::helpWindowScreen()
{
	SDL_BlitSurface(helpImage,NULL,getSurface(),NULL);
	SDL_UpdateWindowSurface(window);
}

void Game::handleBackToGameButton(SDL_Event &event)
{
	if(menuButtons[6].checkEvents(&event))
	{
		helpWindow=true;
	}
}

void Game::handleGameEvents()
{

	if(helpWindow)
	{
		drawTable();
		handleEvents();
	    reduceFPS();
	}
	else
	{
		helpWindowScreen();
		menuButtons[6].draw();
		handleEvents();
	}
}
void Game::reduceFPS()
{
	const int FPS = 30;
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

	SDL_Quit();
}

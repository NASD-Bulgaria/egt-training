/*
 * Start.cpp
 *
 *  Created on: 13.10.2014 ã.
 *      Author: D00M
 */

#include "Start.h"

Start::Start() {
	quickGuidePages = 1;
	menu = 1;
}

Start::~Start() {
}

void Start::startMenu() {
	SDL_ShowCursor( SDL_DISABLE);

	switch(menu) {
		case START:
			begin();
			handleStartMenu();
			break;
		case CONTINUE:
			handleGameEvents();
			break;
		case NEWGAME:
			handleGameEvents();
			break;
		case QUICKGUIDE:
			quickGuide();
			break;
		case CREDITS:
			gameCredits();
			handleQuickGuide();
			break;
		case QUIT:
			running = false;
			break;
		default:
			break;
	}
}

void Start::handleStartMenu() {
	SDL_Event startEvent;
	while(SDL_PollEvent(&startEvent) != 0)
	{
		if(startEvent.type == SDL_QUIT)
		{
			running = false;
		}
		if((startEvent.type == SDL_MOUSEBUTTONDOWN) && (startEvent.button.button == SDL_BUTTON_LEFT))
		{
			 handleContinueButton(startEvent);
			 handleNewGameButton(startEvent);
			 handleQuickGuideButton(startEvent);
			 handleCredButton(startEvent);
			 handleQuitButton(startEvent);
		}
	}
}
void Start::quickGuide() {
	SDL_ShowCursor( SDL_DISABLE);
	switch(quickGuidePages) {
		case FIRST:
			reduceFPS();
			firstPage();
			handleQuickGuide();
			break;
		case SECOND:
			reduceFPS();
			secondPage();
			handleQuickGuide();
			break;
		default:
			break;
	}
}
void Start::firstPage() {
	SDL_Surface* helpSecond = NULL;
	helpSecond = loadSurface("resources//images//other//helpFirst.png");
	SDL_BlitSurface(helpSecond,NULL,getSurface(),NULL);
	menuButtons[15].draw();
	menuButtons[8].draw();
	mouseCursor();
	SDL_UpdateWindowSurface(window);
	SDL_FreeSurface(helpSecond);
	helpSecond = NULL;
}
void Start::secondPage() {
	SDL_Surface* helpSecond = NULL;
	helpSecond = loadSurface("resources//images//other//helpSecond.png");
	SDL_BlitSurface(helpSecond,NULL,getSurface(),NULL);
	menuButtons[15].draw();
	menuButtons[9].draw();
	mouseCursor();
	SDL_UpdateWindowSurface(window);
	SDL_FreeSurface(helpSecond);
	helpSecond = NULL;
}

void Start::gameCredits() {
	SDL_Surface* creators = NULL;
	creators = loadSurface("resources//images//start//gameCredits.png");
	SDL_BlitSurface(creators,NULL,getSurface(),NULL);
	menuButtons[15].draw();
	mouseCursor();
	SDL_UpdateWindowSurface(window);
	SDL_FreeSurface(creators);
	creators = NULL;
}
void Start::handleQuickGuide()
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
				handleBackToMenu(helpEvent);
				handleNextButton(helpEvent);
				handlePrevButton(helpEvent);
			}
		}
}
void Start::handleNextButton(SDL_Event &event) {
	if(menuButtons[8].checkEvents(&event) && (quickGuidePages == 1)) {
		quickGuidePages = SECOND;
	}
}

void Start::handlePrevButton(SDL_Event &event) {
	if(menuButtons[9].checkEvents(&event) && (quickGuidePages == 2)) {
		quickGuidePages = FIRST;
	}
}

void Start::handleContinueButton(SDL_Event &event) {
	if(menuButtons[10].checkEvents(&event)) {
		menu = CONTINUE;
	}
}

void Start::handleNewGameButton(SDL_Event &event) {
	if(menuButtons[11].checkEvents(&event)) {
		menu = NEWGAME;
		player.setCredit(1000);
	}
}

void Start::handleQuickGuideButton(SDL_Event &event) {
	if(menuButtons[12].checkEvents(&event)) {
		menu = QUICKGUIDE;
	}
}

void Start::handleCredButton(SDL_Event &event) {
	if(menuButtons[13].checkEvents(&event)) {
		menu = CREDITS;
	}
}
void Start::handleQuitButton(SDL_Event &event) {
	if(menuButtons[14].checkEvents(&event)) {
		menu = QUIT;
		running = false;
	}
}
void Start::handleBackToMenu(SDL_Event &event) {
	if(menuButtons[15].checkEvents(&event)) {
		menu = 1;
	}
}

void Start::begin() {
	SDL_ShowCursor( SDL_DISABLE);
	SDL_Surface* dragonBackground = NULL;
	dragonBackground = loadSurface("resources//images//background//dragonBackground.png");
	SDL_BlitSurface(dragonBackground, NULL, getSurface(), NULL);
	menuButtons[10].draw();
	menuButtons[11].draw();
	menuButtons[12].draw();
	menuButtons[13].draw();
	menuButtons[14].draw();
	mouseCursor();
	handleStartMenu();
	SDL_UpdateWindowSurface(window);
	SDL_FreeSurface(dragonBackground);
	dragonBackground = NULL;
}

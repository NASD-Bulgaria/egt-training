/*
 * Start.h
 *
 *  Created on: 13.10.2014 ã.
 *      Author: D00M
 */

#ifndef START_H_
#define START_H_
#include "Game.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

// enum for start menu.
enum {
	START = 1,
	CONTINUE,
	NEWGAME,
	QUICKGUIDE,
	CREDITS,
	QUIT
};

// enum for quick guide option.
enum {
	FIRST = 1,
	SECOND,
};

class Start : public Game {
public:
	Start();
	virtual ~Start();

	void startMenu();
// startMenu - function for game menu.

	void handleStartMenu();
// handleStartMenu - function to handle our start menu.

	void handleContinueButton(SDL_Event &);
// handleContinueButton - function to handle continue option.
// @param SDL_Event & - event object for our left mouse button.

	void handleNewGameButton(SDL_Event &);
// handleNewGameButton - function to handle new game option.
// @param SDL_Event & - event object for our left mouse button.

	void handleQuickGuideButton(SDL_Event &);
// handleQuickGuideButton - function to handle quick guide option.
// @param SDL_Event & - event object for our left mouse button.

	void handleCredButton(SDL_Event &);
// handleHelpButton - function to handle help option.
// @param SDL_Event & - event object for our left mouse button.

	void handleQuitButton(SDL_Event &);
// handleQuickButton - function to handle quit option.
// @param SDL_Event & - event object for our left mouse button.

	void handleBackToMenu(SDL_Event &);
// handleBackToMenu - function to handle back to menu button.

	void begin();
// begin - function to be loaded first in our program.

	void quickGuide();
// quickGuide - function for quick guide screens.

	void firstPage();
// firstPage - function for first page in quick guide.

	void secondPage();
// secondPage - function for second page in quick guide.

	void gameCredits();
// gameCredits - function to display creators of the game.

	void handleQuickGuide();
// handleQuickGuide - function to handle quick guide option.

	void handleNextButton(SDL_Event &);
// handleNextButton - function to handle next button in quick guide.
// @param SDL_Event & - event object for our left mouse button.

	void handlePrevButton(SDL_Event &);
// handlePrevButton - function to handle previous button in quick guide.
// @param SDL_Event & - event object for our left mouse button.

private:
	int quickGuidePages;
	int menu;
};

#endif /* START_H_ */

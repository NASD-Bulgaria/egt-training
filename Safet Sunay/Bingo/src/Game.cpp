/*
 * Game.cpp
 *
 *  Created on: Sep 28, 2014
 *      Author:
 */

#include "Game.h"

LTexture gBackgroundTexture;
Player player1;
CheckForBingo checkComp;
LTexture gRulesTexture;
LTexture gHighScoreTexture;
LTexture gStatus;

Game::Game()
{
	quit = false;
	play = false;

	i = -100;
	height = 200;
	h = 100;
	ballNum = 0;

	stop = 0.001;
	startTime = 0;

	gameStatusWin = false;

	bNewgame = false;
	bHighscore = false;
	bRules = false;
	bQuit = false;
	bPlay = false;
	bSound = false;
	bMusic = false;


	winGame = false;

	beep.loadSoundAndMusic();
	beep.startMusic();

	switches.rulesSwitch = 0;
	switches.scoreSwitch = 0;
	switches.muteSounds = 0;
	switches.stopMusic = 0;
	switches.overFifty = 0;
}

Game::~Game()
{
}

void Game::buttonPress(SDL_Event event)
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	if (event.type == SDL_MOUSEMOTION || SDL_MOUSEBUTTONDOWN)
	{
		//Button click
		if (x > 850 && x < 1000 && y > 390 && y < 440) // QUIT
		{
			// Quit
			setbQuit(true);
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				file.writeHsOutput();
				quit = true;
			}
		}
		else
		{
			setbQuit(false);
		}

		if (x > 850 && x < 1000 && y > 310 && y < 360) // RULES
		{
			// Rules
			setbRules(true);

			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				beep.SoundBeep();
				switches.rulesSwitch++;
			}
		}
		else
		{
			setbRules(false);
		}

		if (x > 850 && x < 1000 && y > 230 && y < 280) // HIGH SCORE
		{
			// High Score
			setbHighScore(true);
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				beep.SoundBeep();
			}
		}
		else
		{
			setbHighScore(false);
		}

		if (x > 850 && x < 1000 && y > 150 && y < 200) // NEW GAME
		{
			// New Game
			setbNewGame(true);

			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				beep.SoundBeep();

				play = false;
				i = -100;
				height = 200;
				h = 100;
				ballNum = 0;

				winGame = false;

				player1.setCredit(250);

				check.init();
				checkComp.init();
				game.playgameVars();
				game.setBallNum(ball.getBallNum());
			}
		}
		else
		{
			setbNewGame(false);
		}

		if (x > 400 && x < 652 && y > 450 && y < 534) // PLAY
		{
			// Play
			setbPlay(true);
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				beep.SoundBeep();
				winGame = false;
				if (player1.getCredit() >= 10)
				{
					if (!play)
					{
						player1.setCredit(player1.getCredit() - 10);
						game.playgameVars();
					}
					setPlay(true);
				}
			}
		}
		else
		{
			setbPlay(false);
		}

		if (x > 925 && x < 975 && y > 50 && y < 100) // SOUND
		{
			// Sound
			setbSound(true);

			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				switches.muteSounds++;
				if(switches.muteSounds == 1)
				{
					beep.SoundMute();
				}
				else
				{
					beep.SoundUnMute();
				}
				beep.SoundBeep();
			}
		}
		else
		{
			setbSound(false);
		}

		if (x > 875 && x < 925 && y > 50 && y < 100) // MUSIC
		{
			// Music

			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				switches.stopMusic++;
				beep.SoundBeep();
				if(switches.stopMusic == 1)
				{
					beep.stopMusic();
				}
				else
				{
					beep.startMusic();
				}
			}
			setbMusic(true);
		}
		else
		{
			setbMusic(false);
		}

		if ((check.getCol() != -1) && (check.getRow() != -1)) // CARD NUMBER SCRATCH
		{
			int startPointX = (260 + (check.getCol() * 50));
			int endPointX = (260 + ((check.getCol() + 1) * 50));

			int startPointY = (140 + (check.getRow() * 50));
			int endPointY = 140 + ((check.getRow() + 1) * 50);

			if ((x >= startPointX) && (x <= endPointX) && (y >= startPointY)
					&& (y <= endPointY))
			{
				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					beep.SoundScratch();
					playerTicket.ticket[check.getRow()][check.getCol()] = "X";

					bool hor = check.horizontalLine();
					bool vert = check.verticalLine();
					bool diag = check.diagonalLine();

					if (hor || vert || diag)
					{
						status = "You Win !";

						beep.SoundWin();

						winGame = true;
						player1.CounterWins();
						player1.setCredit((player1.getCredit() + win(hor, vert, diag)) + (100 * switches.overFifty));
						switches.overFifty = 0;

						gameStatus(true);
						game.setBallNum(ball.getBallNum());

						file.writeHsOutput();
						file.statsFromFile();
					}
				}
			}
		}
	}
}

bool Game::getQuit()
{
	return quit;
}

void Game::setQuit(bool q)
{
	quit = q;
}

void Game::renderScreen()
{
	// Renders button glow
	if (getbPlay())
	{
		buttonPlay.render(400, 451);
	}

	if (getbHighScore())
	{
		buttonInfo.render(851, 230);
	}

	if (getbRules())
	{
		buttonRules.render(851, 310);
	}

	if (getbQuit())
	{
		buttonQuit.render(851, 390);
	}

	if (getbNewGame())
	{
		buttonNewGame.render(851, 150);
	}

	if (getbSound())
	{
		buttonSound.render(926, 48);
	}

	if (getbMusic())
	{
		buttonMusic.render(874, 52);
	}

	if(switches.muteSounds == 1)
	{
		soundStop.render(926, 48);
	}
	if(switches.stopMusic == 1)
	{
		musicStop.render(874,52);
	}

	// renders player and computer cards
	if (play || winGame)
	{
		playerTicket.putOnScreen(266, 147);
		compTicket.putOnScreen(546, 147);
	}

	if (winGame)
	{
		SDL_Color winc = { 255, 100, 50 };
		gStatus.loadFromRenderedText(status.c_str(), winc);
		gStatus.render(((SCREEN_WIDTH - gStatus.getWidth()) / 2), 25);
	}

	if (switches.rulesSwitch == 1)
	{
		gRulesTexture.render(0, 0);
	}

	if (switches.scoreSwitch == 1)
	{
		gRulesTexture.render(0, 0);
	}

	// updates screen
	SDL_RenderPresent(gRenderer);

	// draw color, clear render
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);

	// render background
	gBackgroundTexture.render(0, 0);

	// Renders player's credit on screen
	game.displayCredit(player1.getCredit());

	SDL_Color col = {255, 255, 255};
	stats.loadFromRenderedTextStatistics(file.getStatistics().c_str(),col);
	stats.render(705,560);

}

void Game::playgameVars()
{
	playerTicket.drawNewTicket();
	compTicket.drawNewTicket();

	ball.shuffle();
}

int Game::win(bool hor, bool vert, bool diag) // function to check if someone have bingo and return credit
{
	int credit = 0;

	if (hor)
	{
		credit += 20;
	}
	if (vert)
	{
		credit += 30;
	}
	if (diag)
	{
		credit += 40;
	}

	return credit;
}

void Game::gameStatus(bool status)
{
	play = false;
	i = -100;
	height = 200;
	h = 100;

	if(player1.getGamesCount() % 50 == 0)
	{
		switches.overFifty = 1;
	}

	check.init();
	checkComp.init();
}

bool Game::renderBall(Uint32 stimer)
{
	SDL_Rect* currentClip = spriteclip(ballNum, height);

	gSpriteSheetTexture.setHeight(h);
	gSpriteSheetTexture.setWidth(100);

	return spriteRender(i, height, h, currentClip, stimer);
}

SDL_Rect* Game::spriteclip(int i, int height)
{
	SDL_Rect* temp;
	gSpriteClips.x = 200 * ((i - 1) % 10);
	gSpriteClips.y = 200 * ((i - 1) / 10);
	gSpriteClips.w = 200;
	gSpriteClips.h = height;

	temp = &gSpriteClips;
	return temp;
}

bool Game::spriteRender(int& moveVert, int& hideHeight, int& h, SDL_Rect* clip, Uint32 stimer)
{
	bool refresh = false;
	int velocity = 2400;

	if (moveVert < 0)
	{
		velocity = 1950;
		hideHeight = 200;
		h = 100;
	}

	if ((moveVert >= 300) && switches.rulesSwitch == 0)
	{
		h -= 2;
		hideHeight -= 4;
	}

	gSpriteSheetTexture.render(52, (int) (moveVert += velocity * stop), clip);

	if (i >= 400)
	{
		i = -100;
		refresh = true;
	}

	if (i == 148)
	{
		checkComp.setRowCol(ballNum, compTicket.ticket);

		if ((checkComp.getRow() != -1) && (checkComp.getCol() != -1))
		{
			beep.SoundScratch();
			compTicket.ticket[checkComp.getRow()][checkComp.getCol()] = "X";

			bool hor = checkComp.horizontalLine();
			bool vert = checkComp.verticalLine();
			bool diag = checkComp.diagonalLine();

			if (hor || vert || diag)
			{
				status = "You Loose !";
				beep.SoundLoose();
				winGame = true;
				player1.CounterLoss();
				gameStatus(true);
				game.setBallNum(ball.getBallNum());

				file.writeHsOutput();
				file.statsFromFile();
			}

		}

		startTime = SDL_GetTicks();
	}

	if (((stimer - startTime) < 500) || switches.rulesSwitch == 1)
	{
		stop = 0;
	}
	else
	{
		stop = 0.001;
	}

	return refresh;
}

void Game::setBallNum(int ball)
{
	ballNum = ball;
}

int Game::getBallNum()
{
	return ballNum;
}

bool Game::isPlay()
{
	return play;
}

void Game::setPlay(bool p)
{
	play = p;
}

void Game::displayCredit(int bet)
{
	SDL_Color creditColor =
	{ 255, 255, 255 };
	LTexture displayCredit;
	string credit;

	stringstream inpCredit;

	inpCredit << bet;

	credit = inpCredit.str();

	displayCredit.loadFromRenderedTextStatistics(credit, creditColor);

	displayCredit.render(160, 455);
}

void Game::displayBet(int a)
{
	SDL_Color betColor =
	{ 255, 255, 255 };
	LTexture displayBet;
	string bet;

	stringstream inpBet;
	inpBet << a;

	bet = inpBet.str();
	displayBet.loadFromRenderedTextStatistics(bet, betColor);

	displayBet.render(160, 525);
}

// Button BOOLS

bool Game::getbPlay()
{
	return bPlay;
}

void Game::setbPlay(bool p)
{
	bPlay = p;
}

bool Game::getbNewGame()
{
	return bNewgame;
}

void Game::setbNewGame(bool g)
{
	bNewgame = g;
}

bool Game::getbHighScore()
{
	return bHighscore;
}

void Game::setbHighScore(bool h)
{
	bHighscore = h;
}

bool Game::getbRules()
{
	return bRules;
}

void Game::setbRules(bool r)
{
	bRules = r;
}

bool Game::getbQuit()
{
	return bQuit;
}

void Game::setbQuit(bool q)
{
	bQuit = q;
}

void Game::setbSound(bool s)
{
	bSound = s;
}

void Game::setbMusic(bool m)
{
	bMusic = m;
}

bool Game::getbSound()
{
	return bSound;
}

bool Game::getbMusic()
{
	return bMusic;
}

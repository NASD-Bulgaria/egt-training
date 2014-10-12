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
LTexture gInfoTexture;
LTexture gStatus;

Game::Game()
{

	calls.fillBallsInVector(chunkList, calls);

	efects.setRenderer(gRenderer);
	efects.fillEfectsInVector(efectList, efects);

	button.setRenderer(gRenderer);
	button.fillInVector(panel, button);
	mouseOverGlow = false;
	renderingButton = 0;

	quit = false;
	play = false;

	i = -100;
	height = 200;
	h = 100;
	ballNum = 0;

	stop = 0.001;
	startTime = 0;

	gameStatusWin = false;
	winGame = false;

	beep.loadSoundAndMusic();
	beep.startMusic();

	switches.rulesSwitch = 0;
	switches.infoSwitch = 0;
	switches.muteSounds = 1;
	switches.stopMusic = 0;
	switches.overFifty = 0;
	switches.PlayerComputer = 0;
}

Game::~Game()
{
}

bool Game::searchButton(int& x, int& y, SDL_Event& event)
{
	for (int i = 0; i < 7; ++i)
	{
		if (panel[i].findButton(event, x, y))
		{
			renderingButton = i;
			return true;
		}
	}
	return false;
}

void Game::laFin()
{
	efectList[B].makeEffect(START_POSITION_LAFIN+(B*75), -30);
	efectList[I].makeEffect(START_POSITION_LAFIN+(I*75), -160);
	efectList[N].makeEffect(START_POSITION_LAFIN+(N*75), 30);
	efectList[G].makeEffect(START_POSITION_LAFIN+(G*75), 10);
	efectList[O].makeEffect(START_POSITION_LAFIN+(O*75), - 30);

	efects.colorEffect(2);
}

void Game::laFinEffect(bool win)
{
	if (win && switches.PlayerComputer == 0)
	{
		efectList[B].moveLaFinEffect(265, -1);
		efectList[I].moveLaFinEffect(316, -1);
		efectList[N].moveLaFinEffect(363, -1);
		efectList[G].moveLaFinEffect(416, -1);
		efectList[O].moveLaFinEffect(465, -1);
	}
	else if (win && switches.PlayerComputer == 1)
	{
		efectList[B].moveLaFinEffect(545, 1);
		efectList[I].moveLaFinEffect(594, 1);
		efectList[N].moveLaFinEffect(643, 1);
		efectList[G].moveLaFinEffect(696, 1);
		efectList[O].moveLaFinEffect(745, 1);
	}
	else
	{
		laFin();
	}
}

void Game::renderButtonsGlow()
{
	panel[renderingButton].render();
}

void Game::buttonPress(SDL_Event& event)
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	if (event.type == SDL_MOUSEMOTION)
	{
		mouseOverGlow = searchButton(x, y, event);
	}

	if(!mouseOverGlow)
	{
		renderingButton = -1;
	}

	if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
	{
		//Button click
		switch (renderingButton)
		{
		case NEW_GAME:
			if((switches.infoSwitch == OFF) && (switches.rulesSwitch == OFF))
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
			}
			break;

		case RULES:
			if(switches.infoSwitch == OFF)
			{
				beep.SoundBeep();
				switches.rulesSwitch++;
			}
			break;

		case INFO:
			if(switches.rulesSwitch == OFF)
			{
				beep.SoundBeep();
				switches.infoSwitch++;
			}
			break;

		case QUIT:
			file.writeHsOutput(switches.overFifty);
			quit = true;
			break;

		case PLAY:
			beep.SoundBeep();
			winGame = false;
			if (player1.getCredit() >= 10)
			{
				if (!play)
				{
					player1.setCredit(player1.getCredit() - 10);
					playgameVars();
					setBallNum(ball.getBallNum());
					efectList[B].returnDefaultValuesEffect(0);
					efectList[I].returnDefaultValuesEffect(24);
					efectList[N].returnDefaultValuesEffect(0);
					efectList[G].returnDefaultValuesEffect(24);
					efectList[O].returnDefaultValuesEffect(0);
				}
				setPlay(true);
			}
			break;

		case MUSIC_BUTTON:
			switches.stopMusic++;
			beep.SoundBeep();
			if (switches.stopMusic == 1)
			{
				beep.stopMusic();
			}
			else
			{
				beep.startMusic();
			}
			break;

		case SOUND_BUTTON:
			switches.muteSounds++;
			if (switches.muteSounds == OFF)
			{
				beep.SoundMute();
			}
			else
			{
				beep.SoundUnMute();
			}
			beep.SoundBeep();
			break;
		}
	}

	if ((check.getCol() != -1) && (check.getRow() != -1)) // CARD NUMBER MARK
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

					switches.PlayerComputer = 0;
					winGame = true;
					player1.CounterWins();
					player1.setCredit(
							(player1.getCredit() + win(hor, vert, diag))
									+ (100 * switches.overFifty));
					switches.overFifty = 0;

					gameStatus(true);

					file.writeHsOutput(switches.overFifty);
					file.statsFromFile();
				}
			}
		}
	} // End of card mark condition
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
	laFinEffect(winGame);
	// renders player's and computer's cards
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

	if (switches.infoSwitch == 1)
	{
		gInfoTexture.render(0, 0);
	}

	if (mouseOverGlow)
	{
		renderButtonsGlow();
	}

	if (switches.muteSounds == 0)
	{
		musicStop.render(934, 60);
	}
	if (switches.stopMusic == 1)
	{
		musicStop.render(883, 60);
	}

	// updates screen
	SDL_RenderPresent(gRenderer);

	// draw color, clear render
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);

	// render background
	gBackgroundTexture.render(0, 0);

	// Renders player's credit on screen
	displayCredit(player1.getCredit());

	SDL_Color col = { 255, 255, 255 };
	stats.loadFromRenderedTextStatistics(file.getStatistics().c_str(), col);
	stats.render(705, 560);
}

void Game::playgameVars()
{
	playerTicket.drawNewTicket();
	ball.shuffle();
	compTicket.drawNewTicket();
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

	if (player1.getGamesCount() % 50 == 0)
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

	if (moveVert == -50)
	{
		chunkList[getBallNum() - 1].mute(switches.muteSounds);
		chunkList[getBallNum() - 1].makeCall();
	}

	if (moveVert < 0)
	{
		velocity = 1950;
		hideHeight = 200;
		h = 100;
	}

	if ((moveVert >= 300) && (switches.rulesSwitch == 0)
			&& (switches.infoSwitch == 0))
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
				status = "You loose !";
				beep.SoundLoose();

				switches.PlayerComputer = 1;
				winGame = true;
				player1.CounterLoss();
				gameStatus(true);

				file.writeHsOutput(switches.overFifty);
				file.statsFromFile();
			}

		}

		startTime = SDL_GetTicks();
	}

	if (((stimer - startTime) < 500) || (switches.rulesSwitch == 1)
			|| (switches.infoSwitch == 1))
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

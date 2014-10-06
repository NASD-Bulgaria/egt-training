/*
 * RouletteApplication.cpp
 *
 *  Created on: Sep 22, 2014
 *      Author: NandM
 */

#include "RouletteApplication.h"

namespace GameObjects {

RouletteApplication::RouletteApplication(RouletteWheel* wheel, GameBoard* board, Player* player) {
//	this->board = new GameBoard();
//	this->wheel = new RouletteWheel();
//	this->player = new Player(1000);
	this->wheel = wheel;
	this->board = board;
	this->player = player;
}

RouletteApplication::~RouletteApplication() {
	if (board) {
		board->free();
	}
	for (int i = 0; i < 3; ++i) {
		infoFields[i].free();
	}
	for (unsigned int i = 0; i < infoButtons.size(); ++i) {
		infoButtons[i].free();
	}
}

void RouletteApplication::loadMedia() {
}

void RouletteApplication::init(SDL_Renderer * gRenderer) {
	initInfoButtons(gRenderer);
	initInfoFields(gRenderer);
}

void RouletteApplication::handleMouseEvent(SDL_MouseButtonEvent e, SDL_Renderer* gRenderer) {
	if (e.state == SDL_PRESSED && board->isClicked(e.x, e.y)) {
		if (e.button == SDL_BUTTON_LEFT) {
			handleBetCreation(e.x,e.y, gRenderer);
		} else if (e.button == SDL_BUTTON_RIGHT) {
			handleBetDeletion(e.x,e.y, gRenderer);
		}
	}
}

void RouletteApplication::changeInfoValues(SDL_Renderer* gRenderer) {
	stringstream ss;
	int value = 0;
	for (int i = 0; i < 3; ++i) {
		value = i == 0 ? board->collectWinings() :
				i == 1? player->getTotalBet() : player->getBalance();
		ss << value;
		infoFields[i].setRenderedText(gRenderer, ss.str());
		infoFields[i].setTextRectY(infoFields[i].getY() + infoFields[i].getHeight() / 2);
		ss.str("");
	}
	ss.clear();
}

void RouletteApplication::handleBetCreation(int x, int y, SDL_Renderer* gRenderer) {
	stringstream ss;
	for (unsigned int i = 0; i < board->allSectors.size(); ++i) {
		if (board->allSectors[i]->isClicked(x, y)) {
			if (board->allSectors[i]->bet) {
				if (player->getTotalBet() + player->BET_AMOUNT <= player->getBalance()){
					board->allSectors[i]->bet->increaseCredits(player->BET_AMOUNT);
					player->increaseBet();
					ss << board->allSectors[i]->bet->getCredits();
					board->allSectors[i]->bet->setRenderedText(gRenderer,ss.str(),22,0,0,0);
					ss.str("");
				}
			} else {
				if (i >= board-> ROULETTESIZE) {
					board->allSectors[i]->placeBet(player->createNormalBet());
				} else {
					board->allSectors[i]->placeBet(player->createNumberBet());
				}
				if (board->allSectors[i]->bet) {
					board->allSectors[i]->bet->loadFromFile(gRenderer,
							"Roulette/chip_on_table.png");
				}
			}
			break;
		}
	}
	ss.clear();
}

void RouletteApplication::handleBetDeletion(int x, int y, SDL_Renderer* gRenderer) {
	stringstream ss;
	for (unsigned int i = 0; i < board->allSectors.size(); ++i) {
		if (board->allSectors[i]->isClicked(x, y)) {
			if (board->allSectors[i]->bet) {
				if (board->allSectors[i]->bet->decreaseCredits(player->BET_AMOUNT)) {
					ss<< board->allSectors[i]->bet->getCredits();
					board->allSectors[i]->bet->setRenderedText(gRenderer,ss.str(),22,0,0,0);
					ss.str("");
					player->decreaseBet();
					if (board->allSectors[i]->bet->getCredits() < player->BET_AMOUNT) {
						board->allSectors[i]->bet->free();
						delete board->allSectors[i]->bet;
						board->allSectors[i]->bet = NULL;
					}
				}
			}
			break;
		}
	}
	ss.clear();
}

void RouletteApplication::initInfoButtons(SDL_Renderer* gRenderer) {
	for (int i = 0; i < 5; ++i) {
		infoButtons.push_back(IRendable());
	}
	infoButtons[0].loadFromFile(gRenderer, "Roulette/music.png");
	infoButtons[1].loadFromFile(gRenderer, "Roulette/fx.png");
	infoButtons[2].loadFromFile(gRenderer, "Roulette/stat.png");
	infoButtons[3].loadFromFile(gRenderer, "Roulette/info.png");
	infoButtons[4].loadFromFile(gRenderer, "Roulette/about.png");
	int y = 35;
	for (int i = 0; i < 5; ++i) {
		infoButtons[i].setPosition(1112, y);
		y += 55;
	}
}

void RouletteApplication::intiRouletteButtons(SDL_Renderer* gRenderer) {
	for (int i = 0; i < 2; ++i) {
		infoButtons.push_back(IRendable());
	}
	rouletteButtons[0].loadFromFile(gRenderer,"Roulette/clear_button.png");
	rouletteButtons[1].loadFromFile(gRenderer,"Roulette/spin_button.png");
	int x = 440;
	for (int i = 0; i < 2; ++i) {
		rouletteButtons[i].setPosition(x, 396);
		x += 600;
	}
}

void RouletteApplication::initInfoFields(SDL_Renderer* gRenderer) {
	for (int i = 0; i < 3; ++i) {
		infoFields.push_back(IRendable());
	}
	infoFields[0].loadFromFile(gRenderer, "Roulette/winning_amount.png");
	infoFields[1].loadFromFile(gRenderer, "Roulette/total_bet.png");
	infoFields[2].loadFromFile(gRenderer, "Roulette/balance_amount.png");
	int x = 560;
	stringstream ss;
	for (int i = 0; i < 3; ++i) {
		infoFields[i].setPosition(x, 395);
		if (i == 2) {
			ss << player->getBalance();
			infoFields[i].setRenderedText(gRenderer,ss.str());
			ss.str("");
			ss.clear();
		} else {
			infoFields[i].setRenderedText(gRenderer,"0");
		}
		infoFields[i].setTextRectY(infoFields[i].getY() + infoFields[i].getHeight() / 2);
		x += 160;
	}
}

}

/*
 * RouletteApplication.cpp
 *
 *  Created on: Sep 22, 2014
 *      Author: NandM
 */

#include "RouletteApplication.h"

namespace GameObjects {

RouletteApplication::RouletteApplication(GameBoard* board, Player* player,
		RouletteWheel* wheel, IRendable* bet, IRendable* win,
		IRendable* balance) {
	this->board = board;
	this->wheel = wheel;
	this->player = player;
	this->infoFields[0] = bet;
	this->infoFields[1] = win;
	this->infoFields[2] = balance;
}

RouletteApplication::~RouletteApplication() {
	if (board != NULL) {
		board->free();
	}
	if (player->colorBet) {
		player->colorBet->free();
	}
	if (player->halfBet) {
		player->halfBet->free();
	}
	if (player->typeBet) {
		player->typeBet->free();
	}
	if (player->numberBet) {
		player->numberBet->free();
	}
	for (int i = 0; i < 3; ++i) {
		if (infoFields[i]) {
			infoFields[i]->free();
		}
	}
}

void RouletteApplication::loadMedia() {
}

void RouletteApplication::init() {
}

void RouletteApplication::handleBetCreation(int mouseX, int mouseY) {
	int clickedNum = -1;
	NumberSector * numSector = NULL;
	TypeSector * typeSector = NULL;
	ColorSector * colorSector = NULL;
	HalfSector * halfSector = NULL;
	if (board->isClicked(mouseX, mouseY)) {
		numSector = board->getClickedSector(mouseX, mouseY);
		typeSector = board->getClickedTypeSector(mouseX, mouseY);
		colorSector = board->getClickedColorSector(mouseX, mouseY);
		halfSector = board->getClickedHalfSector(mouseX, mouseY);
		if (numSector != NULL) {
			clickedNum = numSector->getNumber();
			if (numSector->numberBet == NULL) {
				board->placeNumberBet(*player->createNumberBet(clickedNum, 5));
			} else {
				player->totalBet -= numSector->numberBet->getCredits();
				player->addToBalance(numSector->numberBet->getCredits());
				numSector->numberBet = NULL;
			}
		} else if (typeSector != NULL) {
			if (typeSector->typeBet == NULL) {
				board->placeTypeBet(
						*player->createTypeBet(typeSector->getType(), 5));
			} else {
				player->totalBet -= typeSector->typeBet->getCredits();
				player->addToBalance(typeSector->typeBet->getCredits());
				typeSector->typeBet = NULL;
			}
		} else if (colorSector != NULL) {
			if (colorSector->colorBet == NULL) {
				board->placeColorBet(
						*player->createColorBet(colorSector->getColor(), 5));
			} else {
				player->totalBet -= colorSector->colorBet->getCredits();
				player->addToBalance(colorSector->colorBet->getCredits());
				colorSector->colorBet = NULL;
			}
		} else if (halfSector != NULL) {
			if (halfSector->halfBet == NULL) {
				board->placeHalfBet(
						*player->createHalfBet(halfSector->getHalf(), 5));
			} else {
				player->totalBet -= halfSector->halfBet->getCredits();
				player->addToBalance(halfSector->halfBet->getCredits());
				halfSector->halfBet = NULL;
			}
		}
	}
	numSector = NULL;
	typeSector = NULL;
	halfSector = NULL;
	colorSector = NULL;
}

void RouletteApplication::changeInfoValues(SDL_Renderer* gRenderer) {
	stringstream ss;
	int value = 0;
	for (int i = 0; i < 3; ++i) {
		if (i == 0) {
			value = player->getTotalBet();
		} else if (i == 1) {
			value = board->collectWinings();
		} else {
			value = player->getBalance();
		}
		ss << value;
		infoFields[i]->setRenderedText(gRenderer, ss.str());
		infoFields[i]->setTextRectSize(
				infoFields[i]->getX()
				+ (infoFields[i]->getWidth() - ss.str().length() * 10) / 2,
				infoFields[i]->getY() + infoFields[i]->getHeight() / 2,
				ss.str().length() * 10, 20);
		ss.str("");
		infoFields[i]->draw(gRenderer);
	}
}

}

/*
 * RouletteApplication.cpp
 *
 *  Created on: Sep 22, 2014
 *      Author: NandM
 */

#include "RouletteApplication.h"

namespace GameObjects {

RouletteApplication::RouletteApplication(GameBoard* board, Player* player, RouletteWheel* wheel) {
	this->board = board;
	this->wheel = wheel;
	this->player = player;
}

RouletteApplication::~RouletteApplication() {
	if (board != NULL) {
		board->free();
	}
	delete board;
	delete wheel;
	delete player;
	board = NULL;
	wheel = NULL;
	player = NULL;
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
				board->placeNumberBet(
						*player->createNumberBet(clickedNum, 5));
			} else {
				player->addToBalance(numSector->numberBet->getCredits());
				numSector->numberBet = NULL;
			}
		} else if (typeSector != NULL) {
			if (typeSector->typeBet == NULL) {
				board->placeTypeBet(
						*player->createTypeBet(typeSector->getType(), 5));
			} else {
				player->addToBalance(typeSector->typeBet->getCredits());
				typeSector->typeBet = NULL;
			}
		} else if (colorSector->isClicked(mouseX, mouseY)) {
			if (colorSector->colorBet == NULL) {
				board->placeColorBet(
						*player->createColorBet(colorSector->getColor(), 5));
			} else {
				player->addToBalance(colorSector->colorBet->getCredits());
				colorSector->colorBet = NULL;
			}
		} else if (halfSector->isClicked(mouseX, mouseY)) {
			if (halfSector->halfBet == NULL) {
				board->placeHalfBet(
						*player->createHalfBet(halfSector->getHalf(), 5));
			} else {
				player->addToBalance(halfSector->halfBet->getCredits());
				halfSector->halfBet = NULL;
			}
		}
	}
}

} /* namespace GameObjects */

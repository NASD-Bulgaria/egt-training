/*
 * GameBoard.cpp
 *
 *  Created on: Sep 16, 2014
 *      Author: NandM
 */

#include "GameBoard.h"

namespace GameObjects {

GameBoard::GameBoard() {
	typeSectors[0] = new TypeSector(OddType);
	typeSectors[1] = new TypeSector(EvenType);
	halfSectors[0] = new HalfSector(LowHalf);
	halfSectors[1] = new HalfSector(HighHalf);
	colorSectors[0] = new ColorSector(BlackColor);
	colorSectors[1] = new ColorSector(RedColor);
	allBetValue = 0;
	this->setX(456);
	this->setY(58);
	initNumberSectors();
}

GameBoard::~GameBoard() {
	free();
	delete typeSectors[0];
	delete typeSectors[1];
	delete halfSectors[0];
	delete halfSectors[1];
	delete colorSectors[0];
	delete colorSectors[1];
	for (unsigned int i = 0; i < numberSectors.size(); ++i) {
		delete numberSectors[i];
	}
}

const std::vector<NumberSector*>& GameBoard::getNumberSectors() const {
	return numberSectors;
}

void GameBoard::placeHalfBet(HalfBet& halfBet) {
	for (int i = 0; i < 2; ++i) {
		if(halfSectors[i]->getHalf() == halfBet.getHalf()){
			halfSectors[i]->placeHalfBet(&halfBet);
		}
	}
	for (unsigned int i = 0; i < numberSectors.size(); ++i) {
		if (halfBet.getHalf() == numberSectors[i]->getHalf()) {
			numberSectors[i]->placeHalfBet(&halfBet);
		}
	}
	allBetValue += halfBet.getCredits();
}

void GameBoard::placeTypeBet(TypeBet& typeBet) {
	for (int i = 0; i < 2; ++i) {
		if(typeSectors[i]->getType() == typeBet.getType()){
			typeSectors[i]->placeTypeBet(&typeBet);
		}
	}
	for (unsigned int i = 0; i < numberSectors.size(); ++i) {
		if (typeBet.getType() == numberSectors[i]->getType()) {
			numberSectors[i]->placeTypeBet(&typeBet);
		}
	}
	allBetValue += typeBet.getCredits();
}

void GameBoard::placeNumberBet(NumberBet& numberBet) {
	numberSectors[numberBet.getNumber()]->placeNumberBet(&numberBet);
	allBetValue += numberBet.getCredits();
}

void GameBoard::placeColorBet(ColorBet& colorBet) {
	for (int i = 0; i < 2; ++i) {
		if(colorSectors[i]->getColor() == colorBet.getColor()){
			colorSectors[i]->placeColorBet(&colorBet);
		}
	}
	for (unsigned int i = 0; i < numberSectors.size(); ++i) {
		if (colorBet.getColor() == numberSectors[i]->getColor()) {
			numberSectors[i]->placeColorBet(&colorBet);
		}
	}
	allBetValue += colorBet.getCredits();
}

void GameBoard::clearAllBets() {
	halfSectors[0]->halfBet = NULL;
	halfSectors[1]->halfBet = NULL;
	colorSectors[0]->colorBet = NULL;
	colorSectors[1]->colorBet = NULL;
	typeSectors[0]->typeBet = NULL;
	typeSectors[1]->typeBet = NULL;
	for (unsigned int i = 0; i < numberSectors.size(); ++i) {
		numberSectors[i]->numberBet = NULL;
		numberSectors[i]->colorBet = NULL;
		numberSectors[i]->typeBet = NULL;
		numberSectors[i]->halfBet = NULL;
	}
	allBetValue = 0;
}

int GameBoard::collectWinings() {
	int winings = 0;
	if (winingNumberSector->colorBet) {
		winings += winingNumberSector->colorBet->getCredits()
				* winingNumberSector->colorBet->getCoef();
	}
	if (winingNumberSector->halfBet) {
		winings += winingNumberSector->halfBet->getCredits()
				* winingNumberSector->halfBet->getCoef();
	}
	if (winingNumberSector->typeBet) {
		winings += winingNumberSector->typeBet->getCredits()
				* winingNumberSector->typeBet->getCoef();
	}
	if (winingNumberSector->numberBet) {
		winings += winingNumberSector->numberBet->getCredits()
				* winingNumberSector->numberBet->getCoef();
	}
	return winings;
}

int GameBoard::getAllBetValue() const {
	return allBetValue;
}

NumberSector* GameBoard::getWiningNumberSector() const {
	return winingNumberSector;
}

void GameBoard::setWiningNumberSector(short winingNumber) {
	this->winingNumberSector = numberSectors[winingNumber];
}

void GameBoard::draw(SDL_Renderer* gRenderer) {
	IRendable::draw(gRenderer);
	for (unsigned int i = 0; i < numberSectors.size(); ++i) {
		numberSectors[i]->draw(gRenderer);
	}
	typeSectors[0]->draw(gRenderer);
	typeSectors[1]->draw(gRenderer);
	colorSectors[0]->draw(gRenderer);
	colorSectors[1]->draw(gRenderer);
	halfSectors[0]->draw(gRenderer);
	halfSectors[1]->draw(gRenderer);
}

bool GameBoard::loadFromFile(SDL_Renderer* gRenderer, std::string path) {
	bool success = true;
	for (unsigned int i = 0; i < numberSectors.size(); ++i) {
		if (numberSectors[i]->getColor() == RedColor) {
			if (numberSectors[i]->loadFromFile(gRenderer,
					"Roulette/NumberRedSector.png")) {
				success = false;
			}
		} else if (numberSectors[i]->getColor() == BlackColor) {
			if (numberSectors[i]->loadFromFile(gRenderer,
					"Roulette/NumberBlackSector.png")) {
				success = false;
			}
		} else {
			if (numberSectors[i]->loadFromFile(gRenderer,
					"Roulette/ZeroSector.png")) {
				success = false;
			}
		}
	}
	success = colorSectors[0]->loadFromFile(gRenderer,
			"Roulette/BigBlackSector.png");
	success = colorSectors[1]->loadFromFile(gRenderer, "Roulette/BigRedSector.png");
	success = typeSectors[0]->loadFromFile(gRenderer, "Roulette/BigGreenSector.png");
	success = typeSectors[1]->loadFromFile(gRenderer,
			"Roulette/BigGreenSector.png");
	success = halfSectors[0]->loadFromFile(gRenderer, "Roulette/BigGreenSector.png");
	success = halfSectors[1]->loadFromFile(gRenderer,
			"Roulette/BigGreenSector.png");
	return (IRendable::loadFromFile(gRenderer, path) && success);
}

NumberSector* GameBoard::getClickedSector(int x, int y) {
	for (unsigned int i = 0; i < numberSectors.size(); ++i) {
		if (numberSectors[i]->isClicked(x, y)) {
			return numberSectors[i];
		}
	}
	return NULL;
}

void GameBoard::free() {
	for (unsigned int i = 0; i < numberSectors.size(); ++i) {
		numberSectors[i]->free();
	}
	this->colorSectors[0]->free();
	this->colorSectors[1]->free();
	this->typeSectors[0]->free();
	this->typeSectors[1]->free();
	this->halfSectors[0]->free();
	this->halfSectors[1]->free();
	IRendable::free();
}

TypeSector* GameBoard::getClickedTypeSector(int x, int y) {
	for (int i = 0; i < 2; ++i) {
		if (typeSectors[i]->isClicked(x, y)) {
			return typeSectors[i];
		}
	}
	return NULL;
}

HalfSector* GameBoard::getClickedHalfSector(int x, int y) {
	for (int i = 0; i < 2; ++i) {
		if (halfSectors[i]->isClicked(x, y)) {
			return halfSectors[i];
		}
	}
	return NULL;
}

ColorSector* GameBoard::getClickedColorSector(int x, int y) {
	for (int i = 0; i < 2; ++i) {
		if (colorSectors[i]->isClicked(x, y)) {
			return colorSectors[i];
		}
	}
	return NULL;
}

void GameBoard::initNumberSectors() {
	Type type;
	Half half;
	this->numberSectors.push_back(
			new NumberSector(0, NoneColor, NoneType, NoneHalf));
	for (int i = 1; i < ROULETTESIZE; ++i) {
		type = i % 2 == 0 ? EvenType : OddType;
		half = i < LowHalf ? LowHalf : HighHalf;
		this->numberSectors.push_back(
				new NumberSector(i, rouletteSectorColors[i], type, half));

	}
}

const Color GameBoard::rouletteSectorColors[ROULETTESIZE] = { NoneColor,
		RedColor, BlackColor, RedColor, BlackColor, RedColor, BlackColor,
		RedColor, BlackColor, RedColor, BlackColor, BlackColor, RedColor,
		BlackColor, RedColor, BlackColor, RedColor, BlackColor, RedColor,
		RedColor, BlackColor, RedColor, BlackColor, RedColor, BlackColor,
		RedColor, BlackColor, RedColor, BlackColor, BlackColor, RedColor,
		BlackColor, RedColor, BlackColor, RedColor, BlackColor, RedColor };

} /* namespace GameObjects */

void GameObjects::GameBoard::initSectorPositions() {
	int x = this->getX();
	int y = this->getY();
	int counter = 0;
	numberSectors[0]->setX(x);
	numberSectors[0]->setY(y);
	numberSectors[0]->textRect.y = y + 75;
	numberSectors[0]->textRect.x = x + 15;
	for (unsigned int i = 1; i < numberSectors.size(); ++i) {
		if (counter % 3 == 0) {
			x += numberSectors[i - 1]->getWidth();
			counter = 0;
		}
		y = numberSectors[0]->getY() + numberSectors[0]->getHeight()
				- ((counter + 1) * numberSectors[0]->getHeight() / 3);
		numberSectors[i]->setX(x);
		numberSectors[i]->setY(y);
		numberSectors[i]->textRect.x = x + 15;
		numberSectors[i]->textRect.y = y + 17;
		counter++;
	}
	halfSectors[0]->setX(this->getX() + numberSectors[0]->getWidth());
	halfSectors[0]->setY(this->getY() + numberSectors[0]->getHeight());
	typeSectors[1]->setX(halfSectors[0]->getX() + halfSectors[0]->getWidth());
	typeSectors[1]->setY(halfSectors[0]->getY());
	colorSectors[1]->setX(typeSectors[1]->getX() + typeSectors[1]->getWidth());
	colorSectors[1]->setY(halfSectors[0]->getY());
	colorSectors[0]->setX(colorSectors[1]->getX() + colorSectors[1]->getWidth());
	colorSectors[0]->setY(halfSectors[0]->getY());
	typeSectors[0]->setX(colorSectors[0]->getX() + colorSectors[0]->getWidth());
	typeSectors[0]->setY(halfSectors[0]->getY());
	halfSectors[1]->setX(typeSectors[0]->getX() + typeSectors[0]->getWidth());
	halfSectors[1]->setY(halfSectors[0]->getY());
}

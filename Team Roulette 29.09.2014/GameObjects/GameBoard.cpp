/*
 * GameBoard.cpp
 *
 *  Created on: Sep 16, 2014
 *      Author: NandM
 */

#include "GameBoard.h"

namespace GameObjects {

GameBoard::GameBoard() {
	oddSector = new TypeSector(OddType);
	evenSector = new TypeSector(EvenType);
	lowSector = new HalfSector(LowHalf);
	highSector = new HalfSector(HighHalf);
	blackSector = new ColorSector(BlackColor);
	redSector = new ColorSector(RedColor);
	allBetValue = 0;
	this->setX(458);
	this->setY(58);
	initNumberSectors();
}

GameBoard::~GameBoard() {
	// TODO Auto-generated destructor stub
}

const ColorSector* GameBoard::getBlackSector() const {
	return blackSector;
}

const TypeSector* GameBoard::getEvenSector() const {
	return evenSector;
}

const HalfSector* GameBoard::getHighSector() const {
	return highSector;
}

const HalfSector* GameBoard::getLowSector() const {
	return lowSector;
}

const std::vector<NumberSector*>& GameBoard::getNumberSectors() const {
	return numberSectors;
}

const TypeSector* GameBoard::getOddSector() const {
	return oddSector;
}

const ColorSector* GameBoard::getRedSector() const {
	return redSector;
}

void GameBoard::placeHalfBet(HalfBet& halfBet) {
	for (unsigned int i = 0; i < numberSectors.size(); ++i) {
		if (halfBet.getHalf() == numberSectors[i]->getHalf()) {
			numberSectors[i]->placeHalfBet(&halfBet);
		}
	}
	allBetValue += halfBet.getCredits();
}

void GameBoard::placeTypeBet(TypeBet& typeBet) {
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
	for (unsigned int i = 0; i < numberSectors.size(); ++i) {
		if (colorBet.getColor() == numberSectors[i]->getColor()) {
			numberSectors[i]->placeColorBet(&colorBet);
		}
	}
	allBetValue += colorBet.getCredits();
}

void GameBoard::clearAllBets() {
	for (unsigned int i = 0; i < numberSectors.size(); ++i) {
		if (numberSectors[i]->colorBet) {
			delete numberSectors[i]->colorBet;
			numberSectors[i]->colorBet = 0;
		}
		if (numberSectors[i]->halfBet) {
			delete numberSectors[i]->halfBet;
			numberSectors[i]->halfBet = 0;
		}
		if (numberSectors[i]->typeBet) {
			delete numberSectors[i]->typeBet;
			numberSectors[i]->typeBet = 0;
		}
		if (numberSectors[i]->numberBet) {
			delete numberSectors[i]->numberBet;
			numberSectors[i]->numberBet = 0;
		}
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
		if (numberSectors[i]->numberBet != NULL) {
			numberSectors[i]->numberBet->loadFromFile(gRenderer, "Roulette/chip_on_table.png");
			numberSectors[i]->numberBet->setX(numberSectors[i]->getX() +
					(numberSectors[i]->getWidth() -
					numberSectors[i]->numberBet->getWidth()) / 2);
			numberSectors[i]->numberBet->setY(numberSectors[i]->getY()+
					(numberSectors[i]->getHeight() -
					numberSectors[i]->numberBet->getHeight()) / 2);
			numberSectors[i]->numberBet->draw(gRenderer);
		}
	}
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
	return (IRendable::loadFromFile(gRenderer,path) && success);
}

short GameBoard::getClickedSectorValue(int x, int y) {
	for (unsigned int i = 0; i < numberSectors.size(); ++i) {
		if (numberSectors[i]->isClicked(x , y)) {
			return numberSectors[i]->getNumber();
		}
	}
	return -1;
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
	for (unsigned int i = 1; i < numberSectors.size(); ++i) {
		if (counter % 3 == 0) {
			x += numberSectors[i - 1]->getWidth();
			counter = 0;
		}
		y = numberSectors[0]->getY() + numberSectors[0]->getHeight()
				- ((counter + 1) * numberSectors[0]->getHeight() / 3);
		numberSectors[i]->setX(x);
		numberSectors[i]->setY(y);
		counter++;
	}
}

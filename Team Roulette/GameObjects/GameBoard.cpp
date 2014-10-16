/*
 * GameBoard.cpp
 *
 *  Created on: Sep 16, 2014
 *      Author: NandM
 */

#include "GameBoard.h"

namespace GameObjects {

GameBoard::GameBoard(int x, int y)
	:IRendable(x,y){
	initNumberSectors();
	initBetSectors();
	winingNumberSector = NULL;
}

GameBoard::~GameBoard() {
	this->free();
	for (unsigned int i = 0; i < allSectors.size(); ++i) {
		if (allSectors[i]) {
			delete allSectors[i];
			allSectors[i] = NULL;
		}
	}
	if (winingNumberSector) {
		winingNumberSector->free();
		delete winingNumberSector;
		winingNumberSector = NULL;
	}
}

const std::vector<NumberSector*>& GameBoard::getNumberSectors() const {
	return numberSectors;
}

void GameBoard::clearAllBets() {
	for (unsigned int i = 0; i < allSectors.size(); ++i) {
		if (allSectors[i]->bet) {
			allSectors[i]->bet->free();
			delete allSectors[i]->bet;
			allSectors[i]->bet = NULL;
		}
	}
}

int GameBoard::collectWinings() {
	int winings = 0;
	if (winingNumberSector) {
		vector<ColorSector*> colorSectors = getColorSectors();
		vector<TypeSector*> typeSectors = getTypeSectors();
		vector<HalfSector*> halfSectors = getHalfSectors();
		for (unsigned int i = 0; i < colorSectors.size(); ++i) {
			if (colorSectors[i]->bet &&
					colorSectors[i]->getColor() == winingNumberSector->getColor()) {
				winings += (colorSectors[i]->bet->getCredits()
						* colorSectors[i]->bet->getCoef());
			}
			if (typeSectors[i]->bet &&
					typeSectors[i]->getType() == winingNumberSector->getType()) {
				winings += (typeSectors[i]->bet->getCredits()
						* typeSectors[i]->bet->getCoef());
			}
			if (halfSectors[i]->bet &&
					halfSectors[i]->getHalf() == winingNumberSector->getHalf()) {
				winings += (halfSectors[i]->bet->getCredits()
						* halfSectors[i]->bet->getCoef());
			}
			halfSectors[i] = NULL;
			colorSectors[i] = NULL;
			typeSectors[i] = NULL;
		}
		if (winingNumberSector->bet) {
			winings += (winingNumberSector->bet->getCredits()
					* winingNumberSector->bet->getCoef());
		}
	}
	return winings;
}

NumberSector* GameBoard::getWiningNumberSector() const {
	return winingNumberSector;
}

void GameBoard::setWiningNumberSector(short winingNumber) {
	if (winingNumber >= 0 && winingNumber <= 36) {
		this->winingNumberSector = numberSectors[winingNumber];
	} else {
		this->winingNumberSector = NULL;
	}
}

void GameBoard::draw(SDL_Renderer* gRenderer) {
	IRendable::draw(gRenderer);
	for (unsigned int i = 0; i < allSectors.size(); ++i) {
		allSectors[i]->draw(gRenderer);
	}
}

bool GameBoard::loadFromFile(SDL_Renderer* gRenderer, std::string path) {
	bool success = true;
	string sectorPath;
	for (unsigned int i = 0; i < numberSectors.size(); ++i) {
		sectorPath = numberSectors[i]->getColor() == NoneColor ? "Roulette/ZeroSector.png" :
				(numberSectors[i]->getColor() == BlackColor ?
								"Roulette/NumberBlackSector.png" : "Roulette/NumberRedSector.png");
		numberSectors[i]->loadFromFile(gRenderer, sectorPath);
	}
	for (unsigned int i = 0; i < betSectors.size(); ++i) {
		if (i == 3) {
			sectorPath = "Roulette/BigBlackSector.png";
		} else if (i == 2){
			sectorPath = "Roulette/BigRedSector.png";
		} else {
			sectorPath = "Roulette/BigGreenSector.png";
		}
		betSectors[i]->loadFromFile(gRenderer, sectorPath);
	}
	return (IRendable::loadFromFile(gRenderer, path) && success);
}

void GameBoard::free() {
	for (unsigned int i = 0; i < allSectors.size(); ++i) {
		allSectors[i]->free();
	}
	IRendable::free();
}

bool GameBoard::anyBetPlaced() {
	for (unsigned int i = 0; i < allSectors.size(); ++i) {
		if (allSectors[i]->bet) {
			return true;
		}
	}
	return false;
}

vector<TypeSector*> GameBoard::getTypeSectors() {
	vector<TypeSector*> typeSectors;
	typeSectors.push_back(dynamic_cast<TypeSector*>(betSectors[1]));
	typeSectors.push_back(dynamic_cast<TypeSector*>(betSectors[4]));
	return typeSectors;
}

vector<HalfSector*> GameBoard::getHalfSectors() {
	vector<HalfSector*> halfSectors;
	halfSectors.push_back(dynamic_cast<HalfSector*>(betSectors[0]));
	halfSectors.push_back(dynamic_cast<HalfSector*>(betSectors[5]));
	return halfSectors;
}

vector<ColorSector*> GameBoard::getColorSectors() {
	vector<ColorSector*> colorSectors;
	colorSectors.push_back(dynamic_cast<ColorSector*>(betSectors[2]));
	colorSectors.push_back(dynamic_cast<ColorSector*>(betSectors[3]));
	return colorSectors;
}

void GameBoard::initNumberSectors() {
	Type type;
	Half half;
	this->numberSectors.push_back(
			new NumberSector(0, NoneColor, NoneType, NoneHalf));
	allSectors.push_back(numberSectors[0]);
	for (int i = 1; i < ROULETTESIZE; ++i) {
		type = i % 2 == 0 ? EvenType : OddType;
		half = i < LowHalf ? LowHalf : HighHalf;
		this->numberSectors.push_back(
				new NumberSector(i, rouletteSectorColors[i], type, half));
		allSectors.push_back(numberSectors[i]);
	}
}

const Color GameBoard::rouletteSectorColors[ROULETTESIZE] = { NoneColor,
		RedColor, BlackColor, RedColor, BlackColor, RedColor, BlackColor,
		RedColor, BlackColor, RedColor, BlackColor, BlackColor, RedColor,
		BlackColor, RedColor, BlackColor, RedColor, BlackColor, RedColor,
		RedColor, BlackColor, RedColor, BlackColor, RedColor, BlackColor,
		RedColor, BlackColor, RedColor, BlackColor, BlackColor, RedColor,
		BlackColor, RedColor, BlackColor, RedColor, BlackColor, RedColor };

void GameBoard::setPosition(int x, int y) {
	IRendable::setPosition(x, y);
	int counter = 0;
	numberSectors[0]->setPosition(x, y);
	for (unsigned int i = 1; i < numberSectors.size(); ++i) {
		if (counter % 3 == 0) {
			x += numberSectors[i - 1]->getWidth();
			counter = 0;
		}
		y = numberSectors[0]->getY() + numberSectors[0]->getHeight()
				- ((counter + 1) * numberSectors[0]->getHeight() / 3);
		numberSectors[i]->setPosition(x, y);
		counter++;
	}
	betSectors[0]->setPosition(numberSectors[0]->getX() + numberSectors[0]->getWidth(),
			numberSectors[0]->getY() + numberSectors[0]->getHeight());
	for (unsigned int i = 1; i < betSectors.size(); ++i) {
		betSectors[i]->setPosition(betSectors[i - 1]->getX() + betSectors[i - 1]->getWidth(),
				betSectors[i - 1]->getY());
	}
}

void GameBoard::initBetSectors() {
	betSectors.push_back(new HalfSector(LowHalf));
	betSectors.push_back(new TypeSector(EvenType));
	betSectors.push_back(new ColorSector(RedColor));
	betSectors.push_back(new ColorSector(BlackColor));
	betSectors.push_back(new TypeSector(OddType));
	betSectors.push_back(new HalfSector(HighHalf));
	for (unsigned int i = 0; i < betSectors.size(); ++i) {
		allSectors.push_back(betSectors[i]);
	}
}

} /* namespace GameObjects */

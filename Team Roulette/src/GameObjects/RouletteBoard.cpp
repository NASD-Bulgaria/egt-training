/*
 * RouletteBoard.cpp
 *
 *  Created on: Oct 7, 2014
 *      Author: NandM
 */

#include "RouletteBoard.h"

namespace GameObjects {

RouletteBoard::RouletteBoard(int x, int y)
	:IRendable(x,y){
	wheel = new RouletteWheel(x, y);
	ball = new Ball();
	initNumberDegrees();
	currentNumberIndex = -1;
}

bool RouletteBoard::loadFromFile(SDL_Renderer* gRenderer, std::string path) {
	bool success = IRendable::loadFromFile(gRenderer, path);
	success &= wheel->loadFromFile(gRenderer, "Roulette/wheel.png");
	success &= ball->loadFromFile(gRenderer,"Roulette/ball.png");
	ball->initBall(wheel->getXCenter(), wheel->getYCenter(),
			this->getRadius(), wheel->getRadius() - 40);
	setPosition(getX(), getY());
	return success;
}

short RouletteBoard::getWininngNumber() {
	if (currentNumberIndex != - 1) {
		return (short)numbersDegrees[currentNumberIndex][0];
	} else {
		return currentNumberIndex;
	}
}

void RouletteBoard::draw(SDL_Renderer* gRenderer) {
	IRendable::draw(gRenderer);
	wheel->draw(gRenderer);
	ball->draw(gRenderer);
}

void RouletteBoard::initRouletteBoard() {
	wheel->initiate();
	ball->initBall(wheel->getXCenter(), wheel->getYCenter(),
			this->getRadius(), wheel->getRadius() - 40);
	currentNumberIndex = -1;
}

int RouletteBoard::getRadius() {
	return getWidth() / 2;
}

void RouletteBoard::setPosition(int x, int y) {
	rect.x = x;
	rect.y = y;
	wheel->setPosition(x + getRadius() - wheel->getRadius(),
			y + getRadius() - wheel->getRadius());
	ball->setPosition(x, y);
}

RouletteBoard::~RouletteBoard() {
	this->free();
	delete wheel;
	delete ball;
	ball = NULL;
	wheel = NULL;
}

double RouletteBoard::numbersDegrees[37][3] = { { 20, 360.0 - 180.0 / 37, 180.0 / 37}, { 1, 0, 0},
		{ 33, 0, 0}, { 16, 0, 0}, { 24, 0, 0}, { 5, 0, 0}, { 10, 0, 0}, { 23, 0, 0},
		{ 8, 0, 0}, { 30, 0, 0}, { 11, 0, 0}, { 36, 0, 0}, { 13, 0, 0}, { 27, 0, 0},
		{ 6, 0, 0}, { 34, 0, 0}, { 17, 0, 0}, { 25, 0, 0}, { 2, 0, 0}, { 21, 0, 0},
		{ 4, 0, 0}, { 19, 0, 0}, { 15, 0, 0}, { 32, 0, 0}, { 0, 0, 0}, { 26, 0, 0},
		{ 3, 0, 0}, { 35, 0, 0}, { 12, 0, 0}, { 28, 0, 0}, { 7, 0, 0}, { 29, 0, 0},
		{ 18, 0, 0}, { 22, 0, 0}, { 9, 0, 0}, { 31, 0, 0}, { 14, 0, 0} };

void RouletteBoard::handleBallInSector() {
	double ballAngle = wheel->getSpinAngle() + ball->angle * (180.0 / M_PI) - 180;
	while(ballAngle >= 360){
		ballAngle -= 360;
	}
	if (ballAngle > numbersDegrees[0][1] ||
			ballAngle <= numbersDegrees[0][2]) {
		currentNumberIndex = 0;
		ball->angle = (-180 - wheel->getSpinAngle()) / (180.0 / M_PI);
		return;
	}
	for (int i = 1; i < 37; ++i) {
		if(ballAngle > numbersDegrees[i][1] &&
				ballAngle <= numbersDegrees[i][2]) {
			currentNumberIndex = i;
			ball->angle = ((numbersDegrees[i][2] + numbersDegrees[i][1]) / 2.0
					+ 180 - wheel->getSpinAngle()) / (180.0 / M_PI);
			break;
		}
	}
}

void RouletteBoard::resetWiningNumber() {
	currentNumberIndex = -1;
}

void RouletteBoard::free() {
	ball->free();
	wheel->free();
	IRendable::free();
}

void RouletteBoard::initNumberDegrees() {
	double offset = 360.0 / 37;
	for (int i = 1; i < 37; ++i) {
		numbersDegrees[i][2] = numbersDegrees[i - 1][2] + offset;
		numbersDegrees[i][1] = numbersDegrees[i - 1][2];
	}
}

} /* namespace GameObjects */

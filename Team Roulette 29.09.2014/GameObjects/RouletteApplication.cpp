/*
 * RouletteApplication.cpp
 *
 *  Created on: Sep 22, 2014
 *      Author: NandM
 */

#include "RouletteApplication.h"

namespace GameObjects {

RouletteApplication::RouletteApplication(int initialBalance) {
	this->board = new GameBoard();
	this->wheel = new RouletteWheel();
	this->player = new Player(initialBalance);
}

RouletteApplication::~RouletteApplication() {
	delete board;
	delete wheel;
	delete player;
	board = NULL;
	wheel = NULL;
	player = NULL;
}

void RouletteApplication::init() {
}

} /* namespace GameObjects */

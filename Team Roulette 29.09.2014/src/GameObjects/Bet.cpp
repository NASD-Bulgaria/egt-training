/*
 * Bet.cpp
 *
 *  Created on: Sep 12, 2014
 *      Author: NandM
 */

#include "Bet.h"

GameObjects::Bet::Bet(int winCoef, int credits) {
	this->winCoef = winCoef;
	this->credits = credits;
}

GameObjects::Bet::~Bet() {
	free();
}

int GameObjects::Bet::getCoef() {
	return this->winCoef;
}

int GameObjects::Bet::getCredits() {
	return this->credits;
}

void GameObjects::Bet::setCredits(int credits) {
	if (credits >= 0) {
		this->credits = credits;
	}
}

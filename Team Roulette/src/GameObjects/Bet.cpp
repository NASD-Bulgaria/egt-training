/*
 * Bet.cpp
 *
 *  Created on: Sep 12, 2014
 *      Author: NandM
 */

#include "Bet.h"
namespace GameObjects {

Bet::Bet(int winCoef, int credits) {
	this->winCoef = winCoef;
	this->credits = credits;
}

Bet::~Bet() {
	free();
}

int Bet::getCoef() {
	return this->winCoef;
}

int Bet::getCredits() {
	return this->credits;
}

void Bet::setCredits(int amount) {
	if (amount >= 0) {
		this->credits = amount;
	}
}

void Bet::increaseCredits(int amount) {
	credits += amount;
}

bool Bet::loadFromFile(SDL_Renderer* gRenderer, std::string path) {
	bool success = IRendable::loadFromFile(gRenderer,path);
	stringstream ss;
	ss<< getCredits();
	setRenderedText(gRenderer, ss.str(), 22, 0, 0, 0);
	ss.str("");
	ss.clear();
	return success;
}

bool Bet::decreaseCredits(int amount) {
	if (credits - amount >= 0) {
		credits -= amount;
		return true;
	}
	return false;
}

}

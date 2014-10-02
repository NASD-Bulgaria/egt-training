/*
 * Statistics.cpp
 *
 *  Created on: 19.09.2014
 *      Author: Kameliq
 */

#include "Statistics.h"

using namespace GameObjects;

Statistics::~Statistics() {
	free();
}

Statistics::Statistics(string path, int initialAmount) :
		initialAmount(initialAmount) {
	this->path = path;
	colors[0] = "Red";
	colors[1] = "Black";
	colors[2] = "Green";
}

bool Statistics::write(short num, Color color, int totalBet, int winings,
		int currentBalance) {
	if (initiateStream()) {
		stream.setf(ios::fixed);
		stream << setw(10) << num << setw(10) << colors[color] << setw(14) << totalBet
				<< setw(14) << winings - totalBet << setw(14)
				<< setprecision(2) <<calcDeviateBet(totalBet, winings)<< '%' << setw(14)
				<< calcDeviateCapital(currentBalance) << '%'<< endl;
		stream.close();
		return true;
	}
	return false;
}

void Statistics::read(SDL_Renderer* gRenderer) {
	destroyTextures();
	string line;
	SDL_Surface * textSurface = NULL;
	TTF_Font * font = TTF_OpenFont("Roulette/luximb.ttf", 16);
	SDL_Color color = { 0xFF, 0xFF, 0xFF };
	int index = 0;
	int counter = 0;
	stringstream ss;
	if (initiateStream()) {
		while (getline(stream, line)) {
			ss <<setfill(' ') << setw(4) << counter;
			textSurface = TTF_RenderText_Solid(font, (ss.str() + line).data(),color);
			textTextures.push_back(
					SDL_CreateTextureFromSurface(gRenderer, textSurface));
			SDL_FreeSurface(textSurface);
			line.erase(0, index + 1);
			ss.str("");
			counter++;
		}
		ss<<setw(14)<<"Number"<<setw(10)<<"Color"<<setw(14)<<"Total Bet"<<setw(14)<<
				"Win/Loss" << setw(15) <<"Bet Yield" << setw(15) << "Capital Yield";
		textSurface = TTF_RenderText_Solid(font, ss.str().data(),color);
		textTextures.push_back(
				SDL_CreateTextureFromSurface(gRenderer, textSurface));
		SDL_FreeSurface(textSurface);
		stream.close();
	}
	TTF_CloseFont(font);
	font = NULL;
	textSurface = NULL;
}

bool Statistics::initiateStream() {
	if (!stream.is_open()) {
		stream.open(this->path.data(), ios::in | ios::out | ios::app);
	}
	if (!stream) {
		return false;
	}
	return true;
}

double Statistics::calcDeviateBet(int totalBet, int winings) {
	return winings / (double) totalBet * 100 - 100;
}

void Statistics::draw(SDL_Renderer* gRenderer, double angle, SDL_Point* center,
		SDL_RendererFlip flip) {
	int x = 156;
	int y = 136;
	SDL_Rect rect = { x, y, 840, 24 };
	int lowLimit = 0;
	if (textTextures.size() > 11) {
		lowLimit = textTextures.size() - 11;
	}
	IRendable::draw(gRenderer);
	for (int i = textTextures.size() - 1; i >= lowLimit; i--) {
		SDL_RenderCopy(gRenderer, textTextures[i], NULL, &rect);
		rect.y += rect.h;
	}
}

void Statistics::free() {
	destroyTextures();
	IRendable::free();
}

double Statistics::calcDeviateCapital(int currentBalance) {
	return (currentBalance / double(initialAmount) * 100) - 100;
}

void Statistics::destroyTextures() {
	for (unsigned int i = 0; i < textTextures.size(); ++i) {
		if (textTextures[i]) {
			SDL_DestroyTexture(textTextures[i]);
			textTextures[i] = NULL;
		}
		textTextures.pop_back();
	}
}

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
	string line;
	unsigned int counter = 1;
	stringstream ss;
	if (initiateStream()) {
		while (getline(stream, line)) {
			ss <<setfill(' ') << setw(4) << counter;
			if (counter > lines.size()) {
				lines.push_back(ss.str() + line);
			}
			ss.str("");
			counter++;
		}
		stream.close();
		initRenderedLines(gRenderer);
		initLast10(gRenderer);
	}
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
	IRendable::draw(gRenderer);
	for (unsigned int i = 0; i < renderedLines.size() ; i++) {
		renderedLines[i]->draw(gRenderer);
	}
}

void Statistics::free() {
	destroyRendererdLines();
	IRendable::free();
}

double Statistics::calcDeviateCapital(int currentBalance) {
	return (currentBalance / double(initialAmount) * 100) - 100;
}

void Statistics::initRenderedLines(SDL_Renderer* gRenderer) {
	int y = 136;
	stringstream ss;
	destroyRendererdLines();
	IRendable* renderedLine = new IRendable();
	ss<<setw(3)<<"Nr."<<setw(11)<<"Number"<<setw(10)<<"Color"<<setw(14)<<"Total Bet"<<setw(14)<<
			"Win/Loss" << setw(15) <<"Bet-Yield" << setw(15) << "Total-Gain";
	renderedLine->setRenderedText(gRenderer, ss.str(), 24, 253, 221, 175);
	renderedLine->setTextRectX(getX() + (getWidth() - ss.str().length()* 11)/2);
	renderedLine->setTextRectY(y);
	y += 24;
	renderedLines.push_back(renderedLine);
	ss.str("");
	ss.clear();

	int lowLimit = lines.size() > 10 ? lines.size() - 10 : 0;
	for (int i = lines.size() - 1; i >= lowLimit; i--) {
		renderedLine = new IRendable();
		renderedLine->setRenderedText(gRenderer, lines[i], 24, 253, 221, 175);
		renderedLine->setTextRectX(getX() + (getWidth() - lines[i].length()* 11) / 2);
		renderedLine->setTextRectY(y);
		y += 24;
		renderedLines.push_back(renderedLine);
		renderedLine = NULL;
	}
}

void Statistics::destroyRendererdLines() {
	while(renderedLines.size() > 0){
		renderedLines.back()->free();
		delete renderedLines.back();
		renderedLines.back() = NULL;
		renderedLines.pop_back();
	}
}

void Statistics::initLast10(SDL_Renderer * gRenderer) {
	destroyLast10();
	int lowLimit = lines.size() > 11 ? lines.size() - 11 : 0;
	int g = 0;
	IRendable* value;
	string num;
	for (int i = lines.size() - 1; i >= lowLimit; i--) {
		value = new IRendable();
		g = 5;
		while(!isdigit(lines[i][g])){
			g++;
		}
		value->loadFromFile(gRenderer,"Roulette/transparent.png");
		num = lines[i].substr(g, lines[i].find(' ', g) - g);
		if (lines[i].find("Red") != string::npos) {
			value->setRenderedText(gRenderer, num, 51, 255, 0, 0);
		} else if (lines[i].find("Black") != string::npos){
			value->setRenderedText(gRenderer, num, 51, 120, 120, 120);
		} else {
			value->setRenderedText(gRenderer, num, 51, 0, 255, 0);
		}
		last10.push_back(value);
	}
}

void Statistics::drawLast10(SDL_Renderer* gRenderer,IRendable* container) {
	container->draw(gRenderer);
	if (last10.size() > 0) {
		last10[0]->setPosition(container->getX() +
				container->getWidth() - last10[0]->getWidth(), container->getY());
		last10[0]->draw(gRenderer);
	}
	for (unsigned int i = 1; i < last10.size(); ++i) {
		last10[i]->setPosition(last10[i-1]->getX() - last10[i]->getWidth(), container->getY());
		last10[i]->draw(gRenderer);
	}
}

void Statistics::destroyLast10() {
	while(last10.size() > 0){
		last10.back()->free();
		delete last10.back();
		last10.back() = NULL;
		last10.pop_back();
	}
}

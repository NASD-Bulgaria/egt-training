/*
 * RouletteApplication.cpp
 *
 *  Created on: Sep 22, 2014
 *      Author: NandM
 */

#include "RouletteApplication.h"

namespace GameObjects {

RouletteApplication::RouletteApplication() {
	this->board = new GameBoard();
	this->rouletteBoard= new RouletteBoard();
	this->recovery = new Recovery();
	this->player = new Player(recovery->getMoney());
	this->board = board;
	this->stats = new Statistics("Statistics", player->getBalance());
	music = NULL;
	lastNumbers = new IRendable();
	statBackground = new IRendable();
	startBackground = new IRendable();
	infoBackground = new IRendable();
	mainBackground = new IRendable();
	buttonLocks[5] = true;
	buttonLocks[8] = true;
	for (int i = 0; i < 7; ++i) {
		maxOccurrences.push_back(new IRendable());
	}
}

RouletteApplication::~RouletteApplication() {
	for (unsigned int i = 0; i < numSounds.size(); ++i) {
		Mix_FreeMusic(numSounds[i]);
		numSounds[i] = NULL;
	}
	if (rouletteBoard) {
		rouletteBoard->free();
		delete rouletteBoard;
		rouletteBoard = NULL;
	}
	if (board) {
		board->free();
		delete board;
		board = NULL;
	}
	if (player) {
		delete player;
		player = NULL;
	}
	if (stats) {
		delete stats;
		stats = NULL;
	}
	for (int i = 0; i < 3; ++i) {
		infoFields[i].free();
	}
	for (unsigned int i = 0; i < infoButtons.size(); ++i) {
		infoButtons[i].free();
	}
	for (unsigned int i = 0; i < rouletteButtons.size(); ++i) {
		rouletteButtons[i].free();
	}
	for (unsigned int i = 0; i < last10.size(); ++i) {
		last10[i]->free();
		delete last10[i];
		last10[i] = NULL;
	}
	for (unsigned int i = 0; i < statisticLines.size(); ++i) {
		statisticLines[i]->free();
		delete statisticLines[i];
		statisticLines[i] = NULL;
	}
	for(unsigned int i = 0; i < musicChunks.size(); i++){
		Mix_FreeChunk(musicChunks[i]);
		musicChunks[i] = NULL;
	}
	for(unsigned int i = 0; i < maxOccurrences.size(); i++){
		maxOccurrences[i]->free();
		delete maxOccurrences[i];
		maxOccurrences[i] = NULL;
	}
	Mix_FreeMusic(music);
	music = NULL;
	lastNumbers->free();
	statBackground->free();
	lastNumbers = NULL;
	statBackground = NULL;
	startBackground->free();
	startBackground = NULL;
	infoBackground->free();
	infoBackground = NULL;
	mainBackground->free();
	mainBackground = NULL;
	if (recovery) {
		delete recovery;
		recovery = NULL;
	}
}

void RouletteApplication::loadMedia(SDL_Renderer * gRenderer) {
	rouletteBoard->loadFromFile(gRenderer,"Roulette/RouletteBoard.png");
	board->loadFromFile(gRenderer, "Roulette/proba.png");
	lastNumbers->loadFromFile(gRenderer,"Roulette/last10aaa.png");
	lastNumbers->setPosition(395, 315);
	statBackground->loadFromFile(gRenderer,"Roulette/statistics.png");
	startBackground->loadFromFile(gRenderer,"Roulette/startscreen.png");
	infoBackground->loadFromFile(gRenderer,"Roulette/instruction.png");
	mainBackground->loadFromFile(gRenderer,"Roulette/table.png");
	maxOccurrences[0]->loadFromFile(gRenderer,"Roulette/redStat1.png");
	maxOccurrences[1]->loadFromFile(gRenderer,"Roulette/blackStat1.png");
	maxOccurrences[2]->loadFromFile(gRenderer,"Roulette/greenStat.png");
	init(gRenderer);
	initMusic();
}

void RouletteApplication::init(SDL_Renderer * gRenderer) {
	initInfoButtons(gRenderer);
	initInfoFields(gRenderer);
	initRouletteButtons(gRenderer);
}

void RouletteApplication::handleMouseEvent(SDL_MouseButtonEvent e, SDL_Renderer* gRenderer) {
	if (e.state == SDL_PRESSED) {
		if (e.button == SDL_BUTTON_LEFT) {
			if(!handleButtonLocks(e.x,e.y)){
				handleRouletteButtonClick(e.x,e.y);
				if (board->isClicked(e.x, e.y)) {
					handleBetCreation(e.x,e.y, gRenderer);
				}
			}
		} else if (e.button == SDL_BUTTON_RIGHT) {
			if ((buttonLocks[6] || buttonLocks[7]) &&
					board->isClicked(e.x,e.y)) {
				handleBetDeletion(e.x,e.y, gRenderer);
			}
		}
	}
}

void RouletteApplication::changeInfoValues(SDL_Renderer* gRenderer) {
	stringstream ss;
	int value = 0;
	for (int i = 0; i < 3; ++i) {
		value = i == 0 ? board->collectWinings() :
				i == 1? player->getTotalBet() : player->getBalance();
		ss << value;
		infoFields[i].setRenderedText(gRenderer, ss.str());
		infoFields[i].setTextRectY(infoFields[i].getY() + infoFields[i].getHeight() / 2);
		ss.str("");
	}
	ss.clear();
}

void RouletteApplication::handleBetCreation(int x, int y, SDL_Renderer* gRenderer) {
	stringstream ss;
	for (unsigned int i = 0; i < board->allSectors.size(); ++i) {
		if (board->allSectors[i]->isClicked(x, y)) {
			if (board->allSectors[i]->bet) {
				if (player->getTotalBet() + player->BET_AMOUNT <= player->getBalance()){
					board->allSectors[i]->bet->increaseCredits(player->BET_AMOUNT);
					player->increaseBet();
					ss << board->allSectors[i]->bet->getCredits();
					board->allSectors[i]->bet->setRenderedText(gRenderer,ss.str(),22,0,0,0);
					ss.str("");
				}
			} else {
				if (i >= board-> ROULETTESIZE) {
					board->allSectors[i]->placeBet(player->createNormalBet());
				} else {
					board->allSectors[i]->placeBet(player->createNumberBet());
				}
				if (board->allSectors[i]->bet) {
					board->allSectors[i]->bet->loadFromFile(gRenderer,
							"Roulette/chip_on_table.png");
				}
			}
			break;
		}
	}
	ss.clear();
}

void RouletteApplication::handleBetDeletion(int x, int y, SDL_Renderer* gRenderer) {
	stringstream ss;
	for (unsigned int i = 0; i < board->allSectors.size(); ++i) {
		if (board->allSectors[i]->isClicked(x, y)) {
			if (board->allSectors[i]->bet) {
				if (board->allSectors[i]->bet->decreaseCredits(player->BET_AMOUNT)) {
					ss<< board->allSectors[i]->bet->getCredits();
					board->allSectors[i]->bet->setRenderedText(gRenderer,ss.str(),22,0,0,0);
					ss.str("");
					player->decreaseBet();
					if (board->allSectors[i]->bet->getCredits() < player->BET_AMOUNT) {
						board->allSectors[i]->bet->free();
						delete board->allSectors[i]->bet;
						board->allSectors[i]->bet = NULL;
					}
				}
			}
			break;
		}
	}
	ss.clear();
}

void RouletteApplication::initInfoButtons(SDL_Renderer* gRenderer) {
	for (int i = 0; i < 9; ++i) {
		infoButtons.push_back(IRendable());
	}
	infoButtons[0].loadFromFile(gRenderer, "Roulette/music.png");
	infoButtons[1].loadFromFile(gRenderer, "Roulette/fx.png");
	infoButtons[2].loadFromFile(gRenderer, "Roulette/stat.png");
	infoButtons[3].loadFromFile(gRenderer, "Roulette/info.png");
	infoButtons[4].loadFromFile(gRenderer, "Roulette/about.png");
	infoButtons[5].loadFromFile(gRenderer, "Roulette/home.png");
	infoButtons[6].loadFromFile(gRenderer, "Roulette/back.png");
	infoButtons[7].loadFromFile(gRenderer, "Roulette/play.png");
	infoButtons[8].loadFromFile(gRenderer, "Roulette/arrow.png");
	int y = 35;
	for (int i = 0; i < 5; ++i) {
		infoButtons[i].setPosition(1112, y);
		y += 55;
	}
	infoButtons[5].setPosition(298, 395);
	infoButtons[6].setPosition(1135, 5);
	infoButtons[7].setPosition(950, 395);
	infoButtons[8].setPosition(10, 10);
}

void RouletteApplication::initRouletteButtons(SDL_Renderer* gRenderer) {
	for (int i = 0; i < 3; ++i) {
		rouletteButtons.push_back(IRendable());
	}
	rouletteButtons[0].loadFromFile(gRenderer,"Roulette/clear_button.png");
	rouletteButtons[1].loadFromFile(gRenderer,"Roulette/spin_button.png");
	rouletteButtons[2].loadFromFile(gRenderer,"Roulette/getchips.png");
	int x = 440;
	for (int i = 0; i < 2; ++i) {
		rouletteButtons[i].setPosition(x, 396);
		x += 600;
	}
	rouletteButtons[2].setPosition(40, 395);
}

void RouletteApplication::setStatisticLines(SDL_Renderer* gRenderer,
		vector<PlayerRecord>& records) {
	stringstream ss;
	int y = 136;
	for (unsigned int i = 0; i < statisticLines.size(); ++i) {
		statisticLines[i]->free();
		delete statisticLines[i];
	}
	statisticLines.clear();
	IRendable* renderedLine = new IRendable();
	ss<<setfill(' ')<<setw(3)<<"#"<<setw(11)<<"Number"<<setw(10)<<"Color"<<setw(14)
			<<"Total Bet"<<setw(14)<< "Win/Loss" << setw(15) <<"Bet Yield"
			<< setw(15) << "Total Gain";
	string line = ss.str();
	renderedLine->setRenderedText(gRenderer, line, 24, 253, 221, 175,"Roulette/luximb.ttf");
	renderedLine->setTextRectX(statBackground->getX() +
			(statBackground->getWidth() - line.length() * 12)/2);
	renderedLine->setTextRectY(y);
	statisticLines.push_back(renderedLine);
	ss.str("");
	y += 24;
	for (unsigned int i = 0; i < records.size(); ++i) {
		renderedLine = new IRendable();
		ss << (records[i].index + 1)<< setw(10) << records[i].num <<
				setw(10) << colors[records[i].color] << setw(14) <<  records[i].totalBet
				<< setw(14) <<  records[i].winnings -  records[i].totalBet << setw(14)
				<<fixed<< setprecision(2) <<  records[i].deviateBet << '%' << setw(14)
				<<  records[i].deviateCapital << '%';
		line = ss.str();
		renderedLine->setRenderedText(gRenderer, line, 24, 253, 221, 175,"Roulette/luximb.ttf");
		renderedLine->setTextRectX(statBackground->getX() +
				(statBackground->getWidth() - line.length() * 12)/2);
		renderedLine->setTextRectY(y);
		y += 24;
		ss.str("");
		statisticLines.push_back(renderedLine);
	}
	ss.clear();
}

void RouletteApplication::setLast10(SDL_Renderer* gRenderer,
	vector<StatisticRecord>& records) {
	for (unsigned int i = 0; i < last10.size(); ++i) {
		last10[i]->free();
		delete last10[i];
	}
	IRendable* value;
	last10.clear();
	stringstream ss;
	for (unsigned int i = 0; i < records.size(); i++) {
		value = new IRendable();
		value->loadFromFile(gRenderer,"Roulette/transparent.png");
		ss<< records[i].num;
		if (records[i].color == RedColor) {
			value->setRenderedText(gRenderer, ss.str(), 51, 255, 0, 0);
		} else if (records[i].color == BlackColor){
			value->setRenderedText(gRenderer, ss.str(), 51, 75, 75, 75);
		} else {
			value->setRenderedText(gRenderer, ss.str(), 51, 0, 200, 0);
		}
		last10.push_back(value);
		ss.str("");
	}
	ss.clear();
}

void RouletteApplication::drawStatisticLines(SDL_Renderer* gRenderer) {
	statBackground->draw(gRenderer);
	for (unsigned int i = 0; i < statisticLines.size(); ++i) {
		statisticLines[i]->draw(gRenderer);
	}
}

void RouletteApplication::drawLast10(SDL_Renderer* gRenderer) {
	lastNumbers->draw(gRenderer);
	for (unsigned int i = 0; i < last10.size(); ++i) {
		if (i == 0) {
			last10[i]->setPosition(lastNumbers->getX() +
					lastNumbers->getWidth() - last10[i]->getWidth(), lastNumbers->getY());
		} else {
			last10[i]->setPosition(last10[i - 1]->getX() - last10[i - 1]->getWidth(),
					lastNumbers->getY());
		}
		last10[i]->draw(gRenderer);
	}
}

void RouletteApplication::draw(SDL_Renderer* gRenderer) {
	drawHomeScreen(gRenderer);
	drawMainScreen(gRenderer);
	drawInfoScreen(gRenderer);
	drawStatScreen(gRenderer);
	if (buttonLocks[4]) {
		SDL_ShowSimpleMessageBox(
				SDL_MESSAGEBOX_INFORMATION, "About",
				"SDL by GalaxyNET and Kamelia\nLogic by NAND and Stan",
				NULL);
		buttonLocks[4] = false;
	}
}

void RouletteApplication::initMusic() {
	for (int i = 0; i < 7; ++i) {
		musicChunks.push_back(new Mix_Chunk());
	}
	musicChunks[0] = Mix_LoadWAV("Roulette/play.wav");
	musicChunks[1] = Mix_LoadWAV("Roulette/chip.wav");
	musicChunks[2] = Mix_LoadWAV("Roulette/tick.wav");
	musicChunks[3] = Mix_LoadWAV("Roulette/back.wav");
	musicChunks[4] = Mix_LoadWAV("Roulette/info.wav");
	musicChunks[5] = Mix_LoadWAV("Roulette/clear.wav");
	music = Mix_LoadMUS("Roulette/roulette.mp3");
	stringstream ss;
	for (unsigned int i = 0; i < 37; ++i) {
		ss<<"Roulette/NumSound/" << i << ".wav";
		numSounds.push_back(Mix_LoadMUS(ss.str().data()));
		ss.str("");
	}
}

bool RouletteApplication::handleButtonLocks(int x, int y) {
	if (buttonLocks[2] || buttonLocks[3]) {
		if (infoButtons[6].isClicked(x, y)) {
			buttonLocks[2] = false;
			buttonLocks[3] = false;
			buttonLocks[8] = true;
			buttonLocks[6] = true;
			return true;
		}
		if (buttonLocks[2] && infoButtons[8].isClicked(x, y)) {
			buttonLocks[8] = !buttonLocks[8];
			return true;
		}
	} else if (buttonLocks[6] || buttonLocks[7]) {
		if (infoButtons[0].isClicked(x, y)) {
			buttonLocks[0] = !buttonLocks[0];
			return true;
		}
		if (infoButtons[1].isClicked(x, y)) {
			buttonLocks[1] = !buttonLocks[1];
			return true;
		}
		if (infoButtons[2].isClicked(x, y)) {
			buttonLocks[2] = true;
			buttonLocks[6] = false;
			buttonLocks[7] = false;
			return true;
		}
		if (infoButtons[3].isClicked(x, y)) {
			buttonLocks[3] = true;
			buttonLocks[6] = false;
			buttonLocks[7] = false;
			return true;
		}
		if (infoButtons[4].isClicked(x, y)) {
			buttonLocks[4] = true;
			return true;
		}
		if (infoButtons[5].isClicked(x, y)) {
			buttonLocks[5] = true;
			buttonLocks[6] = false;
			buttonLocks[7] = false;
			return true;
		}
	} else if (buttonLocks[5] && infoButtons[7].isClicked(x, y)) {
		buttonLocks[5] = false;
		buttonLocks[7] = true;
		return true;
	}
	return false;
}

void RouletteApplication::drawHomeScreen(SDL_Renderer* gRenderer) {
	if (buttonLocks[5]) {
		startBackground->draw(gRenderer);
		infoButtons[7].draw(gRenderer);
		rouletteButtons[2].draw(gRenderer);
	}
}

void RouletteApplication::drawMainScreen(SDL_Renderer* gRenderer) {
	if (buttonLocks[6] || buttonLocks[7]) {
		rouletteBoard->handleSpin();
		mainBackground->draw(gRenderer);
		board->draw(gRenderer);
		rouletteBoard->draw(gRenderer);
		drawLast10(gRenderer);
		for (unsigned int i = 0; i < 6; ++i) {
			infoButtons[i].draw(gRenderer);
		}
		for (unsigned int i = 0; i < infoFields.size(); ++i) {
			infoFields[i].draw(gRenderer);
		}
		rouletteButtons[0].draw(gRenderer);
		rouletteButtons[1].draw(gRenderer);
	}
}

void RouletteApplication::drawInfoScreen(SDL_Renderer* gRenderer) {
	if (buttonLocks[3]) {
		infoBackground->draw(gRenderer);
		infoButtons[6].draw(gRenderer);
	}
}

void RouletteApplication::drawStatScreen(SDL_Renderer* gRenderer) {
	if (buttonLocks[2]) {
		SDL_RendererFlip flip = SDL_FLIP_NONE;
		if (buttonLocks[8]) {
			drawStatisticLines(gRenderer);
		} else {
			flip = SDL_FLIP_HORIZONTAL;
			drawMaxOccurrences(gRenderer);
		}
		infoButtons[6].draw(gRenderer);
		infoButtons[8].draw(gRenderer,0,flip);
	}
}

void RouletteApplication::handleRouletteButtonClick(int x, int y) {
	if (rouletteBoard->wheel->getSpinSpeed() == Stoped) {
		if (buttonLocks[6] || buttonLocks[7]) {
			if (rouletteButtons[1].isClicked(x, y) && player->getTotalBet()) {

				player->creditBalance(player->getTotalBet());
				rouletteButtons[0].setAlpha(125);
				rouletteButtons[1].setAlpha(125);
				rouletteBoard->initRouletteBoard();
				return;
			}
			if (rouletteButtons[0].isClicked(x, y)) {
				if (buttonLocks[1]) {
					Mix_PlayChannel(0, musicChunks[5], 0);
				}
				if (player->getTotalBet()) {
					player->addToBalance(player->getTotalBet());
				}
				player->clearBet();
				board->clearAllBets();
				return;
			}
		}
		if (buttonLocks[5] && rouletteButtons[2].isClicked(x , y)) {
			if (recovery->getTime() + 3600 < time(0)) {
				player->addToBalance(100);
				recovery->setMoney(player->getBalance());
				recovery->setTime(time(0));
				recovery->save();
				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
						"Bonus!!"," You get 100 chips!!", NULL);
			} else {
				stringstream ss ;
				ss << "Try again after " << (60 - (time(0) - recovery->getTime()) / 60)
						<< " minutes!";
				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
						":(", ss.str().data(), NULL);
				ss.clear();
			}
		}
	}
}

void RouletteApplication::handleNumberHit(SDL_Renderer * gRenderer) {
	if (rouletteBoard->getWininngNumber() != -1) {
		stringstream ss;
		infoButtons[5].setAlpha(255);
		Mix_PlayMusic(numSounds[rouletteBoard->getWininngNumber()], 1);
		rouletteButtons[0].setAlpha(255);
		rouletteButtons[1].setAlpha(255);
		board->setWiningNumberSector(
				rouletteBoard->getWininngNumber());
		player->addToBalance(board->collectWinings());
		stats->write(rouletteBoard->getWininngNumber(),
				board->getWiningNumberSector()->getColor(),
				player->getTotalBet(), board->collectWinings(),
				player->getBalance());
		stats->read();
		setLast10(gRenderer, stats->lastTenNumbers);
		setStatisticLines(gRenderer, stats->lastTenPlayerRecords);
		setMaxOccurrences(gRenderer, stats->numberCount);
		if (player->getBalance() == 0) {
			board->clearAllBets();
			player->clearBet();
		}
		if (player->getTotalBet() > player->getBalance()) {
			board->clearAllBets();
			player->clearBet();
		}
		rouletteBoard->resetWiningNumber();
		ss.str("");
		ss.clear();
	}
}

void RouletteApplication::setMaxOccurrences(SDL_Renderer* gRenderer, int* records) {
	vector<pair<int, int> > sortedRecords;
	int colorsCount[3] = {0};
	double totalCount = 0;
	stringstream ss;
	for (int i = 0; i < 37; ++i) {
		sortedRecords.push_back(pair<int, int>(i, records[i]));
		totalCount += records[i];
		colorsCount[GameBoard::rouletteSectorColors[i]] += records[i];
	}
	int maxRed = -1;
	int maxBlack = -1;
	sort(sortedRecords.begin(), sortedRecords.end(), compareRecords);
	for (int i = 0; i < 37; ++i) {
		if(maxRed == -1 && GameBoard::rouletteSectorColors[sortedRecords[i].first] == RedColor){
			maxRed = i;
		} else if ( maxBlack == -1 &&
				GameBoard::rouletteSectorColors[sortedRecords[i].first] == BlackColor){
			maxBlack = i;
		}
		if (maxRed != -1 && maxBlack != -1) {
			break;
		}
	}
	int x = 50;
	int y = 80;
	maxOccurrences[0]->setPosition(x,y);
	maxOccurrences[1]->setPosition(
			statBackground->getWidth() - maxOccurrences[1]->getWidth() - x, y);
	maxOccurrences[2]->setPosition(x + maxOccurrences[0]->getWidth(), y + 57);
	ss << fixed<<setprecision(2) << (colorsCount[0] / totalCount * 100.0) << "%";
	string a = ss.str();
	maxOccurrences[0]->setRenderedText(gRenderer, a, 44, 253, 221, 175);
	maxOccurrences[0]->setTextRectX(x + 250);
	ss.str("");
	ss << fixed<< setprecision(2) << (colorsCount[1] / totalCount * 100.0) << "%";
	a = ss.str();
	maxOccurrences[1]->setRenderedText(gRenderer, a, 44, 253, 221, 175);
	maxOccurrences[1]->setTextRectX(maxOccurrences[1]->getX() + 84);
	ss.str("");
	ss << fixed<<setprecision(2) << (colorsCount[2] / totalCount * 100.0) << "%";
	a = ss.str();
	maxOccurrences[2]->setRenderedText(gRenderer, a, 44, 253, 221, 175);
	ss.str("");
	ss << fixed <<sortedRecords[maxRed].first << " ("
			<<setprecision(2) << (sortedRecords[maxRed].second / totalCount * 100.0) << "%)";
	a = ss.str();
	maxOccurrences[3]->setRenderedText(gRenderer, a, 58, 200, 12, 14);
	maxOccurrences[3]->setTextRectX(statBackground->getWidth()/2 - a.size() * 29
			- maxOccurrences[2]->getWidth()/2 - 29);
	maxOccurrences[3]->setTextRectY(maxOccurrences[0]->getY()
			+ maxOccurrences[0]->getHeight());
	ss.str("");
	ss << fixed <<sortedRecords[maxBlack].first << " ("
			<<setprecision(2) << (sortedRecords[maxBlack].second / totalCount * 100.0) << "%)";
	a = ss.str();
	maxOccurrences[4]->setRenderedText(gRenderer, a, 58, 16, 16, 16);
	maxOccurrences[4]->setTextRectX(statBackground->getWidth()/2 +
			maxOccurrences[2]->getWidth()/2 + 29);
	maxOccurrences[4]->setTextRectY(maxOccurrences[3]->getTextRectY());
	ss.str("");
	ss << setprecision(0)<<totalCount;
	a = ss.str();
	maxOccurrences[6]->setRenderedText(gRenderer, a, 58, 253, 221, 175);
	maxOccurrences[6]->setTextRectX(statBackground->getWidth()/2 - a.size() * 29 / 2 );
	maxOccurrences[6]->setTextRectY(maxOccurrences[3]->getTextRectY() - 21);
	ss.str("");
	a = "GAMES";
	maxOccurrences[5]->setRenderedText(gRenderer, a, 42, 253, 221, 175);
	maxOccurrences[5]->setTextRectX(statBackground->getWidth()/2 - a.size() * 21 / 2 );
	maxOccurrences[5]->setTextRectY(maxOccurrences[6]->getTextRectY() + 58);
}

void RouletteApplication::initInfoFields(SDL_Renderer* gRenderer) {
	for (int i = 0; i < 3; ++i) {
		infoFields.push_back(IRendable());
	}
	infoFields[0].loadFromFile(gRenderer, "Roulette/winning_amount.png");
	infoFields[1].loadFromFile(gRenderer, "Roulette/total_bet.png");
	infoFields[2].loadFromFile(gRenderer, "Roulette/balance_amount.png");
	int x = 560;
	stringstream ss;
	for (int i = 0; i < 3; ++i) {
		infoFields[i].setPosition(x, 395);
		if (i == 2) {
			ss << player->getBalance();
			infoFields[i].setRenderedText(gRenderer,ss.str());
			ss.str("");
			ss.clear();
		} else {
			infoFields[i].setRenderedText(gRenderer,"0");
		}
		infoFields[i].setTextRectY(infoFields[i].getY() + infoFields[i].getHeight() / 2);
		x += 160;
	}
}
string RouletteApplication::colors[3] = {"RED","BLACK","GREEN"};

void RouletteApplication::drawMaxOccurrences(SDL_Renderer* gRenderer) {
	statBackground->draw(gRenderer);
	for (unsigned int i = 0; i < maxOccurrences.size(); ++i) {
		if (i == 1) {
			maxOccurrences[i]->draw(gRenderer, 0, SDL_FLIP_HORIZONTAL);
		} else {
			maxOccurrences[i]->draw(gRenderer);
		}
	}
}

bool RouletteApplication::compareRecords(pair<int, int> first,
		pair<int, int> second) {
	return first.second > second.second;
}

}

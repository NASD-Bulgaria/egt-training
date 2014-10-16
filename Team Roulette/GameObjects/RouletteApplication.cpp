/*
 * RouletteApplication.cpp
 *
 *  Created on: Sep 22, 2014
 *      Author: NandM
 */

#include "RouletteApplication.h"

namespace GameObjects {

RouletteApplication::RouletteApplication() {
	music = NULL;
	init();
	statChange = true;
	currentGameState = HomeState;
	Mix_PlayMusic(music, -1);
	Mix_PauseMusic();
}

RouletteApplication::~RouletteApplication() {
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
	for (map<string, Mix_Chunk*>::iterator i = musicChunks.begin();
			i != musicChunks.end(); i++) {
		Mix_FreeChunk(i->second);
		i->second = NULL;
	}
	for (map<string, Button*>::iterator i = allButtons.begin();
			i != allButtons.end(); i++) {
		i->second->free();
		i->second = NULL;
	}
	for (map<string, IRendable*>::iterator i = simpleElements.begin();
			i != simpleElements.end(); i++) {
		i->second->free();
		i->second = NULL;
	}
	gCursor = NULL;
	gCursorClicked->free();
	gCursorDefault->free();
	gCursorClicked = NULL;
	gCursorDefault = NULL;
	Mix_FreeMusic(music);
	music = NULL;
	if (recovery) {
		delete recovery;
		recovery = NULL;
	}
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	Mix_Quit();
	TTF_Quit();
	SDL_Quit();
}

void RouletteApplication::init() {
	initSDL();
	initElements();
	initMusic();
	changeWinInfo(0);
	changeBetInfo(0);
	changeBalanceInfo(player->getBalance());
	musicOn = true;
	soundfxOn = true;
	bonusShowTicks = 0;
}

void RouletteApplication::handleMouseEvent(SDL_MouseButtonEvent e) {
	if (e.type == SDL_MOUSEBUTTONUP) {
		gCursorDefault->setPosition(gCursor->getX(),gCursor->getY());
		gCursor = gCursorDefault;
	} else if (e.type == SDL_MOUSEBUTTONDOWN) {
		gCursorClicked->setPosition(gCursor->getX(),gCursor->getY());
		gCursor = gCursorClicked;
		if (e.state == SDL_PRESSED) {
			if (e.button == SDL_BUTTON_LEFT) {
				handleButtonClick(e.x, e.y);
				handleBetCreation(e.x, e.y);
			} else if (e.button == SDL_BUTTON_RIGHT) {
				handleBetDeletion(e.x, e.y);
			}
		}
	}
}

void RouletteApplication::handleBetCreation(int x, int y) {
	stringstream ss;
	for (unsigned int i = 0; i < board->allSectors.size(); ++i) {
		if (board->allSectors[i]->isClicked(x, y, currentGameState)) {
			if (board->allSectors[i]->bet) {
				if (player->getTotalBet() + player->BET_AMOUNT
						<= player->getBalance()) {
					board->allSectors[i]->bet->increaseCredits(
							player->BET_AMOUNT);
					player->increaseBet();
					ss << board->allSectors[i]->bet->getCredits();
					board->allSectors[i]->bet->setRenderedText(gRenderer,
							ss.str(), 22, 0, 0, 0,"Roulette/luximb.ttf");
					ss.str("");
				}
			} else {
				if (i >= board->ROULETTESIZE) {
					board->allSectors[i]->placeBet(player->createNormalBet());
				} else {
					board->allSectors[i]->placeBet(player->createNumberBet());
				}
				if (board->allSectors[i]->bet) {
					board->allSectors[i]->bet->loadFromFile(gRenderer,
							"Roulette/chip_on_table.png");
				}
			}
			changeBetInfo(player->getTotalBet());
			if (soundfxOn && player->getTotalBet() < player->getBalance()) {
				Mix_PlayChannel(-1, musicChunks["chipChunk"], 0);
			}
			break;
		}
	}
	ss.clear();
}

void RouletteApplication::handleBetDeletion(int x, int y) {
	stringstream ss;
	for (unsigned int i = 0; i < board->allSectors.size(); ++i) {
		if (board->allSectors[i]->isClicked(x, y, currentGameState)) {
			if (board->allSectors[i]->bet) {
				if (board->allSectors[i]->bet->decreaseCredits(
						player->BET_AMOUNT)) {
					ss << board->allSectors[i]->bet->getCredits();
					board->allSectors[i]->bet->setRenderedText(gRenderer,
							ss.str(), 22, 0, 0, 0,"Roulette/luximb.ttf");
					ss.str("");
					player->decreaseBet();
					if (board->allSectors[i]->bet->getCredits()
							< player->BET_AMOUNT) {
						board->allSectors[i]->bet->free();
						delete board->allSectors[i]->bet;
						board->allSectors[i]->bet = NULL;
					}
				}
			}
			changeBetInfo(player->getTotalBet());
			break;
		}
	}
	ss.clear();
}

void RouletteApplication::setStatisticLines(vector<PlayerRecord>* records) {
	stringstream ss;
	int y = 136;
	ss << setfill(' ') << setw(3) << "#" << setw(11) << "Number" << setw(10)
			<< "Color" << setw(14) << "Total Bet" << setw(14) << "Win/Loss"
			<< setw(15) << "Bet Yield" << setw(15) << "Total Gain";
	string line = ss.str();
	simpleElements["statLine0"]->setRenderedText(gRenderer, line, 24, 253, 221,
			175, "Roulette/luximb.ttf");
	simpleElements["statLine0"]->setTextRectX(
			simpleElements["statBackground"]->getX()
					+ (simpleElements["statBackground"]->getWidth()
							- line.length() * 12) / 2);
	simpleElements["statLine0"]->setTextRectY(y);
	ss.str("");
	y += 24;
	for (unsigned int i = 0; i < records->size(); ++i) {
		ss << (records->at(i).index + 1) << setw(10) << records->at(i).num << setw(10)
				<< colors[records->at(i).color] << setw(14) << records->at(i).totalBet
				<< setw(14) << records->at(i).winnings - records->at(i).totalBet
				<< setw(14) << fixed << setprecision(2) << records->at(i).deviateBet
				<< '%' << setw(14) << records->at(i).deviateCapital << '%';
		line = ss.str();
		simpleElements[statElementNames[i + 1]]->setRenderedText(gRenderer, line,
				24, 253, 221, 175, "Roulette/luximb.ttf");
		simpleElements[statElementNames[i + 1]]->setTextRectX(
				simpleElements["statBackground"]->getX()
						+ (simpleElements["statBackground"]->getWidth()
								- line.length() * 12) / 2);
		simpleElements[statElementNames[i + 1]]->setTextRectY(y);
		y += 24;
		ss.str("");
	}
	ss.clear();
}

void RouletteApplication::setLast12(vector<StatisticRecord> * records) {
	stringstream ss;
	for (unsigned int i = 0; i < records->size(); i++) {
		ss << records->at(i).num;
		if (records->at(i).color == RedColor) {
			simpleElements[lastTenNumbersNames[i]]->setRenderedText(gRenderer, ss.str(),
					51, 255, 0, 0);
		} else if (records->at(i).color == BlackColor) {
			simpleElements[lastTenNumbersNames[i]]->setRenderedText(gRenderer, ss.str(),
					51, 75, 75, 75);
		} else {
			simpleElements[lastTenNumbersNames[i]]->setRenderedText(gRenderer, ss.str(),
					51, 0, 200, 0);
		}
		ss.str("");
	}
	ss.clear();
}

void RouletteApplication::drawStatisticLines() {
	for (unsigned int i = 0; i <= 10; ++i) {
		simpleElements[statElementNames[i]]->draw(gRenderer);
	}
}

void RouletteApplication::drawLast12() {
	simpleElements["last12"]->draw(gRenderer);
	for (unsigned int i = 0; i < 12; ++i) {
		simpleElements[lastTenNumbersNames[i]]->draw(gRenderer);
	}
}

void RouletteApplication::draw() {
	drawGameScreen();
	drawInitialScreen();
	drawStatScreen();
	drawInfoScreen();
	drawAboutUsScreen();
	gCursor->draw(gRenderer);
}

void RouletteApplication::initMusic() {
	string musicNames[7] = {"chipChunk", "tickChunk", "backChunk", "infoChunk",
			"spinChunk", "clearChunk", "youwinChunk"};

	string musicLoadPats[7] = {"Roulette/chip.wav","Roulette/tick.wav",
			"Roulette/back.wav","Roulette/info.wav","Roulette/spin.wav","Roulette/clear.wav",
			"Roulette/youwin.wav"};

	stringstream ss;
	string name;
	for (int i = 0; i < 37; ++i) {
		ss<< i;
		name = ss.str();
		musicChunks.insert(pair<string, Mix_Chunk*>((name + "Chunk"),
				Mix_LoadWAV(("Roulette/NumSound/" + name + ".wav").data())));
		ss.str("");
	}
	ss.clear();
	for (int i = 0; i < 7; ++i) {
		musicChunks.insert(pair<string, Mix_Chunk*>(musicNames[i],
				Mix_LoadWAV(musicLoadPats[i].data())));
	}
	music = Mix_LoadMUS("Roulette/roulette.mp3");
}

void RouletteApplication::handleNumberHit() {
	board->setWiningNumberSector(rouletteBoard->getWininngNumber());
	player->addToBalance(board->collectWinings());
	stats->write(rouletteBoard->getWininngNumber(),
			board->getWiningNumberSector()->getColor(),
			player->getTotalBet(), board->collectWinings(),
			player->getBalance());
	stats->read();
	recovery->setMoney(player->getBalance());
	recovery->save();
	setLast12(stats->lastTenNumbers);
	setStatisticLines(stats->lastTenPlayerRecords);
	setMaxOccurrences(stats->numberCount);
	if (player->getBalance() == 0) {
		board->clearAllBets();
		player->clearBet();
	}
	if (player->getTotalBet() > player->getBalance()) {
		board->clearAllBets();
		player->clearBet();
		changeBetInfo(player->getTotalBet());
	}
	if(soundfxOn && player->getTotalBet() < board->collectWinings()){
		Mix_PlayChannel(-1, musicChunks["youwinChunk"], 0);
	}
	changeBalanceInfo(player->getBalance());
	changeWinInfo(board->collectWinings());
}

void RouletteApplication::setMaxOccurrences(int* records) {
	vector<pair<int, int> > sortedRecords;
	int colorsCount[3] = { 0 };
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
		if (maxRed == -1
				&& GameBoard::rouletteSectorColors[sortedRecords[i].first]
						== RedColor) {
			maxRed = i;
		} else if (maxBlack == -1
				&& GameBoard::rouletteSectorColors[sortedRecords[i].first]
						== BlackColor) {
			maxBlack = i;
		}
		if (maxRed != -1 && maxBlack != -1) {
			break;
		}
	}
	ss << fixed << setprecision(2) << (colorsCount[0] / totalCount * 100.0)
			<< "%";
	string a = ss.str();
	simpleElements["redPercentage"]->setRenderedText(gRenderer, a, 44, 253, 221,
			175);
	simpleElements["redPercentage"]->setTextRectX(
			simpleElements["redPercentage"]->getX() + 250);
	ss.str("");
	ss << fixed << setprecision(2) << (colorsCount[1] / totalCount * 100.0)
			<< "%";
	a = ss.str();
	simpleElements["blackPercentage"]->setRenderedText(gRenderer, a, 44, 253,
			221, 175);
	simpleElements["blackPercentage"]->setTextRectX(
			simpleElements["blackPercentage"]->getX() + 84);
	ss.str("");
	ss << fixed << setprecision(2) << (colorsCount[2] / totalCount * 100.0)
			<< "%";
	a = ss.str();
	simpleElements["zeroPercentage"]->setRenderedText(gRenderer, a, 44, 253,
			221, 175);
	ss.str("");
	ss << fixed << sortedRecords[maxRed].first << " (" << setprecision(2)
			<< (sortedRecords[maxRed].second / totalCount * 100.0) << "%)";
	a = ss.str();
	simpleElements["maxRedNum"]->setRenderedText(gRenderer, a, 58, 200, 12, 14);
	simpleElements["maxRedNum"]->setTextRectX(
			simpleElements["statBackground"]->getWidth() / 2 - a.size() * 29
					- simpleElements["zeroPercentage"]->getWidth() / 2 - 29);
	simpleElements["maxRedNum"]->setTextRectY(
			simpleElements["redPercentage"]->getY()
					+ simpleElements["redPercentage"]->getHeight());
	ss.str("");
	ss << fixed << sortedRecords[maxBlack].first << " (" << setprecision(2)
			<< (sortedRecords[maxBlack].second / totalCount * 100.0) << "%)";
	a = ss.str();
	simpleElements["maxBlackNum"]->setRenderedText(gRenderer, a, 58, 16, 16,
			16);
	simpleElements["maxBlackNum"]->setTextRectX(
			simpleElements["statBackground"]->getWidth() / 2
					+ simpleElements["zeroPercentage"]->getWidth() / 2 + 29);
	simpleElements["maxBlackNum"]->setTextRectY(
			simpleElements["maxRedNum"]->getTextRectY());
	ss.str("");
	ss << setprecision(0) << totalCount;
	a = ss.str();
	simpleElements["totalGames"]->setRenderedText(gRenderer, a, 58, 253, 221,
			175);
	simpleElements["totalGames"]->setTextRectX(
			simpleElements["statBackground"]->getWidth() / 2
					- a.size() * 29 / 2);
	simpleElements["totalGames"]->setTextRectY(
			simpleElements["maxRedNum"]->getTextRectY() - 21);
	ss.str("");
	a = "GAMES";
	simpleElements["gamesInfo"]->setRenderedText(gRenderer, a, 42, 253, 221,
			175);
	simpleElements["gamesInfo"]->setTextRectX(
			simpleElements["statBackground"]->getWidth() / 2
					- a.size() * 21 / 2);
	simpleElements["gamesInfo"]->setTextRectY(
			simpleElements["totalGames"]->getTextRectY() + 58);
}

string RouletteApplication::colors[3] = { "RED", "BLACK", "GREEN" };

void RouletteApplication::drawMaxOccurrences() {
	simpleElements["redPercentage"]->draw(gRenderer);
	simpleElements["blackPercentage"]->draw(gRenderer);
	simpleElements["zeroPercentage"]->draw(gRenderer);
	simpleElements["maxRedNum"]->draw(gRenderer);
	simpleElements["maxBlackNum"]->draw(gRenderer);
	simpleElements["totalGames"]->draw(gRenderer);
	simpleElements["gamesInfo"]->draw(gRenderer);
}

void RouletteApplication::initElements() {
	int state = 0;
	for (int i = 0; i < 31; ++i) {
		if (elementNames[i] == "gameBoard") {
			this->board = new GameBoard();
			board->loadFromFile(gRenderer, elementloadPats[i]);
			board->setPosition(elementCoords[i][0], elementCoords[i][1]);
		} else if (elementNames[i] == "rouletteBoard") {
			this->rouletteBoard = new RouletteBoard();
			rouletteBoard->loadFromFile(gRenderer, elementloadPats[i]);
			rouletteBoard->setPosition(elementCoords[i][0],elementCoords[i][1]);
		} else if (elementNames[i].find("Button") != string::npos) {
			allButtons.insert(pair<string, Button*>(elementNames[i],
					new Button(elementCoords[i][0], elementCoords[i][1], allowedGameStates[state])));
			allButtons[elementNames[i]]->loadFromFile(gRenderer, elementloadPats[i]);
			state++;
		} else {
			simpleElements.insert(pair<string, IRendable*>(elementNames[i],
					new IRendable(elementCoords[i][0], elementCoords[i][1])));
			simpleElements[elementNames[i]]->loadFromFile(gRenderer, elementloadPats[i]);
		}
	}
	for (int i = 0; i < 15; ++i) {
		simpleElements.insert(
				pair<string, IRendable*>(statElementNames[i], new IRendable()));
	}
	for (int i = 0; i < 12; ++i) {
		simpleElements.insert(pair<string, IRendable*>(lastTenNumbersNames[i],
				new IRendable(lastTenNumbersCoords[i][0], lastTenNumbersCoords[i][1])));
		simpleElements[lastTenNumbersNames[i]]->loadFromFile(
				gRenderer, "Roulette/transparent.png");
	}
	this->recovery = new Recovery();
	this->player = new Player(recovery->getMoney());
	this->stats = new Statistics("Statistics", player->getBalance());
	gCursor = NULL;
	gCursorDefault = new IRendable();
	gCursorClicked = new IRendable();
	gCursorDefault->loadFromFile(gRenderer, "Roulette/cursor.png");
	gCursorClicked->loadFromFile(gRenderer, "Roulette/cursorclicked.png");
	gCursor = gCursorDefault;
}

void RouletteApplication::drawStatScreen() {
	if (currentGameState == StatisticState) {
		simpleElements["statBackground"]->draw(gRenderer);
		allButtons["statBackButton"]->draw(gRenderer);
		if (statChange) {
			allButtons["statChangeButton"]->draw(gRenderer);
			drawStatisticLines();
		} else {
			allButtons["statChangeButton"]->draw(gRenderer, 0, SDL_FLIP_HORIZONTAL);
			drawMaxOccurrences();
		}
	}
}

void RouletteApplication::drawGameScreen() {
	if (currentGameState == PlayState || currentGameState == SpinState) {
		simpleElements["mainBackground"]->draw(gRenderer);
		rouletteBoard->draw(gRenderer);
		board->draw(gRenderer);
		drawLast12();
		simpleElements["winInfo"]->draw(gRenderer);
		simpleElements["betInfo"]->draw(gRenderer);
		simpleElements["balanceInfo"]->draw(gRenderer);
		if (musicOn) {
			allButtons["musicButton"]->draw(gRenderer);
		} else {
			allButtons["noMusicButton"]->draw(gRenderer);
		}
		if (soundfxOn) {
			allButtons["soundfxButton"]->draw(gRenderer);
		} else {
			allButtons["noSoundfxButton"]->draw(gRenderer);
		}
		allButtons["statButton"]->draw(gRenderer);
		allButtons["infoButton"]->draw(gRenderer);
		allButtons["aboutButton"]->draw(gRenderer);
		allButtons["clearButton"]->draw(gRenderer);
		allButtons["spinButton"]->draw(gRenderer);
		allButtons["homeButton"]->draw(gRenderer);
	}
}

void RouletteApplication::drawInitialScreen() {
	if (currentGameState == HomeState) {
		simpleElements["homeBackground"]->draw(gRenderer);
		allButtons["getChipsButton"]->draw(gRenderer);
		allButtons["playButton"]->draw(gRenderer);
		drawBonusMsg();
	}
}

void RouletteApplication::drawInfoScreen() {
	if (currentGameState == InfoState) {
		simpleElements["instructionBackground"]->draw(gRenderer);
		allButtons["infoBackButton"]->draw(gRenderer);
	}
}

void RouletteApplication::handleButtonClick(int x, int y) {
	if (allButtons["playButton"]->isClicked(x, y, currentGameState)) {
		currentGameState = PlayState;
		if (musicOn) {
			Mix_ResumeMusic();
		}
	}
	else if (allButtons["statButton"]->isClicked(x, y, currentGameState)) {
		currentGameState = StatisticState;
	}
	else if (allButtons["aboutButton"]->isClicked(x, y, currentGameState)) {
		currentGameState = AboutState;
	}
	else if (allButtons["infoButton"]->isClicked(x, y, currentGameState)) {
		currentGameState = InfoState;
	}
	else if (allButtons["statBackButton"]->isClicked(x, y, currentGameState)) {
		currentGameState = PlayState;
		if (soundfxOn) {
			Mix_PlayChannel(-1,musicChunks["backChunk"], 0);
		}
	}
	else if (allButtons["infoBackButton"]->isClicked(x, y, currentGameState)) {
		currentGameState = PlayState;
		if (soundfxOn) {
			Mix_PlayChannel(-1,musicChunks["backChunk"], 0);
		}
	}
	else if (allButtons["statChangeButton"]->isClicked(x, y, currentGameState)) {
		statChange = !statChange;
	}
	else if(allButtons["aboutUsBackButton"]->isClicked(x, y, currentGameState)){
		currentGameState = PlayState;
		if (soundfxOn) {
			Mix_PlayChannel(-1,musicChunks["backChunk"], 0);
		}

	} else if (allButtons["spinButton"]->isClicked(x, y, currentGameState)
			&& board->anyBetPlaced()) {
		currentGameState = SpinState;
		rouletteBoard->initRouletteBoard();
		if (soundfxOn) {
			Mix_PlayChannel(-1, musicChunks["tickChunk"], 0);
		}
		player->creditBalance(player->getTotalBet());
		changeBalanceInfo(player->getBalance());
		changeWinInfo(0);
		for (map<string, Button*>::iterator it = allButtons.begin();
				it != allButtons.end(); ++it) {
			it->second->setAlpha(128);
		}
	}  else if (allButtons["homeButton"]->isClicked(x, y, currentGameState)) {
		currentGameState = HomeState;
		if (soundfxOn) {
			Mix_PlayChannel(-1,musicChunks["backChunk"], 0);
		}
	} else if(allButtons["clearButton"]->isClicked(x, y, currentGameState)){
		if (board->anyBetPlaced()) {
			if (soundfxOn) {
				Mix_PlayChannel(-1, musicChunks["clearChunk"], 0);
			}
			player->clearBet();
			board->clearAllBets();
			changeBetInfo(player->getTotalBet());
		}
	} else if(allButtons["musicButton"]->isClicked(x, y, currentGameState) && musicOn){
		musicOn = false;
		Mix_PauseMusic();
	} else if(allButtons["soundfxButton"]->isClicked(x, y, currentGameState) && soundfxOn){
		soundfxOn = false;
	} else if(allButtons["noMusicButton"]->isClicked(x, y, currentGameState) && !musicOn){
		musicOn = true;
		Mix_ResumeMusic();
	} else if(allButtons["noSoundfxButton"]->isClicked(x, y, currentGameState) && !soundfxOn){
		soundfxOn = true;
	} else if(allButtons["getChipsButton"]->isClicked(x, y, currentGameState)){
		string msg;
		if (recovery->getTime() + 3600 < time(0)) {
			player->addToBalance(100);
			recovery->setMoney(player->getBalance());
			recovery->setTime(time(0));
			recovery->save();
			simpleElements["bonus"]->setRenderedText(gRenderer, "Bonus!! You get 100 chips!!",
					28, 0 ,0 ,0 ,"Roulette/luximb.ttf");
			changeBalanceInfo(player->getBalance());
		} else {
			stringstream ss ;
			ss << "Try again after " << (60 - (time(0) - recovery->getTime()) / 60)
					<< " minutes!";
			simpleElements["bonus"]->setRenderedText(gRenderer, ss.str(),
					28, 0, 0, 0,"Roulette/luximb.ttf");
			ss.clear();
		}
		bonusShowTicks = SDL_GetTicks() + 2000;
	}
}

void RouletteApplication::handleSpinState() {
	if (currentGameState == SpinState) {
		if (rouletteBoard->wheel->getSpinSpeed() != Stoped) {
			rouletteBoard->wheel->spin();
			rouletteBoard->ball->moove(rouletteBoard->wheel->getSpinSpeed());
			if (rouletteBoard->ball->isInSector() && rouletteBoard->getWininngNumber() == -1) {
				rouletteBoard->handleBallInSector();
				handleNumberHit();
				if (soundfxOn) {
					stringstream ss;
					ss<<rouletteBoard->getWininngNumber() << "Chunk";
					Mix_PlayChannel(-1, musicChunks[ss.str()], 0);
					ss.clear();
				}
			}
		} else {
			currentGameState = PlayState;
			rouletteBoard->resetWiningNumber();
			for (map<string, Button*>::iterator it = allButtons.begin();
					it != allButtons.end(); ++it) {
				it->second->setAlpha(255);
			}
		}
	}
}

void RouletteApplication::changeBetInfo(int totalBet) {
	stringstream ss;
	ss << totalBet;
	simpleElements["betInfo"]->setRenderedText(gRenderer, ss.str());
	simpleElements["betInfo"]->setTextRectY(simpleElements["betInfo"]->getY()
			+ simpleElements["betInfo"]->getHeight()/ 2);
	ss.str("");
	ss.clear();
}

void RouletteApplication::changeBalanceInfo(int balanceAmount) {
	stringstream ss;
	ss << balanceAmount;
	simpleElements["balanceInfo"]->setRenderedText(gRenderer, ss.str());
	simpleElements["balanceInfo"]->setTextRectY(simpleElements["balanceInfo"]->getY()
			+ simpleElements["balanceInfo"]->getHeight()/ 2);
	ss.str("");
	ss.clear();
}

void RouletteApplication::changeWinInfo(int winAmount) {
	stringstream ss;
	ss << winAmount;
	simpleElements["winInfo"]->setRenderedText(gRenderer, ss.str());
	simpleElements["winInfo"]->setTextRectY(simpleElements["winInfo"]->getY()
			+ simpleElements["winInfo"]->getHeight()/ 2);
	ss.str("");
	ss.clear();
}

void RouletteApplication::drawBonusMsg() {
	if (SDL_GetTicks() < bonusShowTicks) {
		simpleElements["bonus"]->draw(gRenderer);
	}
}

void RouletteApplication::drawAboutUsScreen() {
	if (currentGameState == AboutState) {
		simpleElements["aboutUs"]->draw(gRenderer);
		allButtons["aboutUsBackButton"]->draw(gRenderer);
	}
}

void RouletteApplication::initSDL() {

	int SCREEN_WIDTH = 1192;
	int SCREEN_HEIGHT = 460;

	SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1");

	gWindow = SDL_CreateWindow("European Roulette", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	gRenderer = SDL_CreateRenderer(gWindow, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	int imgFlags = IMG_INIT_PNG;

	IMG_Init(imgFlags);
	TTF_Init();
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
}

void RouletteApplication::start() {
	srand(time(NULL));
	bool quit = false;

	SDL_Event e;
	int x, y;
	SDL_ShowCursor(0);

	stringstream ss;
	setLast12(stats->lastTenNumbers);
	setStatisticLines(stats->lastTenPlayerRecords);
	setMaxOccurrences(stats->numberCount);

	while (!quit) {
		SDL_GetMouseState(&x, &y);
		gCursor->setPosition(x, y);
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			handleMouseEvent(e.button);
		}
		handleSpinState();
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);
		draw();
		SDL_RenderPresent(gRenderer);
	}
}

bool RouletteApplication::compareRecords(pair<int, int> first,
		pair<int, int> second) {
	return first.second > second.second;
}

string RouletteApplication::elementNames[31] = { "homeBackground",
		"statBackground", "instructionBackground", "mainBackground",
		"gameBoard", "rouletteBoard", "last12", "winInfo",
		"betInfo", "balanceInfo", "homeButton", "clearButton", "spinButton",
		"musicButton", "soundfxButton", "statButton", "infoButton",
		"aboutButton", "statBackButton", "infoBackButton", "statChangeButton",
		"getChipsButton", "playButton", "redPercentage", "blackPercentage",
		"zeroPercentage", "noMusicButton", "noSoundfxButton", "bonus", "aboutUs",
		"aboutUsBackButton"
};

string RouletteApplication::statElementNames[15] = { "statLine0", "statLine1",
		"statLine2", "statLine3", "statLine4", "statLine5", "statLine6",
		"statLine7", "statLine8", "statLine9", "statLine10", "maxRedNum",
		"maxBlackNum", "totalGames", "gamesInfo" };

string RouletteApplication::lastTenNumbersNames[12] = {"1stNum", "2ndNum","3thNum",
		"4thNum" , "5thNum", "6thNum", "7thNum", "8thNum", "9thNum", "10thNum",
		"11thNum", "12thNum"
};

int RouletteApplication::elementCoords[31][2] = { { 0, 0 }, { 0, 0 }, { 0, 0 },
		{ 0, 0 }, { 456, 58 }, { 44, 65 }, { 395, 315 }, { 560, 395 },
		{ 720, 395 }, { 880, 395 }, { 298, 395 }, { 440, 395 }, { 1040, 395 }, {
				1112, 35 }, { 1112, 90 }, { 1112, 145 }, { 1112, 200 }, { 1112,
				255 }, { 1135, 5 }, { 1135, 5 }, { 10, 10 }, { 40, 395 }, { 950,
				395 }, { 50, 80 }, { 698, 80 }, { 494, 137 }, {1112, 35 },
				{ 1112, 90 }, {396, 270}, {0, 0}, { 1135, 5 }};

int RouletteApplication::lastTenNumbersCoords[12][2] = {{1102, 315}, {1042, 315}, {982, 315},
		{922, 315}, {862, 315}, {802, 315}, {742, 315}, {682, 315}, {622, 315}, {562, 315},
		{502, 315}, {442, 315}
};

string RouletteApplication::elementloadPats[31] = { "Roulette/startscreen.png",
		"Roulette/statistics.png", "Roulette/instruction.png",
		"Roulette/table.png", "Roulette/proba.png",
		"Roulette/RouletteBoard.png", "Roulette/last10aaa.png",
		"Roulette/winning_amount.png",
		"Roulette/total_bet.png", "Roulette/balance_amount.png",
		"Roulette/home.png", "Roulette/clear_button.png",
		"Roulette/spin_button.png", "Roulette/music.png", "Roulette/fx.png",
		"Roulette/stat.png", "Roulette/info.png", "Roulette/about.png",
		"Roulette/back.png", "Roulette/back.png", "Roulette/arrow.png",
		"Roulette/getchips.png", "Roulette/play.png", "Roulette/redStat1.png",
		"Roulette/blackStat1.png", "Roulette/greenStat.png",
		"Roulette/nomusic.png", "Roulette/nofx.png", "Roulette/bonus.png",
		"Roulette/aboutus.png", "Roulette/back.png"
};

GameState RouletteApplication::allowedGameStates[16] = { PlayState, PlayState,
		PlayState, PlayState, PlayState, PlayState, PlayState, PlayState,
		StatisticState, InfoState, StatisticState, HomeState, HomeState,
		PlayState, PlayState, AboutState };
}

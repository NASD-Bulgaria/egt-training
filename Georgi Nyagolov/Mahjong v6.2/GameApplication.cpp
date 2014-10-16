#include "GameApplication.h"

GameApplication::GameApplication():
        window(NULL), renderer(NULL),
        font(NULL), lockButtons(false),
        ptrHelp(NULL), coordI(0),
        coordJ(0), choice(false),
        moves(0), credits(100),
        matches(0), music(NULL),
        thunder(NULL), bombExploding(NULL),
        explosion(NULL), click(NULL),
        chunk(false), gameOver(false),
        youWin(false), youLose(false),
        allGames(0), winGames(0),
        mark(0), quit(false){
    for(int i = 0; i < NUMBER_OF_BUTTON; ++i){
        temp[i] = false;
    }
}

GameApplication::~GameApplication(){
    close();
}

bool GameApplication::init() {
	bool success = true;
	if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	} else {
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf("Warning: Linear texture filtering not enabled!");
		}
		window = SDL_CreateWindow("Mahjong", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf("Window could not be created! SDL Error: %s\n",
					SDL_GetError());
			success = false;
		} else {
			renderer = SDL_CreateRenderer(window, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (renderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n",
						SDL_GetError());
				success = false;
			} else {
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					printf(
							"SDL_image could not initialize! SDL_image Error: %s\n",
							IMG_GetError());
					success = false;
				}
				if (TTF_Init() == -1) {
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n",
					TTF_GetError());
					success = false;
				}
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
					printf(
							"SDL_mixer could not initialize! SDL_mixer Error: %s\n",
							Mix_GetError());
					success = false;
				}
			}
		}
	}
	return success;
}

bool GameApplication::loadMedia() {
	bool success = true;
	if (!markTile.loadFromFile(renderer, "images/mark.png")) {
		printf("Failed to load mark texture!\n");
		success = false;
	}
	if (!winAnimation.loadAnimationFromFile(renderer, "images/firework_")) {
		printf("Failed to load animation texture!\n");
		success = false;
	}
	if (!firstAnimation_1.loadAnimationFromFile(renderer, "images/explosprite_")) {
		printf("Failed to load animation texture!\n");
		success = false;
	}
	if (!secondAnimation_1.loadAnimationFromFile(renderer, "images/explosprite_")) {
		printf("Failed to load animation texture!\n");
		success = false;
	}
	if (!firstAnimation_2.loadAnimationFromFile(renderer, "images/explosion_")) {
		printf("Failed to load animation texture!\n");
		success = false;
	}
	if (!secondAnimation_2.loadAnimationFromFile(renderer, "images/explosion_")) {
		printf("Failed to load animation texture!\n");
		success = false;
	}
	if (!firstAnimation_3.loadAnimationFromFile(renderer, "images/lightning_")) {
		printf("Failed to load animation texture!\n");
		success = false;
	}
	if (!secondAnimation_3.loadAnimationFromFile(renderer, "images/lightning_")) {
		printf("Failed to load animation texture!\n");
		success = false;
	}

	if (!sceneTexture.loadFromFile(renderer, "images/window.png")) {
		printf("Failed to load window texture!\n");
		success = false;
	}
	if (!gameOverTexture.loadFromFile(renderer, "images/game_over.png")) {
		printf("Failed to load Game over texture!\n");
		success = false;
	}
	if (!youWinTexture.loadFromFile(renderer, "images/you_win.png")) {
		printf("Failed to load You win texture!\n");
		success = false;
	}
	if (!youLoseTexture.loadFromFile(renderer, "images/you_lose.png")) {
		printf("Failed to load You lose texture!\n");
		success = false;
	}
	font = TTF_OpenFont("text/MAGNETOB.ttf", 18);
	if (font == NULL) {
		printf("Failed to load MAGNETOB font! SDL_ttf Error: %s\n",
		TTF_GetError());
		success = false;
	}
	if (!helpFirst.loadFromFile(renderer, "images/help_0.png")) {
		printf("Unable to render help texture!\n");
	}
	if (!helpSecond.loadFromFile(renderer, "images/help_1.png")) {
		printf("Unable to render help texture!\n");
	}
	for (int i = 0; i < NUMBER_OF_BUTTON; ++i) {
		std::stringstream path;
		path.str("");
		path << "images/button_" << i << ".png";
		if (!button[i].loadFromFile(renderer, path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/button_" << i << ".png";
		if (!button[i].loadBaseFromFile(renderer, path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/button_" << i << "_up.png";
		if (!button[i].loadMotionFromFile(renderer, path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/button_" << i << "_down.png";
		if (!button[i].loadDownFromFile(renderer, path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/button_" << i << "_up.png";
		if (!button[i].loadUpFromFile(renderer, path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
	}
	for (int i = 0; i < NUMBER_OF_TILE * 4; ++i) {
		std::stringstream path;
		path.str("");
		path << "images/tile_" << i / 4 << ".png";
		if (!tile[i].loadFromFile(renderer, path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/tile_" << i / 4 << ".png";
		if (!tile[i].loadBaseFromFile(renderer, path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/tile_" << i / 4 << "_up.png";
		if (!tile[i].loadMotionFromFile(renderer, path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/tile_" << i / 4 << "_down.png";
		if (!tile[i].loadDownFromFile(renderer, path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/tile_" << i / 4 << "_up.png";
		if (!tile[i].loadUpFromFile(renderer, path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
	}
	music = Mix_LoadMUS("sounds/background.mp3");
	if (music == NULL) {
		printf("Failed to load beat music! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}
	thunder = Mix_LoadWAV("sounds/thunder.wav");
	if (thunder == NULL) {
		printf("Failed to load thunder sound effect! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}
	bombExploding = Mix_LoadWAV("sounds/bombExploding.wav");
	if (bombExploding == NULL) {
		printf(
				"Failed to load bombExploding sound effect! SDL_mixer Error: %s\n",
				Mix_GetError());
		success = false;
	}
	explosion = Mix_LoadWAV("sounds/explosion.wav");
	if (explosion == NULL) {
		printf("Failed to load explosion sound effect! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}
	click = Mix_LoadWAV("sounds/low.wav");
	if (click == NULL) {
		printf("Failed to load low sound effect! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}
	return success;
}

void GameApplication::close() {
	markTile.free();
	winAnimation.freeAnimation();
	firstAnimation_1.freeAnimation();
	secondAnimation_1.freeAnimation();
	firstAnimation_2.freeAnimation();
	secondAnimation_2.freeAnimation();
	firstAnimation_3.freeAnimation();
	secondAnimation_3.freeAnimation();

	sceneTexture.free();
	gameOverTexture.free();
	youWinTexture.free();
	youLoseTexture.free();
	helpFirst.free();
	helpSecond.free();
	ptrHelp = NULL;
	board.freeBoard();
	tileMap.clear();
	checkPair.clear();
	pairXY.clear();

	for (int i = 0; i < NUMBER_OF_TILE * 4; ++i) {
		tile[i].freeButton();
	}
	for (int i = 0; i < NUMBER_OF_BUTTON; ++i) {
		button[i].freeButton();
	}
	TTF_CloseFont(font);
	font = NULL;
	Mix_FreeMusic(music);
	music = NULL;
	Mix_FreeChunk(thunder);
	thunder = NULL;
	Mix_FreeChunk(bombExploding);
	bombExploding = NULL;
	Mix_FreeChunk(explosion);
	explosion = NULL;
	Mix_FreeChunk(click);
	click = NULL;

	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void GameApplication::logicButtons(bool temp[]) {
	for (int i = 0; i < NUMBER_OF_BUTTON; ++i) {
		if (temp[i] == true) {
			switch (i) {
			case 0:
				if (!lockButtons) {
					startStopGame();
				}
				if (chunk) {
					Mix_PlayChannel(-1, click, 0);
				}
				temp[i] = false;
				break;
			case 1:
				if (!lockButtons) {
					setToDefault();
					loadGame(board);
					if (availableMatches() == 0) {
						startStopGame();
					}
				}
				if (chunk) {
					Mix_PlayChannel(-1, click, 0);
				}
				temp[i] = false;
				break;
			case 2:
				showHelp();
				if (chunk) {
					Mix_PlayChannel(-1, click, 0);
				}
				temp[i] = false;
				break;
			case 3:
				startStopSound();
				if (chunk) {
					Mix_PlayChannel(-1, click, 0);
				}
				temp[i] = false;
				break;
			}
		}
	}
}

void GameApplication::startStopTimer() {
	if (timer.isStarted()) {
		timer.stop();
	} else {
		timer.start();
	}
}

void GameApplication::startStopSound() {
	if (Mix_PlayingMusic() == 0) {
		Mix_PlayMusic(music, -1);
		chunk = true;
	} else {
		if (Mix_PausedMusic() == 1) {
			Mix_ResumeMusic();
			chunk = true;
		} else {
			Mix_PauseMusic();
			chunk = false;
		}
	}
}

void GameApplication::showHelp() {
	lockButtons = true;
	if (ptrHelp == NULL) {
		ptrHelp = &helpFirst;
	} else if (ptrHelp == &helpFirst) {
		ptrHelp = &helpSecond;
	} else {
		lockButtons = false;
		ptrHelp = NULL;
	}
}

void GameApplication::startStopGame() {
	if (board.isStarted()) {
		board.stop();
		startStopTimer();
		setToDefault();
	} else {
		if (!theGameIsOver()) {
			board.start();
			startStopTimer();
			bet();
			setToDefault();
		} else {
			gameOver = true;
		}
	}
}

void GameApplication::drowGame(Board board) {
	int x = 200;
	int y = 100;
	int moveY = 0;
	int temp = 0;

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	sceneTexture.render(renderer, 0, 0);

	if (ptrHelp == NULL) {

		for (int i = 0; i < NUMBER_OF_BUTTON; ++i) {
			if (i == 3) {
				button[i].setPosition(760, 5);
			} else {
				button[i].setPosition(650, 50 + 40 * i);
			}
			button[i].renderButton(renderer);
		}

		if (board.isStarted()) {
			for (int i = 0; i < 5; ++i) {
				for (int j = 0; j < 6; ++j) {
					if (!board.pile[i][j].empty()) {
						temp = takeID(board.pile[i][j].top().getFace());
						tile[temp].setFace(board.pile[i][j].top().getFace());
						tile[temp].setBlocked(
								!board.pile[i][j].top().getBlocked());
						tile[temp].coordinates.i = i;
						tile[temp].coordinates.j = j;
						moveY = 0;
						for (size_t z = 0; z < board.pile[i][j].size(); z++) {
							tile[temp].setPosition(x, y + moveY);
							tile[temp].renderButton(renderer);
							moveY -= 3;
						}
					}
					x += tile[temp].getWidth();
				}
				y += (tile[temp].getHeight() + 4);
				x = 200;
			}
		}
		if (gameOver) {
			gameOverTexture.render(renderer, (SCREEN_WIDTH - gameOverTexture.getWidth()) / 2,
					(SCREEN_HEIGHT - gameOverTexture.getHeight()) / 2);
		}
		if (youWin) {
			youWinTexture.render(renderer, (SCREEN_WIDTH - youWinTexture.getWidth()) / 2,
					(SCREEN_HEIGHT - youWinTexture.getHeight()) / 2);
		}
		if (youLose) {
			youLoseTexture.render(renderer, (SCREEN_WIDTH - youLoseTexture.getWidth()) / 2,
					(SCREEN_HEIGHT - youLoseTexture.getHeight()) / 2);
		}
	} else {
		ptrHelp->render(renderer, 25, 50);
		button[2].setPosition(
				25 + ptrHelp->getWidth() / 2 - button[2].getWidth() / 2,
				ptrHelp->getHeight());
		button[2].renderButton(renderer);
		button[3].setPosition(760, 5);
		button[3].renderButton(renderer);
	}

	markSelectedTile();

	generateTime();
	wordTime.render(renderer, 20, 550);

	generateMoves();
	wordMoves.render(renderer, 20, 530);

	generateMatches();
	wordMatches.render(renderer, 20, 510);

	generateCredits();
	wordCredits.render(renderer, 630, 470);

	generateInfo();
	wordAllGame.render(renderer, 630, 490);
	wordWinGame.render(renderer, 630, 510);
	wordLoseGame.render(renderer, 630, 530);
	wordWinRateGame.render(renderer, 630, 550);

	firstAnimation_1.renderAnimation(renderer);
	secondAnimation_1.renderAnimation(renderer);
	firstAnimation_2.renderAnimation(renderer);
	secondAnimation_2.renderAnimation(renderer);
	firstAnimation_3.renderAnimation(renderer);
	secondAnimation_3.renderAnimation(renderer);
	winAnimation.renderAnimation(renderer);

	SDL_RenderPresent(renderer);
}

int GameApplication::takeID(faceType type) {
	for (int i = FIRST; i < NONE; ++i) {
		if (i == type) {
			int temp = tileMap[i];
			if (temp < 4) {
				tileMap[i] = temp + 1;
				return i * 4 + temp;
			} else {
				tileMap[i] = 0;
				return i * 4;
			}
		}
	}
	return 0;
}

void GameApplication::eraseTileMap() {
	for (int i = 0; i < NUMBER_OF_TILE * 4; ++i) {
		tile[i].setPosition(0, 0);
	}
	for (int i = FIRST; i < NONE; ++i) {
		tileMap[i] = 0;
	}
}

void GameApplication::logicBoard() {
	eraseTileMap();
	unblockedBoard();

	if (endOfTheGame() && board.isStarted()) {
		youWin = true;
		winGames++;
		allGames++;
		award(calculateAward(calculate()));
		saveStatsFile(allGames, winGames);
		board.stop();
		timer.stop();
		winAnimation.startAnimation(50, 50);
	}
	if (availableMatches() == 0 && board.isStarted()) {
		youLose = true;
		allGames++;
		saveStatsFile(allGames, winGames);
		board.stop();
		timer.stop();
	}
}

void GameApplication::takePair() {
	if (pairXY.size() == 0) {
		tempCoord.x = coordI;
		tempCoord.y = coordJ;
		pairXY.push_back(tempCoord);
		checkPair.push_back(board.pile[coordI][coordJ].top());
	} else if (pairXY.size() == 1) {
		if (pairXY.back().x == coordI && pairXY.back().y == coordJ) {
			pairXY.clear();
			checkPair.clear();
		} else {
			tempCoord.x = coordI;
			tempCoord.y = coordJ;
			pairXY.push_back(tempCoord);
			checkPair.push_back(board.pile[coordI][coordJ].top());
		}

	}
	if (checkPair.size() == 2) {
		if (checkPair[0].getFace() == checkPair[1].getFace()
				&& !board.pile[pairXY[0].x][pairXY[0].y].top().getBlocked()
				&& !board.pile[pairXY[1].x][pairXY[1].y].top().getBlocked()) {
			moves++;
			backSpace.push(lastPair);
			backSpace.top().first.x = pairXY[0].x;
			backSpace.top().first.y = pairXY[0].y;
			backSpace.top().second.x = pairXY[1].x;
			backSpace.top().second.y = pairXY[1].y;
			returnPair.push(board.pile[pairXY[0].x][pairXY[0].y].top());
			returnPair.push(board.pile[pairXY[1].x][pairXY[1].y].top());
			board.pile[pairXY[0].x][pairXY[0].y].pop();
			board.pile[pairXY[1].x][pairXY[1].y].pop();
			pairXY.clear();
			checkPair.clear();
			if (returnPair.top().getFace() < SIXTH) {
				firstAnimation_1.startAnimation(
						200 + pairXY[0].y * firstAnimation_1.getWidth(),
						100 + pairXY[0].x * firstAnimation_1.getHeight());
				secondAnimation_1.startAnimation(
						200 + pairXY[1].y * secondAnimation_1.getWidth(),
						100 + pairXY[1].x * secondAnimation_1.getHeight());
				if (chunk) {
					Mix_PlayChannel(-1, explosion, 0);
				}
			} else if (returnPair.top().getFace() < EVELENTH) {
				firstAnimation_2.startAnimation(
						200 + pairXY[0].y * firstAnimation_2.getWidth(),
						100 + pairXY[0].x * firstAnimation_2.getHeight());
				secondAnimation_2.startAnimation(
						200 + pairXY[1].y * secondAnimation_2.getWidth(),
						100 + pairXY[1].x * secondAnimation_2.getHeight());
				if (chunk) {
					Mix_PlayChannel(-1, bombExploding, 0);
				}
			} else if (returnPair.top().getFace() < NONE) {
				firstAnimation_3.startAnimation(
						200 + pairXY[0].y * firstAnimation_3.getWidth(),
						100 + pairXY[0].x * firstAnimation_3.getHeight());
				secondAnimation_3.startAnimation(
						200 + pairXY[1].y * secondAnimation_3.getWidth(),
						100 + pairXY[1].x * secondAnimation_3.getHeight());
				if (chunk) {
					Mix_PlayChannel(-1, thunder, 0);
				}
			}
			saveGame(board);
		} else {
			pairXY.clear();
			checkPair.clear();
		}
	}
}

bool GameApplication::endOfTheGame() {
	bool endGame = true;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (!board.pile[i][j].empty()) {
				endGame = false;
				break;
			}
		}
	}
	return endGame;
}

int GameApplication::availableMatches() {
	int result = 0;
	std::multiset<faceType> temp;
	unblockedBoard();

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (!board.pile[i][j].empty()
					&& !board.pile[i][j].top().getBlocked()) {
				temp.insert(board.pile[i][j].top().getFace());
			}
		}
	}

	for (size_t i = FIRST; i < NONE; ++i) {
		faceType face = static_cast<faceType>(i);
		result += temp.count(face) / 2;
	}
	return result;
}

void GameApplication::unblockedBoard() {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 6; ++j) {
			board.unblock(i, j);
		}
	}
}

void GameApplication::generateTime() {
	std::stringstream text;
	SDL_Color textColor = { 255, 255, 255, 255 };
	text.str("");
	text << "Time: " << std::fixed << std::setprecision(0)
			<< timer.getTicks() / 1000.f;
	if (!wordTime.loadFromRenderedText(renderer, font, text.str().c_str(), textColor)) {
		printf("Unable to render time texture!\n");
	}
}

void GameApplication::generateMoves() {
	std::stringstream text;
	SDL_Color textColor = { 255, 255, 255, 255 };
	text.str("");
	text << "Moves: " << moves;
	if (!wordMoves.loadFromRenderedText(renderer, font, text.str().c_str(), textColor)) {
		printf("Unable to render time texture!\n");
	}
}

void GameApplication::generateMatches() {
	std::stringstream text;
	SDL_Color textColor = { 255, 255, 255, 255 };
	text.str("");
	matches = availableMatches();
	text << "Available matches: " << matches;
	if (!wordMatches.loadFromRenderedText(renderer, font, text.str().c_str(), textColor)) {
		printf("Unable to render time texture!\n");
	}
}

void GameApplication::generateCredits() {
	std::stringstream text;
	SDL_Color textColor = { 255, 255, 255, 255 };
	text.str("");
	text << "Credits: " << credits;
	if (!wordCredits.loadFromRenderedText(renderer, font, text.str().c_str(), textColor)) {
		printf("Unable to render time texture!\n");
	}
}

void GameApplication::generateInfo() {
	std::stringstream text;
	SDL_Color textColor = { 255, 255, 255, 255 };
	text.str("");
	text << "All games: " << allGames;
	if (!wordAllGame.loadFromRenderedText(renderer, font, text.str().c_str(), textColor)) {
		printf("Unable to render time texture!\n");
	}
	text.str("");
	text << "Win games: " << winGames;
	if (!wordWinGame.loadFromRenderedText(renderer, font, text.str().c_str(), textColor)) {
		printf("Unable to render time texture!\n");
	}
	text.str("");
	text << "Lose game: " << allGames - winGames;
	if (!wordLoseGame.loadFromRenderedText(renderer, font, text.str().c_str(), textColor)) {
		printf("Unable to render time texture!\n");
	}
	text.str("");
	text << std::fixed << std::setprecision(1) << "Win rate: "
			<< ((double) winGames / (double) allGames * 100.0) << "%";
	if (!wordWinRateGame.loadFromRenderedText(renderer, font, text.str().c_str(), textColor)) {
		printf("Unable to render time texture!\n");
	}
}

void GameApplication::undo() {
	if (!returnPair.empty()) {
		board.pile[backSpace.top().first.x][backSpace.top().first.y].push(
				returnPair.top());
		board.block(backSpace.top().first.x, backSpace.top().first.y);
		returnPair.pop();
		board.pile[backSpace.top().second.x][backSpace.top().second.y].push(
				returnPair.top());
		board.block(backSpace.top().second.x, backSpace.top().second.y);
		returnPair.pop();
		backSpace.pop();
		saveGame(board);
	}
}

void GameApplication::bet() {
	credits -= BET;
}

void GameApplication::award(int multiply) {
	credits += (multiply * BET);
}

bool GameApplication::theGameIsOver() {
	return ((credits - BET) < 0);
}

int GameApplication::calculate() {
	if (moves == 30) {
		return 2;
	} else if (moves < 40) {
		return 1;
	} else {
		return 0;
	}
}

int GameApplication::calculateAward(int multiply) {
	int time = timer.getTicks() / 1000.f;
	if (time < 60) {
		return multiply + 3;
	} else if (time < 90) {
		return multiply + 2;
	} else if (time < 120) {
		return multiply + 1;
	}
	return multiply;
}

void GameApplication::saveGame(Board saveBoard) {
	std::vector<int> temp;
	unsigned sizeOfStack;
	int element;
	Uint32 time = timer.getTicks() / 1000.f;
	std::ofstream file("files/recovery.dat", std::ios::out | std::ios::binary);

	if (file.is_open()) {
		file.write(reinterpret_cast<const char*>(&moves), sizeof(int));
		file.write(reinterpret_cast<const char*>(&credits), sizeof(int));
		file.write(reinterpret_cast<const char*>(&time), sizeof(Uint32));
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 6; ++j) {
				temp.clear();
				sizeOfStack = saveBoard.pile[i][j].size();
				file.write(reinterpret_cast<const char*>(&sizeOfStack),
						sizeof(unsigned));
				while (!saveBoard.pile[i][j].empty()) {
					element = saveBoard.pile[i][j].top().getFace();
					temp.push_back(element);
					saveBoard.pile[i][j].pop();
				}
				while (!temp.empty()) {
					element = temp.back();
					file.write(reinterpret_cast<char*>(&element), sizeof(int));
					temp.pop_back();
				}
			}
		}
		file.close();
	} else {
		printf("recovery.dat can't be open for write!");
	}
}

void GameApplication::loadGame(Board &tempBoard) {
	Tile tempTile;
	int temp;
	unsigned sizeOfStack;
	Uint32 time;

	std::ifstream file;
	file.open("files/recovery.dat", std::ios::in | std::ios::binary);

	tempBoard.freeBoard();

	if (file.is_open()) {
		file.read(reinterpret_cast<char*>(&moves), sizeof(int));
		file.read(reinterpret_cast<char*>(&credits), sizeof(int));
		file.read(reinterpret_cast<char*>(&time), sizeof(Uint32));
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 6; ++j) {
				file.read(reinterpret_cast<char*>(&sizeOfStack),
						sizeof(unsigned));
				while (tempBoard.pile[i][j].size() < sizeOfStack) {
					file.read(reinterpret_cast<char*>(&temp), sizeof(int));
					tempTile.setFace(returnFaceType(temp));
					tempBoard.pile[i][j].push(tempTile);
				}
			}
		}
		timer.loadTime(time);
		tempBoard.startGame = true;
		file.close();
	} else {
		printf("recovery.dat can't be open for read");
	}
}

faceType GameApplication::returnFaceType(int temp) {
	for (int i = FIRST; i < NONE; ++i) {
		if (i == temp) {
			faceType face = static_cast<faceType>(i);
			return face;
		}
	}
	return NONE;
}

void GameApplication::saveStatsFile(int all, int win) {
	std::ofstream file("files/statsFile.bin", std::ios::out | std::ios::binary);
	if (file.is_open()) {
		file.write(reinterpret_cast<const char*>(&all), sizeof(int));
		file.write(reinterpret_cast<const char*>(&win), sizeof(int));
		file.close();
	} else {
		printf("statsFile.bin can't be open!");
	}
}

void GameApplication::loadStatsFile() {
	std::ifstream file;
	file.open("files/statsFile.bin");
	if (file.is_open()) {
		file.read(reinterpret_cast<char*>(&allGames), sizeof(int));
		file.read(reinterpret_cast<char*>(&winGames), sizeof(int));
		file.close();
	} else {
		printf("statsFile.bin can't be open!");
	}
}

void GameApplication::musicVolumeControl() {
	Mix_VolumeChunk(click, 50);
	Mix_VolumeChunk(explosion, 10);
	Mix_VolumeChunk(bombExploding, 50);
	Mix_VolumeChunk(thunder, 80);
	Mix_VolumeMusic(70);
}

void GameApplication::setToDefault() {
	mark = 0;
	youWin = false;
	youLose = false;
	moves = 0;
	while (!returnPair.empty()) {
		returnPair.pop();
	}
	while (!backSpace.empty()) {
		backSpace.pop();
	}
	pairXY.clear();
	checkPair.clear();
}

void GameApplication::markSelectedTile() {
	if (board.pile[coordI][coordJ].size() == 3) {

		if (mark < 2) {
			if (mark == 1) {
				markTile.render(renderer, 200 + coordJ * markTile.getWidth(),
						100 + coordI * (markTile.getHeight() + 4) - 6);
			}
		} else {
			mark = 0;
		}
	} else if (board.pile[coordI][coordJ].size() == 2) {

		if (mark < 2) {
			if (mark == 1) {
				markTile.render(renderer, 200 + coordJ * markTile.getWidth(),
						100 + coordI * (markTile.getHeight() + 4) - 3);
			}
		} else {
			mark = 0;
		}
	} else {

		if (mark < 2) {
			if (mark == 1) {
				markTile.render(renderer, 200 + coordJ * markTile.getWidth(),
						100 + coordI * (markTile.getHeight() + 4));
			}
		} else {
			mark = 0;
		}
	}
}

void GameApplication::gameLoop(){
    loadStatsFile();
    musicVolumeControl();
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_BACKSPACE) {
                    if (board.isStarted() && !endOfTheGame()) {
                        undo();
                    }
                }
            }
            for (int i = 0; i < NUMBER_OF_BUTTON; ++i) {
                if (lockButtons) {
                    temp[2] = button[2].handleEvent(e);
                    temp[3] = button[3].handleEvent(e);
                } else {
                    temp[i] = button[i].handleEvent(e);
                }
            }
            for (int i = 0; i < NUMBER_OF_TILE * 4; i++) {
                choice = tile[i].handleEvent(e, coordI, coordJ);
                if (choice == true) {
                    mark++;
                    if (!board.pile[coordI][coordJ].empty()) {
                        takePair();
                        break;
                    } else {
                        choice = false;
                    }
                }
            }
        }

        logicButtons(temp);
        logicBoard();

        drowGame(board);
    }
}

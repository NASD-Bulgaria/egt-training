#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <sstream>
#include <stdio.h>
#include <SDL_image.h>
#include "LWindow.h"
#include "LTimer.h"
#include "LButton.h"
#include "LTile.h"
#include "Board.h"

const int NUMBER_OF_TILE = 15;
const int NUMBER_OF_BUTTON = 4;
LWindow gWindow;
SDL_Renderer* gRenderer = NULL;
LTexture gSceneTexture;
LButton gButton[NUMBER_OF_BUTTON];
LTimer gTimer;
TTF_Font* gFont = NULL;
LTexture gHelp;
LTexture* gPtrHelp = NULL;
Board board;
LTile gTile[NUMBER_OF_TILE * 4];
std::map<int, int> tileMap;
std::vector<Tile> checkPair;
int coordI = 0;
int coordJ = 0;
bool choice = false;
tileCoord tempCoord;
std::vector<tileCoord> pairXY;
int gMoves = 0;
int gMatches = 0;
LTexture gWordTime;
LTexture gWordMoves;
LTexture gWordMatches;

bool init();
bool loadMedia();
void close();
void renderTexture(LTexture *sceneTexture, int x, int y, int w, int h);
void logicButtons(bool temp[]);
void startStopTimer();
void showHelp();
void drowGame(Board board);
int takeID(faceType);
void startStopGame();
void eraseTileMap();
faceType returnFace(int number);
void logicBoard();
void takePair();
bool endOfTheGame();
int availableMatches();
void unblockedBoard();
void calculateTime();
void calculateMoves();
void calculateMatches();

int main(int argc, char* args[]) {
	if (!init()) {
		printf("Failed to initialize!\n");
	} else {
		if (!loadMedia()) {
			printf("Failed to load media!\n");
		} else {
			bool quit = false;
			SDL_Event e;

			bool temp[NUMBER_OF_BUTTON] = { false };

			while (!quit) {
				while (SDL_PollEvent(&e) != 0) {
					if (e.type == SDL_QUIT) {
						quit = true;
					}
					for (int i = 0; i < NUMBER_OF_BUTTON; ++i) {
						temp[i] = gButton[i].handleEvent(e);
					}
					for (int i = 0; i < NUMBER_OF_TILE * 4; i++) {
						choice = gTile[i].handleEvent(e, coordI, coordJ);
						if (choice == true) {
							if (!board.pile[coordI][coordJ].empty()) {
                                takePair();
								break;
							} else {
								choice = false;
							}
						}
					}

					//Handle window events
					gWindow.handleEvent(e);
					if (gWindow.isMinimized()) {
						gTimer.pause();
					} else {
						gTimer.unpause();
					}
				}

				logicButtons(temp);
				logicBoard();

				if (!gWindow.isMinimized()) {
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
					SDL_RenderClear(gRenderer);
					renderTexture(&gSceneTexture, 0, 0, gWindow.getWidth(),
							gWindow.getHeight());

					for (int i = 0; i < NUMBER_OF_BUTTON; ++i) {
						gButton[i].setPosition(650, 50 + 40 * i);
						gButton[i].renderButton();
					}

                    calculateTime();
					gWordTime.render(20, 550);

                    calculateMoves();
					gWordMoves.render(20, 530);

                    calculateMatches();
					gWordMatches.render(20, 510);

                    drowGame(board);

					SDL_RenderPresent(gRenderer);
				}
			}
		}
	}
	close();
	return 0;
}

void renderTexture(LTexture *sceneTexture, int x, int y, int w, int h) {
	SDL_Rect stretchRect;
	stretchRect.x = 0;
	stretchRect.y = 0;
	stretchRect.w = w;
	stretchRect.h = h;
	sceneTexture->render(x, y, &stretchRect);
}

bool init() {
	bool success = true;
	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	} else {
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf("Warning: Linear texture filtering not enabled!");
		}
		if (!gWindow.init()) {
			printf("Window could not be created! SDL Error: %s\n",
					SDL_GetError());
			success = false;
		} else {
			gRenderer = gWindow.createRenderer();
			if (gRenderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n",
						SDL_GetError());
				success = false;
			} else {
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
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
			}
		}
	}
	return success;
}

bool loadMedia() {
	bool success = true;
	if (!gSceneTexture.loadFromFile("images/window.png")) {
		printf("Failed to load window texture!\n");
		success = false;
	}

	gFont = TTF_OpenFont("text/lazy.ttf", 16);
	if (gFont == NULL) {
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	if (!gHelp.loadFromFile("images/help.png")) {
		printf("Unable to render time texture!\n");
	}
	for (int i = 0; i < NUMBER_OF_BUTTON; ++i) {
		std::stringstream path;
		path.str("");
		path << "images/button_" << i << ".png";
		if (!gButton[i].loadFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/button_" << i << ".png";
		if (!gButton[i].loadBaseFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/button_" << i << "_up.png";
		if (!gButton[i].loadMotionFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/button_" << i << "_down.png";
		if (!gButton[i].loadDownFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/button_" << i << "_up.png";
		if (!gButton[i].loadUpFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
	}
	for (int i = 0; i < NUMBER_OF_TILE * 4; ++i) {
		std::stringstream path;
		path.str("");
		path << "images/tile_" << i / 4 << ".png";
		if (!gTile[i].loadFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/tile_" << i / 4 << ".png";
		if (!gTile[i].loadBaseFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/tile_" << i / 4 << "_up.png";
		if (!gTile[i].loadMotionFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/tile_" << i / 4 << "_down.png";
		if (!gTile[i].loadDownFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/tile_" << i / 4 << "_up.png";
		if (!gTile[i].loadUpFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
	}
	return success;
}

void close() {
	gSceneTexture.free();
	gHelp.free();
	gPtrHelp = NULL;
	board.freeBoard();
	tileMap.clear();
	checkPair.clear();
	pairXY.clear();
	gWordTime.free();
	gWordMoves.free();
	gWordMatches.free();

	for (int i = 0; i < NUMBER_OF_TILE * 4; ++i) {
		gTile[i].freeButton();
	}
	for (int i = 0; i < NUMBER_OF_BUTTON; ++i) {
		gButton[i].freeButton();
	}
	TTF_CloseFont(gFont);
	gFont = NULL;

	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;
	gWindow.free();

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void logicButtons(bool temp[]) {
	for (int i = 0; i < NUMBER_OF_BUTTON; ++i) {
		if (temp[i] == true) {
			switch (i) {
			case 0:
				printf("start function \n");
				startStopGame();
				temp[i] = false;
				break;
			case 1:
				printf("save function \n");
				temp[i] = false;
				break;
			case 2:
				printf("load function \n");
				temp[i] = false;
				break;
			case 3:
				printf("help function \n");
				showHelp();
				temp[i] = false;
				break;
			}
		}
	}
}

void startStopTimer() {
	if (gTimer.isStarted()) {
		gTimer.stop();
	} else {
		gTimer.start();
	}
}

void showHelp() {
	if (gPtrHelp == NULL) {
		gPtrHelp = &gHelp;
	} else {
		gPtrHelp = NULL;
	}
}

void startStopGame() {
	if (board.isStarted()) {
		board.stop();
		startStopTimer();
    }
    else {
		board.start();
		startStopTimer();
		gMoves = 0;
	}
}

void drowGame(Board board) {
	int x = 200;
	int y = 100;
	int moveY = 0;
	int temp = 0;

    if (gPtrHelp == NULL)
    {
        if (board.isStarted())
        {
            for (int i = 0; i < 5; ++i) {
                for (int g = 0; g < 6; ++g) {
                    if (!board.pile[i][g].empty()) {
                        temp = takeID(board.pile[i][g].top().getFace());
                        gTile[temp].setFace(board.pile[i][g].top().getFace());
                        gTile[temp].setBlocked(!board.pile[i][g].top().getBlocked());
                        gTile[temp].coordinates.i = i;
                        gTile[temp].coordinates.j = g;
                        if (board.pile[i][g].size() == 3) {
                            moveY = 0;
                            for (int z = 0; z < 3; z++){
                                gTile[temp].setPosition(x, y + moveY);
                                gTile[temp].renderButton();
                                moveY -= 3;
                            }
                        } else if (board.pile[i][g].size() == 2) {
                            moveY = 0;
                            for (int z = 0; z < 2; z++){
                                gTile[temp].setPosition(x, y + moveY);
                                gTile[temp].renderButton();
                                moveY -= 3;
                            }
                        } else {
                            moveY = 0;
                            gTile[temp].setPosition(x, y + moveY);
                            gTile[temp].renderButton();
                        }
                    }
                    x += gTile[temp].getWidth();
                }
                y += (gTile[temp].getHeight() + 2);
                x = 200;
            }
        }
    }
    else
    {
        gPtrHelp->render(25, 50);
    }
}

int takeID(faceType type) {
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

void eraseTileMap() {
	for (int i = FIRST; i < NONE; ++i) {
		tileMap[i] = 0;
	}
}

void logicBoard() {
	eraseTileMap();
    unblockedBoard();

	if(endOfTheGame() && board.isStarted())
    {
        std::cout<<"you win"<<" save in stats"<<std::endl;
        board.stop();
        gTimer.stop();
    }
    if(availableMatches() == 0 && board.isStarted())
    {
        std::cout<<"you lose"<<" save in stats"<<std::endl;
        board.stop();
        gTimer.stop();
    }
}

void takePair()
{
    if(pairXY.size() == 0)
    {
        tempCoord.x = coordI;
        tempCoord.y = coordJ;
        pairXY.push_back(tempCoord);
        checkPair.push_back(board.pile[coordI][coordJ].top());
    }
    else if(pairXY.size() == 1)
    {
        if(pairXY.back().x == coordI && pairXY.back().y == coordJ)
        {
            pairXY.clear();
            checkPair.clear();
            std::cout<<"unmark"<<std::endl;
        }
        else
        {
            tempCoord.x = coordI;
            tempCoord.y = coordJ;
            pairXY.push_back(tempCoord);
            checkPair.push_back(board.pile[coordI][coordJ].top());
        }

    }
    if(checkPair.size()==2)
    {
        if(checkPair[0].getFace() == checkPair[1].getFace() && !board.pile[pairXY[0].x][pairXY[0].y].top().getBlocked() && !board.pile[pairXY[1].x][pairXY[1].y].top().getBlocked() )
        {
            gMoves++;
            std::cout<<"OK"<<std::endl;
            board.pile[pairXY[0].x][pairXY[0].y].pop();
            board.pile[pairXY[1].x][pairXY[1].y].pop();
            pairXY.clear();
            checkPair.clear();
        }
        else
        {
            pairXY.clear();
            checkPair.clear();
            std::cout<<"unmark"<<std::endl;
        }
    }
}

bool endOfTheGame()
{
    bool endGame = true;
    for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 6; ++j) {
			if(!board.pile[i][j].empty())
            {
                endGame = false;
                break;
            }
		}
	}
	return endGame;
}

int availableMatches()
{
    int result = 0;
    std::multiset<faceType> temp;
    unblockedBoard();

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (!board.pile[i][j].empty() && !board.pile[i][j].top().getBlocked())
            {
                temp.insert(board.pile[i][j].top().getFace());
            }
        }
    }

    for(size_t i = FIRST; i < NONE; ++i)
    {
        faceType face = static_cast<faceType> (i);
        result += temp.count(face)/2;
    }
    return result;
}

void unblockedBoard()
{
    for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 6; ++j) {
			board.unblock(i, j);
		}
	}
}

void calculateTime()
{
    std::stringstream text;
    SDL_Color textColor = { 0, 0, 0, 255 };
    text.str("");
    text << "Time: " << std::fixed << std::setprecision(0)
            << gTimer.getTicks() / 1000.f;
    //Render text
    if (!gWordTime.loadFromRenderedText(text.str().c_str(),
            textColor)) {
        printf("Unable to render time texture!\n");
    }
}

void calculateMoves()
{
    std::stringstream text;
    SDL_Color textColor = { 0, 0, 0, 255 };
    text.str("");
    text << "Moves: " << gMoves;
    if (!gWordMoves.loadFromRenderedText(text.str().c_str(),
            textColor)) {
        printf("Unable to render time texture!\n");
    }
}

void calculateMatches()
{
    std::stringstream text;
    SDL_Color textColor = { 0, 0, 0, 255 };
    text.str("");
    gMatches = availableMatches();
    text << "Available matches: " << gMatches;
    if (!gWordMatches.loadFromRenderedText(text.str().c_str(),
            textColor)) {
        printf("Unable to render time texture!\n");
    }
}

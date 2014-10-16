#ifndef GAMEAPPLICATION_H
#define GAMEAPPLICATION_H

#include <iomanip>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Timer.h"
#include "Button.h"
#include "TileButton.h"
#include "Board.h"
#include "Animation.h"

const int NUMBER_OF_TILE = 15;
const int NUMBER_OF_BUTTON = 4;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int BET = 10;

class GameApplication
{
    public:
        /** Default constructor */
        GameApplication();
        /** Default destructor */
        virtual ~GameApplication();
        bool init();
        bool loadMedia();
        void close();
        void logicButtons(bool temp[]);
        void startStopTimer();
        void startStopSound();
        void showHelp();
        void drowGame(Board board);
        int takeID(faceType);
        void startStopGame();
        void eraseTileMap();
        void logicBoard();
        void takePair();
        bool endOfTheGame();
        int availableMatches();
        void unblockedBoard();
        void generateTime();
        void generateMoves();
        void generateMatches();
        void generateInfo();
        void generateCredits();
        void saveStatsFile(int, int);
        void loadStatsFile();
        void undo();
        void bet();
        void award(int multiply);
        int calculate();
        int calculateAward(int multiply);
        bool theGameIsOver();
        void saveGame(Board saveBoard);
        void loadGame(Board &tempBoard);
        faceType returnFaceType(int temp);
        void musicVolumeControl();
        void setToDefault();
        void markSelectedTile();
        void gameLoop();

    protected:
    private:
        SDL_Window* window;
SDL_Renderer* renderer;
TTF_Font* font;
        Texture sceneTexture;
        Button button[NUMBER_OF_BUTTON];
        Timer timer;
        Texture helpFirst;
        Texture helpSecond;
        bool lockButtons;
        Texture* ptrHelp;
        Texture gameOverTexture;
        Texture youWinTexture;
        Texture youLoseTexture;
        Texture wordTime;
        Texture wordMoves;
        Texture wordMatches;
        Texture wordAllGame;
        Texture wordWinGame;
        Texture wordLoseGame;
        Texture wordWinRateGame;
        Texture wordCredits;
        Board board;
        TileButton tile[NUMBER_OF_TILE * 4];
        std::map<int, int> tileMap;
        std::vector<Tile> checkPair;
        int coordI;
        int coordJ;
        bool choice;
        tileCoord tempCoord;
        std::vector<tileCoord> pairXY;
        int moves;
        int credits;
        int matches;
        Mix_Music* music;
        Mix_Chunk* thunder;
        Mix_Chunk* bombExploding;
        Mix_Chunk* explosion;
        Mix_Chunk* click;
        bool chunk;
        pairCoord lastPair;
        std::stack<pairCoord> backSpace;
        std::stack<Tile> returnPair;
        bool gameOver;
        bool youWin;
        bool youLose;
        int allGames;
        int winGames;
        Animation firstAnimation_1;
        Animation secondAnimation_1;
        Animation firstAnimation_2;
        Animation secondAnimation_2;
        Animation firstAnimation_3;
        Animation secondAnimation_3;
        Animation winAnimation;
        Texture markTile;
        int mark;
        bool temp[NUMBER_OF_BUTTON];
        bool quit;
        SDL_Event e;
};

#endif // GAMEAPPLICATION_H

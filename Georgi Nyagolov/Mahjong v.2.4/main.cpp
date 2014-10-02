//#include <SDL.h>
//#include <SDL_image.h>
//#include <SDL_ttf.h>
//#include <stdio.h>
//#include <vector>
//#include <stack>
//#include <string>
//#include <sstream>
#include <iostream>
#include <iomanip>
#include <map>
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
std::map <int, int> tileMap;

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

int main(int argc, char* args[])
{

    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            bool quit = false;
            SDL_Event e;
            LTexture word;
            SDL_Color textColor = { 0, 0, 0, 255 };
            std::stringstream timeText;
            LButton* ptrButton[NUMBER_OF_BUTTON];
            for (int i = 0; i < NUMBER_OF_BUTTON; ++i)
            {
                ptrButton[i] = &gButton[i];
            }

            bool temp[NUMBER_OF_BUTTON] = { false };

            while (!quit)
            {
                while (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                    for (int i = 0; i < NUMBER_OF_BUTTON; ++i)
                    {
                        temp[i] = ptrButton[i]->handleEvent(e);
                    }

                    for (int i = 0; i < NUMBER_OF_TILE * 4; i++)
                    {
                        gTile[i].handleEvent(e);
                    }

                    //Handle window events
                    gWindow.handleEvent(e);
                    if (gWindow.isMinimized())
                    {
                        gTimer.pause();
                    }
                    else
                    {
                        gTimer.unpause();
                    }
                }

                logicButtons(temp);



//                for (int i = 0; i < 5; ++i){
//                    for (int g = 0; g < 6; ++g){
//                        board.unblock(i, g);
//                    }
//                }
//                for (int i = 0; i < 5; ++i){
//                    for (int g = 0; g < 6; ++g){
//                        board.unblock(i, g);
//                    }
//                }

                if (!gWindow.isMinimized())
                {
                    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                    SDL_RenderClear(gRenderer);
                    renderTexture(&gSceneTexture, 0, 0, gWindow.getWidth(),
                                  gWindow.getHeight());

                    for (int i = 0; i < NUMBER_OF_BUTTON; ++i)
                    {
                        ptrButton[i]->setPosition(650, 50 + 40 * i);
                        ptrButton[i]->renderButton();
                    }
                    timeText.str("");
                    timeText << "Time: " << std::fixed << std::setprecision(1)
                             << (gTimer.getTicks() / 1000.f);
                    //Render text
                    if (!word.loadFromRenderedText(timeText.str().c_str(),
                                                   textColor))
                    {
                        printf("Unable to render time texture!\n");
                    }
                    word.render(20, 550);



                    if (gPtrHelp == NULL)
                    {
                        if (board.isStarted())
                        {
                            drowGame(board);
                        }

                    }

                    else
                    {
                        gPtrHelp->render(25, 50);
                    }

                    SDL_RenderPresent(gRenderer);
                }
            }
        }
    }
    close();
    return 0;
}

void renderTexture(LTexture *sceneTexture, int x, int y, int w, int h)
{
    SDL_Rect stretchRect;
    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.w = w;
    stretchRect.h = h;
    sceneTexture->render(x, y, &stretchRect);
}

bool init()
{
    bool success = true;
    if (SDL_Init( SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }
        if (!gWindow.init())
        {
            printf("Window could not be created! SDL Error: %s\n",
                   SDL_GetError());
            success = false;
        }
        else
        {
            gRenderer = gWindow.createRenderer();
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n",
                       SDL_GetError());
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf(
                        "SDL_image could not initialize! SDL_image Error: %s\n",
                        IMG_GetError());
                    success = false;
                }
                if (TTF_Init() == -1)
                {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n",
                           TTF_GetError());
                    success = false;
                }
            }
        }
    }
    return success;
}

bool loadMedia()
{
    bool success = true;
    if (!gSceneTexture.loadFromFile("images/window.png"))
    {
        printf("Failed to load window texture!\n");
        success = false;
    }

    gFont = TTF_OpenFont("text/lazy.ttf", 16);
    if (gFont == NULL)
    {
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    }
    if (!gHelp.loadFromFile("images/help.png"))
    {
        printf("Unable to render time texture!\n");
    }
    for (int i = 0; i < NUMBER_OF_BUTTON; ++i)
    {
        std::stringstream path;
        path.str("");
        path << "images/button_" << i << ".png";
        if (!gButton[i].loadFromFile(path.str().c_str()))
        {
            printf("Failed to load image texture!\n");
            success = false;
        }
        path.str("");
        path << "images/button_" << i << ".png";
        if (!gButton[i].loadBaseFromFile(path.str().c_str()))
        {
            printf("Failed to load image texture!\n");
            success = false;
        }
        path.str("");
        path << "images/button_" << i << "_up.png";
        if (!gButton[i].loadMotionFromFile(path.str().c_str()))
        {
            printf("Failed to load image texture!\n");
            success = false;
        }
        path.str("");
        path << "images/button_" << i << "_down.png";
        if (!gButton[i].loadDownFromFile(path.str().c_str()))
        {
            printf("Failed to load image texture!\n");
            success = false;
        }
        path.str("");
        path << "images/button_" << i << "_up.png";
        if (!gButton[i].loadUpFromFile(path.str().c_str()))
        {
            printf("Failed to load image texture!\n");
            success = false;
        }
    }
    for (int i = 0; i < NUMBER_OF_TILE * 4; ++i)
    {
        std::stringstream path;
        path.str("");
        path << "images/tile_" << i / 4 << ".png";
        if (!gTile[i].loadFromFile(path.str().c_str()))
        {
            printf("Failed to load image texture!\n");
            success = false;
        }
        path.str("");
        path << "images/tile_" << i / 4 << ".png";
        if (!gTile[i].loadBaseFromFile(path.str().c_str()))
        {
            printf("Failed to load image texture!\n");
            success = false;
        }
        path.str("");
        path << "images/tile_" << i / 4 << "_up.png";
        if (!gTile[i].loadMotionFromFile(path.str().c_str()))
        {
            printf("Failed to load image texture!\n");
            success = false;
        }
        path.str("");
        path << "images/tile_" << i / 4<< "_down.png";
        if (!gTile[i].loadDownFromFile(path.str().c_str()))
        {
            printf("Failed to load image texture!\n");
            success = false;
        }
        path.str("");
        path << "images/tile_" << i / 4 << "_up.png";
        if (!gTile[i].loadUpFromFile(path.str().c_str()))
        {
            printf("Failed to load image texture!\n");
            success = false;
        }
    }

    return success;
}

void close()
{
    gSceneTexture.free();
    gHelp.free();
    gPtrHelp = NULL;
    board.freeBoard();

    for (int i = 0; i < NUMBER_OF_TILE * 4; ++i)
    {
        gTile[i].freeButton();
    }
    for (int i = 0; i < NUMBER_OF_BUTTON; ++i)
    {
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

void logicButtons(bool temp[])
{
    for (int i = 0; i < NUMBER_OF_BUTTON; ++i)
    {
        if (temp[i] == true)
        {
            switch (i)
            {
            case 0:
                printf("start function \n");
                startStopTimer();
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

void startStopTimer()
{
    if (gTimer.isStarted())
    {
        gTimer.stop();
    }
    else
    {
        gTimer.start();
    }
}

void showHelp()
{
    if (gPtrHelp == NULL)
    {
        gPtrHelp = &gHelp;
    }
    else
    {
        gPtrHelp = NULL;
    }
}

void startStopGame()
{
    if (board.isStarted())
    {
        board.stop();
    }
    else
    {
        board.start();
    }
}

void drowGame(Board board)
{
    eraseTileMap();
    int x = 200;
    int y = 100;
    int moveY = 0;
    for (int i = 0; i < 5; ++i){
        for (int g = 0; g < 6; ++g){
            board.unblock(i, g);
            int temp = takeID(board.pile[i][g].top().getFace());
            gTile[temp].setblocked(!board.pile[i][g].top().getblocked());
            if (board.pile[i][g].size() == 3){
                moveY = 0;
                for (int z = 0; z < 3; z++){
                    gTile[temp].setPosition(x, y + moveY);
                    gTile[temp].renderButton();
                    moveY += 3;
                }
            }
            else if (board.pile[i][g].size() == 2){
                moveY = 0;
                for (int z = 0; z < 2; z++){
                    gTile[temp].setPosition(x, y + moveY);
                    gTile[temp].renderButton();
                    moveY += 3;
                }
            }
            else{
                moveY = 0;
                gTile[temp].setPosition(x,y + moveY);
                gTile[temp].renderButton();
            }
            x += 40;
        }
        if (i > 1){
            y += 64;
        }
        else{
            y += 68;
        }
        x = 200;
    }
}

int takeID(faceType type)
{
    for (int i = FIRST; i < NONE; ++i){
        if (i == type){
            int temp = tileMap[i];
            if(temp < 4){
                tileMap[i] = temp +1;
                return i * 4 + temp;
            }
            else{
                tileMap[i] = 0;
                return i*4;
            }
        }
    }
    return 0;
}

void eraseTileMap(){
    for(int i = FIRST; i < NONE; ++i){
        tileMap[i] = 0;
    }
}



/*
 * Board.h
 *
 *  Created on: Sep 29, 2014
 *      Author: ekipMahjong
 */
#include <stack>
#include <vector>
#include "LTile.h"

#ifndef BOARD_H_
#define BOARD_H_
struct tileCoord
{
    int x,y;
};
struct pairCoord
{
    tileCoord first, second;
};
class Board
{
public:
    Board();
    virtual ~Board();

    std::stack<LTile> pile[5][6];
    std::vector<std::stack<faceType> > tileHolder;
    std::stack<pairCoord> coordinates;
    std::vector<tileCoord> freeTile;
    bool startGame;

    void fillBoard();
    bool solvedPosition();
    void initField();
    void unblock(int x, int y);
    void fillFreeTiles();
    void generateGameBoard();
    void generateTiles();

    void start();
    void stop();
    bool isStarted();
    void freeBoard();

};

#endif /* BOARD_H_ */

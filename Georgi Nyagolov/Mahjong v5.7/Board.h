#ifndef BOARD_H_
#define BOARD_H_

#include <stack>
#include <vector>
#include "Tile.h"

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

    std::stack<Tile> pile[5][6];
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
    void block(int x,int y);

    void start();
    void stop();
    bool isStarted();
    void freeBoard();

};

#endif /* BOARD_H_ */

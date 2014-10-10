#include <ctime>
#include "Board.h"

Board::Board() :
    startGame(false)
{
}

Board::~Board()
{
    freeBoard();
}

bool Board::solvedPosition()
{
    int index;
    srand(time(NULL));
    pairCoord p;
    initField();
    fillFreeTiles();

    while (freeTile.size() > 0)
    {
        coordinates.push(p);
        index = rand() % freeTile.size();
        coordinates.top().first = freeTile[index];
        pile[freeTile[index].x][freeTile[index].y].pop();
        unblock(freeTile[index].x, freeTile[index].y);
        freeTile.erase(freeTile.begin() + index);

        if (freeTile.size() == 0)
        {
            return false;
        }

        index = rand() % freeTile.size();
        coordinates.top().second = freeTile[index];
        pile[freeTile[index].x][freeTile[index].y].pop();
        unblock(freeTile[index].x, freeTile[index].y);
        freeTile.erase(freeTile.begin() + index);

        fillFreeTiles();
    }
    return true;
}

void Board::fillBoard()
{
}

void Board::initField()
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            pile[i][j].push(Tile());
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            pile[i][j].push(Tile());
            if (i < 2)
            {
                pile[i][j].push(Tile());
            }
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (j == 0 || j == 5 || (j == 4 && i < 4) || (j == 3 && i < 2))
            {
                pile[i][j].top().blocked = false;
            }
        }
    }
    fillFreeTiles();
}

void Board::unblock(int x, int y)
{
    if (y - 1 >= 0 && pile[x][y - 1].size() > 0
            && pile[x][y].size() < pile[x][y - 1].size()
            && pile[x][y - 1].top().blocked)
    {
        pile[x][y - 1].top().blocked = false;
    }
    if (y + 1 <= 5 && pile[x][y + 1].size() > 0
            && pile[x][y].size() < pile[x][y + 1].size()
            && pile[x][y + 1].top().blocked)
    {
        pile[x][y + 1].top().blocked = false;
    }
    if (pile[x][y].size() > 0)
    {
        if (y == 0 || y == 5)
        {
            pile[x][y].top().blocked = false;
        }
        else if (pile[x][y - 1].size() < pile[x][y].size()
                 || pile[x][y + 1].size() < pile[x][y].size())
        {
            pile[x][y].top().blocked = false;
        }
    }

}

void Board::fillFreeTiles()
{
    freeTile.clear();
    tileCoord coord;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (!pile[i][j].empty() && !pile[i][j].top().blocked)
            {
                coord.x = i;
                coord.y = j;
                freeTile.push_back(coord);
            }
        }
    }
}
void Board::generateGameBoard()
{
    int index = 0;
    srand(time(NULL));
    pairCoord current;
    generateTiles();
    while (!coordinates.empty())
    {
        current = coordinates.top();
        coordinates.pop();
        index = rand() % tileHolder.size();
        pile[current.first.x][current.first.y].push(
            Tile(tileHolder[index].top()));
        tileHolder[index].pop();
        pile[current.second.x][current.second.y].push(
            Tile(tileHolder[index].top()));
        tileHolder[index].pop();
        if (tileHolder[index].empty())
        {
            tileHolder.erase(tileHolder.begin() + index);
        }
    }
}
void Board::generateTiles()
{
    for (int i = FIRST; i < NONE; i++)
    {
        tileHolder.push_back(std::stack<faceType>());
        for (int g = 0; g < 4; g++)
        {
            tileHolder[i].push(static_cast<faceType>(i));
        }
    }
}

bool Board::isStarted()
{
    return startGame;
}

void Board::stop()
{
    startGame = false;
    freeBoard();
}

void Board::start()
{
    freeBoard();
    startGame = true;
    while (!solvedPosition())
    {
        while (!coordinates.empty())
        {
            coordinates.pop();
        }
    }
    generateGameBoard();
}

void Board::freeBoard(){
    freeTile.clear();
    tileHolder.clear();
    while(!coordinates.empty()){
        coordinates.pop();
    }
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 6; ++j){
            while(!pile[i][j].empty()){
                pile[i][j].pop();
            }
        }
    }
}

void Board::block(int x, int y) {
	if ((y == 0 && pile[x][y + 1].size() == pile[x][y].size())) {
		pile[x][y + 1].top().blocked = true;
	}
	if ((y == 5 && pile[x][y - 1].size() == pile[x][y].size())) {
		pile[x][y - 1].top().blocked = true;
	}
    if((y!=5 && y!=0) &&
            (pile[x][y - 1].size() == pile[x][y].size()))
                    {
        pile[x][y-1].top().blocked = true;
    }
    if((y!=5 && y!=0) &&
            (pile[x][y + 1].size() == pile[x][y].size()))
                    {
        pile[x][y+1].top().blocked = true;
    }
}


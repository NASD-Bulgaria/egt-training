#include <iostream>
#define n 12
#include <iomanip>
using namespace std;


//2. One of the more interesting puzzlers for chess buffs is
//the Knight's Tour problem. The question is this: Can
//the chess piece called the knight move around an
//empty chessboard and touch each of the 64 squares
//once and only once? Write a program to solve the
//problem.

struct horseMove
{
    int x;
    int y;
};
void showResult(char chessBoard[][]);
bool isMovePossible(horseMove nextMove, int chessBoard[n][n]);
bool findTour(int chessBoard[n][n], horseMove moveHorse[],horseMove currentMove, int moveCount);
void knightTour();

static int operationCount = 0;

int main()
{


    knightTour();
    cout<<endl;
}

void showResult(char chessBoard[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<setw(2)<<chessBoard[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isMovePossible(horseMove nextMove, int chessBoard[n][n])
{
       int i = nextMove.x;
       int j = nextMove.y;
       if (r >= 0 && r <= 11 && c >= 0 && c <= 11 && maze[ r ][ c ] != 'x')
       {
           return true;
       }

       else
       {
           return false;
       }

}

bool findTour(char chessBoard[][], horseMove possibleHorseMoves[], horseMove currentPossition, int fieldCount)
{

       horseMove nextMove;

       if (fieldCount == n*n-1)
       {
          return true;
       }

       else
       {
           for (int i = 0; i < n; i++)
           {

              nextMove.x = currentPossition.x + possibleHorseMoves[i].x;
              nextMove.y = currentPossition.y + possibleHorseMoves[i].y;

              if (isMovePossible(nextMove, chessBoard))
              {
                chessBoard[nextMove.x][nextMove.y] = fieldCount+2;
                    operationCount++;

                 if (findTour(chessBoard, possibleHorseMoves, nextMove, fieldCount+1) == true)
                 {
                    return true;
                    operationCount++;
                 }

                 else
                 {

                    chessBoard[nextMove.x][nextMove.y] = 0;
                    operationCount++;

                 }
              }
           }

            return false;
       }

}

void knightTour()
{
    int chessBoard[n][n] ={{'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
      {'x', '0', '0', '0', 'x', '0', '0', '0', '0', '0', '0', 'x'},
      {'0', '0', 'x', '0', 'x', '0', 'x', 'x', 'x', 'x', '0', 'x'},
      {'x', 'x', 'x', '0', 'x', '0', '0', '0', '0', 'x', '0', 'x'},
      {'x', 'u', 'x', '0', '0', 'x', 'x', 'x', '0', 'x', '0', '0'},
      {'x', 'x', 'x', 'x', '0', 'x', 'u', 'x', '0', 'x', 'x', 'x'},
      {'x', 'u', 'u', 'x', '0', 'x', 'u', 'x', '0', 'x', 'u', 'x'},
      {'x', 'x', 'u', 'x', '0', 'x', 'x', 'x', '0', 'x', 'u', 'x'},
      {'x', 'u', 'u', 'x', '0', '0', '0', '0', '0', 'x', 'u', 'x'},
      {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'u', 'x'},
      {'x', 'u', 'u', 'u', 'u', 'u', 'u', 'x', 'u', 'u', 'u', 'x'},
      {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'}};;

    int x = 1;
    int y = 0;




       horseMove moveHorse[4] = { {0,1},{1,0},{-1,0},{0,-1},

 };
       horseMove currentMove = {x,y}; //startova poziciq
        chessBoard[x][y]= 0;
       if(findTour(chessBoard, moveHorse, currentMove, 0))
       {
           cout<<endl << "Have solution of knight's problem"<<endl<<endl;
           showResult(chessBoard);
           cout << operationCount<< endl;
       }


}

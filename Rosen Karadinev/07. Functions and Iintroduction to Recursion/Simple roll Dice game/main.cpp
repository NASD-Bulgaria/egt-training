// Fig. 6.8: main.cpp
// Shifted and scaled random integers.
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib> // contains function prototype for rand

using namespace std;

int rollDice();

int main()
{
    srand(time(0));

    rollDice();

    //enumeration with constants that represent the game status
    enum Status {CONTINUE, WON, LOST}; //all caps in constants

    int myPoint; // point if no win or loss on first roll

    Status gameStatus; // can contain CONTINUE, WON or LOST

    int sumOfDice = rollDice(); //first roll of the dice

    //determine game status and point (if needed) based on first roll

    switch(sumOfDice)
    {
        case 7: // win with 7 on first roll
        case 11: //win with 11 on first roll
            gameStatus = WON;
            break;
        case 2: //lose  with 2 on first roll
        case 3: //lose  with 3 on first roll
        case 12: //lose  with 12 on first roll
            gameStatus = LOST;
            break;
        default: // did not win or lose, so remember point
            gameStatus = CONTINUE; // game is not over
            myPoint = sumOfDice; // remember the point
            cout << "Point is " << myPoint << endl;
            break;
    }

    while(gameStatus == CONTINUE)
        {
            sumOfDice = rollDice(); // roll dice again

            if(sumOfDice ==  myPoint) // win by making point
            {
                gameStatus = WON;
            }
            else
            {
                if(sumOfDice == 7)
                {
                    gameStatus = LOST;
                }
            }

        }

        if(gameStatus == WON)
        {
            cout << "Player wins" << endl;
        }
        else
        {
            cout << "Player loses" << endl;
        }

    return 0;

} // end main

int rollDice()
{
    //pick random die value;
    int die1 = 1 + rand() % 6; // first die roll
    int die2 = 1 + rand() % 6; // second die roll

    int sum = die1 + die2;

    cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << endl;

    return sum;
 }

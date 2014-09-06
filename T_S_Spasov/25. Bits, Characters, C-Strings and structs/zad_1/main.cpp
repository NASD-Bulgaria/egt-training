// Fig. 4.16: main.cpp
// Card shuffling and dealing program.
#include "DeckOfCards.h" // DeckOfCards class definition
#include <iostream>
using namespace std;
int main()
{
   DeckOfCards deckOfCards; // create DeckOfCards object
   deckOfCards.deal(); // deal the cards in the deck
   deckOfCards.shuffle();
//   *******************
   cout << endl << endl;
   deckOfCards.deal();
   return 0; // indicates successful termination
} // end main



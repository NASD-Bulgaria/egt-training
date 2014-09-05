// Fig. 4.16: main.cpp
// Card shuffling and dealing program.
#include "DeckOfCards.h" // DeckOfCards class definition

int main()
{
   DeckOfCards deckOfCards; // create DeckOfCards object
   deckOfCards.shuffleDeck();
   deckOfCards.deal(); // deal the cards in the deck
   return 0; // indicates successful termination
} // end main



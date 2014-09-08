/*Modify the program of Fig. 25.14 to shuffle the cards
using a high-performance shuffle, as shown in Fig.
25.3. Print the resulting deck in two-column format,
as in Fig. 25.4. Precede each card with its color.*/

#include "DeckOfCards.h" // DeckOfCards class definition

int main()
{
   DeckOfCards deckOfCards; // create DeckOfCards object

   deckOfCards.shuffleCardInTheDeck();
   deckOfCards.deal(); // deal the cards in the deck
   return 0; // indicates successful termination
} // end main



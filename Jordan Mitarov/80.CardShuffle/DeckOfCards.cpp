// Fig. 4.15: DeckOfCards.cpp
// Member-function definitions for class DeckOfCards that simulates
// the shuffling and dealing of a deck of playing cards.
#include <iostream>
#include <cstdlib> //rand i srand
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include "DeckOfCards.h" // DeckOfCards class definition

// no-argument DeckOfCards constructor intializes deck
DeckOfCards::DeckOfCards()
{
   for ( int i = 0; i <= 51; i++ ) 
   {
      deck[ i ].face = i % 13; // faces in order
      deck[ i ].suit = i / 13; // suits in order
      deck[ i ].color = i / 26; // colors in order - tova 26 e poneje ot 0 do 25 shte imame cvqt 4erven, a sled tova primerno cheren- dva cvqta
   } // end for
} // end no-argument DeckOfCards constructor

// deal cards in deck
void DeckOfCards::deal()
{
   for ( int k1 = 0, k2 = k1 + 26; k1 <= 25; k1++, k2++ ) 
      cout << "Card:" << setw( 3 ) << deck[ k1 ].face 
         << "  Suit:" << setw( 2 ) << deck[ k1 ].suit 
         << "  Color:" << setw( 2 ) << deck[ k1 ].color 
         << "   " << "Card:" << setw( 3 ) << deck[ k2 ].face
         << "  Suit:" << setw( 2 ) << deck[ k2 ].suit 
         << "  Color:" << setw( 2 ) << deck[ k2 ].color << endl;
} // end function deal


// shuffle cards in the deck
void DeckOfCards::shuffleCardInTheDeck()
{
	for ( int i = 0; i < 52; i++ )
	{
		int j = rand() % 52;
		BitCard swap = deck[ i ];
		deck[ i ] = deck[ j ];
		deck[ j ] = swap;
	}
}



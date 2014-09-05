
#include <iostream>
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
      deck[ i ].color = i / 26; // colors in order

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

void DeckOfCards::shuffle()
{

   for ( int i = 0; i < 52; i++ )
   {
      int j = rand() % 52;
      BitCard temp = deck[ i ];
      deck[ i ] = deck[ j ];
      deck[ j ] = temp;
   } // end for
}


// Fig. 4.2: DeckOfCards.h
// Definition of class DeckOfCards that 
// represents a deck of playing cards.

// Card structure definition
struct Card                 
{                           
   char *face;              
   char *suit;
   char *color;
}; // end structure Card    

// DeckOfCards class definition
class DeckOfCards
{
public:
   DeckOfCards(); // constructor initializes deck
   void shuffle(); // shuffles cards in deck
   void deal(); // deals cards in deck

private:
   Card deck[ 52 ]; // represents deck of cards
}; // end class DeckOfCards


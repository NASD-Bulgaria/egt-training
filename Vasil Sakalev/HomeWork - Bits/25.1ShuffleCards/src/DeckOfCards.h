
#include <ctime>
#include <cstdlib>
struct BitCard
{
   unsigned face : 4; // 4 bits; 0-15
   unsigned suit : 2; // 2 bits; 0-3
   unsigned color : 1; // 1 bit; 0-1
}; // end struct BitCard

// DeckOfCards class definition
class DeckOfCards
{
public:
   DeckOfCards(); // constructor initializes deck
   void deal(); // deals cards in deck
   void shuffle();
private:
   BitCard deck[ 52 ]; // represents deck of cards
}; // end class DeckOfCards



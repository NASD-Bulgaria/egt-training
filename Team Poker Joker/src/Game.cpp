/*
 * Game.cpp
 *
 *  Created on: 17.09.2014 г.
 *      Author: Kateto
 */

#include "Game.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

enum type
{
	NONE = 0, KINGS_OR_BETTER,       //1
	TWO_PAIRS,             //2
	THREE_OF_A_KIND,       //3
	STRAIGHT,              //4
	FLUSH,                 //5
	FULL_HOUSE,            //6
	FOUR_OF_A_KIND,        //7
	STRAIGHT_FLUSH,        //8
	WILD_ROYAL_FLUSH,      //9
	FIVE_OF_A_KIND,        //10
	NATURAL_ROYAL_FLUSH    //11
};

int winType;

Game::Game()
{
	srand(time(0));
	winType = 0;
	for (int row = 0; row <= 3; row++)
	{
		for (int column = 0; column <= 13; column++)
		{
			deck[row][column] = 0;
			if (row > 0 && column > 12)
			{
				deck[row][column] = 100;
			}
		}
	}
	shuffle();

}

void Game::shuffle()
{

	int row;
	int column;
	bool checkJoker = false;
	for (int card = 1; card <= 52; card++)
	{
		do
		{
			row = rand() % 4;
			column = rand() % 14;

			if (checkJoker == true)
			{
				column = rand() % 13;
			}
			if (column == 13)
			{
				checkJoker = true;

			}
		} while (deck[row][column] != 0);

		deck[row][column] = card;
	}

}

void Game::dealCards()
{
	winType = 0;
	hand.clear();
	srand(time(0));
	int row;
	int column;
//	bool checkJoker = false;
//	bool checkOldCard = true;
//	do
//	{
//		row = rand() % 4;
//		column = rand() % 14;
//
//		if (checkJoker == true)
//			column = rand() % 13;
//
//		if (column == 13)
//			checkJoker = true;
//
//		for (unsigned i = 0; i < hand.size(); i++)
//		{
//			if (row == hand[i].getSuit() && column == hand[i].getFace())
//				checkOldCard = false;
//		}
//
//		if (checkOldCard == true)
//		{
//
//			Card newCard(row, column);
//			hand.push_back(newCard);
//
//		}
//		checkOldCard = true;
//	} while (hand.size() != 5);
	credit.readCreaditsFromFile(credit);
	credit.deductCredits(BET);
	credit.writeCreditsToFile(credit);

	Card card1(2,11);
	hand.push_back(card1);

	Card card2(1, 11);
	hand.push_back(card2);

	Card card3(3, 11);
	hand.push_back(card3);

	Card card4(0, 11);
	hand.push_back(card4);

	Card card5(1, 12);
	hand.push_back(card5);

	sort(hand.begin(), hand.end(), cardCompare);
}
void getRecovery(fstream &file, Credits &credit)
{
	file.seekg(0);
	file.read(reinterpret_cast<char *>(&credit), sizeof(Credits));
	credit.setCredits(credit.getCredits());
}
void Game::secondDealCards()
{
	winType = 0;
	srand(time(0));
	bool checkJoker = false;
	hand[4].getFace() == 13 ? checkJoker = true : checkJoker = false;
	vector<Card> holdedCards;
	for (unsigned i = 0; i < hand.size(); i++)
	{
		if (hand[i].isHold())
		{
			Card holdCard(hand[i].getSuit(), hand[i].getFace());
			holdedCards.push_back(holdCard);
		}
	}
	bool checkOldCard = true;

	while (holdedCards.size() < 5)
	{
		int row = rand() % 4;
		int column = rand() % 14;
		if (checkJoker == true)
			column = rand() % 13;

		if (column == 13)
			checkJoker = true;

		for (unsigned i = 0; i < hand.size(); i++)
		{
			if (row == hand[i].getSuit() && column == hand[i].getFace())
				checkOldCard = false;
		}
		if (checkOldCard == true)
		{
			Card newCard(row, column);
			holdedCards.push_back(newCard);
		}
		checkOldCard = true;
	}

	sort(holdedCards.begin(), holdedCards.end(), cardCompare);
	hand.clear();

	for (unsigned i = 0; i < holdedCards.size(); i++)
	{
		Card changeCard(holdedCards[i].getSuit(), holdedCards[i].getFace());
		hand.push_back(changeCard);
	}

	sort(hand.begin(), hand.end(), cardCompare);
	Bets bet;
	checkHand();
// statistic
	stats.readFromFile();
	stats.addHandsPlayed();
	credit.readCreaditsFromFile(credit);
	if (winType > 0)
	{
		stats.addWinGames();
		stats.addCreditsWon(bet.wins(winType));
		credit.addCredits(bet.wins(winType));
	}
	else
	{
		stats.addLostGames();

	}
	stats.writeToFile();
	stats.printStats();
	credit.writeCreditsToFile(credit);

}

void Game::showHand()
{
//	Bets bet;
//	cout << "\nYour hand is : ";
//	bet.handName(winType);
//
//	cout << endl << endl;
//	for (unsigned int i = 0; i < hand.size(); i++)
////		hand[i].ShowCard();
//	cout << endl;
}

bool Game::cardCompare(Card first, Card second)
{
	return first.face < second.face;
}

void Game::autoHold()
{

	int checkSuit[4];
	for (unsigned i = 0; i < hand.size(); i++)
	{
		counts[hand[i].getFace()]++;

		checkSuit[hand[i].getSuit()]++;

		if (checkSuit[i - 1] > 3) // chech 4 or more equal suits
		{
			for (int j = 0; j < 4; j++)
			{
				if (hand[j].getSuit() == checkSuit[i - 1])
				{
					hand[j].Hold();
				}
			}

		}

		if (hand[i].getFace() + 1 == hand[i + 1].getFace()
				&& hand[i + 1].getFace() + 1 == hand[i + 2].getFace()
				&& hand[4].getFace() == 13) // checks 3 straight with joker
		{
			hand[i].Hold();
			hand[i + 1].Hold();
			hand[i + 2].Hold();
		}
		if (hand[i].getFace() == hand[i + 1].getFace()) // check for Pair
		{
			hand[i].Hold();
			hand[i + 1].Hold();
		}
	}

	int maxIndex;

	for (unsigned i = 0; i < countFace; i++)    // chech index of winType
	{
		if (counts[i] > 1)
			maxIndex = i;
	}

	if (hand[4].getFace() == 13 && hand[0].getFace() == 0) // check for Joker and Ace
	{
		hand[4].Hold();
		hand[0].Hold();
	}

	if (hand[4].getFace() == 13 && hand[3].getFace() == 12) // chech for Joker and King
	{
		hand[4].Hold();
		hand[3].Hold();
	}

	if (hand[4].getFace() == 13) //check only for Joker
	{
		hand[4].Hold();
	}

	if (winType == NONE)
	{
		if (hand[0].getFace() == 0) // if there is Ace and high card
		{
			hand[0].Hold();
		}
		else
		{
			hand[4].Hold();
		}
	}
	else //hold win type
	{
		for (unsigned i = 0; i < hand.size() - 2; i++)
		{
			if (hand[i].getFace() == maxIndex)
			{
				hand[i].Hold();
			}
		}
	}

}

void Game::holdCards()
{
//	int unHoldIndex;
//	cout << "Enter number of cards to unhold";
//	cin >> unHoldIndex;
//	for (int i = 0; i < unHoldIndex; i++)
//	{
//
//		int card;
//
//		cout << "Enter card number: ";
//		cin >> card;
//
//		hand[card - 1].Unhold();
//	}
//	int num;
//	cout << "Enter number of cards to hold";
//	cin >> num;
//
//	for (int i = 0; i < num; i++)
//	{
//
//		int card;
//
//		cout << "Enter card number: ";
//		cin >> card;
//
//		hand[card - 1].Hold();
//	}
}

void Game::checkHand()
{

	if (hand[4].getFace() == 13)
	{
		isKingOrBetterJoker() ? winType = KINGS_OR_BETTER : winType;
		isThreeOfAKindJoker() ? winType = THREE_OF_A_KIND : winType;
		isStraightJoker() ? winType = STRAIGHT : winType;
		isFlushJoker() ? winType = FLUSH : winType;
		isfullHouseJoker() ? winType = FULL_HOUSE : winType;
		isFourOfAKindJoker() ? winType = FOUR_OF_A_KIND : winType;
		isStraightFlushJoker() ? winType = STRAIGHT_FLUSH : winType;
		isWildRoyalFlush() ? winType = WILD_ROYAL_FLUSH : winType;
		isFiveOfAKind() ? winType = FIVE_OF_A_KIND : winType;
	}
	else
	{
		isKingOrBetter() ? winType = KINGS_OR_BETTER : winType;
		isTwoPair() ? winType = TWO_PAIRS : winType;
		isThreeOfAKind() ? winType = THREE_OF_A_KIND : winType;
		isStraight() ? winType = STRAIGHT : winType;
		isFlush() ? winType = FLUSH : winType;
		isfullHouse() ? winType = FULL_HOUSE : winType;
		isFourOfAKind() ? winType = FOUR_OF_A_KIND : winType;
		isStraightFlush() ? winType = STRAIGHT_FLUSH : winType;
		isNaturalRoyalFlush() ? winType = NATURAL_ROYAL_FLUSH : winType;
	}

}

bool Game::isKingOrBetterJoker()
{
	return ((hand[3].getFace() == 12) || (hand[0].getFace() == 0))
			&& (hand[4].getFace() == 13);

}

bool Game::isKingOrBetter()
{
	return ((((hand[3].getFace() == 12) && (hand[4].getFace() == 12))
			|| ((hand[0].getFace() == 0) && hand[1].getFace() == 0)));

}

bool Game::isTwoPair()
{
	int countPair = 0;
	if (hand[0].getFace() == hand[1].getFace())
		countPair++;
	if (hand[1].getFace() == hand[2].getFace())
		countPair++;
	if (hand[2].getFace() == hand[3].getFace())
		countPair++;
	if (hand[3].getFace() == hand[4].getFace())
		countPair++;
	return countPair == 2;

}

bool Game::isThreeOfAKindJoker()
{

	return (((hand[0].getFace() == hand[1].getFace()) ||

	(hand[1].getFace() == hand[2].getFace()) ||

	(hand[2].getFace() == hand[3].getFace())) &&

	(hand[4].getFace() == 13));

}

bool Game::isThreeOfAKind()
{

	return (((hand[0].getFace() == hand[1].getFace())
			&& (hand[0].getFace() == hand[2].getFace()))
			|| ((hand[1].getFace() == hand[2].getFace())
					&& (hand[1].getFace() == hand[3].getFace()))
			|| ((hand[2].getFace() == hand[3].getFace())
					&& (hand[2].getFace() == hand[4].getFace())));
}

bool Game::isStraightJoker()
{
	int countNotstraight = 0;
	for (unsigned i = 0; i < hand.size(); i++)
	{
		if (hand[i].getFace() + 2 == hand[i + 1].getFace())
		{
			countNotstraight++;
		}
	}

	if (hand[0].getFace() != 0)
	{

		return (countNotstraight != 2
				&& ((hand[0].getFace() + 1 == hand[1].getFace())
						|| (hand[0].getFace() + 2 == hand[1].getFace()))
				&& ((hand[1].getFace() + 1 == hand[2].getFace())
						|| (hand[1].getFace() + 2 == hand[1].getFace()))
				&& ((hand[2].getFace() + 1 == hand[3].getFace())
						|| (hand[2].getFace() + 2 == hand[3].getFace()))
				&& hand[4].getFace() == 13);
	}
	else
	{
		return (((hand[1].getFace() == 9) || (hand[1].getFace() == 10))
				&& ((hand[2].getFace() == 10) || (hand[2].getFace() == 11))
				&& ((hand[3].getFace() == 11) || (hand[3].getFace() == 12))
				&& hand[4].getFace() == 13)
				|| (((hand[1].getFace() == 1) || (hand[1].getFace() == 2))
						&& ((hand[2].getFace() == 2) || (hand[2].getFace() == 3))
						&& ((hand[3].getFace() == 3) || (hand[3].getFace() == 4))
						&& hand[4].getFace() == 13);
	}
}

bool Game::isStraight()
{
	if (hand[0].getFace() != 0)
	{
		return ((hand[0].getFace() + 1 == hand[1].getFace())

		&& (hand[1].getFace() + 1 == hand[2].getFace())

		&& (hand[2].getFace() + 1 == hand[3].getFace())

		&& (hand[3].getFace() + 1 == hand[4].getFace()));
	}
	else
	{
		return ((hand[1].getFace() == 9)

		&& (hand[2].getFace() == 10)

		&& (hand[3].getFace() == 11)

		&& (hand[4].getFace() == 12));
	}

}

bool Game::isFlushJoker()
{

	return ((hand[0].getSuit() == hand[1].getSuit()) &&

	(hand[1].getSuit() == hand[2].getSuit()) &&

	(hand[2].getSuit() == hand[3].getSuit()) &&

	(hand[4].getFace() == 13));
}

bool Game::isFlush()
{

	return ((hand[0].getSuit() == hand[1].getSuit()) &&

	(hand[1].getSuit() == hand[2].getSuit()) &&

	(hand[2].getSuit() == hand[3].getSuit()) &&

	(hand[3].getSuit() == hand[4].getSuit()));
}

bool Game::isfullHouseJoker()
{
	int countPair = 0;
	bool checkThree = isThreeOfAKind();
	if (hand[0].getFace() == hand[1].getFace())
		countPair++;
	if (hand[1].getFace() == hand[2].getFace())
		countPair++;
	if (hand[2].getFace() == hand[3].getFace())
		countPair++;

	return ((countPair == 2) && (hand[4].getFace() == 13) && checkThree == 0);
}

bool Game::isfullHouse()
{
	int countPair = 0;
	int check = isThreeOfAKind();
	if (hand[0].getFace() == hand[1].getFace())
		countPair++;
	if (hand[1].getFace() == hand[2].getFace())
		countPair++;
	if (hand[2].getFace() == hand[3].getFace())
		countPair++;
	if (hand[3].getFace() == hand[4].getFace())
		countPair++;

	return ((countPair == 3) && (check));
}

bool Game::isFourOfAKindJoker()
{
	return (isThreeOfAKind() && hand[4].getFace() == 13);
}

bool Game::isFourOfAKind() // to repair
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (hand[i].getFace() == hand[i + 1].getFace())
		{
			count++;
		}
	}
	return count == 3 ;
}

bool Game::isStraightFlush()
{
	return (isStraight() && isFlush());
}

bool Game::isStraightFlushJoker()
{
	return (isStraightJoker() && isFlushJoker());
}

bool Game::isWildRoyalFlush()
{
	return (isFlushJoker()
			&& ((hand[0].getFace() == 0 || hand[0].getFace() == 9)
					&& (hand[1].getFace() == 9 || hand[1].getFace() == 10)
					&& (hand[2].getFace() == 10 || hand[2].getFace() == 11)
					&& (hand[3].getFace() == 11 || hand[3].getFace() == 12)));
}

bool Game::isFiveOfAKind()
{
	return (isFourOfAKind() && hand[4].getFace() == 13);
}

bool Game::isNaturalRoyalFlush()
{
	return (isFlush() && (hand[0].getFace() == 0) && (hand[1].getFace() == 9)
			&& (hand[2].getFace() == 10) && (hand[3].getFace() == 11)
			&& (hand[4].getFace() == 12));
}

int Game::getWinType()
{
	return winType;
}

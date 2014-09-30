/*
 * Bets.cpp
 *
 *  Created on: Sep 19, 2014
 *      Author: vasko
 */

#include "Bets.h"

Bets::Bets()
{
	myBets.insert(pair<int, int>(0, 0));
	myBets.insert(pair<int, int>(1, 1));
	myBets.insert(pair<int, int>(2, 3));
	myBets.insert(pair<int, int>(3, 4));
	myBets.insert(pair<int, int>(4, 6));
	myBets.insert(pair<int, int>(5, 9));
	myBets.insert(pair<int, int>(6, 10));
	myBets.insert(pair<int, int>(7, 20));
	myBets.insert(pair<int, int>(8, 50));
	myBets.insert(pair<int, int>(9, 400));
	myBets.insert(pair<int, int>(10, 600));
	myBets.insert(pair<int, int>(11, 800));

	betsName.insert(pair<int, string>(0, " None :( "));
	betsName.insert(pair<int, string>(1, " Kings or better "));
	betsName.insert(pair<int, string>(2, " Two pairs "));
	betsName.insert(pair<int, string>(3, "Three of a kind"));
	betsName.insert(pair<int, string>(4, "Straight"));
	betsName.insert(pair<int, string>(5, "Flush"));
	betsName.insert(pair<int, string>(6, "Full house"));
	betsName.insert(pair<int, string>(7, "Four of a kind"));
	betsName.insert(pair<int, string>(8, "Straight flush"));
	betsName.insert(pair<int, string>(9, "Wild royal flush"));
	betsName.insert(pair<int, string>(10, "Five of a kind"));
	betsName.insert(pair<int, string>(11, "Natural royal flush"));

}

Bets::~Bets()
{
	// TODO Auto-generated destructor stub
}

int Bets::wins(int winType)
{
	int result;
	map<int, int>::iterator it;
	for (it = myBets.begin(); it != myBets.end(); it++)
	{
		if (it->first == winType)
		{
			result = it->second * BET;
		}
	}
	return result;
}

string Bets::handName(int winType)
{
	map<int, string>::iterator it;
	string result;
	for (it = betsName.begin(); it != betsName.end(); it++)
	{
		if (it->first == winType)
		{
			result = it->second;
		}
	}
	return result;
}

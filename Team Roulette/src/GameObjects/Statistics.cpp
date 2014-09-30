/*
 * Statistics.cpp
 *
 *  Created on: 19.09.2014
 *      Author: Kameliq
 */

#include "Statistics.h"

using namespace GameObjects;

Statistics::~Statistics()
{
}

Statistics::Statistics(string path, int initialAmount) :
		initialAmount(initialAmount)
{
	this->path = path;
}

bool Statistics::write(short num, Color color, int totalBet, int winings,
		int currentBalance)
{
	if (initiateStream())
	{
		stream << num << " " << color << " " << totalBet << " "
				<< winings - totalBet << calcDeviateBet(totalBet, winings)
				<< calcDeviateCapital(currentBalance) << endl;
		stream.close();
		return true;
	}
	return false;
}

const vector<vector<double> > Statistics::read()
{
	int counter = 0;
	vector<vector<double> > gameResults;
	if (initiateStream())
	{
		while (!stream.eof())
		{
			if (counter == 5)
			{
				gameResults.push_back(vector<double>());
				counter = 0;
			}
			stream >> gameResults[gameResults.size() - 1][0]
					>> gameResults[gameResults.size() - 1][1]
					>> gameResults[gameResults.size() - 1][2]
					>> gameResults[gameResults.size() - 1][3]
					>> gameResults[gameResults.size() - 1][4]
					>> gameResults[gameResults.size() - 1][5];
			counter++;
		}
	}
	return gameResults;
}

bool Statistics::initiateStream()
{
	if (!stream.is_open())
	{
		stream.open(this->path.data(), ios::in | ios::out | ios::app);
	}
	if (!stream)
	{
		return false;
	}
	return true;
}

double Statistics::calcDeviateBet(int totalBet, int winings)
{
	return winings / (double) totalBet * 100 - 100;
}

double Statistics::calcDeviateCapital(int currentBalance)
{
	return (currentBalance / double(initialAmount) * 100) - 100;
}

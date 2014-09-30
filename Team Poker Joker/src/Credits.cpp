/*
 * Credits.cpp
 *
 *  Created on: 21.09.2014 г.
 *      Author: Kateto
 */

#include "Credits.h"

Credits::Credits()
{
	currentCredits = 0;
}

void Credits::setCredits(int credits)
{
	currentCredits = credits;
}

int Credits::getCredits()
{
	return currentCredits;
}

void Credits::addCredits(int credits)
{
	currentCredits += credits;
}

void Credits::deductCredits(int credits)
{
	currentCredits -= credits;
}

void Credits::writeCreditsToFile(Credits &credit)
{
	ofstream outFile("credit.dat", ios::out);

	if (!outFile)
	{
		cout << "File can not be opened writing";
	}
	outFile.clear();
	outFile.seekp(0);
	outFile.write(reinterpret_cast<char *>(&credit), sizeof(Credits));
}

void Credits::readCreaditsFromFile(Credits &credit)
{
	ifstream inFile("credit.dat", ios::in);

	if (!inFile)
	{
		cout << "File can not be opened writing";
	}
	inFile.clear();
	inFile.seekg(0);
	inFile.read(reinterpret_cast<char *>(&credit), sizeof(Credits));
	credit.setCredits(credit.getCredits());
}

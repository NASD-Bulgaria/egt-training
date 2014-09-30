/*
 * Credits.h
 *
 *  Created on: 21.09.2014 г.
 *      Author: Kateto
 */

#ifndef CREDITS_H_
#define CREDITS_H_
#include <iostream>
#include <fstream>
using namespace std;

class Credits
{
	friend class Statistics;
private:

	int currentCredits;

public:

	Credits();
	void setCredits(int);
	int getCredits();

	void addCredits(int);
	void deductCredits(int);

	void writeCreditsToFile(Credits &credit);
	void readCreaditsFromFile(Credits &credit);
};

#endif /* CREDITS_H_ */

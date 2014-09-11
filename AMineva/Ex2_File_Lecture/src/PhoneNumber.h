/*
 * PhoneNumber.h
 *
 *  Created on: Aug 31, 2014
 *      Author: Keen
 */

#ifndef PHONENUMBER_H_
#define PHONENUMBER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

class PhoneNumber
{
private:
	int numberOne;
	int numberTwo;
	int numberThree;
	int numberFour;
	int numberFive;
	int numberSix;
	int numberSeven;
	static const string letter[][9];
	int getIndex(int);
public:
	PhoneNumber();
	PhoneNumber(int, int, int, int, int, int, int);

	void saveCombinations();

//	friend ostream &operator<<(ostream&, const PhoneNumber&);
//	friend istream &operator>>(istream&, PhoneNumber&);

	virtual ~PhoneNumber();
};

#endif /* PHONENUMBER_H_ */

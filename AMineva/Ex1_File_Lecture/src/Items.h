/*
 * Items.h
 *
 *  Created on: Aug 31, 2014
 *      Author: Keen
 */

#ifndef ITEMS_H_
#define ITEMS_H_
#include <string>
using namespace std;

class Items
{
	private:
	int number;
	char name[10];
	double price;
	int count;
public:
	Items();
	Items(int, string, double, int);

	void setNumber(int);
	int getNumber();
	void setName(string);
	string getName();
	void setPrice(double);
	double getPrice();
	void setCount(int);
	int getCount();
	virtual ~Items();
};

#endif /* ITEMS_H_ */

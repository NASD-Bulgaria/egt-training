/*
 * Items.cpp
 *
 *  Created on: Aug 31, 2014
 *      Author: Keen
 */

#include <cstring>
using namespace std;

#include "Items.h"

Items::Items()
{
	setNumber(0);
	setName("");
	setPrice(0.0);
	setCount(0);
}

Items::Items(int num, string n, double p, int c)
{
	setNumber(num);
	setName(n);
	setPrice(p);
	setCount(c);
}

void Items::setNumber(int n)
{
	number=n;
}

int Items::getNumber()
{
	return number;
}

void Items::setName(string n)
{
	const char *nameValue = n.data();
	int length = n.size();
	length = (length < 10 ? length : 9);
	strncpy(name, nameValue, length);
	name[length] = '\0';
}

string Items::getName()
{
	return name;
}

void Items::setPrice(double p)
{
	price=p;
}

double Items::getPrice()
{
	return price;
}

void Items::setCount(int c)
{
	count=c;
}

int Items::getCount()
{
	return count;
}

Items::~Items() {
	// TODO Auto-generated destructor stub
}


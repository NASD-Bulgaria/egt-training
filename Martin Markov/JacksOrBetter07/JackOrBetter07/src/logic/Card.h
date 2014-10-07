/*
 * Card.h
 *
 *  Created on: Sep 16, 2014
 *      Author: Keen
 */

#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Card
{
private:
	int face;
	int suit;
    unsigned id;
public:
	Card(int = 0, int = 0);
    Card(unsigned id);

    Card& operator =(const Card& card);
	virtual ~Card();
    void CalculateID();


	string getImagePath();

	int getFace() const;

	int getSuit() const;

	//friend int compare(Card, Card);
    unsigned getId() const;
    void setId(const unsigned &value);
};

#endif /* CARD_H_ */

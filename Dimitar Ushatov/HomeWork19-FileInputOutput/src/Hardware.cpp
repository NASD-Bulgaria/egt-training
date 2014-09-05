/*
 * Hardware.cpp
 *
 *  Created on: Aug 27, 2014
 *      Author: NandM
 */

#include "Hardware.h"
Hardware::Hardware(){

}
Hardware::Hardware(int identNumber, string type, double price) {
	setIdentNumber(identNumber);
	setType(type);
	setPrice(price);
}

Hardware::~Hardware() {
	// TODO Auto-generated destructor stub
}

int Hardware::getIdentNumber() const {
	return identNumber;
}

Hardware& Hardware::setIdentNumber(int identNumber) {
	this->identNumber = identNumber;
	return *this;
}

double Hardware::getPrice() const {
	return price;
}

Hardware& Hardware::setPrice(double price) {
	this->price = price;
	return *this;
}

const char* Hardware::getType() const {
	return type;
}

Hardware& Hardware::setType(string& type) {
	int length = (type.length() < 30 ? type.length() : 29);
	for (int i = 0; i < 30; ++i) {
		if (i < length) {
			this->type[i] = type[i];
		} else{
			this->type[i] = ' ';
		}
	}
	this->type[30] = '\0';
	return *this;
}

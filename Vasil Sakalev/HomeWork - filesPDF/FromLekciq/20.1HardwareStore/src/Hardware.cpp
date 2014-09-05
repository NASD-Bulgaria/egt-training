/*
 * Hardware.cpp
 *
 *  Created on: Aug 30, 2014
 *      Author: vasko
 */

#include "Hardware.h"

Hardware::Hardware(int accountNumber, string description, int count,
		double price) {
	setDescription(description);
	setCount(count);
	setPrice(price);
	setAccountNumber(accountNumber);

}

Hardware::~Hardware() {
	// TODO Auto-generated destructor stub
}

int Hardware::getCount() const {
	return count;
}

void Hardware::setCount(int count) {
	if (count > 0) {
		this->count = count;
	}
}

double Hardware::getPrice() const {
	return price;
}

void Hardware::setPrice(double price) {
	if (price > 0) {
		this->price = price;
	}
}

const string& Hardware::getDescription() const {
	return description;
}

string Hardware::getInfo() {
	string result;
	stringstream res;
	stringstream ss;
	stringstream aa;
	stringstream num;
	num << getAccountNumber();
	aa << getPrice();
	ss << getCount();
	res << left <<setw(5) << num.str() << setw(15) << getDescription() << setw(6) << ss.str()
			<< aa.str() << "lv.\n";
	result.append(res.str());
	return result;

}

void Hardware::setDescription(const string& description) {

	this->description = description;
}

int Hardware::getAccountNumber() const {
	return accountNumber;
}

void Hardware::setAccountNumber(int accountNumber) {
	this->accountNumber = accountNumber;
}

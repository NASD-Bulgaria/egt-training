/*
 * Hardware.h
 *
 *  Created on: Aug 30, 2014
 *      Author: vasko
 */

#ifndef HARDWARE_H_
#define HARDWARE_H_
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
class Hardware {
public:
	Hardware(int accountNumber = 0,string = "" , int = 0 , double = 0.0);
	virtual ~Hardware();

	string getInfo();

	int getCount() const;
	void setCount(int count);
	double getPrice() const;
	void setPrice(double price);
	const string& getDescription() const;
	void setDescription(const string& description);
	int getAccountNumber() const;
	void setAccountNumber(int accountNumber);

private:
	int accountNumber;
	string description;
	int count;
	double price;


};

#endif /* HARDWARE_H_ */

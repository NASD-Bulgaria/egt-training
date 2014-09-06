/*
 * HardwareStore.h
 *
 *  Created on: 31.08.2014 г.
 *      Author: Ramzi
 */

#include <string>
using namespace std;

#ifndef HARDWARESTORE_H_
#define HARDWARESTORE_H_

class HardwareStore
{
public:
	HardwareStore(int =0,  string = "", int = 0, double = 0.0);
	int getIdNumber() const;
	void setIdNumber(int);
	string getName() const;
	void setName( string);
	double getPrice() const;
	void setPrice(double);
	int getQuantity() const;
	void setQuantity(int );

private:
	int idNumber;
	char name[30];
	int quantity;
	double price;

};


#endif /* HARDWARESTORE_H_ */

/*
 * Hardware.h
 *
 *  Created on: Aug 27, 2014
 *      Author: NandM
 */

#ifndef HARDWARE_H_
#define HARDWARE_H_
#include <string>
using namespace std;
class Hardware {
public:
	Hardware();
	Hardware(int, string, double);
	~Hardware();
	int getIdentNumber() const;
	Hardware& setIdentNumber(int identNumber);
	double getPrice() const;
	Hardware& setPrice(double price);
	const char* getType() const;
	Hardware& setType(string &type);

private:
	int identNumber;
	char type[30];
	double price;
};

#endif /* HARDWARE_H_ */

/*
 * ClientsData.h
 *
 *  Created on: 27.08.2014 ã.
 *      Author: PC
 */

#ifndef CLIENTSDATA_H_
#define CLIENTSDATA_H_
#include<string>
using namespace std;

class ClientsData {
public:
	ClientsData( int = 0, string = "", int = 0, double = 0.0 );
	void setToolName(string);
	string getToolName();

	int getNumber()  {
		return number;
	}

	void setNumber(int number) {
		this->number = number;
	}

	int getToolNumber()  {
		return toolNumber;
	}

	void setToolNumber(int toolNumber) {
		this->toolNumber = toolNumber;
	}

	double getToolPrice()  {
		return toolPrice;
	}

	void setToolPrice(double toolPrice) {
		this->toolPrice = toolPrice;
	}

private:
	int number;
	char toolName[ 15 ];
	int toolNumber;
	double toolPrice;
};

#endif /* CLIENTSDATA_H_ */

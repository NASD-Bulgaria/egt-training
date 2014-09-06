/*
 * ClientData.h
 *
 *  Created on: Aug 27, 2014
 *      Author: Student
 */

#include <string>
#include <iostream>
using namespace std;

#ifndef CLIENTDATA_H_
#define CLIENTDATA_H_

class ClientData
{
public:
	ClientData(int = 0,string ="",string = "", double = 0.0);

    int getAccountNumber() const;
    double getBalance() const;
    string getFirstName() const;
    string getLastName() const;
    void setAccountNumber(int);
    void setBalance(double);
    void setFirstName(string);
    void setLastName(string);

private:
	int accountNumber;
	char firstName[15];
	char lastName [10];
	double balance;

};


#endif /* CLIENTDATA_H_ */

/*
 * ClientData.cpp
 *
 *  Created on: Aug 27, 2014
 *      Author: Student
 */
#include <string>
#include <iostream>
using namespace std;

#include "ClientData.h"

ClientData::ClientData(int accountNumberValue, string firstNameValue,
		string lastNameValue,double balanceValue)
{
	setAccountNumber(accountNumberValue);
	setBalance(balanceValue);
	setFirstName(firstNameValue);
	setLastName(lastNameValue);
}

int ClientData::getAccountNumber() const
{
	return accountNumber;
}



string ClientData::getFirstName() const
{
	return firstName;
}



string ClientData::getLastName() const
{
	return lastName;
}



void ClientData::setBalance(double balanceValue)
{
	balance = balanceValue;
}



void ClientData::setFirstName(string firstNameString)
{
	const char *firstNameValue = firstNameString.data();
	int length = firstNameString.size();
	length = ( length < 10 ? length : 9 );
	strncpy( firstName, firstNameValue, length );
	firstName[ length ] = '\0';
}



void ClientData::setAccountNumber(int accountNumberValue)
{
	accountNumber = accountNumberValue;
}



double ClientData::getBalance() const
{
	return balance;
}



void ClientData::setLastName(string lastNameString)
{
	    const char *lastNameValue = lastNameString.data();
		int length = lastNameString.size();
		length = ( length < 15 ? length : 14 );
		strncpy( lastName, lastNameValue, length );
		lastName[ length ] = '\0';
}










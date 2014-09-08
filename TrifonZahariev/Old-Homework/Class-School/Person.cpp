/*
 * Person.cpp
 *
 *  Created on: 20.08.2014 ã.
 *      Author: Admin
 */

#include "Person.h"

Person::Person(string firstName, string lastName, string EGN) {
	// TODO Auto-generated constructor stub
	this->lastName = lastName;
	this->firstName = firstName;
	this->EGN = EGN;
}

Person::~Person() {
	// TODO Auto-generated destructor stub
}

const string& Person::getEgn() const {
	return EGN;
}

void Person::setEgn(const string& egn) {
	EGN = egn;
}

const string& Person::getFirstName() const {
	return firstName;
}

void Person::setFirstName(const string& firstName) {
	this->firstName = firstName;
}

const string& Person::getLastName() const {
	return lastName;
}

string Person::getInfo() {
	string result = "";
	result.append("First Name: " + firstName);
	result.append("\nLast Name: " + lastName);
	result.append("\nEGN: " + EGN + "\n");
	return result;
}

void Person::setLastName(const string& lastName) {
	this->lastName = lastName;
}

const string& Person::getEgn() const {
}

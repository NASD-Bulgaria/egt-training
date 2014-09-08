/*
 * Teacher.cpp
 *
 *  Created on: 20.08.2014 ã.
 *      Author: Admin
 */

#include "Teacher.h"

Teacher::Teacher(string firstName, string lastName, string EGN, string subject) :
		Person(firstName, lastName, EGN) {
	// TODO Auto-generated constructor stub
	this->subject = subject;
}

Teacher::~Teacher() {
	// TODO Auto-generated destructor stub
}

const string& Teacher::getSubject() const {
	return subject;
}

string Teacher::getInfo() {
	string result = "Teacher\n";
	result.append(Person::getInfo());
	result.append("  Subject: ");
	result.append(subject);
	result.append("\n");
	return result;
}

void Teacher::setSubject(const string& subject) {
	this->subject = subject;
}

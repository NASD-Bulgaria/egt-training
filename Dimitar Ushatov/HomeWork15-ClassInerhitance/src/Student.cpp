/*
 * Student.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: NandM
 */

#include "Student.h"

Student::Student() {
	this->setFirstName("John");
	this->setLastName("Doe");
}

Student::Student(string& firstName, string& lastName, vector<Grade>& grades) {
	this->setFirstName(firstName);
	this->setLastName(lastName);
	this->setGrades(grades);
}

const string& Student::getFirstName() const {
	return this->firstName;
}

void Student::setFirstName(const string& firstName) {
	this->firstName = firstName;
}

const vector<Grade>& Student::getGrades() const {
	return this->grades;
}

void Student::setGrades(const vector<Grade>& grades) {
	this->grades = grades;
}

const string& Student::getLastName() const {
	return this->lastName;
}

void Student::setLastName(const string& lastName) {
	this->lastName = lastName;
}

Student::~Student() {
	// TODO Auto-generated destructor stub
}

void Student::addGrade(const Grade& grade) {
	this->grades.push_back(grade);
}

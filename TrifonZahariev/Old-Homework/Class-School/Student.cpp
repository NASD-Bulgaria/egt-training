/*
 * Student.cpp
 *
 *  Created on: 20.08.2014 ã.
 *      Author: Admin
 */

#include "Student.h"
#include <sstream>

Student::Student(string firstName, string lastName, string EGN,
		vector<string> & subjects, vector<double> & marks) :
		Person(firstName, lastName, EGN) {
	this->setSubjectsMarks(marks, subjects);
}

Student::~Student() {
	// TODO Auto-generated destructor stub
}

const vector<double>& Student::getMarks() const {
	return marks;
}

void Student::setSubjectsMarks(const vector<double>& marks, const vector<string>& subjects) {
	if (marks.size() == subjects.size()) {
		this->marks = marks;
		this->subjects = subjects;
	} else {
		cerr<<"The count of subjects must be the same as the count of marks!"<<endl;
		exit(1);
	}
}

const vector<string>& Student::getSubjects() const {
	return subjects;
}

string Student::getInfo() {
	string result = "Student\n";
	result.append(Person::getInfo());
	result.append("  Subjects:\n");
	stringstream str;
	for (unsigned int i = 0; i < subjects.size(); ++i) {
		result.append("    " + subjects[i] + " - Mark: ");
		str << marks[i];
		result.append(str.str());
		str.str("");
		result.append("\n");
	}
	result.append("\n");
	return result;
}

Student::Student(string firstName, string lastName, string EGN) :
		Person(firstName, lastName, EGN) {
}

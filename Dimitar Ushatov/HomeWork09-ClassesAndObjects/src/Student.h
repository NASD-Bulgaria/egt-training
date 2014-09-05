/*
 * Student.h
 *
 *  Created on: Jul 23, 2014
 *      Author: NandM
 */

#ifndef STUDENT_H_
#define STUDENT_H_

using namespace std;
#include "Person.h"
#include <vector>
#include "SchoolClass.h";
#include <algorithm>

class Student: public Person {
public:
	Student(string firstName, string lastName) :
			Person(firstName, lastName) {
	}

	const int getID() const {
		return id;
	}

	void setID(int id) {
		this->id = id;
	}

private:
	int id = 0;
	SchoolClass onwClass;

};
#endif /* STUDENT_H_ */

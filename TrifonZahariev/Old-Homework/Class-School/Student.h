/*
 * Student.h
 *
 *  Created on: 20.08.2014 ã.
 *      Author: Admin
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "Person.h"
#include <cstdlib>
#include <iostream>
#include <vector>

class Student: public Person {
	friend class Course;
public:
	Student(string, string, string);
	Student(string, string, string, vector<string>& , vector<double>&);
	virtual string getInfo();
	virtual ~Student();
	const vector<double>& getMarks() const;
	const vector<string>& getSubjects() const;

private:
	void setSubjectsMarks(const vector<double>& marks,const vector<string>& subjects);
	vector<string> subjects;
	vector<double> marks;
};

#endif /* STUDENT_H_ */

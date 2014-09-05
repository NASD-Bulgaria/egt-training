/*
 * Student.h
 *
 *  Created on: Aug 12, 2014
 *      Author: NandM
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <vector>
#include <string>
using namespace std;

struct Grade{
public:
	Grade(){
		this->subject = "No subject";
		this->mark = 2.0;
	}
	Grade(string& subject, double& mark){
		this->subject = subject;
		this->mark = mark;
	}
	string subject;
	double mark;
};

class Student {
public:
	Student();

	Student(string& firstName, string& lastName, vector<Grade>& grades);

	const string& getFirstName() const;

	void setFirstName(const string& firstName);

	const vector<Grade>& getGrades() const;

	void setGrades(const vector<Grade>& grades);

	const string& getLastName() const;

	void setLastName(const string& lastName);

	virtual ~Student();

	void addGrade(const Grade& grade);

private:
	string firstName;
	string lastName;
	vector<Grade> grades;
};

#endif /* STUDENT_H_ */

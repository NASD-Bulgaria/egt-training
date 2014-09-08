/*
 * Course.cpp
 *
 *  Created on: 20.08.2014 ã.
 *      Author: Admin
 */

#include "Course.h"

Course::Course(vector<Teacher> &teachers, vector<Student> &students) {
	this->teachers = teachers;
	this->students = students;
	setSubjects();
	setStudentMarks(3);
}

Course::~Course() {
	// TODO Auto-generated destructor stub
}

string Course::getInfo() {
	string result = "Course:\nTeachers:\n";
	for (int i = 0; i < teachers.size(); ++i) {
		result.append(teachers[i].getInfo());
	}
	result.append("\nStudents:\n");
	for (int i = 0; i < students.size(); ++i) {
		result.append(students[i].getInfo());
	}
	return result;
}

void Course::setStudentMarks(double initialMark) {
	vector<double> marks;
	for (unsigned int i = 0; i < subjects.size(); ++i) {
		marks.push_back(initialMark);
	}
	for (unsigned int i = 0; i < students.size(); ++i) {
		students[i].setSubjectsMarks(marks, subjects);
	}
}

void Course::setSubjects() {
	for (unsigned int i = 0; i < teachers.size(); ++i) {
		subjects.push_back(teachers[i].getSubject());
	}
}

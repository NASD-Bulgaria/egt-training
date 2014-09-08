/*
 * Course.h
 *
 *  Created on: 20.08.2014 ã.
 *      Author: Admin
 */

#ifndef COURSE_H_
#define COURSE_H_

#include "IPrintable.h"
#include <vector>
#include "Teacher.h"
#include "Student.h"


class Course: public IPrintable {
public:
	Course(vector<Teacher> & teachers, vector<Student> & students);
	virtual ~Course();
	virtual string getInfo();

private:
	vector <Teacher> teachers;
	vector <string> subjects;
	vector <Student> students;
	void setStudentMarks(double initialMark);
	void setSubjects();

};

#endif /* COURSE_H_ */

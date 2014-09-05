/*
 * UnderGraduateStudent.h
 *
 *  Created on: Aug 12, 2014
 *      Author: NandM
 */

#ifndef UNDERGRADUATESTUDENT_H_
#define UNDERGRADUATESTUDENT_H_

#include "Student.h"

class UnderGraduateStudent: public Student {
public:
	UnderGraduateStudent();

	UnderGraduateStudent(string& firstName, string& lastName, vector<Grade>& grades,
			string& highSchoolMajor);

	const Grade& getBachelourDiploma() const;

	const string& getBachelourMajor() const;

	void setBachelourMajor(const string& highSchoolMajor);

	virtual ~UnderGraduateStudent();

private:
	string bachelourMajor;
	Grade bachelourDiploma;

	void calculateDiploma();
};

#endif /* UNDERGRADUATESTUDENT_H_ */

/*
 * GraduateStudent.h
 *
 *  Created on: Aug 12, 2014
 *      Author: NandM
 */

#ifndef GRADUATESTUDENT_H_
#define GRADUATESTUDENT_H_

#include "UnderGraduateStudent.h"

class GraduateStudent: public UnderGraduateStudent {
public:
	GraduateStudent();

	GraduateStudent(string& firstName, string& lastName,
			vector<Grade>& grades, string& bachelourMajor,
			string& masterMajor, Grade masterDisertation);

	const Grade& getMasterDiploma() const;

	const Grade& getMasterDisertation() const;

	void setMasterDisertation(const Grade& masterDisertation);

	const string& getMasterMajor() const;

	void setMasterMajor(const string& masterMajor);

	virtual ~GraduateStudent();

private:
	string masterMajor;
	Grade masterDiploma;
	Grade masterDisertation;

	void calculateMasterDiploma();
};

#endif /* GRADUATESTUDENT_H_ */

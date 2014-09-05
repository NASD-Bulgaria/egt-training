/*
 * UnderGraduateStudent.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: NandM
 */

#include "UnderGraduateStudent.h"
using namespace std;

UnderGraduateStudent::UnderGraduateStudent() : Student(){
	this->setBachelourMajor("No Major");
	this->calculateDiploma();
}

UnderGraduateStudent::UnderGraduateStudent(string& firstName, string& lastName,
		vector<Grade>& grades, string& bachelourMajor)
		:Student(firstName, lastName, grades) {

	this->setBachelourMajor(bachelourMajor);
	this->calculateDiploma();
}

const Grade& UnderGraduateStudent::getBachelourDiploma() const {
	return this->bachelourDiploma;
}

const string& UnderGraduateStudent::getBachelourMajor() const {
	return this->bachelourMajor;
}

void UnderGraduateStudent::setBachelourMajor(const string& bachelourMajor) {
	this->bachelourMajor = bachelourMajor;
}

UnderGraduateStudent::~UnderGraduateStudent() {
	// TODO Auto-generated destructor stub
}

void UnderGraduateStudent::calculateDiploma() {
	double avrg = 0;
	int size = this->getGrades().size();
	for (int grade = 0; grade < size; ++grade) {
		avrg += this->getGrades().at(grade).mark;
	}
	if (size != 0) {
		avrg /= size;
	}

	this->bachelourDiploma.mark = avrg;
	this->bachelourDiploma.subject = this->getBachelourMajor();
}

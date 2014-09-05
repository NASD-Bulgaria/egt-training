/*
 * GraduateStudent.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: NandM
 */

#include "GraduateStudent.h"

GraduateStudent::GraduateStudent() : UnderGraduateStudent(){
}

GraduateStudent::GraduateStudent(string& firstName, string& lastName,
		vector<Grade>& grades, string& bachelourMajor, string& masterMajor,
		Grade masterDisertation)
		:UnderGraduateStudent(firstName, lastName, grades, bachelourMajor){
	this->setMasterMajor(masterMajor);
	this->setMasterDisertation(masterDisertation);
}

const Grade& GraduateStudent::getMasterDiploma() const {
	return this->masterDiploma;
}

const Grade& GraduateStudent::getMasterDisertation() const {
	return this->masterDisertation;
}

void GraduateStudent::setMasterDisertation(const Grade& masterDisertation) {
	this->masterDisertation = masterDisertation;
}

const string& GraduateStudent::getMasterMajor() const {
	return this->masterMajor;
}

void GraduateStudent::setMasterMajor(const string& masterMajor) {
	this->masterMajor = masterMajor;
}

GraduateStudent::~GraduateStudent() {
	// TODO Auto-generated destructor stub
}

void GraduateStudent::calculateMasterDiploma() {
	double mark = (this->getBachelourDiploma().mark
			+ this->getMasterDisertation().mark) / 2;

	this->masterDiploma.mark = mark;
	this->masterDiploma.subject = this->getMasterMajor();
}

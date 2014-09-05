/*
 * Employee.h
 *
 *  Created on: Jul 22, 2014
 *      Author: NandM
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

using namespace std;

class Employee{
public:
	Employee(string firstName, string lastName, double salary){
		this->setFirstName(firstName);
		this->setLastName(lastName);
		this->setSalary(salary);
	}
	const string& getFirstName() const {
		return fName;
	}

	const string& getLastName() const {
		return lName;
	}

	double getSalary() const {
		return salary;
	}

	void setSalary(double salary) {
		if (salary < 0) {
			this->salary = 0;
		} else {

		}
		this->salary = salary;
	}

	double getYearlySalary(){
		return this->getSalary() * 12;
	}

	string getFullName(){
		return this->getFirstName() + " " + this->getLastName();
	}

private:
	string fName;
	string lName;
	double salary;
	void setFirstName(const string& name) {
		fName = name;
	}

	void setLastName(const string& name) {
		lName = name;
	}
};



#endif /* EMPLOYEE_H_ */

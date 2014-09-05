/*
 * Employee.h
 *
 *  Created on: Jul 28, 2014
 *      Author: NandM
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <iostream>
using namespace std;

class Employee{
public:
	Employee(string firstName, string lastName, string egn){
		this->setFirstName(firstName);
		this->setLastName(lastName);
		this->setEgn(egn);
		this->setComisionPercent(0);
		this->setSalesCount(0);
	}

	Employee(string firstName, string lastName, string egn, int salesCount)
		: Employee(firstName,lastName, egn) {
		this->setComisionPercent(salesCount);
		this->setSalesCount(0);
	}

	Employee(string firstName, string lastName, string egn, int salesCount, short comisionPercent)
		:Employee(firstName,lastName, egn, salesCount){
		this->setComisionPercent(comisionPercent);
	}

	short getComisionPercent() const {
		return comisionPercent;
	}

	void setComisionPercent(short comisionPercent) {
		if (comisionPercent >= 0 && comisionPercent <= 100) {
			this->comisionPercent = comisionPercent;
		} else {
			this->comisionPercent = 0;
			cout << "Invalid Comisson Percent"<<endl;
		}
	}

	const string& getEgn() const {
		return egn;
	}

	const string& getFirstName() const {
		return firstName;
	}

	void setFirstName(const string& firstName) {
		if (firstName.length() > 0) {
			this->firstName = firstName;
		} else {
			this->firstName = "John";
			cout<< "Invalid First Name!"<<endl;
		}
	}

	const string& getLastName() const {
		return lastName;
	}

	void setLastName(const string& lastName) {
		if (lastName.length() > 0) {
			this->lastName = lastName;
		} else {
			this->lastName = "Doe";
			cout<< "Invalid Last Name!"<<endl;
		}
	}

	int getSalesCount() const {
		return salesCount;
	}

	void setSalesCount(int salesCount) {
		if (salesCount >= 0) {
			this->salesCount = salesCount;
		} else {
			this->salesCount = 0;
			cout << "Invalid Sales Count!";
		}
	}

private:
	string firstName;
	string lastName;
	string egn;
	int salesCount;
	short comisionPercent;

	void setEgn(const string& egn) {
		bool valid = true;
		if (egn.length() == 10) {
			for (int i = 0; i < 10; ++i) {
				if (!isdigit(egn[i])) {
					valid = false;
					break;
				}
			}
		} else{
			valid = false;
		}
		if (valid) {
			this->egn = egn;
		} else {
			this->egn = "0000000000";
			cout << "Invalid EGN!"<<endl;
		}
	}
};



#endif /* EMPLOYEE_H_ */

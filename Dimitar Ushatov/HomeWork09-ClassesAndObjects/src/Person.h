/*
 * Person.h
 *
 *  Created on: Jul 23, 2014
 *      Author: NandM
 */

#ifndef PERSON_H_
#define PERSON_H_
using namespace std;

class Person{
public:
	Person(string firstName, string lastName){
		this->setFirstName(firstName);
		this->setLastName(lastName);
	}

	const string& getFirstName() const {
		return firstName;
	}

	const string& getLastName() const {
		return lastName;
	}

private:
	string firstName;
	string lastName;

	void setFirstName(const string& firstName) {
		this->firstName = firstName;
	}

	void setLastName(const string& lastName) {
		this->lastName = lastName;
	}
};



#endif /* PERSON_H_ */

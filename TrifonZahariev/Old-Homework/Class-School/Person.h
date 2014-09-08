/*
 * Person.h
 *
 *  Created on: 20.08.2014 ã.
 *      Author: Admin
 */

#ifndef PERSON_H_
#define PERSON_H_

#include "IPrintable.h"
using namespace std;
class Person: public IPrintable {
public:
	Person(string, string, string);
	virtual ~Person();
	virtual string getInfo();
	const string& getEgn() const;
	void setEgn(const string& egn);
	const string& getFirstName() const;
	void setFirstName(const string& firstName);
	const string& getLastName() const;
	void setLastName(const string& lastName);

private:
	string firstName;
	string lastName;
	string EGN;

};

#endif /* PERSON_H_ */

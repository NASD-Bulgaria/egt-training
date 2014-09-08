/*
 * Teacher.h
 *
 *  Created on: 20.08.2014 ã.
 *      Author: Admin
 */

#ifndef TEACHER_H_
#define TEACHER_H_

#include "Person.h"

class Teacher: public Person {
public:
	Teacher(string, string, string, string);
	virtual ~Teacher();
	virtual string getInfo();
	const string& getSubject() const;
	void setSubject(const string& subject);

private:
	string subject;
};

#endif /* TEACHER_H_ */

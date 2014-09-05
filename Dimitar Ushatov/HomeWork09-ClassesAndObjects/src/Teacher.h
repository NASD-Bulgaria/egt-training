/*
 * Teacher.h
 *
 *  Created on: Jul 23, 2014
 *      Author: NandM
 */

#ifndef TEACHER_H_
#define TEACHER_H_
using namespace std;
#include "Person.h"
#include "Title.h"
class Teacher : public Person{
public:
	Teacher(string fristName, string lastName, Title title){
		this->setTitle(title);
	}

	const Title getTitle() const {
		return title;
	}

private:
	Title title;

	void setTitle(Title title) {
		this->title = title;
	}
};




#endif /* TEACHER_H_ */

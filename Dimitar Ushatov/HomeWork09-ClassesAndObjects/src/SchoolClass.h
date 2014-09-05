/*
 * SchoolClass.h
 *
 *  Created on: Jul 23, 2014
 *      Author: NandM
 */

#ifndef SCHOOLCLASS_H_
#define SCHOOLCLASS_H_
#include <vector>
#include "Student.h"
using namespace std;


class SchoolClass{
public:
	SchoolClass(string id, vector<Student> students){

	}

	const vector<Student>& getStudents() const {
		return students;
	}

	void addStudent(Student student){
		this->students.push_back(student);
		student.setID(this->students.size());
	}

	const string& getId() const {
		return id;
	}

	void setId(const string& id) {
		this->id = id;
	}

private:
	vector<Student> students;
	static vector<string> UniqueIDs;
	string id;
	void setStudents(vector<Student>& students) {
		vector<Student>::iterator it = students.begin();
		int id = 1;
		while(it < students.end()){
			(*it).setID(id);
			id++;
			it++;
		}
		this->students = students;
	}
};

vector<string> SchoolClass::UniqueIDs (0);


#endif /* SCHOOLCLASS_H_ */

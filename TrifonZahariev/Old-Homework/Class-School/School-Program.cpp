/*
 * School-Program.cpp
 *
 *  Created on: 20.08.2014 ã.
 *      Author: Admin
 */

// Class Abstract class Person - Fields: string firstName, string LastName, string EGN
// Class Student : public Person - Fields: static const int numberOfSubjects, string[numberOfSubjects] subjects,
//					double[numberOfSubjects] marsk;
// Class Teacher : public Person - Fields: string subjects
// Class Course - Fields: string name, const int numberOfSubjects, const string[numberOfSubjects], Student[numberOfStudents] students,
//					Teacher teacher;
// Class School - Fields: string name, const int numberOfCourses, Course[numberOfCourses] courses
// Abstract Class Printable - virtual string getInfo() = 0;
// Person:
// Student:
// Teacher: >>>>>> Printable
// Course:
// School:
#include "Student.h"
#include "Teacher.h"
#include "Course.h"

using namespace std;

int main() {
	Student student1("Dimitar", "Ushatov", "123446567");
	Student student2("Pesho", "Ushatov", "123446567");
	Student student3("Gosho", "Ushatov", "123446567");
	Student student4("Ivan", "Ushatov", "123446567");
	Student student5("Donka", "Ushatov", "123446567");
	Teacher teacher("Kalin", "Metodiev", "123450000", "C++");
	Teacher teacher1("Miseto", "Petrov", "123450090", "Java");
	vector<Teacher> teachers;
	teachers.push_back(teacher);
	teachers.push_back(teacher1);
	vector<Student> students;
	students.push_back(student1);
	students.push_back(student2);
	students.push_back(student3);
	students.push_back(student4);
	students.push_back(student5);
	Course course1(teachers, students);

	cout << course1.getInfo() << endl;

	return 0;
}


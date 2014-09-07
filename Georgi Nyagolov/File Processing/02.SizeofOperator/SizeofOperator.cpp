//============================================================================
// Name        : SizeofOperator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void canOpenfile(const fstream &);

int main() {
	char charTemp;
	short int shortIntTemp;
	int intTemp;
	long int longIntTemp;
	long long longlongTemp;
	unsigned int unsignetIntTemp;
	float floatTemp;
	double doubleTemp;

	fstream file( "test.txt", ios::out );

	canOpenfile(file);

	file << "char -> " << sizeof(charTemp) << endl;
	file << "short int -> " << sizeof(shortIntTemp) << endl;
	file << "int -> " << sizeof(intTemp) << endl;
	file << "long int -> " << sizeof(longIntTemp) << endl;
	file << "long long -> " << sizeof(longlongTemp) << endl;
	file << "unsigned int -> " << sizeof(unsignetIntTemp) << endl;
	file << "float -> " << sizeof(floatTemp) << endl;
	file << "double -> " << sizeof(doubleTemp) << endl;

	file.close();

	return 0;
}

void canOpenfile(const fstream& file) {
	 if ( !file ){
		 cerr << "File could not be opened." << endl;
		 exit( EXIT_FAILURE );
	 }
}

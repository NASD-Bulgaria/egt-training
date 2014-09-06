//============================================================================
// Name        : Strings.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <string>

int main() {
	using namespace std;

	ifstream inf("Sample.dat");
	ofstream onf("Numbered.dat");


	if (!inf) {

		cerr << "Sample.dat could not be opened for reading!" << endl;

	}
	int counter = 1;

	string strInput;
	// While there's still stuff left to read
	while (!inf.eof()) {
		// read stuff from the file into a string and print it

		getline(inf, strInput);
		onf << counter << " " << strInput << endl;
		counter++;

	}



	return 0;

}

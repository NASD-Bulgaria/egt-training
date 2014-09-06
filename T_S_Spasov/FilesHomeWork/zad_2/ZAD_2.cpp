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
#include <vector>
#include <algorithm>

int main() {
	using namespace std;

	ifstream inf("Sample.dat");
	ofstream onf("Sorted.dat");
    vector<string> names;

	if (!inf) {

		cerr << "Sample.dat could not be opened for reading!" << endl;

	}
	int counter = 1;

	string strInput;
	// While there's still stuff left to read
	while (!inf.eof()) {
		// read stuff from the file into a string and print it

		getline(inf, strInput);
		names.push_back(strInput);


	}
     sort(names.begin(), names.end());

     for (vector<string>::iterator it=names.begin(); it!=names.end(); ++it)
		onf << *it<< endl;





	return 0;

}

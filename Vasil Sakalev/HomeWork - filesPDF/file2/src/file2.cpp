//2. Write a program that reads a text file containing a list of strings, sorts them and saves them
//to another text file. Example:
//Ivan George
//Peter Ivan
//Maria Maria
//George Peter

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream names("names.txt", ios::in);
	ofstream sortNames("sortNames.txt", ios::out);
	if (!names) {
		cerr << "The file coud not be opened !!!";
	}
	vector<string> nam;
	string name;

	while (names >> name) {
		nam.push_back(name);
	}

	sort(nam.begin(), nam.end());

	for (unsigned int i = 0; i < nam.size(); i++) {
		sortNames << nam[i] << endl;
	}
	return 0;
}

//1. Write a program that reads a text file and inserts line numbers in front of each line. The
//result should be another text file.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	ifstream names("names.txt", ios::in);
	ofstream namesNumber("numberNames.txt", ios::out);

	if (!names) {
		cerr << "File coud not be opened !!!";
		exit(1);
	}
	string name;
	string lastName;
	int i = 1;
	while (names >> name >> lastName) {
		namesNumber << left << setw(10) << i << setw(10) << name << setw(10)
				<< lastName << endl;
		i++;

	}
	return 0;
}


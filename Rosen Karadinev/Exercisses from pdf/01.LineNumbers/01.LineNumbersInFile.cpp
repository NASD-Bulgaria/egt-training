#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;


int main()
{

	ifstream inNameFile("Names.txt", ios::in); // Чете от файл и принтира на конзолата
	ofstream outNamesFile("numberNames.txt", ios::out); // Създава файл и пише в него

	if(!inNameFile && !outNamesFile)
	{
		cerr <<"File could not be opened";
		exit(1);
	}

	string firstName;
	string lastName;
	int number = 1;

	while (inNameFile >> firstName >> lastName)
	{
		outNamesFile << left << number << ". "  << firstName << " " << lastName << endl;
		number++;
	}

	return 0;
}


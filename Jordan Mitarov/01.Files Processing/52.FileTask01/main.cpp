/*1. Write a program that reads a text file and inserts line numbers in
front of each line. The
result should be another text file.*/

#include <iostream>
using namespace std;
#include <cstdlib>
#include <fstream>


int main()
{

	string fName;
	string lName;
	int count = 0;  //tova 6te mi broi redovete
	ifstream readFile("read.txt",ios::in); // tva e za 4etene

	if(!readFile)
	{
		cerr<<"Read File could not be opened";
		exit(1);
	}

	ofstream writeFile("write.txt",ios::out); // tva e za zapisvane

	if(!writeFile)
	{
		cerr<<"Write File could not be opened";
		exit(1);
	}

	while(readFile && !readFile.eof())
	{
		count++;
		readFile >> fName >> lName;
		cout<<fName <<" "<<lName<<endl;

		writeFile<<count<<" "<<fName<<" "<<lName<<endl;
	}


	return 0;
}

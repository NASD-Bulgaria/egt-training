/*9. Write a program that compares two text files line by line and prints
the number of lines that are different.*/

#include <iostream>
using namespace std;
#include <fstream>
#include <cstdlib>

int main()
{
	int count = 0;

	ifstream readFile("read.txt",ios::in);
	ifstream readFile2("read2.txt",ios::in);

	if(!readFile)
	{
		cerr<<"File could not be resolved";
		exit(1);
	}

	if(!readFile2)
	{
		cerr<<"File could not be resolved";
		exit(1);
	}

	string fileOne,fileTwo;
	while(readFile && !readFile.eof())
	{
		getline(readFile,fileOne);
		getline(readFile2,fileTwo);

		if(fileOne != fileTwo)
		{
			count++;
		}

		if(readFile2.eof())
		{
			break;
		}


	}
	cout<<"The number of difference row is: "<<count;

	ofstream writeFile("writeResult.txt",ios::out);

	writeFile << "The number of difference row is: " <<count;


	return 0;
}

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;
int main()
{

	ofstream outFile("datasize.dat");

	if (!outFile)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}


	outFile << setw(25) << right << "Data type" << setw(25) << right << "Size (kb)" << endl
			<< setw(25) << right << "char" << setw(25) << right << sizeof(char)<< endl
			<< setw(25) << right << "unsigned char" << setw(25) << right << sizeof(unsigned char)<< endl
			<< setw(25) << right << "short integer" << setw(25) << right << sizeof(short int)<< endl
			<< setw(25) << right << "unsigned short integer" << setw(25) << right << sizeof(unsigned short)<< endl
			<< setw(25) << right << "integer" << setw(25) << right << sizeof(int)<< endl
			<< setw(25) << right << "unsigned int" << setw(25) << right << sizeof(unsigned)<< endl
			<< setw(25) << right << "long int" << setw(25) << right << sizeof(long)<< endl
			<< setw(25) << right << "unsigned long int" << setw(25) << right << sizeof(unsigned long)<< endl
			<< setw(25) << right << "float" << setw(25) << right << sizeof(float)<< endl
			<< setw(25) << right << "double" << setw(25) << right << sizeof(double)<< endl
			<< setw(25) << right << "long double" << setw(25) << right << sizeof(long double)<< endl;

	return 0;
}

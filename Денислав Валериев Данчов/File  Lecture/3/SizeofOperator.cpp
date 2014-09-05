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
		cerr << "Unable to open \"datasize.dat\".\n";
		exit(1);
	}

	outFile << "Data type" << setw(24) << "Size\n char" << setw(21)
			<< sizeof(char) << "\n unsigned char" << setw(12)
			<< sizeof(unsigned char) << "\n short integer" << setw(16)
			<< sizeof(short int) << "\n unsigned short integer" << setw(7)
			<< sizeof(unsigned short) << "\n integer" << setw(22) << sizeof(int)
			<< '\n';

	outFile << "unsigned int" << setw(13) << sizeof(unsigned) << "\nlong int"
			<< setw(17) << sizeof(long) << "\nunsigned long int" << setw(8)
			<< sizeof(unsigned long) << "\nfloat" << setw(20) << sizeof(float)
			<< "\ndouble" << setw(19) << sizeof(double) << "\nlong double"
			<< setw(14) << sizeof(long double) << endl;
}

//============================================================================
// Name        : Ex3_File_Lecture.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	ofstream out("datasize.dat", ios::out);
	if(!out)
	{
		cout<<"Error file opening!";
		return -1;
	}

	out <<left<< setw(20) << "char" <<setw(1)<<sizeof(char)<<setw(5)<<" byte"<<endl;
	out <<left<< setw(20) << "int" <<setw(1)<<sizeof(int)<<setw(5)<<" bytes"<<endl;
	out <<left<< setw(20) << "unsigned int" <<setw(1)<<sizeof(unsigned int)<<setw(5)<<" bytes"<<endl;
	out <<left<< setw(20) << "double" <<setw(1)<<sizeof(double)<<setw(5)<<" bytes"<<endl;
	out <<left<< setw(20) << "float" <<setw(1)<<sizeof(float)<<setw(5)<<" bytes"<<endl;
	out <<left<< setw(20) << "long" <<setw(1)<<sizeof(long)<<setw(5)<<" bytes"<<endl;
	out <<left<< setw(20) << "unsigned long" <<setw(1)<<sizeof(unsigned long)<<setw(5)<<" bytes"<<endl;
	out <<left<< setw(20) << "string" <<setw(1)<<sizeof(string)<<setw(5)<<" bytes"<<endl;

	out.close();

	return 0;
}

//============================================================================
// Name        : ZAD_5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
ifstream file("Sample.txt");
string temp;

ostringstream out;

out << file.rdbuf();

temp = out.str();

file.close();

size_t found = temp.find("start");
 if (found!=std::string::npos)
	 temp.replace(found,5,"finish");
while( found!=string::npos){
 found=temp.find("start",found+1);

 if (found!=std::string::npos)
	 temp.replace(found,5,"finish");

}

ofstream outFile("Sample.txt", ios::trunc);
outFile << temp;
outFile.close();
	return 0;
}

//============================================================================
// Name        : ZAD_8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream file1("Sample_1.txt");
	ifstream file2("Sample_2.txt");
		string temp1, temp2;
while(!(file1.eof() ||file2.eof())){
	getline(file1, temp1);
	getline(file2, temp2);
	if(temp1.compare(temp2)){

		cout << temp1;
		cout<<endl;

		cout << temp2;
		cout<<endl;
	}
	temp1.clear();
	temp2.clear();


}

	return 0;
}

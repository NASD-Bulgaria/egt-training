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
#include <cctype>

using namespace std;

int main() {
	ifstream file("Sample.txt");
	string temp, temp2;

	ostringstream out;

	out << file.rdbuf();

	temp = out.str();

	file.close();
	int begin = 0, end = 0;
	bool flag = true;
	for (unsigned iter = 0; iter <= temp.size(); ++iter) {

		if ((isalpha(temp[iter]) || isdigit(temp[iter])|| temp[iter] == '_') && flag) {
			begin = iter;
			flag = false;
		}
		if (!(isalpha(temp[iter]) || isdigit(temp[iter])|| temp[iter] == '_') && !flag) {
			end = iter;
			flag = true;
			temp2 = temp.substr(begin, end - begin);

			size_t found = temp2.find("test");
				 if (found!=std::string::npos){
					 if(found == 0){
					temp.erase(begin, end - begin);
					 }
				 }



		}

	}


	ofstream outFile("Sample.txt", ios::trunc);
	outFile << temp;
	outFile.close();
	return 0;
}

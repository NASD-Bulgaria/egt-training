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
#include <vector>
using namespace std;

struct alphAndInt {
	int count;
	string nono;
};

void splitStr(string, vector<alphAndInt> &);

int main() {
	ifstream file1("Sample_1.txt");
	ifstream file2("Sample_2.txt");
	string temp1, temp2;

	ostringstream out;

	out << file1.rdbuf();

	temp1 = out.str();
	out << file2.rdbuf();

	temp2 = out.str();

	file1.close();
	file2.close();
	vector<alphAndInt> output;
		splitStr(temp1, output);

		int begin = 0, end = 0;
			bool flag = true;
			unsigned iter = 0;
			for (unsigned iter = 0; iter <= temp2.size(); ++iter) {

				if (isalpha(temp2[iter]) && flag) {
					begin = iter;
					flag = false;
				}
				if (!isalpha(temp2[iter]) && !flag) {
					end = iter;
					flag = true;
					for (unsigned iter = 0; iter < output.size(); ++iter){
					if(temp2.compare(begin, (end - begin), output[iter].nono ) == 0){
						temp2.erase(begin, (end - begin));

						break;
					}
					}


				}

			}

			ofstream outFile("Sample_2.txt", ios::trunc);
			outFile << temp2;
			outFile.close();

	return 0;

}
void splitStr(string str, vector<alphAndInt> &iput) {
	string str2;
	int begin = 0, end = 0;
	alphAndInt temp;

	bool flag = true;
	for (unsigned iter = 0; iter <= str.size(); ++iter) {

		if (isalpha(str[iter]) && flag) {
			begin = iter;
			flag = false;
		}
		if (!isalpha(str[iter]) && !flag) {
			end = iter;
			str2 = str.substr(begin, end - begin);
			if (iput.empty()) {
				temp.nono = str2;
				temp.count = 1;
				iput.push_back(temp);
			} else {
				bool isInSet = false;
				for (unsigned iter = 0; iter < iput.size(); ++iter) {
					if (iput[iter].nono.compare(str2) == 0) {
						iput[iter].count++;
						isInSet = true;
						break;
					}
				}
				if (!isInSet) {
					temp.nono = str2;
					temp.count = 1;
					iput.push_back(temp);
				}
			}
			flag = true;
		}
	}
}



/*
 * 222.cpp
 *
 *  Created on: 30.08.2014 г.
 *      Author: Ramzi
 */

#include <iostream>
#include<iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {

	ifstream inPutfile("fiveTask.txt", ios::in);
	ofstream outPutfile("fiveTaskResult2.txt", ios::out);
	if (!inPutfile && !outPutfile) {
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	string s;
	string result;
	int count = 0;
	while (inPutfile >> s) {
		result = s;
		if (result.length() == 5) {

			unsigned int position = result.find("start");
			while (position != string::npos) {
				result.replace(position, 5, "finish");
				position = result.find("start", position + 1);
			}
			unsigned int position2 = result.find("Start");
			while (position2 != string::npos) {
				result.replace(position2, 5, "Finish");
				position2 = result.find("Start", position2 + 1);
			}
		}
		if (result.length() > 5 && isalpha(result[5]) == false) {
			unsigned int position = result.find("start");
			while (position != string::npos) {
				result.replace(position, 5, "finish");
				position = result.find("start", position + 1);
			}
			unsigned int position2 = result.find("Start");
			while (position2 != string::npos) {
				result.replace(position2, 5, "Finish");
				position2 = result.find("Start", position2 + 1);
			}

		}
		outPutfile << result << " ";
		count++;
		if (count % 6 == 0) {
			outPutfile << endl;
		}
	}

	return 0;
}

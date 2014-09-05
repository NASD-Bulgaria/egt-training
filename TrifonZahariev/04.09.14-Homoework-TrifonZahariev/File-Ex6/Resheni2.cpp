/*
 * Resheni2.cpp
 *
 *  Created on: 30.08.2014 ã.
 *      Author: Admin
 */

#include <iostream>
#include<iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {

	ifstream inText("text.txt", ios::in);
	ofstream outResultText("resultText.txt", ios::out);

	if (!inText && outResultText) {
		cerr << "File could not be opened" << endl;
		exit(1);
	}
	string s;
	string result;
	int count = 0;
	while (inText >> s) {
		result = s;
		if (result.length() == 5) {

			int position = result.find("start");
			while (position != string::npos) {
				result.replace(position, 5, "finish");
				position = result.find("start", position + 1);
			}
			int position2 = result.find("Start");
			while (position2 != string::npos) {
				result.replace(position2, 5, "Finish");
				position2 = result.find("Start", position2 + 1);
			}
		}
		if (result.length() > 5 && isalpha(result[5]) == false) {
			int position = result.find("start");
			while (position != string::npos) {
				result.replace(position, 5, "finish");
				position = result.find("start", position + 1);
			}
			int position2 = result.find("Start");
			while (position2 != string::npos) {
				result.replace(position2, 5, "Finish");
				position2 = result.find("Start", position2 + 1);
			}

		}
		outResultText << result << " ";
		count++;
		if (count % 6 == 0) {
			outResultText << endl;
		}
	}

	return 0;
}


//============================================================================
// Name        : String-Ex6.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using std::string;
using namespace std;


int main() {
	string str;
	getline (cin, str);

	char ch;
	int countA = 0;
	int countE = 0;
	int countO = 0;
	int countI = 0;
	int countU = 0;

	for (unsigned int i = 0 ; i < str.length(); i++) {
		if (islower(str[i])) {
			str[i] = toupper(str[i]);
		}
		ch = str[i];

		switch (ch) {
		case 'A':
		countA++; break;
		case 'E':
		countE++; break;
		case 'O':
		countO++; break;
		case 'I':
		countI++; break;
		case 'U':
		countU++; break;
		default:
			break;
		}
	}

	if (countA != 0)
	cout << "Number of A's is: " << countA << endl;
	if (countE != 0)
	cout << "Number of E's is: " << countE << endl;
	if (countO != 0)
	cout << "Number of O's is: " << countO << endl;
	if (countI != 0)
	cout << "Number of I's is: " << countI << endl;
	if (countU != 0)
	cout << "Number of U's is: " << countU << endl;

	cout << "Total number of vowels is: " << countA + countE + countO + countI + countU << endl;

	return 0;
}

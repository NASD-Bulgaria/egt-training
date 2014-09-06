/*
 * stringStream2.cpp
 *
 *  Created on: 31.08.2014 г.
 *      Author: Ramzi
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;

int main() {

	string str = "ajhjakhkekAjkElykjhyYkykuuuUulkiinmmiiiiiioooOoooooooo";
		int countA = 0;
		int countE = 0;
		int countY = 0;
		int countU = 0;
		int countI = 0;
		int countO = 0;
		char c;
		for (unsigned int i = 0; i < str.length(); i++)
		{
			c=str[i];
			if (c == 'a' || c == 'A'){
				countA++;
			}
			if (c == 'e' || c == 'E' ){
						countE++;
			}
			if (c == 'y' || c == 'Y'){
								countY++;
					}
			if (c == 'u' || c == 'U'){
								countU++;
					}
			if (c == 'i' || c == 'I'){
								countI++;
					}
			if (c == 'o' || c == 'O'){
								countO++;
					}


		}
		cout << "Number of \"a\": " << countA << endl;
		cout << "Number of \"e\": " << countE << endl;
		cout << "Number of \"y\": " << countY << endl;
		cout << "Number of \"u\": " << countU << endl;
		cout << "Number of \"i\": " << countI << endl;
		cout << "Number of \"o\": " << countO << endl;
		cout << "Total of vowels is: " << countA + countE + countI + countO + countU + countY << endl;

	return 0;
}




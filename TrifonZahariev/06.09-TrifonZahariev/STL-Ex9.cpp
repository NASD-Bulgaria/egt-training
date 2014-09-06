//============================================================================
// Name        : STL-Ex9.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>
#include<iterator>
#include <algorithm>
using namespace std;

int main() {
	int array[] = { 2, 2, 3, 3, 2, 3, 4, 3, 3 };

	set<int> oftenElement(array, array + 9);

	int repetitionCount = 0;
	int maxRepetition = 0;
	int majorant;

	for (set<int>::iterator it = oftenElement.begin(); it != oftenElement.end();
			++it) {
		repetitionCount = count(array, array + 9, *it);
		if (repetitionCount > maxRepetition) {
			maxRepetition = repetitionCount;
			majorant = *it;
		}
	}

	if(maxRepetition >= (9 + 1) / 2){
		cout << "The majorant is: " << majorant << endl;
	} else {
		cout <<"There is no majorant" << endl;
	}

	return 0;
}

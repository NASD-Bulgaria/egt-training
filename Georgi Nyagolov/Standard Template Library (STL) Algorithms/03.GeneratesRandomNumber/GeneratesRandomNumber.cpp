//============================================================================
// Name        : GeneratesRandomNumber.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int nextNumber();
bool descendingOrder (int ,int );

int main() {
	srand(time(NULL));

	vector<int> tempVector(20);
	ostream_iterator< int > output( cout, " " );

	generate(tempVector.begin(), tempVector.end(), nextNumber);
	copy( tempVector.begin(), tempVector.end(), output);

	cout << endl;

	sort(tempVector.begin(), tempVector.end(), descendingOrder);
	copy( tempVector.begin(), tempVector.end(), output);


	return 0;
}

int nextNumber()
{
	return  rand()%50 + 1;
} // end function

bool descendingOrder (int i,int j) {
	return (i>j);
}

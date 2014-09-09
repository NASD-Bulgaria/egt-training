//============================================================================
// Name        : FirstThree.cpp
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
bool descendingOrderFirstThree (int ,int, int );

int main() {
	srand(time(NULL));
	vector<int> tempVector(20);
	ostream_iterator< int > output( cout, " " );
	vector< int >::iterator it;

	generate(tempVector.begin(), tempVector.end(), nextNumber);
	copy( tempVector.begin(), tempVector.end(), output);

	for (it = tempVector.begin(); it != (tempVector.end()-3); ++it) {
		if (descendingOrderFirstThree(*it, *(it+1), *(it+2))) {
			cout << endl << *it << " " << *(it+1) <<" "<< *(it+2);
			break;
		}
	}
	return 0;
}

int nextNumber()
{
	return  rand()%50 + 1;
} // end function

bool descendingOrderFirstThree (int i,int j, int n) {
	if (i>j) {
		if (j>n) {
			return true;
		}
	}
	return false;
}

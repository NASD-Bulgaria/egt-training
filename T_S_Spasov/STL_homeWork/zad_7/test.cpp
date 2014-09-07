#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	vector<int> myVec;



	int myarray[] = { 1, 1, 2, -1, 2, 3, 4, -4, -4, -4, 4 };
	int arrSize = sizeof(myarray) / sizeof(*myarray);

	for (int i = 0; i < arrSize; ++i) {
        if(myarray[i] > -1)
		myVec.push_back(myarray[i]);
	}


	ostream_iterator<int> out(cout, ", ");
	copy(myVec.begin(), myVec.end(), out);

	return 0;
}


/* 7. Write a program that removes from a given
sequence all negative numbers.*/
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

bool negativ(const int& value){return (value<0);};
int main() {
	const int SIZE = 10;
	int array[SIZE] = {1,2,-4,-5,-6,7,8,9,-10, -11};
	list <int> withoutNegativ;
	list <int>::const_iterator iter;

	withoutNegativ.insert(withoutNegativ.begin(), array, array +SIZE);
	for(iter = withoutNegativ.begin(); iter != withoutNegativ.end(); iter++){

			//cout << *iter;
			withoutNegativ.remove_if(negativ);

	}

	for(iter = withoutNegativ.begin(); iter != withoutNegativ.end(); iter++){
			cout << *iter << endl;
		}
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

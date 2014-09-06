//============================================================================
// Name        : STL-Ex7.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<algorithm>
#include <list>
#include <iterator>
using namespace std;

template<typename T>
void print(const list<T> &integersRef);

bool isNegative(int element){
	return element < 0;
}

int main() {
int size;
cout << "Enter an array's size: "<< endl;
cin >> size;
int array[size];

cout << "Enter the elements of array one by onbe: "<< endl;

for (int i = 0; i < size; ++i) {
	cin >> array[i];
}

list<int> elements(array, array + size);

elements.remove_if(isNegative);

print(elements);

	return 0;
}
template<typename T>
void print(const list<T> &integersRef) {
	if (integersRef.empty()) // list is empty
		cout << "List is empty";
	else {
		ostream_iterator<T> output(cout, " ");
		copy(integersRef.begin(), integersRef.end(), output);

	}
}

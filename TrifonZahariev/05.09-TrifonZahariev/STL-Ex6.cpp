//============================================================================
// Name        : STL-Ex6.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main() {

	int array[] = {3, 4, 4, 2, 3, 3, 4, 3, 2};

	map<int, int> elements;

	for (int i = 0; i < 9; ++i) {
		if (elements.find(array[i]) == elements.end()) {
			elements.insert(pair<int,int>(array[i],0));
		}
		elements[array[i]]++;
	}

	for(map<int, int>::iterator it = elements.begin(); it != elements.end(); it++){
		cout << it->first << " -> " << it -> second << "\n";
	}

	return 0;
}

//============================================================================
// Name        : 5SortNames.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

int main() {

	vector<string>names;
	string name;

	cout << "Write 5 names of animals: " << endl;

	for (int i = 0 ; i < 5 ; i ++){
		cin>>name;
		names.push_back(name);
	}
	sort(names.begin(), names.end());
	for(unsigned i = 0 ; i < names.size(); i ++){
		cout << names[i] << endl;
	}
	return 0;
}

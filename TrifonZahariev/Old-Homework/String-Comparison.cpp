//============================================================================
// Name        : String-Comparison.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string name;
	vector<string>animals;

	cout << "Please enter the animals: ";


while(name != "end") {
	cin >> name;
	animals.push_back(name);
	cout << "Enter next animal or enter \"end\" to finish:  "<< endl;
}

sort(animals.begin(), animals.end());

for (unsigned int i = 0; i < animals.size(); ++i) {
	if(animals[i] == "end"){
		animals.erase(animals.begin() + i);
	}
	cout << animals[i]<< " ";
}

	return 0;
}

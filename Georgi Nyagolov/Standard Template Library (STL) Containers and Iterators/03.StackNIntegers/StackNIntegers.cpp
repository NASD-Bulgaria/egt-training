//============================================================================
// Name        : StackNIntegers.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
using namespace std;

int main() {
	int check = 1;
	int num;
	stack<int> numbers;
	while (check == 1) {
		cout << "Please enter a intiger:" << endl;
		cin >> num;

		numbers.push(num);
		cout << " do you want to continue 1 - yes/0 - no" << endl;
		cin >> check;
	}

	while (!numbers.empty()) {
		cout << numbers.top() << ' ';
		numbers.pop();
	}

	return 0;
}

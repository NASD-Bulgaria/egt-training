//============================================================================
// Name        : Sequence.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	queue<int> tempQueue;
	int number;
	int temp;
	int counter = 0;

	cout << "Enter number N: ";
	cin >> number;

	tempQueue.push(number);

	for (int i = 1; i < 101; ++i) {
		if (i == 1) {
			temp = tempQueue.front();
			tempQueue.pop();
			cout << temp << " ";
		} else {
			counter++;
			switch (counter) {
				case 1:
					cout << (temp + 1) << " ";
					tempQueue.push(temp + 1);
					break;
				case 2:
					cout << (2*temp + 1) << " ";
					tempQueue.push(2*temp + 1);
					break;
				case 3:
					cout << (temp + 2) << " ";
					tempQueue.push(temp + 2);
					counter = 0;
					temp = tempQueue.front();
					tempQueue.pop();
					break;
			}
		}
	}

	return 0;
}

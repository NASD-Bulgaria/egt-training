//============================================================================
// Name        : core1-STL-9ta-zadacha.cpp
// Author      : Ivan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<map>
#include<iterator>
#include<algorithm>
using namespace std;

int main() {
	const int size = 10;
	int arr[size] = { 5, 5, 5, 1, 9, 3, 5, 5, 3, 3 };
	int k;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				k = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = k;
			}
		}
	}
	map<int, int> integers;
	int currentNumber = arr[0], currentMax = 1;
	for (int i = 1; i < 10; i++)

	{

		if (arr[i] == currentNumber)

		{
			currentMax++;

		}

		else

		{
			integers.insert(
					std::map<int, int>::value_type(currentNumber, currentMax));

			currentNumber = arr[i];
			currentMax = 1;
			if (currentNumber == arr[9]) {

				for (int j = i + 1; j < 10; j++) {
					currentMax++;
				}
				integers.insert(
						std::map<int, int>::value_type(currentNumber,
								currentMax));

			}

		}

	}
	map<int, int>::iterator p;
	int maxCount=size/2;
	int maxNum=0;

	for (p = integers.begin(); p != integers.end(); ++p)
		{if(maxCount<=p->second)
			maxNum=p->first;

		}
	if(maxNum>0)
	cout<<"The majorand integer is "<<maxNum<<endl;
	else
		cout<<"There is no majorand integer"<<endl;

		return 0;
}

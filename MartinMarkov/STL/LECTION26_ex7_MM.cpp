//============================================================================
// Name        : LECTION26_ex7_MM.cpp
// Author      : Martin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

/*
 STL-7.Write a program that removes from a given
 sequence all negative numbers.
 */

using namespace std;

int main()
{
	vector<float> numbers;
	float number = 1.0;

	cout << "Insert a signed integer: " << endl << "Insert zero to break"
			<< endl;

	while (number != 0)
	{

		cout << "Number :";
		cin >> number;

		if (number == 0)
		{
			break;
		}

		numbers.push_back(number);

	}



	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] < 0)
		{
			numbers.erase(numbers.begin() + i);
			i--;
		}
	}

	cout << "The positive integers are: ";

	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << " ";
	}
	/*

	Console:
	Insert a signed integer:
	Insert zero to break
	Number :4
	Number :5
	Number :-3
	Number :-2
	Number :4
	Number :7.8
	Number :-1.9
	Number :0
	The positive integers are: 4 5 4 7.8
	 */

	return 0;
}

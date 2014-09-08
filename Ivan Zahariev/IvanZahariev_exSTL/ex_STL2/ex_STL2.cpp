//============================================================================
// Name        : ex_STL2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>


using namespace std;

template <typename T>
int longestSequence(T array[], int size);

int main()
{
		int array[11] = {1, 1, 1, 0, 5, 0, 3, 3, 4, 4, 6};
		cout<<"The longest sequence is: "<<longestSequence(array, 11);

	return 0;
}

template <typename T>
int longestSequence(T array[], int size)
{
	int currentNumber = array[0];
	int currentMax = 1;
	int longestMax = 1;
		for (int i = 0; i < size; ++i)
		{
				if (array[i] == currentNumber)
				{
					currentMax++;
				}
					else
					{
						currentNumber = array[i];
							if (currentMax > longestMax)
							{
								longestMax = currentMax;
								currentMax = 1;
							}
					}
		}
	return longestMax;
}

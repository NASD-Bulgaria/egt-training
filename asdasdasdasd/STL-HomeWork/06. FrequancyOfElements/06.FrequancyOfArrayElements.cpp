//06. Write a program that finds in a given array of integers how
//many times each of them presents.

#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	int array[] = { 1, 1, 2, 1, 2, 3, 4 };

	int sizeArr = sizeof(array) / sizeof *array;

	for(int i = 0; i < sizeArr; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl << endl;

	list<int> numbers;

	numbers.insert(numbers.begin(), array, array + sizeArr);

	numbers.sort();
	numbers.unique();

	list<int>::const_iterator list;
	int counter = 0;



	for (list = numbers.begin(); list != numbers.end(); list++)
	{
		for (int j = 0; j < sizeArr; j++)
		{
			if (*list == array[j])
			{
				counter++;
			}
		}

		cout << *list << " -> " << counter << endl;
		counter = 0;
	}
	return 0;
}

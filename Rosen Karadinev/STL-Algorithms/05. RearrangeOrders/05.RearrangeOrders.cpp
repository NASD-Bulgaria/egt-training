//5. Make a function that rearranges the order of
//elements in a sequence so that elements that are less
//than or equal to the nth element are placed before
//the nth element. Elements in this group are sorted.
//Other elements are placed after the nth element and
//are not sorted.

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void rearrangesElements(int[], int, int);

int main()
{
	srand(time(0));

	int size;
	cout << "Array size: ";
	cin >> size;

	int arr[size];

	cout << "The array is: ";
	for(int i = 0; i < size; i++)
	{
		arr[i] = 1 + rand() % 20;
		cout << arr[i] << " ";
	}


	cout << "\nChoose an element from the array ";
	int element;
	cin >> element;

	rearrangesElements(arr, size, element);

	return 0;
}

void rearrangesElements(int array[], int size, int element)
{
	vector<int> lessNumbers;
	vector<int> greaterNumbers;

	for(int i = 0; i < size; i++)
	{
		if(array[i] <= element)
		{
			lessNumbers.push_back(array[i]);
		}
		else
		{
			greaterNumbers.push_back(array[i]);
		}
	}

	sort(lessNumbers.begin(), lessNumbers.end());

	vector<int> rearrangeNumbers(lessNumbers.size() + greaterNumbers.size() );

	merge(lessNumbers.begin(), lessNumbers.end(), greaterNumbers.begin(), greaterNumbers.end(),
			rearrangeNumbers.begin());

	cout << "The result is: ";
	for(unsigned int i = 0; i < rearrangeNumbers.size(); i++)
	{
		cout << rearrangeNumbers[i] << " ";
	}
}

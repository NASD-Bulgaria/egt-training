#include <iostream>
#include <iomanip>

using namespace std;

template<typename T>
void selectionSort(T * const , const int); // prototype

template<typename T>
void swap(T * cosnt, T * const);

int main()
{

	const int arraySize = 10;
	int a[arraySize] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 47};

	cout << "Data items in original order\n";

	for(int i = 0; i < arraySize; i++)
	{
		cout << setw(4) << a[i];
	}

	selectionSort(a, arraySize);

	cout << "\nData items in ascending order\n";

	for(int j = 0; j < arraySize; j++)
	{
		cout << setw(4) << a[j];

	}

	cout << endl;
	return 0;
}


template<typename T>
void selectionSort(T * const array, const int size)
{
	int smallest; // index of smallest element

	// loop over size - 1 elements

	for(int i = 0; i < size - 1; i++)
	{
		smallest = i;

		for(int index = i + 1; index < size; index++)
		{
			if(array[index] < array[smallest])
			{
				smallest = index;
			}
		}

		swap(&array[i], &array[smallest]);
	}
}


template<typename T>
void swap(T * const element1Ptr, T * const element2Ptr)
{
	int hold = *element1Ptr;
	*element1Ptr = * element2Ptr;
	*element2Ptr = hold;
}


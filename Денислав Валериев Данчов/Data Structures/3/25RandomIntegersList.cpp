#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "List2.h"

int sumList(List2<int> &listRef)
{
	List2<int> temp(listRef);
	int sum = 0;
	int value;
	while (!temp.isEmpty())
	{
		temp.removeFromFront(value);
		sum += value;
	}

	return sum;
}

double aveList(List2<int> &listRef)
{
	List2<int> temp(listRef);
	int sum = 0;
	int value;
	int count = 0;

	while (!temp.isEmpty())
	{
		temp.removeFromFront(value);
		count++;
		sum += value;
	}

	return static_cast<double>(sum) / count;
}

int main()
{
	srand(time(0));

	List2<int> intList;

	for (int i = 1; i <= 25; i++)
		intList.insertInOrder(rand() % 101);

	intList.print();

	int sum = sumList(intList);
	double average = aveList(intList);

	cout << "The sum of the elements is: " << sum << '\n';
	cout << "The average of the elements is: " << average << '\n';
	return 0;
}

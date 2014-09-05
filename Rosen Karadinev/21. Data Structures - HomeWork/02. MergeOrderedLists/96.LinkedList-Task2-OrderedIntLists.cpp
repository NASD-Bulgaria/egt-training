#include <iostream>
#include "List.h"
using namespace std;

template<typename T>
void merge(List<T> &first, List<T> &second, List<T> &third)
{
	List<T> tempFirst(first);
	List<T> tempSecond(second);

	T value1;
	T value2;

	tempFirst.removeFromFront(value1);
	tempSecond.removeFromFront(value2);

	while(!tempFirst.isEmpty() && !tempSecond.isEmpty())
	{
		if(value1 <= value2)
		{
			third.insertAtBack(value1);
			tempFirst.removeFromFront(value1);
		}
		else
		{
			third.insertAtBack(value2);
			tempSecond.removeFromFront(value2);
		}
	}

	if(value1 < value2)
	{
		third.insertAtBack(value1);
		third.insertAtBack(value2);
	}
	else
	{
		third.insertAtBack(value2);
		third.insertAtBack(value1);
	}

	if(!tempFirst.isEmpty())
	{
		do
		{
			tempFirst.removeFromFront(value1);
			third.insertAtBack(value2);
		}
		while(!tempFirst.isEmpty());
	}
	else
	{
		do
		{
			tempSecond.removeFromFront(value2);
			third.insertAtBack(value2);
		}
		while(!tempSecond.isEmpty());
	}
}

int main()
{
	List<int> list1;
	List<int> list2;
	List<int> list3;

	for(int i = 1; i <= 9; i++)
	{
		list1.insertAtBack(i);
	}

	cout << "List 1 is: "; list1.print();

	for(int i = 10; i <= 20; i++)
	{
		list2.insertAtBack(i);
	}

	cout << "List 2 is: "; list2.print();

	merge(list1,list2,list3);

	cout << "The merged list is: "; list3.print();

	return 0;
}

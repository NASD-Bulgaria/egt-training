/*
Write a program that creates a linked list object of
10 characters and creates a second list object
containing a copy of the first list, but in reverse
order.
*/

#include <iostream>
using namespace std;

#include "List.h"

template <typename T>
void merge(List<T> &first,List<T> &second,List<T>&result)
{
	List<T> tempfirst(first); //create copy of first
	List<T> tempsecond(second); //create copy of second
	T value1;
	T value2;

	tempfirst.removeFromFront(value1);
	tempsecond.removeFromFront(value2);

	while(!tempfirst.isEmpty() && !tempsecond.isEmpty())
	{
		if(value1 <= value2)
		{
			result.insertAtBack(value1);
			tempfirst.removeFromFront(value1);
		}

		else
		{
			result.insertAtBack(value2);
			tempsecond.removeFromFront(value2);
		}
	}

	if(value1 < value2)
	{
		result.insertAtBack(value1);
		result.insertAtBack(value2);
	}

	else
	{
		result.insertAtBack(value2);
		result.insertAtBack(value1);
	}

	if(!tempfirst.isEmpty())
	{
		do
		{
			tempfirst.removeFromFront(value1);
			result.insertAtBack(value2);
		}while(!tempfirst.isEmpty());
	}

	else
	{
		do
		{
			tempsecond.removeFromFront(value2);
			result.insertAtBack(value2);
		}while(!tempsecond.isEmpty());
	}
}

int main()
{

	List<int> listOne;
	List<int> listTwo;
	List<int> listResult;

	for(int i=12;i<=26;i=i+3)
	{
		listOne.insertAtBack(i);
	}

	listOne.print();
	for(int i = 23;i<45;i=i+5)
	{
		listTwo.insertAtBack(i);
	}
	listTwo.print();

	merge(listOne,listTwo,listResult);
	listResult.print();

	return 0;
}

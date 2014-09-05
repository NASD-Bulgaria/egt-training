#include <iostream>
#include"List.h"
using namespace std;



template<typename T>
void concatenate(List<T> &first, List<T> &second)
{
	List<T> temp(second);
	T value;

	while (!temp.isEmpty())
	{
		temp.removeFromFront(value);
		first.insertAtBack(value);
	}
}

int main()
{
	List<char> list1;
	List<char> list2;
	char c;

	for (c = 'a'; c <= 'e'; c++)
		list1.insertAtBack(c);

	list1.print();

	for (c = 'f'; c <= 'j'; c++)
		list2.insertAtBack(c);

	list2.print();

	concatenate(list1, list2);
	cout << "The new list1 after concatenation is:\n";
	list1.print();
	return 0;
}

/*Write a program that merges two ordered list
objects of integers into a single ordered list object of
integers.*/

#include <iostream>
using namespace std;

#include "List.h"

int main()
{

	List<char> list;
	char c;


	for(c ='a';c <= 'j'; c++)
	{
		list.insertAtBack(c);
	}

	list.print();

	list.recursivePrint();

	return 0;
}

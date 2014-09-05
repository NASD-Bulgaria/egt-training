/*Write a program that concatenates two linked list
objects of characters.*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "List.h" // List class definition


int main()
{
	List<char> listOne;
	List<char> listTwo;
	char c;

	for(c='a';c<='e';c++) //pulnq listOne s bukvi ot 'a' do 'e'
	{
		listOne.insertAtBack( c );
	}

	listOne.print();

	for(c='f';c<='k';c++) //pulnq list dve s bukvi ot 'f' do 'k'
	{
		listTwo.insertAtBack( c );
	}

	listTwo.print();

	concatenate(listOne,listTwo); //podavame dvata lista na funkciqta concatenate
	listOne.print();


   return 0;
} // end main


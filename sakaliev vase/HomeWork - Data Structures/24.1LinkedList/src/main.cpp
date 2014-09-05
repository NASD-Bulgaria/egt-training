// Fig. 3.5: main.cpp
// List class test program.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "List.h" // List class definition


int main()
{

	List<char> list1;
	List<char> list2;


	list1.insertAtBack('V');
	list1.insertAtBack('a');
	list1.insertAtBack('s');
	list1.insertAtBack('i');
	list1.insertAtBack('l');

	cout << "First list is " << endl; list1.print();

	list2.insertAtBack('S');
	list2.insertAtBack('a');
	list2.insertAtBack('k');
	list2.insertAtBack('a');
	list2.insertAtBack('l');
	list2.insertAtBack('e');
	list2.insertAtBack('v');

	cout << "Second list is " << endl; list2.print();

	list1.linkedList(list2);
	cout << "The linked list is " << endl; list1.print();


	return 0;
}




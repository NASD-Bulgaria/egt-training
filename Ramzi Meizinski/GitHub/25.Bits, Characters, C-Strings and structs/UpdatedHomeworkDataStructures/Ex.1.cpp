//============================================================================
//// Write a program that concatenates two linked list
//objects of characters.




#include <iostream>
#include <string>
#include <functional>
using namespace std;
#include "List.h"
#include "Listnode.h"

int main() {

	List< int > list1;
	List< int > list2;
	list1.insertAtBack(56);
	list1.insertAtBack(14);
	list1.insertAtBack(3);
	list1.insertAtBack(99);
	list1.insertAtBack(21);
	list1.insertAtBack(30);
	list1.insertAtBack(11);
	list1.insertAtBack(1);
	list1.insertAtBack(0);
	list1.print();
	list1.sorted();
	list1.print();

	list2.insertAtBack(24);
	list2.insertAtBack(14);
	list2.insertAtBack(19);
	list2.insertAtBack(4);
	list2.insertAtBack(7);
	list2.insertAtBack(17);
	list2.insertAtBack(11);
	list2.insertAtBack(99);
	list2.insertAtBack(28);
	list2.print();
	list2.sorted();
	list2.print();
	list1.concatenat(list2);
	list1.sorted();
	list1.print();



	return 0;
}

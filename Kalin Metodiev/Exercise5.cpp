///*
// * Exercise5.cpp
// *
// *  Created on: 5.09.2014 г.
// *      Author: стаса
// */
//
//#include <iostream>
//#include <list>
//#include <algorithm>
//#include <iterator>
//#include<numeric>
//using namespace std;
//
//template<typename T> void printList(const std::list<T> &listRef);
//
//int main() {
//
//	list<int> integers;
//	integers.push_front(3);
//	integers.push_front(6);
//	integers.push_back(9);
//	integers.push_back(0);
//    cout << "integers contains: ";
//    printList(integers);
//	integers.sort();
//	cout << "\n integers after sorting contains: ";
//	printList(integers);
//
//	return 0;
//}
//
//template<typename T> void printList(const list<T> &listRef) {
//	if (listRef.empty())
//		cout << "List is empty";
//	else {
//		ostream_iterator<T> output(cout, " ");
//		copy(listRef.begin(), listRef.end(), output);
//	}
//}
//

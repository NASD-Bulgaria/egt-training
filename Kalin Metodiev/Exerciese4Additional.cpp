///*
// * Exerciese4Additional.cpp
// *
// *  Created on: 8.09.2014 г.
// *      Author: стаса
// */
//
//
//#include <iostream>
//#include <list>
//#include <algorithm>
//#include<set>
//#include <iterator>
//
//using namespace std;
//
//int main() {
//	int N;
//	cout << "Enter N";
//	cin >> N;
//	int array[] = { 4, 2, 2, 5, 2, 3, 2, 3, 1, 5, 2 };
//	list<int> presentsNums(array, array + 11);
//	set<int> uniqueNums(array, array + 11);
//	set<int>::iterator it;
//	for (it = uniqueNums.begin(); it != uniqueNums.end(); it++) {
//		if (count(array, array + 11, *it) == N) {
//			presentsNums.remove(*it);
//		}
//	}
//	ostream_iterator<int> out(cout, " ");
//	copy(presentsNums.begin(), presentsNums.end(), out);
//
//	return 0;
//}
//
//

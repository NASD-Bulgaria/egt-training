///*
// * Exercise3Additional.cpp
// *
// *  Created on: 7.09.2014 г.
// *      Author: стаса
// */
//
//#include <iostream>
//#include <list>
//#include <algorithm>
//#include<set>
//#include <iterator>
//#include<cmath>
//
//using namespace std;
//
//int main() {
//	int array[] = { 4, 8, 2, 2, 16, 3, 1, 5, 2 };
//	list<int> presentsNums(array, array + 9);
//	set<int> uniqueNums(array, array + 9);
//	set<int>::iterator it, it2;
//	for (it = uniqueNums.begin(); it != uniqueNums.end(); it++) {
//		for (it2 = uniqueNums.begin(); it2 != uniqueNums.end(); it2++) {
//			if (pow(2, *it2) == *it) {
//				presentsNums.remove(*it);
//
//			}
//		}
//	}
//	ostream_iterator<int> out(cout, " ");
//	copy(presentsNums.begin(), presentsNums.end(), out);
//
//	return 0;
//}
//

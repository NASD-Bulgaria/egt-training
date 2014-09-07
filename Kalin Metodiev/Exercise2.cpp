///*
// * Exercise2.cpp
// *
// *  Created on: 4.09.2014 г.
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
//int main() {
//
//	const int SIZE = 14;
//	int array[SIZE] = { 3, 3, 3, 3, 3, 5, 5, 6, 6, 7, 7, 7, 7, 7 };
//	list<int> eqValues;
//	list<int>::iterator it = eqValues.begin();
//	for (int i = 0; i < SIZE; i++) {
//		if (array[i] != eqValues.front()) {
//			it = eqValues.begin();
//		}
//		if (it == eqValues.end()) {
//			eqValues.push_back(array[i]);
//		} else {
//			*it = array[i];
//			it++;
//		}
//	}
//	cout << eqValues.back() << " " << eqValues.size() << endl;
//
//	return 0;
//}
//

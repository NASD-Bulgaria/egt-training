///*
// * Exercise3.cpp
// *
// *  Created on: 5.09.2014 г.
// *      Author: стаса
// */
//
//#include <iostream>
//#include <stack>
//#include <algorithm>
//#include <iterator>
//#include<numeric>
//using namespace std;
//
//int main() {
//
//	unsigned int N = 5;
//	cout << "Enter N integers" << endl;
//	istream_iterator<int> inputInt(cin);
//	stack<int> Integers;
//	while (true) {
//		Integers.push(*inputInt);
//		if (Integers.size() < N) {
//			++inputInt;
//		} else {
//			break;
//		}
//	}
//	int number;
//	while (!Integers.empty()) {
//		number = Integers.top();
//		cout << "The reversed integers are: " << " " << number << endl;
//		Integers.pop();
//	}
//	cout << endl;
//
//	return 0;
//}
//

///*
// * Exercise4.cpp
// *
// *  Created on: 9.09.2014 г.
// *      Author: стаса
// */
//
//#include<iostream>
//#include<iomanip>
//#include<vector>
//#include<algorithm>
//#include<ctime>
//#include<cstdlib>
//#include<iterator>
//using namespace std;
//
//int main() {
//	srand(time(0));
//	int N;
//	cout << "Enter N times some numbers" << endl;
//	cin >> N;
//	vector<int> integers;
//
//	for (int i = 0; i < N; ++i) {
//		integers.push_back(1 + rand() % 50);
//	}
//
//	ostream_iterator<int> output(cout, " ");
//	copy(integers.begin(), integers.end(), output);
//	cout << endl;
//	sort(integers.rbegin(), integers.rend());
//
//	copy(integers.begin(), integers.end(), output);
//	cout << endl;
//	cout << "The first 3 integers in descending order are: ";
//	for (int i = 0; i < N - 2; ++i) {
//		if (integers[i] > integers[i + 1]
//				&& integers[i + 1] > integers[i + 2]) {
//
//			cout << integers[i] << " " << integers[i + 1] << " "
//					<< integers[i + 2];
//			break;
//		}
//	}
//	return 0;
//
//}
//

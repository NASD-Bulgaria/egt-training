///*
// * Exercise6.cpp
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
//	cout << "Enter N" << endl;
//	cin >> N;
//	int array[N];
//	for (int i = 0; i < N; ++i) {
//		array[i] = 1 + rand() % 30;
//	}
//	vector<int> integers(array, array + N);
//	vector<int> integers2;
//
//	ostream_iterator<int> output(cout, " ");
//	copy(integers.begin(), integers.end(), output);
//	cout << endl;
//	make_heap(integers.begin(), integers.end());
//
//	cout << "After make_heap vector is: " << endl;
//	copy(integers.begin(), integers.end(), output);
//	cout << endl;
//	sort_heap(integers.begin(), integers.end());
//
//	cout << "After sort_heap vecto is: " << endl;
//	copy(integers.begin(), integers.end(), output);
//
//	return 0;
//}
//

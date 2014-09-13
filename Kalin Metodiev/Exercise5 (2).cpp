///*
// * Exercise5.cpp
// *
// *  Created on: 9.09.2014 г.
// *      Author: стаса
// */
//
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
//void Rearranges(int[], int, int);
//
//int main(){
//	srand(time(0));
//	int N;
//	cout << "Enter N";
//	cin >> N;
//
//	int array[N];
//	for (int i = 0; i < N; ++i) {
//		array[i] = 1 + rand() % 10;
//	}
//	int element;
//	cout << "Please enter an element" << endl;
//	cin >> element;
//    Rearranges(array, N, element);
//	return 0;
//}
//void Rearranges(int array[], int N, int element ){
//	vector<int>lessElements;
//	vector<int>bigers;
//
//	for (int i = 0; i < N; ++i) {
//		if(array[i] <= element){
//			lessElements.push_back(array[i]);
//		}
//		else{
//			bigers.push_back(array[i]);
//		}
//	}
//	sort(lessElements.begin(), lessElements.end());
//
//	for (unsigned int i = 0; i < bigers.size(); ++i) {
//		lessElements.push_back(bigers[i]);
//	}
//	for (unsigned int i = 0; i < lessElements.size(); ++i) {
//		cout << lessElements[i] << " ";
//	}
//}
//
//

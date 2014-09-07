///*
// * Execise10.cpp
// *
// *  Created on: 6.09.2014 г.
// *      Author: стаса
// */
//
//#include<iostream>
//#include<algorithm>
//#include<stack>
//using namespace std;
//int main() {
//	int N;
//	cout << "Enter N" << endl;
//	cin >> N;
//	int M;
//	cout << "Enter M" << endl;
//	cin >> M;
//	stack<string> operations;
//	while (M != N) {
//		if (M % 2 != 0) {
//			M = M - 1;
//			operations.push("M - 1");
//		}
//		if (M / 2 > N) {
//			M = M / 2;
//			operations.push("N * 2");
//			break;
//		}
//	}
//	if(M < N * 2){
//		M = M - 2;
//		operations.push("N + 2");
//		if (M - 1 == N){
//			M = M - 1;
//			operations.push("N + 1");
//		}
//	}
//
//while(!operations.empty()){
//	cout << operations.top() << endl;
//	operations.pop();
//}
//	return 0;
//}
//

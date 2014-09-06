////============================================================================
//// Name        : 111.cpp
//// Author      :
//// Version     :
//// Copyright   : Your copyright notice
//// Description : Hello World in C++, Ansi-style
////============================================================================
//
//#include <iostream>
//#include<iomanip>
//#include <fstream>
//#include <cstdlib>
//#include <vector>
//using namespace std;
//
//int main(){
//
//	ifstream inPutfile ("fiveTask.txt", ios::in);
//		ofstream outPutfile("fiveTaskResult.txt", ios::out);
//		if(!inPutfile && !outPutfile)
//		{
//			cerr << "File could not be opened." << endl;
//					exit(1);
//		}
//		string s;
//		string result;
//		int count = 0;
//		while(inPutfile >> s)
//		{
//			result = s;
//
//			int position = result.find( "start" );
//			while ( position != string::npos ) {
//			result.replace(position,5, "finish");
//			position = result.find( "start", position + 1 );
//			}
//			int position2 = result.find( "Start" );
//			while ( position2 != string::npos ) {
//			result.replace(position2,5, "Finish");
//			position2 = result.find( "Start", position2 + 1 );
//			}
//			outPutfile << result << " ";
//			count++;
//			if (count%6 == 0)
//				{outPutfile << endl;}
//		}
//
// 	return 0;
//}

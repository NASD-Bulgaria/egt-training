///*
// * secondTaskFileProcesing.cpp
// *
// *  Created on: Aug 28, 2014
// *      Author: Student
// */
//#include <iostream>
//#include<iomanip>
//#include <fstream>
//#include <cstdlib>
//#include <vector>
//using namespace std;
//
//int main(){
//
//	ifstream inPutfile ("demoNumber.txt", ios::in);
//	ofstream outPutfile("demoSecondTask.txt", ios::out);
//	if(!inPutfile && !outPutfile)
//	{
//		cerr << "File could not be opened." << endl;
//			exit(1);
//	}
//	string name;
//	string lastName;
//	vector <string> names;
//	while (inPutfile >> name >> lastName)
//	{
//		names.push_back(name);
//	}
//
//	sort(names.begin(),names.end());
//	for (int i = 0; i < names.size(); i++)
//	{
//		outPutfile << names[i] << endl;
//	}
//
//	return 0;
//}

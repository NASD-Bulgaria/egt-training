///*
// * fourthTask.cpp
// *
// *  Created on: Aug 28, 2014
// *      Author: Student
// */
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
//	ifstream inPutfile ("fourthTaskMatrix.txt", ios::in);
//	ofstream outPutfile("fourthTaskMatrixResult.txt", ios::out);
//	if(!inPutfile && !outPutfile)
//	{
//		cerr << "File could not be opened." << endl;
//				exit(1);
//	}
//	int numb;
//	int sizeOfMatrix;
//
//	while(inPutfile >> numb )
//		{
//			sizeOfMatrix = numb;
//			break;
//		}
//	int arr[sizeOfMatrix][sizeOfMatrix];
//	int i = 0;
//	int j = 0;
//	inPutfile.seekg(1);
//	while(inPutfile >> numb )
//	{
//		if(j < sizeOfMatrix)
//		{
//			arr[i][j] = numb;
//			j++;
//		}
//		else
//		{
//			i++;
//			j=0;
//			arr[i][j]=numb;
//			j++;
//		}
//	}
//	int maxValue = 0;
//	for (int i = 0; i<sizeOfMatrix -1;i++)
//	{
//		for (int j = 0;j<sizeOfMatrix-1; j++)
//		{
//			int a = arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1];
//			if (maxValue < a)
//			{
//				maxValue = a;
//			}
//		}
//
//	}
//	outPutfile << maxValue;
//
//
//
//	return 0;
//}

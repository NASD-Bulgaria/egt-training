//============================================================================
// Name        : 3ta.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

int main() {
	string str;

	ifstream in("matrix.txt",ios::in);
	if(!in)
		{
			cout<<" Error"<<endl;
			return -1;
		}
	getline(in,str);
	int n=0;
	n=atoi(str.c_str());
	int matrix[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			in>>str;
			matrix[i][j]=atoi(str.c_str());
		}
	}

	int max=0;
	for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<n-1;j++)
			{
				int sum=matrix[i][j]+matrix[i][j+1]+matrix[i+1][j]+matrix[i+1][j+1];
				if(sum>max)
				{
					max=sum;
				}
			}
		}
	ofstream out("maxnum.txt",ios::out);
	out<<max<<endl;
	in.close();
	out.close();

	return 0;
}

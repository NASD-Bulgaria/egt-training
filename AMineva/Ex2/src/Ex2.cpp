//============================================================================
// Name        : Ex2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int n=4;
	ifstream in("input.txt");
	if(in.is_open())
	{
		int arr[n][n];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
			in>>arr[i][j];
		in.close();
		ofstream out("output.txt");
		if(out.is_open())
		{
			for(int i=0; i<n; i++)
			{
				int ii=i;
				for(int j=0; j<=i; j++)
				{
					out<<arr[ii][j]<<" ";
					--ii;
				}
				out<<endl;
			}
			for(int j=1; j<n; j++)
			{
				int jj=j;
				for(int i=n-1; i>=j; i--)
				{
					out<<arr[i][jj]<<" ";
					jj++;
				}
				out<<endl;
			}
			out.close();
		}
		else cerr<<"Error opening file!";
	}
	else cerr<<"Error opening file!";
	return 0;
}

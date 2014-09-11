//============================================================================
// Name        : Ex6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

//void rotate(int [][6], int, int);

void rotate(int a[][6], int i, int j)
{
	int temp = a[i][j];
	a[i][j] = a[i+1][j];
	a[i+1][j] = a[i+1][j+1];
	a[i+1][j+1] = a[i][j+1];
	a[i][j+1] = temp;
}

int main()
{
	string str;
	ifstream in("input.txt");
	if(in.is_open())
	{
		int arr[6][6];
		for(int i=0; i<6; i++)
			for(int j=0; j<6; j++)
			in>>arr[i][j];
		in.close();
		ifstream inR("rotate.txt");
		if(inR.is_open())
		{
			int rot;
			string temp;
			ofstream out("output.txt");
			if(out.is_open())
			{
				inR>>rot;
				for(int i = 0; i < rot; i++)
				{
					inR>>temp;
					out<<temp<<endl;
					rotate(arr, (int)temp[7]-48,(int)temp[9]-48);
					for(int i=0; i<6; i++)
					{
						for(int j=0; j<6; j++)
						{
							out<<arr[i][j]<<" ";
						}
						out<<endl;
					}
				}
				inR.close();
				out.close();
			}
			else cerr<<"Error opening file!";

		}
		else cerr<<"Error opening file!";
	}
	else cerr<<"Error opening file!";
	return 0;
}

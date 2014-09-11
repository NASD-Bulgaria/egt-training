#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include<sstream>
#include <cstdlib>
using namespace std;

void task1();
void task2();

int main()
{
	task1();
//	task2();

	return 0;
}

void task1()
{
	ifstream in("input.txt",ios::in);
	if (!in)
	{
		cerr << "Error opening file!";
		exit(1);
	}
	string words;
	while(!in.eof())
	{
		getline(in,words);
	}
	int unsigned index=words.find_first_of(",.!?-");
	while(index<=words.length())
	{
		words.erase(index,1);
		index=words.find_first_of(",.!?-",index+1);
	}
	stringstream ss(words);
	ofstream out("output.txt",ios::out);
	do {
		string sub;
		ss >> sub;
		string oneByOne = sub;
		for(int unsigned i=1;i<oneByOne.length();i++)
		{
			if(isupper(oneByOne.at(0))) //at(0) vzima purvata poziciq
			{
				oneByOne[i]='*';
			}
		}
		out<<oneByOne<<" ";
	} while (ss);

}





void task2()
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
}

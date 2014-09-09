#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

void print(int[][4], int);

int main()
{
	ifstream readText("input.txt", ios::in);
	ofstream writeText("output.txt", ios::out);

	if(!readText)
	{
		ofstream write("input.txt");
	    write << "1 1 2 3\n5 8 13 21\n34 55 89 144\n233 377 610 987";
		write.clear();
		write.seekp(0);
	    cerr << "Creating file input.txt"<<endl<<"Please restart the program.";
		exit(1);
	}

	int array[4][4];
	int number;

	int i = 0, j = 0;

	while (readText >> number)
	{
		array[i][j] = number;

		if(j < 4)
		{
			j++;
		}

		if(j == 4)
		{
		   i++;
		   j=0;
		}

	}

	for(int i = 0; i < 4; i++ )
	{
	  print(array, i);
	}

	for(int i = 4; i < 7; i++)
	{
	  print(array, i);
	}

	return 0;
}

void print(int arr[][4], int sum)
{

	for(int i = 3; i >= 0; i--)
	{
		for(int j = 3; j >= 0; j--)
		{
			if(sum == i + j)
			{
			   	cout << arr[i][j] << " ";
			}

		}
	}
cout << endl;
}

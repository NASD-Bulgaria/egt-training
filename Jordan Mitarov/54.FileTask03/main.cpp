/*4. Write a program that reads a text file containing a square matrix of numbers and finds in the
matrix an area of size 2 x 2 with a maximal sum of its elements. The first line in the input file
contains the size of matrix N. The next N lines contain N numbers separated by space. The
output should be a in a separate text file – a single number. Example:
4
2 3 3 4
0 2 3 4 17
3 7 1 2
4 3 3 2*/

#include <iostream>
using namespace std;

#include <fstream>
#include <Cstdlib>

int main()
{
	int size = 0;
	int sum = 0;
	int bigestSum = 0;

	ifstream readFile("readMatrix.txt",ios::in);

	if(!readFile)
	{
		cerr<<"File could not be resovelt";
		exit(1);
	}

	while(readFile && !readFile.eof())
	{
		readFile >> size;break;
	}

	int a[size][size];

	while(readFile && !readFile.eof())
	{
		for(int row=0;row<size;row++)
		{
			for(int col=0;col<size;col++)
			{
				readFile >> a[row][col];
			}
		}

	}

	for(int row=0; row <size;row++)
	{
		for(int col=0;col<size;col++)
		{
			cout << a[row][col]<<" ";
		}
		cout<<endl;
	}

	for(int row=0;row<size-1;row++)
	{
		for(int col=0;col<size-1;col++)
		{
			sum = a[row][col] + a[row][col+1] +
				  a[row+1][col] + a[row+1][col+1];
			if(sum > bigestSum)
			{
				bigestSum = sum;
			}
		}
		cout<<endl;
	}

	ofstream writeFile("writeFileResult",ios::out);

    writeFile << bigestSum;




	return 0;
}

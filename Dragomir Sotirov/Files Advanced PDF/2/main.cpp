#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main()
{

	ifstream readText1("input.txt", ios::in);

	if (!readText1 )
    {
	ofstream write1("input.txt");
    write1 << "1 1 2 3\n5 8 13 21\n34 55 89 144\n233 377 610 987";
	write1.clear();
	write1.seekp(0);
    cerr << "Creating file input.txt"<<endl<<"Please restart the program.";
	exit(1);
	}

    int array[4][4];
	int number;
	int i = 0, j = 0;

			while (readText1 >> number)
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

			ofstream writeText("output.txt", ios::out);

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if(i == 0 && j == 0)
					{
						writeText << array[i][j] <<endl;
						break;
					}

					if(i == 1 && j == 0)
					{
						writeText << array[i][j] <<" " << array[i-1][j+1] <<endl;
						break;
					}

					if(i == 2 && j == 0)
					{
						writeText << array[i][j] <<" "<< array[i-1][j+1] <<" "<< array[i-2][j+2] <<endl;
						break;
					}

					if(i == 3 && j == 0)
					{
						writeText << array[i][j] <<" "<< array[i-1][j+1] <<" "<< array[i-2][j+2] <<" "<< array[i-3][j+3] <<endl;

					}

					if(i == 3 && j == 1)
					{
						writeText << array[i][j] <<" "<< array[i-1][j+1] <<" "<< array[i-2][j+2] <<endl;
					}

					if(i == 3 && j == 2)
					{
						writeText << array[i][j] <<" " << array[i-1][j+1] <<endl;
					}

					if(i == 3 && j == 3)
					{
						writeText << array[i][j] <<endl;
					}
				}
			}

		cout << "Done! Check output.txt"<<endl;

	return 0 ;
}

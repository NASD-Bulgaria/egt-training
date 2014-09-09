#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void Rotate(int array[][6], int, int);

int main()
{

	ifstream readText("game36.txt", ios::in);

	if (!readText)
		    {
			ofstream write("game36.txt");
		    write << "2\nRotate(2,4)\nRotate(1,3)";
		    write.clear();
			write.seekp(0);
			exit(1);
			}

	int array[6][6];
	int count = 1;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			array[i][j] = count;
			count++;
		}
	}

	string word;
	readText.seekg(2);

	while (readText >> word)
	{
		for (unsigned i = 0; i < word.size(); i++)
		{
			if (isdigit(word.at(i)))
			{
				char r = word.at(i);
				char c = word.at(i+ 2);
				int row = r - '0';
				int col = c - '0';

				Rotate(array, row, col);
				break;

			}
		}
	}

	readText.clear();
	readText.seekg(0);

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

void Rotate(int array[][6], int row, int col)
{
	int temp[2][2];
	temp[0][0] = array[row][col];
	temp[0][1] = array[row][col + 1];
	temp[1][0] = array[row + 1][col];
	temp[1][1] = array[row + 1][col + 1];

	array[row][col] = temp[1][0];
	array[row][col + 1] = temp[0][0];
	array[row + 1][col] = temp[1][1];
	array[row + 1][col + 1] = temp[0][1];

}


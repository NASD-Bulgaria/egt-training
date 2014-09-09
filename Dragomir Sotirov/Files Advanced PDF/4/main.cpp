#include <iostream>
#include <string>
#include <fstream>
#include <math.h>


using namespace std;

int main() {
	ifstream readFile("message.txt", ios::in);
	ofstream writeFile("encoded-message.txt", ios::out);

	string word = "";
	string sentence = "";
	while(readFile >> word)
	{
		sentence = sentence + word + " ";
	}

	//cout<<sentence;

	int counter = 0;
	for(unsigned i = 0; i < sentence.size()-1; i++)
	{
		counter++;
	}

	int size = sqrt(counter);
	int ost = size*size - counter;
	if(ost < 0)
	{
		size++;
	}

	//cout<<counter<<" "<<ost<<" "<<size<<endl;

	char matrix[size][size];

	int m = 0;

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j <size; j++)
		{
			if(m > 25)
			{
				//continue;
				matrix[j][i] = ' ';
			}
			else
			{
			matrix[j][i] = sentence[m];
			cout<<matrix[j][i];
			m++;
			}
		}
	}

	int h = 0;
	string result = "";
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			result += matrix[i][j];
			h++;
		}
	}
	cout<<"\n"<<result;
	writeFile << result;

	return 0;
}

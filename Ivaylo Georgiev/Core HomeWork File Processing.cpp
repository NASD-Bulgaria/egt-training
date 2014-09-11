#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void task1email();
void task2email();
void task2();

int main() {

//	task2();
//	task1email();
	task2email();
	return 0;
}

void task1email()
{

//	Write a program that reads a text file and inserts line numbers in front of each line. The
//	result should be another text file.

	ifstream readFile("Combination.txt", ios::in);
	ofstream writeFile("CombinationNum.txt", ios::out);
	string str;
	int index = 1;
	while (getline(readFile, str))
	{
		writeFile << index << ". " << str << endl;
		index++;
	}
	readFile.close();
	writeFile.close();
}

void task2email()
{
	ifstream names("name.txt", ios::in);
	string word;
	int index = 0;
	while (names >> word)
	{
		index++;
	}
	string str[index];
	int temp = 0;
	while (names >> word)
	{
		str[temp] = word;
		temp++;
	}
	cout << str[1]<< endl;
}

void task2() {
//	Standard telephone keypads contain the digits 0
//	through 9. The numbers 2 through 9 each have
//	three letters associated with them ...

	string alph[8] =
			{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	string str;
	cout << "Enter 7 digits number without 0 and 1: " << endl;
	cin >> str;
	ofstream comb("Combination.txt", ios::out);
	char combination[7];
	for (unsigned int i = 0; i < alph[(str[0] - 48) - 2].length(); ++i)
	{
		combination[0] = alph[(str[0] - 50)][i];
		for (unsigned int a = 0; a < alph[(str[1] - 48) - 2].length(); ++a)
		{
			combination[1] = alph[(str[1] - 50)][a];
			for (unsigned int b = 0; b < alph[(str[2] - 48) - 2].length();
					++b) {
				combination[2] = alph[(str[2] - 50)][b];
				for (unsigned int c = 0; c < alph[(str[3] - 48) - 2].length();
						++c) {
					combination[3] = alph[(str[3] - 50)][c];
					for (unsigned int d = 0;
							d < alph[(str[4] - 48) - 2].length(); ++d)
					{
						combination[4] = alph[(str[4] - 50)][d];
						for (unsigned int e = 0;
								e < alph[(str[5] - 48) - 2].length(); ++e)
						{
							combination[5] = alph[(str[5] - 50)][e];
							for (unsigned int f = 0;
									f < alph[(str[6] - 48) - 2].length(); ++f)
							{
								combination[6] = alph[(str[6] - 48) - 2][f];
								comb << combination << endl;
							}
						}
					}
				}
			}
		}
	}
	comb.close();
}

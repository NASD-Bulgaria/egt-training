//============================================================================
// Name        : FileProcessing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//void read(fstream &);
//void sortFile(fstream &, ofstream &);
//void matrixSum(fstream &, ofstream &);
//void lineNumber(fstream &, ofstream &);
//void wordReplace(fstream &);

//void countWordsFromFiles(fstream &, ifstream &);
//string fileToString(ifstream &readfile);
//
//void checkIfWordInMiddle(string, string, int, int &);
//void checkIfWordInEnd(string, string, int, int &);
//void checkIfWordInBeg(string, string, int, int &);
//void vectorSort(vector<string> &, vector<int> &);

int main()
{
	fstream file;
	ofstream newfile;
	ifstream readfile;

//	sortFile(file, newfile);
//
//	lineNumber(file, newfile);
//
//	matrixSum(file, newfile);
//	wordReplace(file);
//
//	countWordsFromFiles(file, readfile);







	return 0;
}
//
//void countWordsFromFiles (fstream &file, ifstream &readfile)
//{
//	file.open("Words.dat", ios::in | ios::out);
//	readfile.open("Text.dat");
//	string temp;
//	string text = fileToString(readfile);
//	int i = 0;
//	int counter = 0;
//	vector<string> words;
//	vector<int> count;
//
//	while (!file.eof())
//	{
//		file >> temp;
//
//		i = text.find(temp);
//
//		while (i != string::npos)
//		{
//			checkIfWordInMiddle(text, temp, i, counter);
//
//			checkIfWordInBeg(text, temp, i, counter);
//
//			checkIfWordInEnd(text, temp, i, counter);
//
//			i = text.find(temp, i + 1);
//		} // end of inner loop
//
//		if (counter > 0)
//		{
//			words.push_back(temp);
//			count.push_back(counter);
//		}
//
//		counter = 0;
//		i = 0;
//	} // end of outer loop
//
//	file.close();
//	file.open("Result.dat", ios::out);
//
//	vectorSort(words, count);
//
//	for (int i = 0; i < words.size(); i++)
//	{
//		file << words[i] << " - "<< count[i]<<endl;
//	}
//
//
//}
//
//string fileToString(ifstream &readfile)
//{
//	string temp;
//	string text;
//	while (!readfile.eof())
//	{
//		getline(readfile, temp);
//
//		text += temp +"\n";
//	}
//
//	readfile.close();
//
//	return text;
//}
//
//void checkIfWordInMiddle(string text, string temp, int i, int &c)
//{
//	if(((text[i - 1] == ' ') || (text[i - 1] == '\n')) &&
//			((text[i + temp.length()] == '\n') || (text[i + temp.length()] == ' ')))
//	{
//		c++;
//	}
//}
//
//void checkIfWordInBeg(string text, string temp, int i, int &c)
//{
//	if(i == 0 && (text[i + temp.length()]) == ' ')
//	{
//		c++;
//	}
//}
//
//void checkIfWordInEnd(string text, string temp, int i, int &c)
//{
//	if((text[i - 1] == ' ') && ((i + temp.length()) >= text.length()))
//	{
//		c++;
//	}
//}
//
//void vectorSort(vector<string> &str, vector<int> &num)
//{
//	int a;
//	string s;
//
//	for (int q = 0; q < str.size() - 1; q++) // loop for sort
//	{
//		if (num[q] > num[q + 1])
//		{
//			a = num[q];
//			num[q] = num[q + 1];
//			num[q + 1] = a;
//
//			s = str[q];
//			str[q] = str[q + 1];
//			str[q+1] = s;
//		}
//	} // end of sort loop
//}
//

//
//void wordReplace(fstream &file)
//{
//	file.open("WordReplace.dat", ios::in | ios::out);
//	string temp;
//	string text;
//	string start = "start";
//	string finish = "finish";
//
//
//	while(!file.eof())
//	{
//		getline (file, temp);
//
//		text += temp + "\n";
//	}
//
//	int index = text.find(start);
//
//	while(index != string::npos)
//	{
//		text.replace(index, 5, finish, 0, 6);
//		index = text.find(start, index + 1);
//	}
//
//
//
//	file << text;
//	cout << text;
//
//
//	file.close();
//
//
//}
//
//void lineNumber(fstream &file, ofstream &newfile)
//{
//	string temp;
//	int lineNum = 1;
//	file.open("Names.dat", ios::in | ios::out);
//	newfile.open("NumLines.dat");
//
//	while (!file.eof())
//	{
//		getline(file, temp);
//		newfile << lineNum <<". "<<temp<<endl;
//		lineNum++;
//	}
//
//	newfile.close();
//	file.close();
//}
//
//void sortFile (fstream &file, ofstream &newfile)
//{
//	string temp;
//	vector<string> names;
//
//
//	file.open("Names.dat", ios::in | ios::out);
//
//	while (!file.eof())
//	{
//		getline(file, temp);
//		names.push_back(temp);
//	}
//
//	file.close();
//
//	sort(names.begin(), names.end());
//
//	newfile.open("SortedNames.dat");
//
//	for(unsigned int i = 0; i < names.size(); i++)
//	{
//		newfile << names[i]<<endl;
//	}
//
//	newfile.close();
//}
//
//void read (fstream &fileName)
//{
//	char ch;
//	cout<<"1";
//	while (!fileName.eof())
//	{
//		fileName.get(ch);
//		cout << ch;
//	}
//}
//
//void matrixSum (fstream &file, ofstream &newfile)
//{
//	int n;
//
//	cin >> n;
//
//	int matrix[n][n];
//	int q;
//
//	newfile.open("Matrix.dat");
//
//	newfile << n << " - matrix size"<< endl;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout <<"Enter array element "<<i * n + j<<": ";
//			cin >> matrix[i][j];
//			newfile << matrix[i][j] << " ";
//		}
//		newfile << endl;
//	}
//
//	int sum = matrix[0][0];
//
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - 1; j++)
//		{
//			q = (matrix[i][j] + matrix[i + 1][j] + matrix[i + 1][j + 1] + matrix[i][j + 1]);
//			if (q > sum)
//			{
//				sum = q;
//			}
//		}
//	}
//
//	newfile.close();
//
//	newfile.open("Matrix2x2Sum.dat");
//
//	newfile << sum << endl;
//
//	newfile.close();
//}





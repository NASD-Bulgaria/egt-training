//============================================================================
// Name        : LinkedListStructure.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
void TaskOne() {
	list<int> integers;
	int number;
	cout << "Enter a positive integer pls!";
	cin >> number;
	while (number != 0) {
		if (number < 0) {
			cout << "Error!!!\nEnter a positive integer pls!" << endl;
			cin >> number;
		} else {
			integers.push_back(number);
			cin >> number;
		}
	}
	int sum = 0;
	double average;
	int count = 0;
	int a = integers.size();
	while (!integers.empty()) {
		number = integers.front();
		integers.pop_front();
		sum += number;

	}
	average = double(sum / a);
	cout << "The sum of all elements is " << sum << "!\n And the average is "
			<< average;
}
void TasTwo() {
	int count = 1;
	int maxCount = count;
	int array[] = { 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2,
			2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
	list<int> sequenceList(array, array + 32);
	int current;
	while (!sequenceList.empty()) {
		int number = sequenceList.front();
		sequenceList.pop_front();
		int number2 = sequenceList.front();
		if (number == number2) {
			count++;
			if (count > maxCount) {
				maxCount = count;
				current = number;
			}
		} else {
			count = 1;
		}
	}
	cout << "The highest sequence of numbers is " << current << " " << maxCount
			<< endl;
}
void TaskThree() {
	int n;
	cout << "Please enter N: " << endl;
	cin >> n;
	queue<int> q;
	queue<int> q1;
	q.push(n);
	q1.push(n);
	int number;
	number = n;
	int element = 1;
	while (element < 100) {
		q.push(number + 1);
		q1.push(number + 1);
		element++;
		q.push(2 * number + 1);
		q1.push(2 * number + 1);
		element++;
		q.push(number + 2);
		q1.push(number + 2);
		element++;
		q1.pop();
		number = q1.front();
	}
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
}
void TaskSix() {
	multiset<int> seq;
	multiset<int>::iterator i;
	int array[20] =
			{ 2, 2, 2, 2, 2, 2, 2, 5, 2, 6, 7, 7, 4, 4, 6, 6, 1, 1, 5, 5 };
	for (int i = 0; i < 20; i++) {
		seq.insert(array[i]);
	}
	i = seq.begin();
	int count = 1;
	while (i != seq.end()) {
		int first = *i;
		i++;
		int second = *i;
		if (first == second) {
			count++;
		} else {
			cout << first << "->" << count << endl;
			count = 1;
		}
	}
}
void TaskSeven() {
	vector<int> sequence;
	int array[11] = { -1, -2, -3, 4, 5, -6, 7, -8, -7, -2, 5 };
	for (int i = 0; i < 11; i++) {
		sequence.push_back(array[i]);
	}
	for (unsigned int i = 0; i < sequence.size(); i++) {
		if (sequence[i] < 0) {
			sequence.erase(sequence.begin() + i);
			i--;
		}

	}
	for (unsigned int i = 0; i < sequence.size(); i++) {
		cout << sequence[i] << endl;
	}
}
void TaskTen() {
	int N;
	int M;
	cout << "Please enter N and M(M must be greater then N)" << endl;
	cin >> N >> M;
	while (M <= N) {
		cout << "M must be greater then N!\nPlease enter greater M!!" << endl;
		cin >> M;
	}
	int op = M;
	stack<string> operations;
	while (N != op) {
		if (op % 2 != 0) {
			op = op - 1;
			operations.push("N+1");
		}
		if (op / 2 >= N) {
			op = op / 2;
			operations.push("N*2");
			if (op == N) {
				break;
			}
		}

		if (op < N * 2) {
			op = op - 2;
			operations.push("N+2");
			if (op - 1 == N) {
				op = op - 1;
				operations.push("N+1");
			}
		}
	}
	cout << "The shortest way from " << N << " to " << M << " is:" << endl;
	cout << "Where N is equal to : " << N << endl;
	while (!operations.empty()) {
		cout << operations.top() << endl;
		operations.pop();
	}
}
void TaskTwelve()
{
	multiset<string> words;
	multiset<string>::iterator it;
	cout << "Please enter a text!!!" << endl;
	string sentence;
	string word;
	getline(cin, sentence);
	for (unsigned int i = 0; i < sentence.length(); i++) {
		char d = sentence.at(i);
		if (isalpha(d) || isdigit(d)) {
			word.append(string(1, d));
		}
		if(word != "")
		{
		if (isspace(d) || ispunct(d) || i == sentence.length() - 1 ) {
			words.insert(word);
			word = "";
		}
		}

	}
	int count = 0;
	string element;
	it = words.begin();
	cout<<words.size()<<endl;
	for(;it != words.end();)
	{
		for(multiset<string>::iterator itn = it;itn != words.end();itn++)
		{
			if(*itn == *it)
			{
				count++;
			}
			else
			{
				break;
			}
		}
		cout<<*it<<"->"<<count<<endl;
		while(count>0)
		{
			it++;
			count--;
		}
	}
}
int main() {

	return 0;
}

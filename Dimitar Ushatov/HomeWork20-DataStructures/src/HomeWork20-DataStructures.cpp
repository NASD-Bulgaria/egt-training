//============================================================================
// Name        : HomeWork20-DataStructures.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <algorithm>
#include <stack>
#include <vector>
#include "LinkedList.h"
#include "OrderedLinkedList.h"
#include "BinaryTree.h"

using namespace std;

void solveTaskOne();
void solveTaskTwo();
void solveTaskThree();
void solveTaskFour();
void solveTaskFive();
void solveTaskSix();
void solveTaskSeven();
void solveTaskEight();
void solveTaskNine();
void solveTaskTen();
void solveTaskEleven();

int main() {
//	solveTaskOne();
//	solveTaskTwo();
//	solveTaskThree();
//	solveTaskFour();
//	solveTaskFive();
//	solveTaskSix();
//	solveTaskSeven();
//	solveTaskNine();
//	solveTaskTen();
	solveTaskEleven();
	return 0;
}

void solveTaskOne() {
	LinkedList<char> first;
	LinkedList<char> second;
	for (char i = 'a'; i <= 'z'; ++i) {
		first.addBack(*(new ListNode<char>(i)));
	}
	for (char i = 'A'; i <= 'Z'; ++i) {
		second.addHead(*(new ListNode<char>(i)));
	}
	first.mergeList(second);
	ListNode<char> * ptr = 0;
	while (first.getCount() > 0) {
		ptr = first.popBack();
		cout << ptr->getData() << " ";
	}
	cout << endl;
}

void solveTaskTwo() {
	vector<int> numbers;
	for (int i = 1; i < 21; ++i) {
		numbers.push_back(i);
	}

	OrderedLinkedList<int> first;
	srand(time(NULL));
	int index;
	while (numbers.size() > 5) {
		index = rand() % numbers.size();
		first.add(*(new ListNode<int>(numbers[index])));
		numbers.erase(numbers.begin() + index);
	}

	OrderedLinkedList<int> second;
	while (numbers.size() > 0) {
		index = rand() % numbers.size();
		second.add(*(new ListNode<int>(numbers[index])));
		numbers.erase(numbers.begin() + index);
	}

	first.mergeList(second);
	first.printForward();
}

void solveTaskThree() {
	vector<int> numbers;
	for (int i = 0; i <= 100; ++i) {
		numbers.push_back(i);
	}
	LinkedList<int> linkedList;
	int index;

	srand(time(NULL));
	while (numbers.size() > 76) {
		index = rand() % numbers.size();
		linkedList.sortedInsert(*(new ListNode<int>(numbers[index])));
		numbers.erase(numbers.begin() + index);
	}

	float count = linkedList.getCount();
	int sum = 0;

	ListNode<int> * ptr = 0;
	while (linkedList.getCount() > 0) {
		ptr = linkedList.popBack();
		cout << ptr->getData() << " ";
		sum += ptr->getData();
	}

	cout << endl;

	cout << "The sum of all elements in the linked list is: " << sum
			<< "\nThe avarage is: " << (sum / count) << endl;
}

void solveTaskFour() {
	LinkedList<char> first;
	LinkedList<char> second;
	for (char i = 'a'; i <= 'j'; ++i) {
		first.addHead(*(new ListNode<char>(i)));
		cout << i << " ";
	}
	cout << endl;

	while (first.getCount() > 0) {
		second.addHead(*first.popHead());
	}

	while (second.getCount() > 0) {
		cout << second.popBack()->getData() << " ";
	}
	cout << endl;
}

void solveTaskFive() {
	string text = "This is some text to print in reverse";
	stack<char> stack;
	for (unsigned int i = 0; i < text.length(); ++i) {
		stack.push(text[i]);
	}
	string reversed;

	while (!stack.empty()) {
		reversed.append(string(1, stack.top()));
		stack.pop();
	}
	cout << reversed << endl;
}

bool checkForPalindom(string & text) {
	stack<char> stack;
	string onlyLetters;
	for (unsigned int i = 0; i < text.length(); ++i) {
		if (isalpha(text[i]) || isdigit(text[i])) {
			onlyLetters.append(string(1, text[i]));
		}
	}
	if (onlyLetters.length() % 2 == 1) {
		onlyLetters.erase(onlyLetters.begin() + onlyLetters.length() / 2);
	}
	for (unsigned int i = 0; i < onlyLetters.length(); ++i) {
		if (!stack.empty() && stack.top() == onlyLetters[i]) {
			stack.pop();
		} else {
			stack.push(onlyLetters[i]);
		}
	}

	return stack.empty();
}

void solveTaskSix() {
	string firstPalindom = "ab ba ";
	string secondPalindom = "abbba";
	string notPalindom = "abvg";

	cout << firstPalindom << " is palindom: "
			<< (checkForPalindom(firstPalindom) ? "True" : "False") << endl;
	cout << secondPalindom << " is palindom: "
			<< (checkForPalindom(secondPalindom) ? "True" : "False") << endl;
	cout << notPalindom << " is palindom: "
			<< (checkForPalindom(notPalindom) ? "True" : "False") << endl;
}

void split(string text, vector<string>& words) {
	string word = "";

	while (text.length() > 0) {
		word = "";
		while (text.length() > 0 && (isalpha(text[0]) || isdigit(text[0]))) {
			word.append(string(1, tolower(text[0])));
			text.erase(0, 1);
		}
		if (word != "") {
			words.push_back(word);
		} else {
			text.erase(0, 1);
		}
	}
}

void solveTaskSeven() {
	string text = "This is a string to be splited";
	vector<string> words;
	split(text, words);
	BinaryTree<string> tree;
	for (unsigned int i = 0; i < words.size(); ++i) {
		tree.insert(*(new TreeNode<string>(words[i])));
	}
	cout << "In Order Traversal:" << endl;
	tree.printInOrder();
	cout << endl;
	cout << "Pre Order Traversal:" << endl;
	tree.printPreOrder();
	cout << endl;
	cout << "Post Order Traversal:" << endl;
	tree.printPostOrder();
}

void solveTaskEight() {
	string text = "This is a string to be splited";
	vector<string> words;
	split(text, words);
	BinaryTree<string> tree;
	for (unsigned int i = 0; i < words.size(); ++i) {
		tree.insert(*(new TreeNode<string>(words[i])));
	}
	cout << "The tree has " << tree.getDepth() << " layers!" << endl;
}

void solveTaskNine() {
	OrderedLinkedList<int> list;
	list.add(*(new ListNode<int>(12)));
	list.add(*(new ListNode<int>(5)));
	list.add(*(new ListNode<int>(35)));
	list.add(*(new ListNode<int>(2)));
	list.add(*(new ListNode<int>(1)));
	list.printBackward();
}

void solveTaskTen() {
	LinkedList<int> list;
	list.addBack(*(new ListNode<int>(12)));
	list.addBack(*(new ListNode<int>(5)));
	list.addBack(*(new ListNode<int>(35)));
	list.addBack(*(new ListNode<int>(2)));
	list.addBack(*(new ListNode<int>(1)));

	int searched;
	cout << "Enter a value to search!" << endl;
	cin >> searched;
	ListNode<int> * ptr = list.searchList(searched);
	if (ptr != 0) {
		cout << "There is a list node with that value!" << endl;
	} else {
		cout << "No list node with that value!" << endl;
	}
}

void solveTaskEleven() {
	BinaryTree<int> tree;
	tree.insert(*(new TreeNode<int>(43)));
	tree.insert(*(new TreeNode<int>(18)));
	tree.insert(*(new TreeNode<int>(28)));
	tree.insert(*(new TreeNode<int>(2)));
	tree.insert(*(new TreeNode<int>(14)));
	tree.insert(*(new TreeNode<int>(87)));
	tree.insert(*(new TreeNode<int>(6)));
	tree.insert(*(new TreeNode<int>(7)));
	tree.insert(*(new TreeNode<int>(11)));
	tree.insert(*(new TreeNode<int>(35)));

	int searched;
	cout << "Enter a value to search!" << endl;
	cin >> searched;

	const TreeNode<int> * const ptr = tree.search(tree.getRoot(), searched);
	if (ptr) {
		cout << "There is a tree node with value " << searched << endl;
	} else {
		cout << "There is no tree node with value " << searched << endl;
	}
}

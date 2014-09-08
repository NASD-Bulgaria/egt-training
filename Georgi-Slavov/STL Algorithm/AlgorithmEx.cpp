//============================================================================
// Name        : AlgorithmEx.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

//zadacha3
void descendingWithList();
// descendingWithList - print a sequence of numbers in descending order;
int generateRandomList();
// genrateRandomList - generate a list of a random numbers;
//-------------------------------------------------------------------//


//zadacha4
void firstThreeElementDescending();
// firstThreeElementDescending - function which search first 3 elements who are descending, if any in the random sequence;
//-------------------------------------------------------------------//


//zadacha5
void rearenge();
// rearenge - function which print in sorted order some part of sequence of numbers, and other part is still in random order.
void rearenge2();


//zadacha6
void convertInHeap();
// convertInHeap - function which make sort in heap


//zadacha7
void sortAllWordsInFile();
// sortAllWordsInFile - function which sort all words in a text file.


//zadacha8
void printOnlyUniqueWords();
// printOnlyUniqueWords - function which read 2 text files and print only unique words between them.


int main() {
	srand(time(0));

	//zadacha3
//	descendingWithList();
//-------------------------------------------------------------------//


	//zadacha4     Нуждае се от още дообработка.
//	firstThreeElementDescending();
//-------------------------------------------------------------------//


	//zadacha5
//firstversion
		//	rearenge();

//secondVersion
		//	rearenge2();
//-------------------------------------------------------------------//


	//zadacha6
//	convertInHeap();
//-------------------------------------------------------------------//


	//zadacha7
//	sortAllWordsInFile();
//-------------------------------------------------------------------//

	//zadacha8
//	printOnlyUniqueWords();


	return 0;
}

//-------------------------------------------------------------------//
//zadacha3
void descendingWithList() {

	ostream_iterator<int> output(cout, " ");

	list<int> myList(20);

	generate(myList.begin(), myList.end(),generateRandomList);

	cout<<"The list: ";
	copy(myList.begin(), myList.end(), output);
	cout<<endl;
	cout<<"Sorted list: ";
	myList.sort();
	copy(myList.rbegin(), myList.rend(), output);
}
int generateRandomList() {

	return rand() % 1000;
}
//--------------------------------------------------------------------//


//zadacha4
void firstThreeElementDescending() {

	ostream_iterator<int> output(cout, " ");


	vector<int> myVector(100);
	vector<int> tempVector(3);
	vector<int>::iterator it;

	generate(myVector.begin(), myVector.end(), generateRandomList);
	cout<<"My List contains: ";
	copy(myVector.begin(), myVector.end(), output);

	cout <<endl;

	for(unsigned int i = 0; i < 100 - 3; i++) {

		copy(myVector.begin() + i, myVector.end() + (i + 3), tempVector.begin());

		sort(tempVector.rbegin(), tempVector.rend());

		bool result = equal(myVector.begin() + i, myVector.begin() + (i + 3), tempVector.begin());


		if(result == true) {
			for(it = tempVector.begin(); it != tempVector.end(); ++it){
				cout<<*it<<" ";
			}
		}
		else {
			cout << "There is no such elements in this vector!\n";
			break;
		}

	}
}
//--------------------------------------------------------------------------------------//


//zadacha5
void rearenge() {

	ostream_iterator<int> output(cout , " ");

	vector<int> myVector(50);
	vector<int> beforeN;
	vector<int> afterN;
	generate(myVector.begin(), myVector.end(), generateRandomList);


	cout << "Input a number in a range[50...950]: ";
	int number;
	cin >> number;
	cout<<endl;

	vector<int>::iterator it;

	for(it = myVector.begin(); it != myVector.end(); ++it) {
		if(*it <= number) {
			beforeN.push_back(*it);
			sort(beforeN.begin(), beforeN.end());
		}
		else {
			afterN.push_back(*it);
		}
	}
		cout<<"Before sort: ";
		copy(myVector.begin(), myVector.end(), output);
		cout<<endl;

		cout<<"After sort: ";
		copy(beforeN.begin(), beforeN.end(), output);
		copy(afterN.begin(), afterN.end(), output);
}

void rearenge2() {

	ostream_iterator<int> output(cout, " ");

	vector<int> myVector(50);

	generate(myVector.begin(), myVector.end(), generateRandomList);
	cout<<"Before sort: ";
	copy(myVector.begin(), myVector.end(), output);
	cout<<endl;

	partial_sort(myVector.begin(), myVector.begin() + 33, myVector.end());
	copy(myVector.begin(), myVector.end(), output);
	cout<<endl;
}
//--------------------------------------------------------------------------------------//


//zadacha6
void convertInHeap() {

	ostream_iterator<int> output(cout, " ");

	vector<int> myVector(20);

	generate(myVector.begin(), myVector.end(), generateRandomList);


	make_heap(myVector.begin(), myVector.end());
	cout<<"Vector in heap before sort: ";
	copy(myVector.begin(), myVector.end(), output);
	cout<<endl;

	cout<<"Vector in heap after sort: ";
	sort_heap(myVector.begin(), myVector.end());
	copy(myVector.begin(), myVector.end(), output);
	cout<<endl;

}
//--------------------------------------------------------------------------------------//

//zadacha7
void sortAllWordsInFile() {

	ostream_iterator<string> output(cout, " ");

	string temp;

	vector<string> myVector;
	vector<string>::iterator it;

	try {
		ifstream myFile;
		myFile.open("data.txt");
		while(myFile >> temp) {
			myVector.push_back(temp);
			temp = "";
		}

		myFile.close();
	}
	catch(exception x) {
		cerr<<"\nUnable to load File!\n";
	}
	cout<<"\nText before sort: "<<endl;
	copy(myVector.begin(), myVector.end(), output);
	cout<<endl;

	sort(myVector.begin(), myVector.end());
	try {
		ofstream newFile;
		newFile.open("sortedText.txt", ios::out);


		for(it = myVector.begin(); it != myVector.end(); ++it) {
			newFile << *it <<" ";
		}

		newFile.close();
	}
	catch(exception x) {
		cerr<<"\nUnable to create file!\n";
	}
	cout<<"After sort:\n";
	copy(myVector.begin(), myVector.end(), output);
}
//--------------------------------------------------------------------------------------//

void printOnlyUniqueWords() {

	ostream_iterator<string> output(cout," ");

	string temp;
	vector<string> firstVector;
	vector<string> secondVector;
	vector<string>::iterator it;

	try {
		ifstream firstFile;
		firstFile.open("data.txt");
		while(firstFile >> temp) {
			firstVector.push_back(temp);
			temp = "";
		}
		firstFile.close();
	}
	catch(exception x) {
		cerr<<"Unable to open file!";
	}

	try {
		ifstream secondFile;
		secondFile.open("data2.txt");
		while(secondFile >> temp) {
			secondVector.push_back(temp);
			temp = "";
		}
		secondFile.close();
	}
	catch(exception x) {
		cerr<<"Unable to open file!";
	}
	cout<<"First file: ";
	copy(firstVector.begin(), firstVector.end(), output);
	cout<<endl;

	cout<<"Second file: ";
	copy(secondVector.begin(), secondVector.end(), output);
	cout<<endl;

	sort(firstVector.begin(), firstVector.end());
	sort(secondVector.begin(), secondVector.end());

	string difference[firstVector.size()];
	string *first = set_difference(firstVector.begin(), firstVector.end(), secondVector.begin(),secondVector.end(), difference);


	string difference2[secondVector.size()];
	string *second = set_difference(secondVector.begin(), secondVector.end(), firstVector.begin(), firstVector.end(), difference2);
	cout<<"\nDifferent words between those two text are:\n";

	cout<<endl;
	copy(difference, first, output);
	copy(difference2, second, output);

}
//--------------------------------------------------------------------------------------//

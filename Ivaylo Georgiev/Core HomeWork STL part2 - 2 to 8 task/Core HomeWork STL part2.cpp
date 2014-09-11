 #include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>
#include <iterator>
#include <deque>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <list>
#include <set>


using namespace std;


int randomNumber();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();

int main()
{
    srand (time(NULL));
//  task3();
//  task4();
//  task5();
//  task6();
//  task7();
//  task8();
    return 0;
}


int randomNumber()
{
    int temp;

    temp = rand ()% 100;
    return temp;
}

void task3()
{
//    Write a program that generates a random number
//    sequence and sorts it in descending order.

    vector <int> num (10);

    generate (num.begin(), num.end(), randomNumber);
    sort(num.begin(), num.end());
    reverse(num.begin(), num.end());

    ostream_iterator < int > output( cout, " " );
    copy (num.begin(), num.end(), output);

}

void task4()
{
/*    Write a program that generates a random number
    sequence and finds the first 3 elements in descending
    order.*/

    vector <int> num (20);
    vector <int> temp (3);

    generate (num.begin(), num.end(), randomNumber);
    ostream_iterator < int > output( cout, " " );
    copy (num.begin(), num.end(), output);
    cout << endl;
    for (unsigned int i = 0; i < num.size()-2; ++i)
    {
        copy(num.begin()+i, num.begin()+(i+3),temp.begin() );
        vector <int> sorted (temp);
        sort(sorted.begin(), sorted.end());
        reverse(sorted.begin(), sorted.end());
        if (sorted == temp)
        {
            cout << "First 3 element of sequence in descending order are: " << endl;
            copy (temp.begin(), temp.end(), output);
            break;
        }

    }

}

void task5()
{

/*    Make a function that rearranges the order of
    elements in a sequence so that elements that are less
    than or equal to the nth element are placed before
    the nth element. Elements in this group are sorted.
    Other elements are placed after the nth element and
    are not sorted. Make a function that rearranges the order of
    elements in a sequence so that elements that are less */

    int num;
    cout << "Enter number:";
    cin >> num;
    deque <int> numbers ;
    numbers.push_back(num);
    for (int i = 0; i < 20; ++i)
    {
        int temp;
        temp = rand ()% 100;
        if (temp < num)
        {
            numbers.push_front(temp);
        }
        else
        {
            numbers.push_back(temp);
        }
    }
    deque< int >::iterator location;

    location = find(numbers.begin(), numbers.end(), num);


    sort(numbers.begin(), location);

    ostream_iterator < int > output( cout, " " );
    copy (numbers.begin(), numbers.end(), output);
    cout << endl;
}

void task6()
{
/*	Convert a random sequence of numbers to a heap.
	Convert the heap to a sorted sequence and back to a
	heap.*/

    vector <int> num (20);

    generate (num.begin(), num.end(), randomNumber);
    ostream_iterator < int > output( cout, " " );
    cout << "Random sequence is:" << endl;
    copy (num.begin(), num.end(), output);

    make_heap(num.begin(), num.end());
    cout << "\nNumbers in Heap is: " << endl;
    copy (num.begin(), num.end(), output);

    sort_heap(num.begin(), num.end());
    cout << "\nSorted Heap is: " <<endl;
    copy (num.begin(), num.end(), output);
}

void task7()
{
//	Sort all words in a text file. Write the result in other
//	text file.

	ifstream read("doc.txt", ios::in);
	ofstream write("sorted.txt", ios::out);

	if (!read)
	{
		cerr << "File could not be opened";
		exit (1);
	}
	string temp;
	string str;
	while (read >> temp)
	{
		str.append(temp + " ");
	}

	string word = "";
	char ch;
	int count = 0;

	vector<string> words;
	while(str.length() != 0)
	{
		word = "";
		while (isalpha(str[0]) || isdigit(str[0]))
		{
			ch = tolower(str[0]);
			word += ch;
			str = str.erase(0,1);
		}
		if (word != "")
		{
			words.push_back(word);
			count++;
		}
		str = str.erase(0,1);
	}
	sort (words.begin(), words.end());

	for(unsigned int i = 0; i < words.size(); i++)
	{
		write << words[i] << " ";
	}
	read.close();
	write.close();
	cout << "Words are sorted!";
}

void task8()
{
//	There are two text files. Display all words that
//	present only in one of the files.

	ifstream read1("doc.txt", ios::in);
	ifstream read2("sorted.txt", ios::in);
	ofstream write("result.txt", ios::out);

	if (!read1 || !read2)
	{
		cerr << "File could not be opened";
		exit (1);
	}
	string temp;
	string str;

	while (read1 >> temp)
	{
		str.append(temp + " ");
	}

	while (read2 >> temp)
	{
		str.append(temp + " ");
	}

	string word = "";

	char ch;

	set<string> words;
	while(str.length() != 0)
	{
		word = "";
		while (isalpha(str[0]) || isdigit(str[0]))
		{
			ch = tolower(str[0]);
			word += ch;
			str = str.erase(0,1);
		}
		if (word != "")
		{
			words.insert(word);
		}
		str = str.erase(0,1);
	}
	set<string>::iterator iter;
	for(iter = words.begin(); iter != words.end(); iter++)
	{
		write << *iter << " ";
	}
	read1.close();
	read2.close();
	write.close();
	cout << "End";
}



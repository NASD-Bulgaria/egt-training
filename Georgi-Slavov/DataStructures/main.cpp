//============================================================================
// Name        : Struct.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "DeckOfCards.h"
#include <bitset>
#include <cctype>
using std::isdigit;
#include <cstdlib>

#include <vector>
using std::vector;
#include <string>
#include <sstream>
using std::string;
using namespace std;

//zadacha3
void power2(int,int);

//zadacha4
/*
 * The left-shift operator can be used to pack two
	character values into a two-byte unsigned integer
	variable. Write a program that inputs two
	characters from the keyboard and passes them to
	function packCharacters. To pack two characters
	into an unsigned integer variable, assign the first
	character to the unsigned variable, shift the
	unsigned variable left by 8 bit positions and
	combine the unsigned variable with the second
	character using the bitwise inclusive-OR operator.
	The program should output the characters in their
	bit format before and after they are packed into the
	unsigned integer to prove that they are in fact
	packed correctly in the unsigned variable.
 */
void packCharacters(char,char);


//zadacha5
/*
 * Using the right-shift operator, the bitwise AND
	operator and a mask, write function
	unpackCharacters that takes the unsigned integer
	from Exercise 4 and unpacks it into two characters.
	To unpack two characters from an unsigned twobyte
	integer, combine the unsigned integer with the
	mask 65280 (11111111 00000000) and right-shift the
	result 8 bits. Assign the resulting value to a char
	variable. Then, combine the unsigned integer with
	the mask 255 (00000000 11111111). Assign the result
	to another char variable. The program should print
	the unsigned integer in bits before it is unpacked,
	then print the characters in bits to confirm that they
	were unpacked correctly.
 */
void unpackedCharacters(int);

//zadacha6
void characterTest(char);

//zadacha7
void stringToInteger(const char *,const char *, const char *, const char *);

//zadacha8
void stringToDouble(const char *,const char *, const char *, const char *);




int main() {
	//zadacha1
	/*
	 * Modify the program of Fig. 25.14 to shuffle the cards
		using a high-performance shuffle, as shown in Fig.
		25.3. Print the resulting deck in two-column format,
		as in Fig. 25.4. Precede each card with its color.
	 */
	cout<<"Task One!" <<endl;
	DeckOfCards cards;
	cards.shuffle();
	cards.deal();
	cout<<endl;
	cout<<endl;

	//zadacha2
	/* Write a program that right-shifts an integer variable
		4 bits. The program should print the integer in bits
		before and after the shift operation.
	 */
	cout<<"Task Two!"<<endl;
	int number = 50000;
	bitset<16>theNumber(number);
	cout << "Before shift: "<<theNumber;
	cout<<endl;
	int shiftedNumber = number >> 4;
	bitset<16>shifted(shiftedNumber);
	cout<<"After  shift: "<<shifted;
	cout<<endl;
	cout<<endl;

	//zadacha3
	/*
	 *Left-shifting an unsigned integer by 1 bit is
	equivalent to multiplying the value by 2. Write
	function power2 that takes two integer arguments,
	number and pow, and calculates number* 2pow
	Use a shift operator to calculate the result. The program
	should print the values as integers and as bits.
	 */
	cout<<"Task Three!"<<endl;
	power2(3,5);
	cout<<endl;
	cout<<endl;

	//zadacha4 , zaedno sus zadacha 5
	cout<<"Task Four and Five!"<<endl;
	packCharacters('t','y');
	cout<<endl;
	cout<<endl;


    //zadacha6
	/*
	 * Write a program that inputs a character from the
		keyboard and tests the character with each
		function in the character-handling library. Print
		the value returned by each function.
	 */
	cout<<"Task Six!"<<endl;
	characterTest('g');
	cout<<endl;
	cout<<endl;

	//zadacha7
	/*
	 * Write a program that inputs four strings that
		represent integers, converts the strings to integers,
		sums the values and prints the total of the four
		values. Use only the C-style string-processing
		techniques shown in this chapter.
	 */
	cout<<"Task Seven!"<<endl;
	stringToInteger("7953","1266","3541","5683");
	cout<<endl;
	cout<<endl;


	//zadacha8
	/*
	 *Write a program that inputs four strings that
		represent floating-point values, converts the strings
		to double values, sums the values and prints the
		total of the four values. Use only the C-style stringprocessing
		techniques shown in this chapter.
	 */
	cout<<"Task Eight!"<<endl;
	stringToDouble("654.32","468.18","137.36","981.11");
	cout<<endl;
	cout<<endl;


	return 0;
}

//zadacha3
void power2(int number, int pow) {
	int product = 1;
	int totalProduct = 1;
	for(int i = 0; i < pow; i++) {
		product *= 2;
	}
	cout<<"Product of 2^pow = "<<product;
	cout<<endl;
	totalProduct = number * product;
	cout<<"Total of number * 2^pow = "<<totalProduct;
	cout<<endl;
	bitset<16>before(totalProduct);
	cout<<"Before shift of totalProduct: "<<before <<endl;

	int shifted = totalProduct << 1;
	bitset<16>shift(shifted);
	cout<<"After shift of totalProduct:  "<<shift << endl;
	cout<<"New number: "<<shifted;
}

//zadacha4
void packCharacters(char first, char second){
	cout<<"First Char: " <<first<<" , "<<"SecondChar: " << second;
	cout<<endl;
	unsigned char a = first;
	unsigned char b = second;

	int num1 = a;
	int num2 = b;
	int sum;

	bitset<16>firstChar(num1);
	cout<<"First char before shift: "<<firstChar;
	cout<<endl;
	bitset<16>secondChar(num2);
	cout<<"Second char:             "<<secondChar;
	cout<<endl;
	int shiftFirst = num1 << 8;
	bitset<16>afterShift(shiftFirst);
	cout<<"First char after shift:  "<<afterShift;
	cout<<endl;
	sum = (shiftFirst|num2);
	bitset<16>theSum(sum);
	cout<<"Sum of those characters: "<<theSum;
	cout<<endl;

	unpackedCharacters(sum);
}


//zadacha5
void unpackedCharacters(int number) {
	unsigned mask2 = 255;    //(00000000 11111111)
	unsigned mask = 65280;   //(11111111 00000000)
	int changedFirst = number & mask;
	int changedSecond = number & mask2;
	int shiftFirst = changedFirst >> 8;


	bitset<16>fir(changedFirst);
	cout<<"First Before shift: "<<fir;
	cout<<endl;
	bitset<16>sec(changedSecond);
	cout<<"Second:             "<<sec;
	cout<<endl;
	bitset<16>chan(shiftFirst);
	cout<<"First After shift:  "<<chan;
	cout<<endl;
	char first = shiftFirst;
	char second = changedSecond;

	cout<<"CharOne: " <<first << " , CharTwo: " <<second <<endl;

}

//zadacha6
void characterTest(char c) {
	cout<<"Return 1 for true, and 0 for False."<<endl;
	cout<<"Is digit? " <<isdigit(c) <<endl;
	cout<<"Is alpha? " <<isalpha(c) <<endl;
	cout<<"Is alnum? " <<isalnum(c) <<endl;
	cout<<"Is xdigit? " <<isxdigit(c) <<endl;
	cout<<"Is lower? " <<islower(c) <<endl;
	cout<<"Is upper? " <<isupper(c) <<endl;
	cout<<"To lower? " <<tolower(c) <<endl;
	cout<<"To upper? " <<toupper(c) <<endl;
	cout<<"Is space? " <<isspace(c) <<endl;
	cout<<"Is cntrl? " <<iscntrl(c) <<endl;
	cout<<"Is punct? " <<ispunct(c) <<endl;
	cout<<"Is print? " <<isprint(c) <<endl;
	cout<<"Is graph? " <<isgraph(c) <<endl;
}

//zadacha7
void stringToInteger(const char * first,const char * second, const char *third, const char *four) {
	int a = atoi(first);
	int b = atoi(second);
	int c = atoi(third);
	int d = atoi(four);
	int sum = a + b + c + d;

	cout<<"The sum of those 4 strings is = " << sum;

}


//zadacha8
void stringToDouble(const char * first,const char * second, const char *third, const char *four) {
	double a = atof(first);
	double b = atof(second);
	double c = atof(third);
	double d = atof(four);

	double sum = a + b + c + d;

	cout<<"The double sum of those 4 strings is = "<<sum;
}




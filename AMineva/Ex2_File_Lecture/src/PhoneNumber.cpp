/*
 * PhoneNumber.cpp
 *
 *  Created on: Aug 31, 2014
 *      Author: Keen
 */

#include "PhoneNumber.h"

PhoneNumber::PhoneNumber(){}

PhoneNumber::PhoneNumber(int one, int two, int three, int four, int five, int six, int seven)
{
	numberOne=one;
	numberTwo=two;
	numberThree=three;
	numberFour=four;
	numberFive=five;
	numberSix=six;
	numberSeven=seven;
}

const string PhoneNumber::letter[][9] = {
						{"a", "d", "g", "j", "m", "p", "t", "w", "_"},
						{"b", "e", "h", "k", "n", "q", "u", "x", "_"},
						{"c", "f", "i", "l", "o", "r", "v", "y", "_"},
						{"_", "_", "_", "_", "_", "s", "_", "z", "_"},
				};

int PhoneNumber::getIndex(int n)
{
	if(n>=2 && n<=9) return n-2;
	return 8;
}

void PhoneNumber::saveCombinations()
{
	ofstream out("combinations.txt", ios::out);
	if(!out)
	{
		cout<<"Error opening file!"<<endl;
		exit(1);
	}
	int index = 1;
	for(int one=0; one<4; one++)
	{
		for(int two=0; two<4; two++)
		{
			for(int three=0; three<4; three++)
			{
				for(int four=0; four<4; four++)
				{
					for(int five=0; five<4; five++)
					{
						for(int six=0; six<4; six++)
						{
							for(int seven=0; seven<4; seven++)
							{
								out<<index<<" : "
									<<letter[one][getIndex(numberOne)]
								    <<letter[two][getIndex(numberTwo)]
								    <<letter[three][getIndex(numberThree)]
								    <<letter[four][getIndex(numberFour)]
								    <<letter[five][getIndex(numberFive)]
								    <<letter[six][getIndex(numberSix)]
								    <<letter[seven][getIndex(numberSeven)]
								<<endl;
								index++;
							}
						}
					}
				}
			}
		}
	}
	out.close();
}

//ostream & operator <<(ostream &output,  const PhoneNumber &number)
//{
//	output<<number.numberOne<<number.numberTwo<<number.numberThree<<"-"<<number.numberFour<<number.numberFive<<number.numberSix<<number.numberSeven;
//	return  output;
//}
//
//istream & operator >>(istream &input, PhoneNumber &number)
//{
//	input >> setw(1) >> number.numberOne;
//	input >> setw(1) >> number.numberTwo;
//	input >> setw(1) >> number.numberThree;
//	input.ignore(1);
//	input >> setw(1) >> number.numberFour;
//	input >> setw(1) >> number.numberFive;
//	input >> setw(1) >> number.numberSix;
//	input >> setw(1) >> number.numberSeven;
//	return  input;
//}

PhoneNumber::~PhoneNumber() {
	// TODO Auto-generated destructor stub
}


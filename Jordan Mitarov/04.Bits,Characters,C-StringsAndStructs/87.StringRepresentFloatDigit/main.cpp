#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void convertStringToDigit(char[],char[],char[],char[]);
void calculateTotalSum(double,double,double,double);

int main()
{
	char one[5];
	char two[5];
	char three[5];
	char four[5];

	cout<<"Enter a first string: ";
	cin>>one;
	cout<<"Enter a second string: ";
	cin>>two;
	cout<<"Enter a third string: ";
	cin>>three;
	cout<<"Enter a four string: ";
	cin>>four;

    convertStringToDigit(one,two,three,four);

	return 0;
}
void convertStringToDigit(char one[],char two[],char three[],char four[])
{
	double iOne;
	double iTwo;
	double iThree;
	double iFour;

	iOne = atof(one);
	iTwo = atof(two);
	iThree = atof(three);
	iFour = atof(four);

	cout<<"The value first is: "<<iOne<<endl;
	cout<<"The value second is: "<<iTwo<<endl;
	cout<<"The value third is: "<<iThree<<endl;
	cout<<"The value four is: "<<iFour<<endl;

	calculateTotalSum(iOne,iTwo,iThree,iFour);
}
void calculateTotalSum(double iOne,double iTwo,double iThree,double iFour)
{
	double result = iOne + iTwo + iThree + iFour;
	cout<<"Total of the four values is: "<<result;
}

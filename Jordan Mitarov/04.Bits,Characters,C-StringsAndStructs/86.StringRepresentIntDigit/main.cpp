#include <iostream>
#include <cstdlib>
using namespace std;

void convertStringToDigit(char[],char[],char[],char[]);
void calculateTotalSum(int,int,int,int);

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
	int iOne;
	int iTwo;
	int iThree;
	int iFour;

	iOne = atoi(one);
	iTwo = atoi(two);
	iThree = atoi(three);
	iFour = atoi(four);

	cout<<"The value first is: "<<iOne<<endl;
	cout<<"The value second is: "<<iTwo<<endl;
	cout<<"The value third is: "<<iThree<<endl;
	cout<<"The value four is: "<<iFour<<endl;

	calculateTotalSum(iOne,iTwo,iThree,iFour);
}
void calculateTotalSum(int iOne,int iTwo,int iThree,int iFour)
{
	int result = iOne + iTwo + iThree + iFour;
	cout<<"Sum of the four digits is: "<<result;
}

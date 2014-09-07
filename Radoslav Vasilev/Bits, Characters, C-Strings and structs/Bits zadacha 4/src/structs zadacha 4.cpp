//============================================================================
// Name        : structs.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bitset>
using namespace std;
unsigned int packCharacter(char number, char power2);//zadacha 4
void unpackCharacter(unsigned int);
int main()
{
	char a;
	char b;
	cout<<"edno"<<endl;
	cin>>a;
	cout<<"dve"<<endl;
	cin>>b;

	unpackCharacter(packCharacter(a,b));

	return 0;
}
unsigned int packCharacter(char number, char power2)
{
	unsigned int a;
	unsigned int b;
	cout<<number<<" "<<power2<<endl;
	cout<<(bitset<16>)number<< " "<<(bitset<16>)power2<<endl;
	a= number<<8;
	b= a | power2;
	cout<<(bitset<16>)b<<"  "<< endl;
	return b;
}

void unpackCharacter(unsigned int number)
{
	char a;
	char b;
	unsigned int mask = 65280;
	unsigned int mask1 = 255;
	unsigned int temp;
	temp= number&mask;
	a = temp >> 8;

	b= number&mask1;
	cout<<a <<b<<endl;
}

#include <iostream>
#include <vector>
#include <iterator>
#include "ComplexNumbers.h"

using namespace std;

int main (){
	ComplexNumbers empty;
	ComplexNumbers first;
	first.setReal(5);
	first.setImaginery(6);
	ComplexNumbers second (7,8);
	cin >> empty;
	cout << first << endl;
	cout << empty << endl;
	if (empty == first)
	{
		cout << "The empty is equal to first" << endl;
	}
	else
	{
		cout << "The empty isnt equal to first" << endl;
	}

	empty = first + second;

	cout << "The new empty is - " << empty << endl;

	ComplexNumbers edno(1,1);
	ComplexNumbers dve(2,2);
	ComplexNumbers tri(3,3), chetiri (4,4), pet(5,5);

	vector<ComplexNumbers> complexvector;
	vector<ComplexNumbers>::iterator comItrtr;

	complexvector.push_back(edno); complexvector.push_back(dve); complexvector.push_back(tri);
	complexvector.push_back(chetiri); complexvector.push_back(pet);

	for (comItrtr = complexvector.begin(); comItrtr != complexvector.end(); comItrtr++)
	{
		cout << *comItrtr << endl;
	}

	

	return 0;
}

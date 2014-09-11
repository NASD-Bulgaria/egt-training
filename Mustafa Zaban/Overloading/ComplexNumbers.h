#pragma once
#include <iostream>
using namespace std;

class ComplexNumbers
{
	friend ostream &operator<< (ostream &, ComplexNumbers &);
	friend istream &operator>> (istream &, ComplexNumbers &);
private:
	int real;
	int imaginery;
public:
	ComplexNumbers ();
	ComplexNumbers ( int, int );
	ComplexNumbers (const ComplexNumbers & ); //

	void setReal ( int );
	void setImaginery ( int );

	int getReal ();
	int getImaginery ();

	ComplexNumbers operator+ ( const ComplexNumbers & ); 
	ComplexNumbers operator= ( const ComplexNumbers & ); 

	bool operator== ( const ComplexNumbers & ) const; 
	bool operator!= ( const ComplexNumbers & ) const; 

};


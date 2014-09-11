#include <iostream>
#include "ComplexNumbers.h"

using namespace std;



ComplexNumbers::ComplexNumbers ()
{
	this->real = 0;
	this->imaginery = 0;
}

ComplexNumbers::ComplexNumbers ( int rl, int imgnry)
{
	setReal ( rl );
	setImaginery ( imgnry );
	
}

ComplexNumbers::ComplexNumbers ( const ComplexNumbers & rhs) 
{
	this->real = rhs.real;
	this->imaginery = rhs.imaginery;
}

void ComplexNumbers::setReal ( int rl)
{
	this->real = rl;
}

void ComplexNumbers::setImaginery ( int imgnry)
{
	this->imaginery = imgnry;
}

int ComplexNumbers::getReal ()
{
	return real;
}

int ComplexNumbers::getImaginery ()
{
	return imaginery;
}

ostream &operator<< (ostream &output, ComplexNumbers &number)
{
	output << number.real << "+i." << number.imaginery;
	return output;
}

istream &operator>> (istream &input, ComplexNumbers &number)
{
	input >> number.real;
	input >> number.imaginery;
	return input;
}

ComplexNumbers ComplexNumbers::operator+ ( const ComplexNumbers & rhs )
{
	int resultReal = this->real + rhs.real; 
	int resulImaginery = this->imaginery + rhs.imaginery;
	return ComplexNumbers ( resultReal, resulImaginery ); 
}

ComplexNumbers ComplexNumbers::operator= ( const ComplexNumbers & rhs )
{
	this->real = rhs.real; 
	this->imaginery = rhs.imaginery;
	return *this; 
}

bool ComplexNumbers::operator== ( const ComplexNumbers & rhs ) const
{
	if (( this->real == rhs.real ) && ( this->imaginery == rhs.imaginery ))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ComplexNumbers::operator!= ( const ComplexNumbers & rhs) const
{
	if (( this->real == rhs.real ) && ( this->imaginery == rhs.imaginery ))
	{
		return false;
	}
	else
	{
		return true;
	}
}
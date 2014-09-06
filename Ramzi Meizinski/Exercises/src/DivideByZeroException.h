/*
 * DivideByZeroException.h
 *
 *  Created on: Aug 26, 2014
 *      Author: Student
 */
#include <stdexcept>
using namespace std;

#ifndef DIVIDEBYZEROEXCEPTION_H_
#define DIVIDEBYZEROEXCEPTION_H_

class DivideByZeroException : public runtime_error
{
public:
	DivideByZeroException::DivideByZeroException()
	:runtime_error("attempted to divide by zero"){}

};

#endif /* DIVIDEBYZEROEXCEPTION_H_ */

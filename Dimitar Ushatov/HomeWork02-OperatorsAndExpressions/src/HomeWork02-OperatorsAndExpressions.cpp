//============================================================================
// Name        : HomeWork02-OperatorsAndExpressions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void CheckForOdd(int number){
	bool result = number % 2 == 0;
	cout << "The number " << number << " is odd : " << (result ? "true":"false") << endl;
}

void CheckDivisionBy5And7(int number){
	bool result = number % 5 == 0 && number % 7 == 0;
	cout << "The number " << number << " can be divided by 5 and 7 without reminder: "
			<< (result ? "true":"false") << endl;
}

void CheckThirdDigit(int number){
	bool isSeven = (number / 100) % 10 == 7;
	cout << "The third digit of the number "<< number << " is 7: "
			<< (isSeven? "true":"false") << endl;
}

void CheckThirdBit(int number){
	bool isOne = (number >> 2) % 2 == 1;

	cout << "The third bit of the number " << number << " is 1: "
			<< (isOne ? "true" : "flase") << endl;
}

void CalcAreaAndPerimeter(double width, double height){
	cout<< "The area of a rectangle with width "<< width
			<< " and height " << height
			<< " is " << width*height<<endl;
	cout<< "The perimeter of a rectangle with width "<< width
				<< " and height " << height
				<< " is " << 2*width + 2*height<<endl;
}

void CalcTrapezoidArea(double sideA, double sideB, double height){
	double area = (sideA + sideB)/2 * height;
	cout << "The area of a trapezoid with sideA " << sideA
			<<", sideB " << sideB << " and height "
			<< height << " is " << area << endl;
}

void CalcWeightOnMoon(double weightOnEarth){
	float g = 9.8f;
	float gOnMoon = g * 0.17f;
	cout<<"If you weight " << "kg on Earth, you will weight "
			<< (weightOnEarth / g) * gOnMoon << "kg." << endl;
}

void CheckPoinWithinCirlce(double x, double y, double x0, double y0, double radius){
	bool isWithin = (x - x0)*(x - x0) + (y - y0)*(y - y0) <= radius*radius;
	cout<<"The point X("<< x <<", "<< y <<")"<< " is within the circle K(0, "
			<< radius<<"): " << (isWithin? "true":"false") <<endl;
}

void CheckWithinCircleOutRect(double x, double y, double x0, double y0,
		double radius, double leftX, double leftY, double width,
		double height) {

	bool isWithinCirc = (x - x0) * (x - x0) + (y - y0) * (y - y0)
			<= radius * radius;

	bool xIsOut = x < leftX || x > leftX + width;
	bool yIsOut = y < leftY || y > leftY + height;

	bool isOutRect = xIsOut || yIsOut;

	bool isOutRectWithinCirc = isWithinCirc && isOutRect;

	cout << "The point X(" << x << ", " << y << ")"
			<< " is within the circle K((" << x0 << ", " << y0 << "), "
			<< radius << ") and out of the rectangle R((" << leftX << ", "
			<< leftY << "), " << width << ", " << height << "): "
			<< (isOutRectWithinCirc ? "true" : "false") << endl;
}

void FourDigitNumberOperation() {
	int firstNumber = 0;
	cin >> firstNumber;
	int number = firstNumber;
	int a = number % 10;
	number = number / 10;
	int b = number % 10;
	number /= 10;
	int c = number % 10;
	int d = number / 10;

	int sumOfDigits = a + b + c + d;
	int reversedNum = a * 1000 + b * 100 + c * 10 + d;
	int lastDigitInFront = a * 1000 + d * 100 + c * 10 + b;
	int switchedDigits = d * 1000 + b * 100 + c * 10 + a;
	cout<<firstNumber<<endl;
	cout<<sumOfDigits<<endl;
	cout<<reversedNum<<endl;
	cout<<lastDigitInFront<<endl;
	cout<<switchedDigits<<endl;
}

void FindAllPrimeInInterval(int endInterval){
	int limit = 0;
	bool isPrime = true;
	for (int i = 1; i < endInterval; i++) {
		limit = (int)sqrt(i);
		for (int g = 2; g <= limit; g++) {
			if (i % g == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			cout<< i << " is prime!" << endl;
		}
		isPrime = true;
	}
}

int main() {
	CheckForOdd(7);
	CheckDivisionBy5And7(35);
	CheckThirdDigit(1520);
	CheckThirdBit(256);
	CalcAreaAndPerimeter(15, 18);
	CalcTrapezoidArea(15, 12, 6);
	CalcWeightOnMoon(78);
	CheckPoinWithinCirlce(5, 5, 0, 0, 5);
	CheckWithinCircleOutRect(-2, 2, 1, 1, 4, -1, 1, 5, 5);
	FourDigitNumberOperation();
	FindAllPrimeInInterval(100);
	return 0;
}

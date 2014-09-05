//============================================================================
// Name        : Lection11Ex5.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Point.h"
#include "Rectangle.h"
#include <iostream>

using namespace std;

int main(){

	Point p1(1,3);  	Point p2(3,3);
	Point p3(1,1);   	Point p4(3,1);
	Rectangle r1(p1,p2,p3,p4);
	cout << "Height: " << r1.getHeight()<<endl;
	cout << "Width: " << r1.getWidth()<<endl;
	cout << "Perimeter: "<< r1.getPerimeter()<< endl;
	cout << "Area: "<< r1.getArea()<< endl;
	cout << "Is square?: "<< r1.isSquare() <<endl;


	Point p5(1,7);  	Point p6(3,7);
	Point p7(1,1);   	Point p8(3,1);
	Rectangle r2(p5,p6,p7,p8);
	cout << "Height: " << r2.getHeight()<<endl;
	cout << "Width: " << r2.getWidth()<<endl;
	cout << "Perimeter: "<< r2.getPerimeter()<< endl;
	cout << "Area: "<< r2.getArea()<< endl;
	cout << "Is square?: "<< r2.isSquare() <<endl;

return 0;
}

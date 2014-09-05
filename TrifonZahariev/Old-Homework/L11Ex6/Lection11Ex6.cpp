//============================================================================
// Name        : Lection11Ex6.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Point.h"
#include "Rectangle.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;


void setFillCharacter(char ch, int width, int height)
{
	for (int row = 0; row < width - 1; row++){
	cout << ch;
		for(int col = 0; col < height - 1; col++){
			cout << ch;

		}
	}
}


void drawRectangleInBox(int widthBox, int heightBox, int recWidth,
		int recHeight, int p5X, int p5Y, int p6X, int p6Y, int p7X, int p7Y, int p8X, int p8Y) {
	using std::cout;
	cout << "+";
	for (int i = 0; i < widthBox - 2; i++) {
		cout << "-";
	}
	cout << "+\n";

	for (int i = 0; i < heightBox - 2; i++) {
		if (i == p5X) {
		setFillCharacter('*', recWidth, recHeight);
		} else {
			cout << "|";
		}
		for (int j = 0; j < widthBox - 2; j++) {
			if (j == p5Y) {
				setFillCharacter('*', recWidth, recHeight);
			} else {
				cout << " ";
			}
		}
		cout << "|\n";
	}

	cout << "+";

	for (int i = 0; i < widthBox - 2; i++) {
		cout << "-";
	}
	cout << "+\n";
}

int main() {

	Point p1(1, 3);
	Point p2(3, 3);
	Point p3(1, 1);
	Point p4(3, 1);
	Rectangle r1(p1, p2, p3, p4);
	cout << "Height: " << r1.getHeight() << endl;
	cout << "Width: " << r1.getWidth() << endl;
	cout << "Perimeter: " << r1.getPerimeter() << endl;
	cout << "Area: " << r1.getArea() << endl;
	cout << "Is square?: " << r1.isSquare() << endl;

	Point p5(1, 7);
	Point p6(3, 7);
	Point p7(1, 1);
	Point p8(3, 1);
	Rectangle r2(p5, p6, p7, p8);
	cout << "Height: " << r2.getHeight() << endl;
	cout << "Width: " << r2.getWidth() << endl;
	cout << "Perimeter: " << r2.getPerimeter() << endl;
	cout << "Area: " << r2.getArea() << endl;
	cout << "Is square?: " << r2.isSquare() << endl;


	drawRectangleInBox(25, 25, r2.getWidth(), r2.getHeight(), p5.getX(), p5.getY(), p6.getX(), p6.getY(), p7.getX(), p7.getY(), p8.getX(), p8.getY());

	return 0;
}

//============================================================================
// Name        : HomeWork16-Polymorphism.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
#include "Cube.h"
#include "Pyramid.h"
#include "Sphere.h"
#include <windows.h>


using namespace std;

int main() {
	vector<Shape *> shapes;

	Square square(5);
	Circle circle(6);
	Triangle triangle(3, 4, 5);
	Cube cube(7);
	Pyramid pyramid(4, 5, 6);
	Sphere sphere(10);

	shapes.push_back(&square);
	shapes.push_back(&circle);
	shapes.push_back(&triangle);
	shapes.push_back(&cube);
	shapes.push_back(&pyramid);
	shapes.push_back(&sphere);
	TwoDimShape * checkTwo = 0;
	ThreeDimShape * checkThree = 0;
	for (unsigned int i = 0; i < shapes.size(); ++i) {
		shapes[i]->print();
		cout << endl;
		checkTwo = dynamic_cast<TwoDimShape*>(shapes[i]);
		if (checkTwo != 0) {
			cout << "The " << checkTwo->getName()
					<< " is a Two Dimentional shape and it's area is "
					<< checkTwo->getArea() << endl;
		}
		checkThree = dynamic_cast<ThreeDimShape*>(shapes[i]);
		if (checkThree != 0) {
			cout << "The " << checkThree->getName()
					<< " is a Three Dimentional shape. Tt's area is "
					<< checkThree->getArea() << " and it's volume is "
					<< checkThree->getVolume() << endl;
		}
		cout << endl;
	}
	return 0;
}

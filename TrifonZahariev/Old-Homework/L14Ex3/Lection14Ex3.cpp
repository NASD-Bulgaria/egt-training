//============================================================================
// Name        : Lection14Ex3.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Cube.h"

int main() {

	Circle a(5);
	Rectangle b(3, 5);
	Triangle c(4, 5);
	Sphere d(7);
	Cube e(6);

	vector<Shapes*> shapes;
	shapes.push_back(&a);
	shapes.push_back(&b);
	shapes.push_back(&c);
	shapes.push_back(&d);
	shapes.push_back(&e);
	for (unsigned int i = 0; i < shapes.size(); ++i) {
		shapes[i]->print();

	}

	return 0;
}

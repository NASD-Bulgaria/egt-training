//7. Write a C++ program that prompts the user for
//the radius of a circle then calls inline function
//circleArea to calculate the area of that circle.

#include <iostream>
#include <cmath>

using namespace std;

inline double circleArea(double radius)
{
    return M_PI * (radius * radius);
}

int main()
{

    double radius;
    cout << "Radius of circle: ";
    cin >> radius;

    cout << "The area of circle is " << circleArea(radius) << endl;

    return 0;
}





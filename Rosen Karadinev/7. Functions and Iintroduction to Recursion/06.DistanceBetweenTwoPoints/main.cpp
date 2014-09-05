
#include <iostream>
#include <cmath>

double Distance(double point1X, double point1Y, double point2X, double point2Y)
{
    return sqrt((point2X - point1X)*(point2X - point1X) + (point2Y - point1Y)*(point2Y - point1Y));
}

int main()
{
    using namespace std;

    // Calculate two distances
    cout << "Examples: " << endl;
    cout << "Distance = " << Distance(0.0, 0.0, 0.0, 1.0) << endl;
    cout << "Distance = " << Distance(1.0, 1.0, 5.0, 5.0) << endl << endl;

    double point1X;
    double point1Y;
    double point2X;
    double point2Y;

    cout <<"X1 = ";
    cin >> point1X;
    cout << "X2 = ";
    cin >> point2X;
    cout << "Y1 = ";
    cin >> point1Y;
    cout << "Y2 = ";
    cin >> point2Y;

    cout << endl;

    cout << "The distance between X1X2 and Y1Y2 is " << Distance(point1X, point2X, point1Y, point2Y) << endl << endl;

    return 0;
}





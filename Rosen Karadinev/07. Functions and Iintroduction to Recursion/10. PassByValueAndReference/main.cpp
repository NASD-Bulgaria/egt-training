//10. Write a complete C++ program with the two
//alternate functions specified below, of which
//each simply triples the variable count defined in
//main. Then compare and contrast the two
//approaches. These two functions are :
//-function tripleByValue
//that passes a copy of count by value, triples the
//copy and returns the new value and
//-function tripleByReference
//that passes count by reference via a reference
//parameter and triples the original value of count
//through its alias (i.e., the reference parameter).

#include <iostream>
#include <cmath>


using namespace std;


int passByValue(int);
int passByReference(int &);

int main()
{

  int count = 2;
  cout << "Enter value for count = ";
  cin >> count;

  cout << "Count triple by value --> " << passByValue(count) << endl;
  cout << "original variable count is " << count << endl;

  cout << "Count triple by reference --> " << passByReference(count) << endl;
  cout << "Original variable count is changed to " << count << endl;

}

int passByValue(int number)
{
    return number *= 3;
}

int passByReference(int &numberRef)
{
    return numberRef *= 3;
}





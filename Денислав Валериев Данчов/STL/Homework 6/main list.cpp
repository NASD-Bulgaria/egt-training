#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main()
{
 int arr[] = {2, 2, 3, 2, 3, 4, 3};

 int sizeArr = sizeof(arr) / sizeof *arr;

 list<int> conditionals;

 conditionals.insert(conditionals.begin(), arr, arr + sizeArr);

 conditionals.sort();
 conditionals.unique();

 list<int>::const_iterator it;
 int counter = 0;

 for(it = conditionals.begin(); it != conditionals.end(); it++)
 {
  for(int j = 0; j < sizeArr; j++)
  {
   if(*it == arr[j])
   {
    counter++;
   }
  }
  cout<<*it<<" -> "<<counter<<endl;
  counter = 0;
 }
 return 0;
}

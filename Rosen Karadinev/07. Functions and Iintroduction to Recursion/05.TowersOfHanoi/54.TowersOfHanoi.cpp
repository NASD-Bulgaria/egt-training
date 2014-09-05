#include <iostream>
using namespace std;



void move(int count, int peg1, int peg3, int peg2)
{
    if(count > 0)
        {
            move(count - 1, peg1,peg2,peg3);
            cout << "Move disk " << count << " from " << peg1 << " to " << peg3 << "." << endl;
            move(count - 1, peg2, peg3, peg1);

        }
}

int main()
{
  int numberOfDisks;

  cout << "Enter the number of disks: ";
  cin >> numberOfDisks;
  cout << endl;

  move(numberOfDisks, 1, 3, 2);

  return 0;
}

#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>


using namespace std;
template < typename T >
void printList( const std::list< T > &listRef );
bool isFound(int n, int m);

int main()
{
   int n;
   int m;
   while(n>m)
   {
       cout<< "please enter n "<<endl;
       cin>>n;
       cout<<"Please neter m"<<endl;
       cin>>m;
   }

   list<int>sequence;
   sequence.push_front(m);

    while(n!= m)
    {

        if (isFound(n, m))
        {
            sequence.push_front(n);
            break;
        }
           if (m == 5 && n == 1)
           {
               sequence.push_front(m - 2);
               sequence.push_front(n);
               break;
           }

           if (m % 2 == 1)
           {
               m -= 1;
               sequence.push_front(m);
           }
           else
           {
               if (m / 2 > n)
               {
                   m /= 2;
                   sequence.push_front(m);
               }
               else
               {
                   if (m - 2 > n)
                   {
                       m -= 2;
                       sequence.push_front(m);
                   }
               }
           }


    }

    printList(sequence);
    return 0;
}

bool isFound(int n, int m)
{
    if ((m % 2 == 0) && (m / 2 == n))
    {
        return true;
    }
    else
    {
        if (m - 2 == n)
        {
            return true;
        }
        else
        {
            if (m - 1 == n)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    }

}

template < typename T >
void printList( const list< T > &listRef )
{
     if ( listRef.empty() )
     {
        cout << "List is empty";
     }
     else
     {
     ostream_iterator< T > output( cout, " " );
     copy( listRef.begin(), listRef.end(), output );
    }
}


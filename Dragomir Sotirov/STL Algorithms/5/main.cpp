#include <iostream>
#include <set>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{

srand(time(0));

vector<int> randoms;
vector<int> nsorted;

ostream_iterator< int > output( cout, " " );

cout << "Enter N positon for sorting:";
int n;
cin >> n;

cout << "Enter length of vector:";
int l;
cin >> l;

cout << "Randoms in Vector are:"<<endl;

for (int i = 0; i < l; i++)
{
	randoms.push_back(1 + rand() % 10);
	cout << randoms[i]<<" ";
}

for (int i = 0; i < n ; i++)
{
	nsorted.push_back(randoms[i]);
}

sort(nsorted.begin(),nsorted.end());

for (unsigned i = n; i < randoms.size(); i++)
{
	nsorted.push_back(randoms[i]);
}

cout << endl << "Sorted till N position array are:" << endl;

for (unsigned i = 0; i < nsorted.size(); i++)
{
	cout << nsorted[i]<<" ";
}

return 0;
}

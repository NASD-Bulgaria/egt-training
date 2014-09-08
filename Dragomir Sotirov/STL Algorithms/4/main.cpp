#include <iostream>
#include <set>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{

srand(time(0));

vector<int> randoms;

for (int i = 0; i < 10; i++)
{
	randoms.push_back(1 + rand() % 10);
}

sort(randoms.begin(), randoms.end());

for (unsigned i = randoms.size() - 1; i > 0; i--)
{
	cout << randoms[i]<<" ";
}

cout << endl << "The First 3 bigger elements are:" << endl;

for (unsigned i = randoms.size() - 1; i > 6; i--)
{
	cout << randoms[i]<<" ";
}

return 0;
}

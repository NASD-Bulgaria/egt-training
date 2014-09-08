#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<stdlib.h>
#include<ctime>

using namespace std;
int randomNum();

int main() {
	vector<int> ints(10);
	ostream_iterator<int> output(cout, " ");
	generate(ints.begin(), ints.end(), randomNum);
	copy(ints.begin(), ints.end(), output);
	cout << endl;
	vector<int> vec(3);
	vector<int> vec2(3 );
	for(int i=0;i<ints.size()-2;i++)
	{
	copy(ints.begin()+i, ints.begin() + 3+i, vec2.begin());
	copy(ints.begin()+i, ints.begin() + 3+i, vec.begin());
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	if(vec==vec2)
	{
		copy(vec.begin(), vec.end(), output);
		break;
	}
	}

	return 0;
}
int randomNum() {
	int num = rand() % 100;
	return num;
}


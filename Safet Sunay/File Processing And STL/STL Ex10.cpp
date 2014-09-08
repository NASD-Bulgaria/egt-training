#include <iostream>
#include <vector>
#include <map>

using namespace std;

void nToM(int, int, vector<int> &);

int main()
{
	int n;
	int m;

	cout << "Please enter N: ";
	cin >> n;

	cout << "Please enter M: ";
	cin >> m;

	vector<int> res;

	nToM(n, m, res);

	cout << "N - "<< n <<", M - "<<m<< endl;

	for (unsigned int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}

	cout << res.size() << " - Operations"<<endl;


	return 0;
}

void nToM(int inpN, int inpM, vector<int> &vec1)
{
	map<int, int> tank;

	int temp = inpM;
	int tempRem = 0;

	while(temp >= inpN)
	{
		tempRem = temp % 2;
		tank.insert(make_pair(temp, tempRem));
		temp = temp / 2;
	}

	map<int, int>::iterator it;

	for (it = tank.begin(); it != tank.end(); ++it)
	{
		if (it == tank.begin())
		{
			int w = (*it).first;
			w -= inpN;
			int wRem = w % 2;

			while(inpN != (*it).first)
			{
				if(wRem == 1)
				{
					inpN += 1;
					wRem = 0;
					vec1.push_back(inpN);
				}
				else
				{
					inpN += 2;
					vec1.push_back(inpN);
				}
			}
		}
		else
		{
			inpN *= 2;
			vec1.push_back(inpN);
			if((*it).second == 1)
			{
				inpN += 1;
				vec1.push_back(inpN);
			}
		}
	}
}




#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;


#include "FrequencyNumber.h"

FrequencyNumber::FrequencyNumber() {
	

}

void FrequencyNumber::printMap()
{
	vector<pair<int,int> > sorted(numberFrequency.begin(), numberFrequency.end());
	sort(sorted.begin(), sorted.end(), pairComparer);
	vector<pair<int,int> >::iterator it;

	int counter = 0;

	cout << "\nStatistics" << endl;
	cout << setw(6) << right <<"number" << setw(11) << right <<"frequency" << endl;

	for (it=sorted.begin(); it != sorted.end(); it++)
	{

		if(counter == 10)
		{
			break;
		}

		cout << setw(6) << right << it->first<< setw(11) << right << it->second << endl;
		counter++;

	}

}

void FrequencyNumber::setMapFromFile(map <int,int> fileMap)
{
	this->numberFrequency=fileMap;
}

void FrequencyNumber::setMap(vector<int> randomNumbers)
{
	for (unsigned i = 0; i < randomNumbers.size(); i++) {
			numberFrequency[randomNumbers[i]]++;
		}

}


map<int,int> FrequencyNumber::getMap()
{
	return numberFrequency;
}

bool FrequencyNumber::pairComparer(pair<int, int> first, pair<int, int> second)
{
	return first.second > second.second;
}

FrequencyNumber::~FrequencyNumber() {
	// TODO Auto-generated destructor stub
}


#ifndef FREQUENCYNUMBER_H_
#define FREQUENCYNUMBER_H_

#include <map>
#include <vector>
using namespace std;

class FrequencyNumber {

public:
	FrequencyNumber();
	virtual ~FrequencyNumber();
	void setMap(vector<int> &);
	void setMapFromFile(map<int,int>);
	void printMap();
	map<int,int> getMap();
	vector<int> getNumb();
	vector<int> getFreq();
	void clear();

private:

	vector<int>numb;
	vector<int>freq;

	map<int, int> numberFrequency;
	static bool pairComparer(pair<int,int> first, pair<int,int> second);

};

#endif

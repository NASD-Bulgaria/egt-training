#ifndef FREQUENCYNUMBER_H_
#define FREQUENCYNUMBER_H_

#include <map>
#include <vector>
using namespace std;

class FrequencyNumber {

public:
	FrequencyNumber();
	virtual ~FrequencyNumber();
	void setMap(vector<int>);
	void setMapFromFile(map<int,int>);
	void printMap();
	map<int,int> getMap();

private:
	map<int, int> numberFrequency;
	static bool pairComparer(pair<int,int> first, pair<int,int> second);

};

#endif

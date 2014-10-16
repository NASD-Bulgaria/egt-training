#ifndef RECOVERY_H_
#define RECOVERY_H_

#include <string>
#include <ctime>

namespace GameObjects {

class Recovery {

public:
	Recovery();
	~Recovery();
	int getMoney() const;
	void setMoney(int money);
	int getTime() const;
	void setTime(int time);
	void save();
	bool load();
	void init();

private:
	int money;
	int t;
};
}

#endif 
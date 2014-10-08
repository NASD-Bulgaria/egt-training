#ifndef RECOVERY_H_
#define RECOVERY_H_

class Recovery {
public:
	Recovery(int=0);
	virtual ~Recovery();
	void setRecoveryBalance(int);
	int getRecoveryBalance();

private:
	int balance;
};

#endif /* RECOVERY_H_ */

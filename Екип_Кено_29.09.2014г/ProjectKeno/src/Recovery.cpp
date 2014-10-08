#include "Recovery.h"

Recovery::Recovery(int a)
{
	setRecoveryBalance(a);
}

void Recovery::setRecoveryBalance(int a)
{
	this->balance=a;
}

int Recovery::getRecoveryBalance()
{
	return balance;
}

Recovery::~Recovery() {
	// TODO Auto-generated destructor stub
}


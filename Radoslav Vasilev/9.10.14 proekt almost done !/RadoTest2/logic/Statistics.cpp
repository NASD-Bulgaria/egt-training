#include "Statistics.h"


int Statistics::getWining_hands() const
{
    return wining_hands;
}

void Statistics::setWining_hands(int value)
{
    wining_hands = value;
}

int Statistics::getLossing_hands() const
{
    return lossing_hands;
}

void Statistics::setLossing_hands(int value)
{
    lossing_hands = value;
}

int Statistics::getCash_flow() const
{
    return cash_flow;
}

void Statistics::setCash_flow(int value)
{
    cash_flow = value;
}

int Statistics::getCash_out() const
{
    return cash_out;
}

void Statistics::setCash_out(int value)
{
    cash_out = value;
}


Statistics::Statistics(int wining_hands, int lossing_hands, int cash_flow, int cash_out)
{
}
